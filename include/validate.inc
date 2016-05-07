<?php

// count errors in array
function Counterrors($errors)
{
    $counter = 0;
    foreach ($errors as $field => $error) {
        $counter++;
    }
    return $counter;
}

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


// check number of selected fields
function validateCount(&$errors, $field_list)
{
    if (countNonEmpty($field_list) != 1) {
        $errors[] = 'Must enter a single query';
    }
}

function validatePark(&$errors, $field_list, $field_name)
{
    $pattern = "/[A-Za-z0-9]{2,}/";
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Parkname is required for form submission, type "any" to negate field from query';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'Username field value is invalid, must be between 3 and 16 characters and comprised of only letters and numbers';
    }
}

// validate username
function validateUsername(&$errors, $field_list, $field_name)
{
    $pattern = '/[a-z0-9_-]{3,16}/';
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Username is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'Username field value is invalid, must be between 3 and 16 characters and comprised of only letters and numbers';
    }
}

// validate first name
function validateFirstName(&$errors, $field_list, $field_name)
{
    $pattern = "/[A-Za-z]{2,}/";
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'First Name is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'First Name field value is invalid, must only contain letters and length must be greater than 1';
    }
}

// validate last name
function validateLastName(&$errors, $field_list, $field_name)
{
    $pattern = "/[A-Za-z]{2,}/";
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'Last Name is a required field';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'Last Name field value is invalid, must only contain letters and length must be greater than 1';
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



?>