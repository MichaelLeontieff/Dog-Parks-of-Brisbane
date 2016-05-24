<?php

/*
 * file contains various helper functions for the search and query process
 */

global $queryresult;

/*
 * function checks what was set in the search form and returns the corresponding
 * variables
 */
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

/*
 * debugging function that simply outputs contents of result query
 */
function outputQueryResultsColumn($results, $column)
{
    foreach ($results as $row) {
        echo $row[$column];
    }
}

/*
 * counts the number of results, redundant but kept it anyway
 */
function numberResults($results)
{
    $count = 0;
    foreach ($results as $row) {
        $count++;
    }
    return $count;
}

/*
 * returns single parkname from result for individual item page
 */
function getParkName($result)
{
    foreach ($result as $row) {
        return $row['dogparkname'];
    }
}

/*
 * once the variables from the search form are extracted
 * this function co-ordinates what corresponding query to run
 * and runs that query, output is the results table
 */
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

/*
 * helper method to fetch individual park by id
 */
function fetchIndividualPark($pdo, $parkid)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE id = :parkid');
    $stmt->bindValue(':parkid', $parkid);
    $stmt->execute();

    return $stmt;
}

/*
 * function to add a user to the database, present here as it interacts with database
 */
function addUser($username, $firstname, $lastname, $dob, $gender, $email, $password, $petid, $location)
{
    $pdo = createConnection();
    $stmt = $pdo->prepare('INSERT INTO members VALUES (:username, :fname, :lname, :dob, :gender, :email, :salt, SHA2(CONCAT(:password, :salt), 0), :petid, :location)');
    $stmt->bindValue(':username', $username);
    $stmt->bindValue(':fname', $firstname);
    $stmt->bindValue(':lname', $lastname);
    $stmt->bindValue(':dob', $dob);
    $stmt->bindValue(':gender', $gender);
    $stmt->bindValue(':email', $email);
    $stmt->bindValue(':salt', '4b3403665fea6');
    $stmt->bindValue(':password', $password);
    $stmt->bindValue(':petid', $petid);
    $stmt->bindValue(':location', $location);
    $stmt->execute();
}

/*
 * add review to database
 */
function addReview($username, $comment, $rating, $parkid)
{
    $pdo = createConnection();
    $stmt = $pdo->prepare('INSERT INTO reviews (parkid, username, comment, rating) VALUES (:parkid, :username,:comment, :rating)');
    $stmt->bindValue(':username', $username);
    $stmt->bindValue(':parkid', $parkid);
    $stmt->bindValue(':comment', $comment);
    $stmt->bindValue(':rating', $rating);
    $stmt->execute();
}

/*
 * fetches the park reviews corresponding to parkid and sorts by date
 */
function getParkReviews($parkid)
{
    $pdo = createConnection();
    $stmt = $pdo->prepare('SELECT * FROM reviews, members WHERE reviews.username = members.username AND parkid = :parkid ORDER BY date DESC');
    $stmt->bindValue(':parkid', $parkid);
    $stmt->execute();
    return $stmt;
}

/*
 * searches parks by suburb
 */
function searchBySuburb($pdo, $value)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE suburb = :suburb');
    $stmt->bindValue(':suburb', $value);
    $stmt->execute();

    return $stmt;
}

/*
 * search by rating, returns all unique parks that have a rating equal to input
 */
function searchByRating($pdo, $queryrating)
{
    $stmt = $pdo->prepare('SELECT DISTINCT *
                           FROM dogparks
                           INNER JOIN reviews ON dogparks.id = reviews.parkid
                           GROUP BY id
                           HAVING reviews.rating = :rating');
    $stmt->bindValue(':rating', $queryrating);
    $stmt->execute();
    return $stmt;
}

/*
 * search by parkname
 */
function searchByName($pdo, $value)
{
    $value = strtoupper($value);
    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE dogparkname LIKE :dogparkname');
    $stmt->bindValue(':dogparkname', "%" . $value . "%");
    $stmt->execute();

    return $stmt;
}

/*
 * return all results
 */
function emptySearch($pdo)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks');
    $stmt->execute();
    return $stmt;
}

/*
 * function to return all results that reside within given radius
 */
function searchByGeoLocation($pdo, $lat, $lon, $range)
{
    // query for all results
    $results = emptySearch($pdo);

    // create storage array
    $matchingParks = array();

    // for each park
    foreach ($results as $row) {

        // calculate its distance
        $currentParkDistance =
            LatLonDistance($lat, $lon, $row['latitude'], $row['longitude']);

        // if radius input is for parks over 60 set row in array
        if ($range == 60) {
            if ($currentParkDistance > $range) {
                $matchingParks[] = $row;
            }
            // else set parks that are lower
        } else if ($currentParkDistance < $range) {
            $matchingParks[] = $row;
        }

    }
    // return array of row objects to be plotted by table results builder
    return $matchingParks;
}

/*
 * fetch park by id
 */
function getParkByID($pdo, $id)
{
    $stmt = $pdo->prepare('SELECT * FROM dogparks WHERE id = :id');
    $stmt->bindValue(':id', $id);
    $stmt->execute();
    return $stmt;
}

// helper function to calculate distance between two points
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