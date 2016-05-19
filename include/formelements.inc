<?php

/*
 * This PHP file defines the form elements that comprise the user input
 * forms, individual commenting isn't needed as this is pretty self-explanatory
 */

require_once 'pdo_connect.inc';

function label($name, $label)
{
    echo '<label>' . $label . ':</label>';
}

function posted_value($name)
{
    if (isset($_POST[$name])) {
        return htmlspecialchars($_POST[$name]);
    }

}

function usernameField($name, $label, $type)
{
    if (isset($_POST[$name])) {
        $value = htmlspecialchars($_POST[$name]);
    } else {
        $value = "";
    }
    echo '<h1>' . $label . '</h1>';
    echo "<input type=\"$type\" value=\"$value\" name=\"$name\" required/><br>";

}

function passwordField($name, $label, $type)
{
    if (isset($_POST[$name])) {
        $value = htmlspecialchars($_POST[$name]);
    } else {
        $value = "";
    }
    echo '<h1>' . $label . '</h1>';
    echo "<input type=\"password\" value=\"$value\" name=\"$name\" required/><br>";

}


function input_field($name, $label, $pattern, $title, $type)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    if (isset($_POST[$name])) {
        $value = htmlspecialchars($_POST[$name]);
    } else {
        $value = "";
    }
    echo "<input type=\"$type\" value=\"$value\" name=\"$name\" pattern=\"$pattern\" title=\"$title\" required/>";
    echo '</h2>';
}

function loose_input_field($name, $label, $type)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    if (isset($_POST[$name])) {
        $value = htmlspecialchars($_POST[$name]);
    } else {
        $value = null;
    }
    echo "<input type=\"$type\" value=\"$value\" name=\"$name\"/><br>";

    echo '</h2>';
}

function geo_input_field($name, $label, $type, $id)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    if (isset($_POST[$name])) {
        $value = htmlspecialchars($_POST[$name]);
    } else {
        $value = null;
    }
    echo "<input type=\"$type\" id=\"$id\" value=\"$value\" name=\"$name\" readonly/><br>";

    echo '</h2>';
}

function select($name, $values)
{
    echo "<select name=\"$name\">";
    echo '<option selected disabled>Select</option>';
    foreach ($values as $value => $display) {
        echo "<option>$display</option>";
    }
    echo '</select>';
}

function selectoptional($name, $label)
{
    $contents = array("<10km", "<20km", "<30km", "<40km", "<50km", ">50km");
    $values = array(10, 20, 30, 40, 50, 60);
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    echo "<select name=\"$name\">";
    echo '<option value="5" selected>&lt;5km</option>';
    echo '<option value="10">&lt;10km</option>';
    echo '<option value="20">&lt;20km</option>';
    echo '<option value="30">&lt;30km</option>';
    echo '<option value="40">&lt;40km</option>';
    echo '<option value="50">&lt;50km</option>';
    echo '<option value="60">&gt;60km</option>';
    echo '</select>';
    echo '</h2>';
}

function suburb($name, $label) {
    $pdo = createConnection();
    $result = $pdo->query('SELECT DISTINCT suburb FROM n9455396.dogparks');
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    echo '<select name="suburb">';
    echo '<option value="select" selected disabled>Select</option>';
    foreach ($result as $suburb) {
        echo '<option value="', $suburb['suburb'], '">', $suburb['suburb'], '</option>';
    }
    echo '</select><br>';
    echo '</h2>';
}

function rating($name, $label) {
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    $array = array(1, 2, 3, 4, 5);
    select("rating", $array);
    echo '</h2>';
}


function gender($name, $label)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    $array = array("male", "female", "other");
    select("gender", $array);
    echo '</h2>';
}

function genderradiobutton($name, $label)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    echo "<input type=\"radio\" name=\"$name\" value=\"Male\" required>Male";
    echo "<input type=\"radio\" name=\"$name\" value=\"Female\">Female";
    echo "<input type=\"radio\" name=\"$name\" value=\"Other\">Other";
    echo '</h2>';
}

function usercitycheckbox($name, $label)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    echo "<input type=\"checkbox\" name=\"checkyes\" value=\"yes\">Yes";
    echo "<input type=\"checkbox\" name=\"checkno\" value=\"no\">No";
    echo '</h2>';
}

function dateofbirth($name, $label)
{
    $months = range(1, 12);
    $prepend = array('01', '02', '03', '04', '05', '06', '07', '08', '09');
    $days = array_merge($prepend, range(10, 31));
    $years = range(1900, 2016);

    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    select('day', $days);
    select('month', $months);
    select('year', $years);
    echo '</h2>';
}

function geoLocation($name, $label)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo "<input type=\"checkbox\" onclick=\"getLocation()\" name=\"$name\" value=\"yes\">Yes<br>";
    echo '<br>';
    echo '<a onclick="getLocation()" id="geolocationstatus"></a></h2>';
}

function fieldCheck($name, $label)
{
    echo "<input type=\"checkbox\" default=\"unchecked\" name=\"$name\" value=\"yes\">Yes<br>";
}

function commentField($name)
{
    if (isset($_POST[$name])) {
        $value = htmlspecialchars($_POST[$name]);
    } else {
        $value = null;
    }
    echo "<textarea name=\"$name\" id=\"comments\" required>" . $value . "</textarea>";
}

function radioRating($name)
{
    if (isset($_POST[$name])) {
        $value = htmlspecialchars($_POST[$name]);
    } else {
        $value = null;
    }
    echo "<span class=\"starRating\">";
    echo "<label>Rating: </label>";
    for ($i = 1; $i <= 5; $i++) {
        if ($value == $i) {
            echo '<input id="rating' . $i . '" type="radio" name="rating" value=' . $i . ' checked required>';
        } else {
            echo '<input id="rating' . $i . '" type="radio" name="rating" value=' . $i . ' required>';
        }
        echo '<label for="rating1">' . $i . '</label>';
    }
    echo '</span>';
}


?>

