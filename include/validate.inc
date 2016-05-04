<?php

// validate dob
function validateDateofBirth(&$errors, $field_list, $field_name)
{
    if (!isset($field_list[$field_name])) {
        $errors[$field_name] = 'required';
    }
}


// validate gender
function validateGender(&$errors, $field_list, $field_name)
{

}

// validate email
// validate password
// validate name
// validate username
function validateTextField(&$errors, $field_list, $field_name, $pattern)
{
    if (!isset($field_list[$field_name]) || empty($field_list[$field_name])) {
        $errors[$field_name] = 'required';
    } else if (!preg_match($pattern, $field_list[$field_name])) {
        $errors[$field_name] = 'invalid';
    }
}

?>