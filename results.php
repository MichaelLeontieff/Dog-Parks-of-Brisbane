<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Results</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="resultsscripts.js"></script>
	</head>
	<body id="normal">
		<?php include 'include/nav_normal.inc'; ?>
		<div id="undernavnormal">

			<div class="contentdivider">

				<div id="pageheadings">
					<h1>Query Results</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>The Following Parks Were Found</h1>
					</div>
				<div id="resultsgooglemap"></div>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Detailed Information</h1>
					</div>

					<?php include 'include/query_results_table.inc'; ?>
					
				</div>
			</div>
		
		<!--FOOTER-->
		<?php include 'include/footer_normal.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>