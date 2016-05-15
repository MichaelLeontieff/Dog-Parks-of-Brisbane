<?php


function buildIndividualParkResultTable($result)
{

    /*
     * Due to the inverted orientation of the table and the requirement for microdata,
     * the following code is repeditive
     */

    echo '<div  itemscope itemtype="http://schema.org/Park">';
    echo '<table id="parkinfotable">';
    foreach ($result as $column) {
        echo '<tr><td>ID:</td><td>' . $column['id'] . '</td></tr>';
        echo '<tr><td>Park Code:</td><td itemprop="branchCode">' . $column['parkcode'] . '</td></tr>';
        echo '<tr><td>Park Name:</td><td>' . $column['parkname'] . '</td></tr>';
        echo '<tr><td>Street:</td><td>' . $column['street'] . '</td></tr>';
        echo '<tr><td>Suburb:</td><td>' . $column['suburb'] . '</td></tr>';
        echo '</div>';
        echo '<tr><td>Node ID:</td><td>' . $column['nodeid'] . '</td></tr>';
        echo '<tr><td>Dog Park Name:</td><td itemprop="name">' . $column['dogparkname'] . '</td></tr>';
        echo '<tr><td>Dog Park Area:</td><td>' . $column['dogparkarea'] . '</td></tr>';
        echo '<tr><td>Latitude:</td><td>' . $column['latitude'] . '</td></tr>';
        echo '<tr><td>Longitude:</td><td>' . $column['longitude'] . '</td></tr>';

        // geolocation
        echo '<div itemprop="geo" itemscope itemtype="http://schema.org/GeoCoordinates">';
        echo '<p itemprop="latitude" content="' . $column['latitude'] . '"></p>';
        echo '<p itemprop="longitude" content="' . $column['longitude'] . '"></p>';
        echo '</div>';

        echo '<div itemprop="address" itemscope itemtype="http://schema.org/PostalAddress">';
        echo '<p itemprop="streetAddress" content="' . $column['street'] . '"></p>';
        echo '<p itemprop="addressLocality" content="' . $column['suburb'] . '"></p>';
        echo '<p itemprop="addressRegion" content="' . "Brisbane" . '"></p>';
        echo '</div>';


    }
    echo '</div>';
    echo '</table>';
}