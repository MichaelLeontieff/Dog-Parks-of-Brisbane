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
				
					<form class="signin">
						<h1>Username:</h1>
						<input type="text" name="username" required><br>
						<h1>Password:</h1>
						<input type="text" name="password" required>	
						<br>
						<br>
						<input type="submit" value="Log in" id="loginbutton">
						
						<a href="registration.php" id="registerbutton">Register</a>
						
					</form>

					
			</div>
	
		<!--FOOTER-->
		<?php include 'include/footer_landing.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>