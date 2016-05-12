<?php

global $queryresult;

function fetchVariables()
{
    $queryValues = array();

    if (!empty($_GET['parkname'])) {
        $queryValues[0] = "Park Name";
        $queryValues[1] = $_GET['parkname'];
    } else if (isset($_GET['suburb'])) {
        $queryValues[0] = "Suburb";
        $queryValues[1] = $_GET['suburb'];
    } else if (!empty($_GET['rating'])) {
        $queryValues[0] = "Rating";
        $queryValues[1] = $_GET['rating'];
    } else if (!empty($_GET['lat'])) {
        $queryValues[0] = "GeoLocation";
        $queryValues[1] = $_GET['lat'];
        $queryValues[2] = $_GET['lon'];
    } else {
        // if it's an empty search
        $queryValues[0] = "Empty Search";
    }

    return $queryValues;
}

function numberResults($results)
{
    $count = 0;
    foreach ($results as $row) {
        $count++;
    }
    return $count;
}

function getParkName($result)
{
    foreach ($result as $row) {
        return $row['dogparkname'];
    }
}

function fetchQueryResults($pdo, $queryValues)
{
    if ($queryValues[0] == "Park Name") {
        $result = searchByName($pdo, $queryValues[1]);
    } else if ($queryValues[0] == "Suburb") {
        $result = searchBySuburb($pdo, $queryValues[1]);
    } else if ($queryValues[0] == "Rating") {
        $result = searchByRating($pdo, $queryValues[1]);
    } else if ($queryValues[0] == "GeoLocation") {
        $result = searchByGeoLocation($pdo, $queryValues[1], $queryValues[2]);
    } else if ($queryValues[0] == "Empty Search") {
        $result = emptySearch($pdo);
    }
    return $result;
}

function fetchIndividualPark($pdo, $parkid)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE id = :parkid');
    $stmt->bindValue(':parkid', $parkid);
    $stmt->execute();

    return $stmt;
}

function searchBySuburb($pdo, $value)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE suburb = :suburb');
    $stmt->bindValue(':suburb', $value);
    $stmt->execute();

    return $stmt;
}

function searchByRating($value)
{

}

//function searchByName($pdo, $value)
//{
//    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE parkname LIKE ?');
//    $stmt->bindValue(1, $value + '%');
//    $stmt->execute();
//
//    return $stmt;
//}

function emptySearch($pdo)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks');
    $stmt->execute();
    return $stmt;
}

function searchByGeoLocation($pdo, $lat, $lon)
{

    // query for all results
    $results = emptySearch($pdo);

    // for every park, find the distance from the user,
    // record the current lowest in var to return at end
    $shortestDistPark = 0;
    $shortestDistParkID = 0;
    $firstIteration = true;
    foreach ($results as $row) {
        // initialise current lowest at the first park to set the distance to beat

        $currentParkDistance =
            LatLonDistance($lat, $lon, $row['latitude'], $row['longitude']);

        if ($firstIteration) {
            $firstIteration = false;
            $shortestDistPark = $currentParkDistance;
            $shortestDistParkID = $row['id'];
        }

        if ($currentParkDistance < $shortestDistPark) {
            $shortestDistPark = $currentParkDistance;
            $shortestDistParkID = $row['id'];
        }

    }
    $GLOBALS['shortestDistParkGlobal'] = $shortestDistPark;
    return getParkByID($pdo, $shortestDistParkID);
}

function getParkByID($pdo, $id)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE id = :id');
    $stmt->bindValue(':id', $id);
    $stmt->execute();
    return $stmt;
}

function getParkDistance()
{
    $distance = $GLOBALS['shortestDistParkGlobal'] / 1000;
    return round($distance, 2, PHP_ROUND_HALF_UP);

}

function LatLonDistance($userLat, $userLon, $parkLat, $parkLon)
{
    // set earth radius
    $earthRadius = 6371000;

    // convert from degrees to radians
    $userLatRad = deg2rad($userLat);
    $userLonRad = deg2rad($userLon);
    $parkLatRad = deg2rad($parkLat);
    $parkLonRad = deg2rad($parkLon);

    $latDelta = $parkLatRad - $userLatRad;
    $lonDelta = $parkLonRad - $userLonRad;

    $angle = 2 * asin(sqrt(pow(sin($latDelta / 2), 2) +
            cos($userLatRad) * cos($parkLatRad) * pow(sin($lonDelta / 2), 2)));
    return $angle * $earthRadius;
}

?>