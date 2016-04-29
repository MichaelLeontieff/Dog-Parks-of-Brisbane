<!DOCTYPE html>
<html>
	<head>
		<title>Dog Parks of Brisbane: Registration</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	</head>
	<body id="normal">
		<?php include 'include/nav_normal.inc'; ?>
		<div id="undernavnormal">

			<div class="contentdivider" id="individual">

				<div id="pageheadings">
					<h1>User Registration</h1>
				</div>

				<div class="contentcell">
					<div class="contentheadings">
						<h1>Registration Form</h1>
					</div>
					
					<div class="searchdiv">

						<form class="search">

							<h2 class="subheading">First Name

								<input type="text" name="firstname" pattern="[A-Za-z]{2,}" title="First Name must contain no numbers and at least 2 letters long" required>

							</h2>

							<h2 class="subheading">Last Name
								<br>
								<input type="text" name="lastname" pattern="[A-Za-z\-?]{2,}" title="Last Name must contain no numbers and at least 2 letters long" required />

							</h2>

							<h2 class="subheading">Date of Birth dd/mm/yyyy

								<input type="text" name="dob" 
								pattern="^(?:(?:31(\/|-|\.)(?:0?[13578]|1[02]))\1|(?:(?:29|30)(\/|-|\.)(?:0?[1,3-9]|1[0-2])\2))(?:(?:1[6-9]|[2-9]\d)?\d{2})$|^(?:29(\/|-|\.)0?2\3(?:(?:(?:1[6-9]|[2-9]\d)?(?:0[48]|[2468][048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])00))))$|^(?:0?[1-9]|1\d|2[0-8])(\/|-|\.)(?:(?:0?[1-9])|(?:1[0-2]))\4(?:(?:1[6-9]|[2-9]\d)?\d{2})$" title="D.o.B must be in the format: dd/mm/yyyy" required />

							</h2>

							<h2 class="subheading">Gender<br>

							<select id="selectgender" required>
								<option disabled selected value>-</option>
			  					<option value="volvo">Male</option>
								<option value="saab">Female</option>
								<option value="mercedes">Other</option>
							</select>

							</h2>
							
							<h2 class="subheading">Email Address
								<input type="email" name="email" pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,3}$" title="You must enter a valid email address" required />
							</h2>

							<h2 class="subheading">Password
							<br>
								<input type="text" name="email" pattern=".{6,}" title="Minimum password length is 6 characters" required />
							</h2>

							<input type="submit" value="Sign Up">				
							
						</form>

					</div>
				</div>

			</div>

			<!--FOOTER-->
			<?php include 'include/footer_normal.inc'; ?>

		<!--END CONTENT-->
		</div>
	</body>
</html>