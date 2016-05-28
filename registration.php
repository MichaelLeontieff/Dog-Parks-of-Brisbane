<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Registration</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<!--META DATA-->
		<meta charset="utf8"/>
		<meta name="author" content="Brisbane City Council"/>
		<meta name="description" content="Dog Parks of Brisbane: Registration Page"/>
		<meta name="keywords" content="park, leash, fenced, dog, Brisbane, register, registration"/>
	</head>
	<body id="normal">
		<?php include 'include/nav_normal.inc'; ?>
		<div id="undernavnormal">

			<div class="contentdivider" id="individual">

				<div id="pageheadings">
					<h1>User Registration</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Registration Form</h1>
					</div>
				
					<div class="searchregisterdiv">
						<form action="registration.php" method="post">
							<?php
							include 'include/validate.inc';
							require_once 'include/pdo_connect.inc';
							require_once 'include/search_queries.inc';

							$errors = array();
							if (isset($_POST['username'])) {

								/*
								 * VALIDATION
								 */

								// username
								validateUsername($errors, $_POST, 'username');
								// firstname
								validateFirstName($errors, $_POST, 'firstname');
								// lastname
								validateLastName($errors, $_POST, 'lastname');
								// birthday
								validateDateofBirth($errors, $_POST, 'day');
								validateDateofBirth($errors, $_POST, 'month');
								validateDateofBirth($errors, $_POST, 'year');
								validateDateofBirthLeapYears($errors, $_POST);
								// gender
								validateGender($errors, $_POST, 'gender');
								// validate pet id
								validatepetid($errors, $_POST, 'petid');
								// general location checkbox validation
								validateCheckboxLocation($errors, $_POST);
								// email
								validateEmail($errors, $_POST, 'email');
								// password
								validatePassword($errors, $_POST, 'password');

								// if errors present write them to screen and re-present form
								if ($errors) {
									writeErrors($errors);
									include 'include/registration_form.inc';
								} else {
									// if we reach here form is successful
									// set values into database
									// set dob format from 3 select to single string
									$checkbox;
									if (isset($_POST['checkyes'])) {
										$checkbox = $_POST['checkyes'];
									} else {
										$checkbox = 'no';
									}
									$dob = $_POST['year'] . '-' . $_POST['month'] . '-' . $_POST['day'];
									addUser($_POST['username'], $_POST['firstname'], $_POST['lastname'],
										$dob, $_POST['gender'], $_POST['email'], $_POST['password'], $_POST['petid'], $checkbox);
									
									echo 'form submitted successfully with no errors, welcome to Dog Parks of Brisbane!';
								}
							} else {
								// otherwise include form again
								include 'include/registration_form.inc';
							}


							?>

						</form>
					</div>
				</div>
			</div>

			<!--FOOTER-->
			<?php include 'include/footer_normal.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>