<?php

/*
 * Registration form complete with HTML5 validation pattern integration
 */

require 'include/formelements.inc';

$commonRegexTwoCharsAlpha = "[A-Za-z]{2,}";
$commonRegexUsername = "[a-z0-9_-]{3,16}";
$commonRegexEmail = "[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,3}$";
$commonRegexPassword = ".{6,}";
$numericRegex10Char = "[0-9]{10}";

$TwoCharsAlphaTitle = "must contain no numbers and be at least 2 letters long";
$UsernameTitle = "";

// Username input field
input_field("username", "Username", $commonRegexUsername, "Username must be between 3 and 16 characters with no special characters allowed", "text");

// First Name input field
input_field("firstname", "First Name", $commonRegexTwoCharsAlpha, "First Name $TwoCharsAlphaTitle", "text");

// Last Name input field
input_field("lastname", "Last Name", $commonRegexTwoCharsAlpha, "Last Name" . $TwoCharsAlphaTitle, "text");

// Pet ID Number input field
input_field("petid", "Pet ID Number (10 numeric digits)", $numericRegex10Char, "Pet ID must be 10 digits and contain only numbers", "text");

// Date of Birth input field
dateofbirth("birthday", "Date of Birth (day/month/year)");

// Gender input field
genderradiobutton("gender", "Gender");

// Preferred park input field
usercitycheckbox("location", "Do you live in Brisbane?");

// Email input field
input_field("email", "Email Address", $commonRegexEmail, "You must enter a valid email address", "email");

// Password input field
input_field("password", "Desired Password", $commonRegexPassword, "Password must be 6 characters or longer", "password");

?>

<input type="submit" class="submitbutton" value="Sign Up">
    