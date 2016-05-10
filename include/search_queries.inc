<?php

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

}


function searchByName($value)
{

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
    return $result;
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

function searchByGeolocation($lat, $lon)
{

}

?>