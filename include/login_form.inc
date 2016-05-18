<!--the entire login form-->
<?php
include_once 'bannerheading.inc';
include 'formelements.inc';
echo '<div class="contentcontainer" id="login">';
echo '<form class="signin" action="index.php" method="post">';
usernamepasswordField("username", "Username:", "text");
usernamepasswordField("password", "Password:", "text");
echo '<br><br>';
echo '<input type="submit" id="loginbutton" name="login" value="Login">';
echo '<a href="registration.php" id="registerbutton">Register</a>';
echo '</form>';
echo '</div>';
?>