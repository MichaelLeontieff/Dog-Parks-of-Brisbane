<?php
//handle session starting and login
if (isset($_SESSION['loggedin'])) {
	header($header_location_string);
}
include 'include/checker.inc';
require_once 'include/php_header_location_info.inc';
$errors = array();
if (isset($_POST['login'])) {
	if (checkPassword($_POST['username'], $_POST['password'])) {
		session_start();
		$_SESSION['loggedin'] = true;
		$_SESSION['username'] = $_POST['username'];
		header($header_location_string);
		exit();
	} else {
		//username present but wrong password
		//username not present
		checkUsername($errors, $_POST['username']);

		include 'include/login_form.inc';
		//writeErrors($errors);
		writeLoginErrors($errors);
		echo '</body>';
		echo '</html>';
	}

} else {
	include 'include/login_form.inc';
} ?>


	
