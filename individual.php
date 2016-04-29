<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Individual Result</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="myscripts.js"></script>
	</head>
	<body id="normal">
		<?php include "include/nav_normal.inc"; ?>

		<div class="undernav" id="undernavnormal">

			<div class="contentdivider">

				<div id="pageheadings">
					<h1>Park Location <i>and</i> Information</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>REINHOLD CRES DOG OFF LEASH AREA</h1>
					</div>
					<div id="locationmap"></div>			
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Information</h1>
					</div>
					<?php include 'include/individual_park_information_table.inc'; ?>	
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Social</h1>
					</div>
					<div class="itemheading"><h3>Post a Review</h3></div>

					<div class="userreview" id="post">
						<div class="userimage"></div>
						<div id="centerposcomment">
						<h3>What do you think of this Park?</h3>
							<form method="post">
							
							<textarea name="comments" id="comments" required></textarea>
							<span class="starRating">
								<label>Rating: </label>
								<input id="rating1" type="radio" name="rating" value="1" required>
								<label for="rating1">1</label>
								<input id="rating2" type="radio" name="rating" value="2" required>
								<label for="rating2">2</label>
								<input id="rating3" type="radio" name="rating" value="3" required>
								<label for="rating3">3</label>
								<input id="rating4" type="radio" name="rating" value="4" required>
								<label for="rating4">4</label>
								<input id="rating5" type="radio" name="rating" value="5" required>
								<label for="rating5">5</label>
							</span>
							<input type="submit" value="Post" id="submitbutton">
							</form>
						</div>
					</div>

					<div class="itemheading"><h3>User Ratings</h3></div>
					<?php include 'include/user_review.inc'; ?>
					
				</div>
			</div>
		<!--END CONTENT-->
		</div>
		<!--FOOTER-->
		<?php include 'include/footer_normal.inc'; ?>
	</body>
</html>