<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Registration</title>
		<link rel="stylesheet" type="text/css" href="style.css">
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
							<?php include 'include/registration_form.inc'; ?>
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