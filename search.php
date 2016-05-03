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

						<form class="search">

							<?php require 'include/search_form.inc'; ?>
							
							<h2 class="subheading"><a onclick="getLocation()" id="geolocationstatus">GeoLocation</a></h2>
							
							<input type="submit" class="searchbutton" value="Fetch!">	
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