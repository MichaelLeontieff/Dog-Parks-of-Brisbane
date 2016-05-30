<?php
session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: About Us</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="javascript/searchscripts.js"></script>
		<!--META DATA-->
		<meta charset="utf-8"/>
		<meta name="author" content=“Brisbane City Council
		" />
		<meta name="description" content="Dog Parks of Brisbane: About Us Page"/>
		<meta name="keywords" content="park, leash, fenced, dog, Brisbane"/>
	</head>
	<body id="normal">
		<?php include "include/nav_normal.inc"; ?>
		<div id="undernavnormal">
			<!--Site content start-->
			<div class="contentdivider" id="individual">
			
				<div id="pageheadings">
					<h1>About Us</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Dog Parks of Brisbane</h1>
					</div>
						<div class="about_container">
							<!--Text for about box-->
							<div id="text">
								<p>Brisbane has a diverse scape of recreational areas, 
								many of which are dog friendly. Using this site, you can 
								convieniently search and browse all of your local dog parks 
								and read reviews posted by the Community. If you wish, you may 
								also create an account to post reviews and comments yourself for
								others.
							</div>
							
						</div>

				</div>
			</div>

		<!--FOOTER-->
		<?php include "include/footer_normal.inc"; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>