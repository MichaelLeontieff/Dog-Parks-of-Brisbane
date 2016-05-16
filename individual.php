<?php
session_start();
?>
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
					<?php
					if (isset($_SESSION['loggedin'])) {
						echo '<div class="itemheading"><h3>Post a Review</h3></div>';

						echo '<div class="userreview" id="post">';
						echo '<div class="userimage"></div>';
						echo '<div id="centerposcomment">';

						echo '<h3>What do you think of this Park?</h3>';
						echo '<form action="' . 'individual.php?id=' . $parkid . '" method="post">';

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
								// add review
								addReview($_SESSION['username'], $_POST['comment'], $_POST['rating'], $_GET['id']);
							}
						} else {
							include 'include/review_form.inc';
						}


						echo '</form>';
						echo '</div>';
						echo '</div>';
					}
					?>
					
					<?php include 'include/user_review.inc';
					$result = getParkReviews($_GET['id']);
					echo '<div class="itemheading"><h3>User Ratings | Sorted by Date</h3></div>';
					foreach ($result as $row) {
						userReview($row['username'], $row['comment'], $row['date'], $row['rating']);
					}

					?>

					
				</div>
			</div>
		<!--END CONTENT-->
		</div>
		<!--FOOTER-->
		<?php include 'include/footer_normal.inc'; ?>
	</body>
</html>