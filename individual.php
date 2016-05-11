<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Individual Result</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="javascript/individualparkscripts.js"></script>
	</head>
	<body id="normal">
	<?php
	include "include/nav_normal.inc";
	require_once "include/pdo_connect.inc";
	require_once 'include/search_queries.inc';
	/*
     *
     * The following connection code is repeated in order 
     * to grab query data between two code blocks of different variable scope
     * 
     */

	// get park id value
	$parkid = $_GET['id'];

	// create database connection
	$pdo = createConnection();

	// run query based on supplied id
	$result = fetchIndividualPark($pdo, $parkid);

	?>

		<div class="undernav" id="undernavnormal">

			<div class="contentdivider">
				<div id="pageheadings">
					<h1>Park Location <i>and</i> Information</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1><?php echo getParkName($result); ?></h1>
					</div>
					<div id="locationmap"></div>			
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Information</h1>
					</div>
					<?php
					// include park table creation function
					include 'include/individual_park_information_table.inc';
					// include search_queries

					// get park id value
					$parkid = $_GET['id'];

					// run query based on supplied id
					$result = fetchIndividualPark($pdo, $parkid);

					// render individual table
					buildIndividualParkResultTable($result);

					?>	
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
							<form action="<?php echo 'individual.php?id=' . $parkid ?>" method="post">
								<?php
								include 'include/validate.inc';
								$errors = array();
								if (isset($_POST['comment'])) {
									// validate comment
									validateComment($errors, $_POST, 'comment');
									// validate rating
									validateRating($errors, $_POST, 'rating');

									if ($errors) {
										writeErrors($errors);
										include 'include/review_form.inc';
									} else {
										echo 'form submitted successfully with no errors, thanks for posting!';
									}
								} else {
									include 'include/review_form.inc';
								}
								?>
							</form>
						</div>
					</div>

					<div class="itemheading"><h3>User Ratings</h3></div>
					<?php include 'include/user_review.inc';
					userReview("Michael Leontieff", "5", "Great Park!");
					?>

					
				</div>
			</div>
		<!--END CONTENT-->
		</div>
		<!--FOOTER-->
		<?php include 'include/footer_normal.inc'; ?>
	</body>
</html>