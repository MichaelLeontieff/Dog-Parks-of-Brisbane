<?php

include 'pdo_connect.inc';

function label($name, $label)
{
    echo "<label for=" . $name . ">" . $label . ":</label>";
}

function posted_value($name)
{
    if (isset($_POST[$name]))
        echo htmlspecialchars($_POST[$name]);
}

function usernamepasswordField($name, $label, $type)
{
    if (isset($_POST[$name])) {
        $value = htmlspecialchars($_POST[$name]);
    } else {
        $value = "";
    }
    echo '<h1>' . $label . '</h1>';
    echo "<input type=\"$type\" value=\"$value\" name=\"$name\" required/><br>";

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
    echo '<option selected disabled>select</option>';
    foreach ($values as $value => $display) {
        echo "<option>$display</option>";
    }
    echo '</select>';
}

function selectoptional($name, $values)
{
    echo "<select name=\"$name\">";
    echo '<option selected>all</option>';
    foreach ($values as $value => $display) {
        echo "<option>$display</option>";
    }
    echo '</select>';
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
    select("rating", [1, 2, 3, 4, 5]);
    echo '</h2>';
}


function gender($name, $label)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    select("gender", ["male", "female", "other"]);
    echo '</h2>';
}

function dateofbirth($name, $label)
{
    $months = array('None' => 'Select...', 1 => 'Jan', 2 => 'Feb', 3 => 'Mar', 4 => 'Apr', 5 => 'May', 6 => 'Jun', 7 => 'Jul', 8 => 'Aug',
        9 => 'Sep', 10 => 'Oct', 11 => 'Nov', 12 => 'Dec');
    $days = range(1, 31);
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
    echo "<input type=\"checkbox\" default=\"unchecked\" onclick=\"getLocation()\" name=\"$name\" value=\"yes\">Yes<br>";
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
            echo '<input id="rating1" type="radio" name="rating" value=' . $i . ' checked required>';
        } else {
            echo '<input id="rating1" type="radio" name="rating" value=' . $i . ' required>';
        }
        echo '<label for="rating1">' . $i . '</label>';
    }
    echo '</span>';
}


?>

