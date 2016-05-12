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
	include 'include/search_queries.inc';
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
						<h1><?php echo 'The following ' . numberResults($results) . ' park(s) were found based on ' . $queryValues[0];
							if ($queryValues[0] == "GeoLocation") {
								echo "<br><h1>Closest park from your location is " . getParkDistance() . " kilometres away</h1>";
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
					buildResultsTable($results); ?>
					
				</div>
			</div>
		
		<!--FOOTER-->
		<?php include 'include/footer_normal.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>