<?php
session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Search</title>
		<link rel="stylesheet" type="text/css" href="style.css">
		<script src="javascript/searchscripts.js"></script>
		<!--META DATA-->
		<meta charset="utf8"/>
		<meta name="author" content="Brisbane City Council"/>
		<meta name="description" content="Dog Parks of Brisbane: Search Page"/>
		<meta name="keywords" content="park, leash, fenced, dog, Brisbane, search"/>
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

					<!--search message sub heading div-->
					<div id="searchmessage"><h3>An empty search will return all parks, if multiple search queries are
							set in the form, first one will be used. </h3><br>
						<h3 id="redalert">If you wish to search by GeoLocation, check the box and wait for the two
							fields to fill
							before submitting and the closest park will be found.</h3></div>

					<div class="searchregisterdiv">

						<form action="search.php" method="post">
							<?php
							// include search form, no php validation is done as no input-breaking cases are possible
							include 'include/validate.inc';

							if (count($_POST) > 0) {
								// if we reach here then the form has been posted
									echo 'form submitted successfully with no errors';

								// construct url string based on set fields
								$url = buildURL($_POST);

								// redirect with created url
								echo '<META HTTP-EQUIV=REFRESH CONTENT="1; ' . $url . '">';
							} else {
								include 'include/search_form.inc';
							}
							?>
						</form>
					</div>
				</div>
			</div>

		<!--FOOTER-->
			<?php include "include/footer_normal.inc";

			?>

		<!--END CONTENT-->
		</div>
	</body>
</html>