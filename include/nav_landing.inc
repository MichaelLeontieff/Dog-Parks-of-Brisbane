<!--the landing navigation differs slightly styling wise from the normal one-->
<div class="navigation" id="landingnav">
	<div class="home" id="landinghome">
		<img src="images/logo.svg" alt="Brisbane Open Data Scheme">
		<a href="#">BCC Open Data Initiative</a>
	</div>
	<div class="aboutsocial" id="aboutsociallanding">
		<a href="about.php">About Us</a>
		<a href="search.php">Search</a>
		<?php
		if (!isset($_SESSION['loggedin'])) {
			echo '<a href="index.php">Login</a>';
			echo '<a href="registration.php">Register</a>';
		} else if (isset($_SESSION['loggedin'])) {
			echo '<a href="logout.php">Logout</a>';
		}
		?>
	</div>
</div>