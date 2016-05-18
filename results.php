<?php
session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Results</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="javascript/resultsscripts.js"></script>
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
	$results = fetchQueryResults($pdo, $queryValues);

	?>

		<div id="undernavnormal">

			<div class="contentdivider">

				<div id="pageheadings">
					<h1>Query Results</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<!--Change content heading based on query type-->
						<h1><?php echo 'The following ' . numberResults($results) . ' park(s) were found based on ' . $queryValues[0];
							// if geolocation sreah then print subheading
							if ($queryValues[0] == "GeoLocation") {
								if ($queryValues[3] == 60) {
									echo "<br><h1>Distance selected was greater than 60 kilometres</h1>";
								} else {
									echo "<br><h1>Distance selected was less than " . $queryValues[3] . " kilometres</h1>";
								}
							}
							?></h1>
					</div>
				<div id="resultsgooglemap"></div>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Detailed Information</h1>
					</div>

					<?php include 'include/query_results_table.inc';
					// variable scope workaround
					$results = fetchQueryResults($pdo, $queryValues);
					// build results table
					if ($queryValues[0] == "GeoLocation") {
						buildResultsTable($queryValues[0], $queryValues[1], $queryValues[2], $results);
					} else if ($queryValues[0] == "Rating") {
						buildResultsTable("Rating", 0, 0, $results);
					} else {
						buildResultsTable("", 0, 0, $results);
					}; ?>
					
				</div>
			</div>
		
		<!--FOOTER-->
		<?php include 'include/footer_normal.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>