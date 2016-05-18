<?php
//handle session starting and login
include 'include/checker.inc';
$errors = array();
if (isset($_POST['login'])) {
	if (checkPassword($_POST['username'], $_POST['password'])) {
		session_start();
		$_SESSION['loggedin'] = true;
		$_SESSION['username'] = $_POST['username'];
		header("Location: http://{$_SERVER['HTTP_HOST']}/CAB230-WebDevelopmentMajorAssignment/login.php");
		exit();
	} else {
		//username present but wrong password
		//username not present
		checkUsername($errors, $_POST['username']);

		include 'include/login_form.inc';
		//writeErrors($errors);
		writeLoginErrors($errors);
	}

} else {
	include 'include/login_form.inc';
} ?>
<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body id="landingbody">
		<?php include 'include/nav_landing.inc'; ?>
		<div class="undernav">
			<!--Site content start-->

	
		<!--FOOTER-->
		<?php include 'include/footer_landing.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>