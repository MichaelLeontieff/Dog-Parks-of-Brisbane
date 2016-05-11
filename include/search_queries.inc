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
    } else if ($queryValues[0] == "Geolocation") {
        $result = searchByGeoLocation($pdo, $queryValues[1], $queryValues[2]);
    } else if ($queryValues[0] == "Empty Search") {
        $result = emptySearch($pdo);
    }

    $queryresult = $result;

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

function searchByGeolocation($lat, $lon)
{

}

?>