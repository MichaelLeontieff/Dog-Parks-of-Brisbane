<?php

include 'formelements.inc';

usernamepasswordField("givenusername", "Username:", "text");
usernamepasswordField("givenpassword", "Password:", "text");
echo '<br><br>';
echo '<input type="submit" value="Log in" id="loginbutton">';
echo '<a href="registration.php" id="registerbutton">Register</a>';
?>