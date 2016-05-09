<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body id="landingbody">
		<?php include 'include/nav_landing.inc'; ?>
		<div class="undernav">
			<div class="registrationheading">
				<h3>Your Portal to the best <b>Dog Parks</b> <i>of</i></h3>
				<h1>BRISBANE</h1>
			</div>
			<div class="contentcontainer" id="login">

				<form class="signin" action="index.php" method="post">
					<?php
					include 'include/validate.inc';
					$errors = array();
					if (isset($_POST['givenusername'])) {
						// validate username
						validateUsername($errors, $_POST, 'givenusername', 'Username');
						// validate password
						validatePassword($errors, $_POST, 'givenpassword', 'Password');

						if ($errors) {
							writeErrors($errors);
							include 'include/login_form.inc';
						} else {
							echo '<p class="formsubmitmessage">Success! click here to search</p>';
						}
					} else {
						include 'include/login_form.inc';
					}
					?>
				</form>

					
			</div>
	
		<!--FOOTER-->
		<?php include 'include/footer_landing.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>