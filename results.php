<?php
session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Results</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="javascript/resultsscripts.js"></script>
		<!-- tell search engines not to index this page -->
		<meta name="robots" content="noindex"/>
	</head>
	<body id="normal">
	<?php
	include 'include/nav_normal.inc';
	require_once 'include/search_queries.inc';
	require_once 'include/pdo_connect.inc';

	// fetch name of field that's been queried
	$queryValues = fetchVariables();

	// create database connection
	$pdo = createConnection();

	// run query based on input field
	$resultsPark = fetchQueryResults($pdo, $queryValues);

	// get the number or results
	$numberResults = numberResults($resultsPark);

	?>

		<div id="undernavnormal">

			<div class="contentdivider">

				<div id="pageheadings">
					<h1>Query Results</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<!--Change content heading based on query type-->
						<h1>
							<?php
							echo 'The following ' . $numberResults . ' park(s) were found based on ' . $queryValues[0];
							// if geolocation search then print subheading
							if ($queryValues[0] == "GeoLocation") {
								if ($queryValues[3] == 60) {
									echo "<br>Distance selected was greater than 60 kilometres";
								} else {
									echo "<br>Distance selected was less than " . $queryValues[3] . " kilometres";
								}
							}
							?>
						</h1>
					</div>
					<?php
					echo '<div class="itemheading"><h3>Click <a href="search.php">here</a> to try another query</h3></div>';
					if ($numberResults > 0) {
						echo '<div id="resultsgooglemap"></div>';
					}
					?>
				</div>
				<?php
				// there's some sort of variable scope bug/issue that I can't fix
				// so I'm re-setting the results variable because for some reason it
				// empties before we get here
				$resultsPark = fetchQueryResults($pdo, $queryValues);
				if ($numberResults > 0) {
					echo '<div class="contentcell">';
					echo '<div class="contentheadings"><h1>Detailed Information</h1></div>';
					include 'include/query_results_table.inc';
					// build results table
					if ($queryValues[0] == "GeoLocation") {
						buildResultsTable($queryValues[0], $queryValues[1], $queryValues[2], $resultsPark);
					} else if ($queryValues[0] == "Rating") {
						buildResultsTable("Rating", 0, 0, $resultsPark);
					} else {
						buildResultsTable("", 0, 0, $resultsPark);
					}
					echo '</div>';
				}
				?>
			</div>
		
		<!--FOOTER-->
		<?php include 'include/footer_normal.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>