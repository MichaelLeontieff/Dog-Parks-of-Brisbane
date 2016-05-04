<?php

function label($name, $label)
{
    echo "<label for=" . $name . ">" . $label . ":</label>";
}

function input_field($name, $label, $pattern, $title, $type)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    echo "<input type=\"$type\" name=\"$name\" pattern=\"$pattern\" title=\"$title\" required/>";
    echo '</h2>';
}

function loose_input_field($name, $label, $type)
{
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    echo "<input type=\"$type\" name=\"$name\" />";
    echo '</h2>';
}

function select($name, $values)
{
    echo "<select name=\"$name\">";
    foreach ($values as $value => $display) {
        echo "<option>$display</option>";
    }
    echo '</select>';
}

function suburb($name, $label) {
    echo '<h2 class="subheading">';
    label($name, $label);
    echo '<br>';
    select("suburb", ["Greendale", "Currumbin"]);
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


?>

