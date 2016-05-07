<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Search</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="searchscripts.js"></script>
	</head>
	<body id="normal">
		<?php include "include/nav_normal.inc"; ?>
		<div id="undernavnormal">

			<div class="contentdivider" id="individual">
			
				<div id="pageheadings">
					<h1>Park Search</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Search Attributes</h1>
					</div>

					<div class="searchregisterdiv">

						<form action="search.php" method="post">
							<?php
							include 'include/validate.inc';
							$errors = array();
							if (count($_POST) > 0) {
								validatePark($errors, $_POST, 'parkname');
								if ($errors) {
									writeErrors($errors);
									include 'include/search_form.inc';
								} else {
									echo 'form submitted successfully with no errors';
								}
							} else {
								include 'include/search_form.inc';
							}
							?>
						</form>
					</div>
				</div>
			</div>

		<!--FOOTER-->
		<?php include "include/footer_normal.inc"; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>