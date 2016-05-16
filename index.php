<?php
include 'include/checker.inc';
//require_once 'include/validate.inc';
//$errors = array();
//$firstrun = false;
if (isset($_POST['login'])) {
	//$firstrun = true;
	if (checkPassword($_POST['username'], $_POST['password'])) {
		session_start();
		$_SESSION['loggedin'] = true;
		$_SESSION['username'] = $_POST['username'];
		header("Location: http://{$_SERVER['HTTP_HOST']}/CAB230-WebDevelopmentMajorAssignment/login.php");
		exit();
	} else {
		//$errors[] = "Password doesn't match username";
		include 'include/login_form.inc';
		//writeErrors($errors);
	}
} else {

	// validate username
	//checkEmpty($errors, $_POST, 'username', 'Username');
	// validate password
	//checkEmpty($errors, $_POST, 'password', 'Password');

	include 'include/login_form.inc';
	//if ($firstrun) {
	//	writeErrors($errors);
	//}

	//$firstrun = true;
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
			<!--			<div class="registrationheading">-->
			<!--				<h3>Your Portal to the best <b>Dog Parks</b> <i>of</i></h3>-->
			<!--				<h1>BRISBANE</h1>-->
			<!--			</div>-->
			<!--			<div class="contentcontainer" id="login">-->
			<!---->
			<!--				<form class="signin" action="index.php" method="post">-->
			<!--					--><?php
			//					include 'include/validate.inc';
			//					$errors = array();
			//					if (isset($_POST['username'])) {
			//						// validate username
			//						checkEmpty($errors, $_POST, 'username', 'Username');
			//						// validate password
			//						checkEmpty($errors, $_POST, 'password', 'Password');
			//
			//						if ($errors) {
			//							writeErrors($errors);
			//							include 'include/login_form.inc';
			//						}
			//
			//					} else {
			//						include 'include/login_form.inc';
			//					}
			//					?>
			<!--				</form>-->
			<!---->
			<!--					-->
			<!--			</div>-->
	
		<!--FOOTER-->
		<?php include 'include/footer_landing.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>