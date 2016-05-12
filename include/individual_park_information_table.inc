<?php


function buildIndividualParkResultTable($result)
{

    /*
     * Due to the inverted orientation of the table, the construction is relatively repeditive
     */

    echo '<table id="parkinfotable">';
    foreach ($result as $column) {
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
}