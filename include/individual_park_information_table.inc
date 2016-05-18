<?php


function buildIndividualParkResultTable($result)
{

    /*
     * Due to the inverted orientation of the table and the requirement for microdata,
     * the following code is repeditive
     * 
     * can't directly access rows to build metadata due to stupid HTML validation
     * this is the sole cause of all this redundancy
     * because of these stupid requirements I'm creating seperate vars to store the
     * table data to then insert into the microdata 
     */

    $parkcode;
    $dogparkname;
    $latitude;
    $longitude;
    $street;
    $suburb;


    echo '<table id="parkinfotable">';
    foreach ($result as $column) {
        $parkcode = $column['parkcode'];
        $dogparkname = $column['dogparkname'];
        $latitude = $column['latitude'];
        $longitude = $column['longitude'];
        $street = $column['street'];
        $suburb = $column['suburb'];
        echo '<tr><td>ID:</td><td>' . $column['id'] . '</td></tr>';
        echo '<tr><td>Park Code:</td><td>' . $column['parkcode'] . '</td></tr>';
        echo '<tr><td>Park Name:</td><td>' . $column['parkname'] . '</td></tr>';
        echo '<tr><td>Street:</td><td>' . $column['street'] . '</td></tr>';
        echo '<tr><td>Suburb:</td><td>' . $column['suburb'] . '</td></tr>';
        echo '<tr><td>Node ID:</td><td>' . $column['nodeid'] . '</td></tr>';
        echo '<tr><td>Dog Park Name:</td><td>' . $column['dogparkname'] . '</td></tr>';
        echo '<tr><td>Dog Park Area:</td><td>' . $column['dogparkarea'] . '</td></tr>';
        echo '<tr><td>Latitude:</td><td>' . $column['latitude'] . '</td></tr>';
        echo '<tr><td>Longitude:</td><td>' . $column['longitude'] . '</td></tr>';
    }
    echo '</table>';

    // Microdata, this is seperated from the table instead of being integrated
    // within it due to the need for div containers to split it up (which when done in a table fail validation

    echo '<div class="hiddenmeta" itemscope itemtype="http://schema.org/Park">';
    echo '<p itemprop="branchCode">' . $parkcode . '</p>';
    echo '<p itemprop="name">' . $dogparkname . '</p>';
        // geolocation
        echo '<div itemprop="geo" itemscope itemtype="http://schema.org/GeoCoordinates">';
    echo '<p itemprop="latitude" content="' . $latitude . '"></p>';
    echo '<p itemprop="longitude" content="' . $longitude . '"></p>';
        echo '</div>';
    // address
        echo '<div itemprop="address" itemscope itemtype="http://schema.org/PostalAddress">';
    echo '<p itemprop="streetAddress" content="' . $street . '"></p>';
    echo '<p itemprop="addressLocality" content="' . $suburb . '"></p>';
        echo '<p itemprop="addressRegion" content="' . "Brisbane" . '"></p>';
        echo '</div>';
    echo '</div>';
}