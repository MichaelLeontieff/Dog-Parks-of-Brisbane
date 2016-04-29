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
					
					<div class="searchdiv">

						<form class="search">

							<h2 class="subheading">Suburb<br>
								<select id="selectsuburb" required>
									<option disabled selected value>-</option>
				  					<option value="volvo">Glennvale</option>
									<option value="saab">Currumbin</option>
									<option value="mercedes">Carindale</option>
									<option value="audi">Mulberry</option>
								</select>
							</h2>
							
							<h2 class="subheading">Park Name
								<input type="text" name="parkname" required>
							</h2>

							<h2 class="subheading">Rating<br>
								<select id="selectrating" required>
								<option disabled selected value>-</option>
			  					<option value="1">1</option>
								<option value="2">2</option>
								<option value="3">3</option>
								<option value="4">4</option>
								<option value="5">5</option>
							</select>
								
							</h2>
							
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