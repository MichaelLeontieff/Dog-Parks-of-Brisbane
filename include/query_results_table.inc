<?php

function buildResultsTable($results)
{

    $labelmarker = 1;

    echo '<table id="tableresults">';
    echo
        '<tr><th>Label (ID)</th><th>Dog Park Name</th><th>Street</th><th>Suburb</th>' .
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

<!--<table id="tableresults">-->
<!---->
<!--<tr>-->
<!--	<td>REINHOLD CRES DOG OFF LEASH AREA</td>-->
<!--    <td>HAMILTON RD</td> -->
<!--    <td>CHERMSIDE</td>-->
<!--    <td>10000</td>-->
<!--    <td>-27.38123113</td>-->
<!--    <td>153.0436597</td>-->
<!--    <td><a href="individual.html">More Information...</a></td>-->
<!--</tr>-->
<!--<tr>-->
<!--	<td>ABBEVILLE ST DOG OFF LEASH AREA</td>-->
<!--    <td>ABBEVILLE ST</td> -->
<!--    <td>UPR MT GRAVATT</td>-->
<!--    <td>1332</td>-->
<!--    <td>-27.5445799</td>-->
<!--    <td>153.0893523</td>-->
<!--    <td><a href="individual.html">More Information...</a></td>-->
<!--</tr>-->
<!--<tr>-->
<!--	<td>HEDLEY AVE DOG OFF LEASH AREA</td>-->
<!--    <td>HEDLEY AVE</td> -->
<!--    <td>NUNDAH</td>-->
<!--    <td>6485</td>-->
<!--    <td>-27.40528155</td>-->
<!--    <td>153.0673599</td>-->
<!--    <td><a href="individual.html">More Information...</a></td>-->
<!--</tr>-->
<!--<tr>-->
<!--	<td>KEDRON BROOK DOG OFF LEASH AREA (AMELIA PK SECTION CLOSED FOR ROADWORKS)</td>-->
<!--    <td>MCCORD ST</td> -->
<!--    <td>GORDON PARK</td>-->
<!--    <td>15714</td>-->
<!--    <td>-27.4163804</td>-->
<!--    <td>153.0329195</td>-->
<!--    <td><a href="individual.html">More Information...</a></td>-->
<!--</tr>-->
<!--  -->
<!--</table>-->