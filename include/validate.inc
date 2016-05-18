<?php
/*
 * this file contains all of the PHP valdiation used
 */
require_once 'include/pdo_connect.inc';

// check for unique username
function UsernameUnique($pdo, $username)
{
    $stmt = $pdo->prepare('SELECT * FROM members WHERE username = :username');
    $stmt->bindValue(':username', $username);
    $stmt->execute();

    if ($stmt->rowCount() == 0) {
        return true;
    } else {
        return false;
    }
}

// count errors in array
function Counterrors($errors)
{
    $counter = 0;
    foreach ($errors as $field => $error) {
        $counter++;
    }
    return $counter;
}

// write errors
function writeErrors($errors)
{
    $errorCount = Counterrors($errors);
    echo '<h2 class="validationerror">';
    echo '<p class="validationerrortitle">The following ' . $errorCount . ' error(s) were found:<br></p>';
    foreach ($errors as $field => $error) {
        echo "- $error</br>";
    }
    echo '</h2>';
}

// count non empty
function countNonEmpty($field_list)
{
    $counter = 0;
    foreach ($field_list as $field) {
        if (!empty($field)) {
            $counter++;
        }
    }
    return $counter;
}


// simply checks if field is empty
function checkEmpty(&$errors, $field_list, $field_name, $label)
{
    if (empty($field_list[$field_name])) {
        $errors[$field_name] = $label . ' is required';
    }
}

// check number of selected fields
function validateCount(&$errors, $field_list)
{
    if (countNonEmpty($field_list) != 1) {
        $errors[] = 'Must enter a single query';
    }
}

// validate username
function validateUsername(&$errors, $field_list, $field_name)
{
    $pdo = createConnection();
    $pattern = '/[a-z0-9_-]{3,16}/';
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Username is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'Username field value is invalid, must be between 3 and 16 characters and comprised of only letters and numbers';
    } else if (!UsernameUnique($pdo, $field_list[$field_name])) {
        $errors[$field_name] = 'Username is already registered';
    }
}

// validate first name
function validateFirstName(&$errors, $field_list, $field_name)
{
    $pattern = "/[A-Za-z]{2,21}/";
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'First Name is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'First Name field value is invalid, must only contain letters and length must be greater than 1 and less than 20';
    }
}

// validate last name
function validateLastName(&$errors, $field_list, $field_name)
{
    $pattern = "/[A-Za-z]{2,21}/";
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Last Name is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'Last Name field value is invalid, must only contain letters and length must be greater than 1 and less than 20';
    }
}

// validate dob
function validateDateofBirth(&$errors, $field_list, $field_name)
{
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Birthday is a required field';
    }
}


// validate gender
function validateGender(&$errors, $field_list, $field_name)
{
    if (!isset($field_list[$field_name])) {
        $errors[$field_name] = 'Gender is a required field';
    }
}

// validate email
function validateEmail(&$errors, $field_list, $field_name)
{
    $pattern = '/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/';
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Email is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'Email field value is invalid, must contain valid email address ie (user@example.com)';
    }
}

// validate password
function validatePassword(&$errors, $field_list, $field_name)
{
    $pattern = "/.{6,}/";
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Password is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'Email field value is invalid, must be 6 characters or more';
    }
}

// validate comment
function validateComment(&$errors, $field_list, $field_name)
{
    $pattern = "/^.{4,200}$/";
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Comment is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'A comment of at least 4 characters and no greater than 200 is required';
    }
}

// validate rating
function validateRating(&$errors, $field_list, $field_name)
{
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Rating is a required field';
    }
}

/*
 * construct HTTP query results url to parse values to results page for sql query
 *
 */
function buildURL($field_list)
{
    $vars = array();

    // check suburb
    if (!empty($field_list['suburb'])) {
        $vars = array('suburb' => $field_list['suburb']);
        // check parkname
    } else if (!empty($field_list['parkname'])) {
        if ($field_list['parkname'] != 'any') {
            $vars = array('parkname' => $field_list['parkname']);
        }
        // check rating
    } else if (!empty($field_list['rating'])) {
        $vars = array('rating' => $field_list['rating']);
        // check geolocation
    } else if (!empty($field_list['lat'])) {
        $vars = array('lat' => $field_list['lat'], 'lon' => $field_list['lon'], 'geolocationrange' => $field_list['geolocationrange']);
    }

    // build query string based on set fields
    $querystring = http_build_query($vars);

    // return HTTP query url containing values
    return $url = "results.php?" . $querystring;

}

?>