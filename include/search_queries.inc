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
        $queryValues[3] = $_GET['geolocationrange'];
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
        $result = searchByGeoLocation($pdo, $queryValues[1], $queryValues[2], $queryValues[3]);
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

function addUser($username, $firstname, $lastname, $dob, $gender, $email, $password)
{
    $pdo = createConnection();
    $passwordhash = password_hash($password, PASSWORD_DEFAULT);
    $stmt = $pdo->prepare('INSERT INTO members VALUES (:username, :fname, :lname, :dob, :gender, :email, :password)');
    $stmt->bindValue(':username', $username);
    $stmt->bindValue(':fname', $firstname);
    $stmt->bindValue(':lname', $lastname);
    $stmt->bindValue(':dob', $dob);
    $stmt->bindValue(':gender', $gender);
    $stmt->bindValue(':email', $email);
    $stmt->bindValue(':password', $passwordhash);
    $stmt->execute();
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

function searchByName($pdo, $value)
{
    $value = strtoupper($value);
    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE dogparkname LIKE :dogparkname');
    $stmt->bindValue(':dogparkname', "%" . $value . "%");
    $stmt->execute();

    return $stmt;
}

function emptySearch($pdo)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks');
    $stmt->execute();
    return $stmt;
}

function searchByGeoLocation($pdo, $lat, $lon, $range)
{

    // query for all results
    $results = emptySearch($pdo);

    $matchingParks = array();

    foreach ($results as $row) {

        $currentParkDistance =
            LatLonDistance($lat, $lon, $row['latitude'], $row['longitude']);

        if ($range == 60) {
            if ($currentParkDistance > $range) {
                $matchingParks[] = $row;
            }
        } else if ($currentParkDistance < $range) {
            $matchingParks[] = $row;
        }

    }
    return $matchingParks;
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
    $earthRadius = 6371;

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