<?php

function buildResultsTable($results)
{
    $labelmarker = 1;

    echo '<table id="tableresults">';
    echo
        '<tr><th>Marker</th><th>Dog Park Name</th><th>Street</th><th>Suburb</th>' .
        '<th>Park Area</th><th>Latitude</th><th>Longitude</th><th>Detailed Information</th>' .
        '</tr>';

    foreach ($results as $park) {
        echo '<tr>';
        echo '<td>';
        echo $labelmarker;
        echo '</td><td>';
        echo $park['dogparkname'];
        echo '</td><td>';
        echo $park['street'];
        echo '</td><td>';
        echo $park['suburb'];
        echo '</td><td>';
        echo $park['dogparkarea'] . 'm<sup>2</sup>';
        echo '</td><td>';
        echo $park['latitude'];
        echo '</td><td>';
        echo $park['longitude'];
        echo '</td><td>';
        echo '<a href="individual.php?id=', $park['id'], '">More Information...</a>';
        echo '</tr>';
        $labelmarker++;
    }

    echo '</table>';
}


?>