<!DOCTYPE html>
<html>
<head>
    <title>Dog Parks of Brisbane</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body id="landingbody">
<?php include 'include/nav_landing.inc'; ?>
<div class="undernav">
    <!--Site content start-->
<!--the entire login form-->
<?php
include_once 'bannerheading.inc';
include 'formelements.inc';
echo '<div class="contentcontainer" id="login">';
echo '<form class="signin" action="index.php" method="post">';
usernameField("username", "Username:", "text");
passwordField("password", "Password:", "text");
echo '<br><br>';
echo '<input type="submit" id="loginbutton" name="login" value="Login">';
echo '<a href="registration.php" id="registerbutton">Register</a>';
echo '</form>';
echo '</div>';
?>
    <!--FOOTER-->
    <?php include 'include/footer_landing.inc'; ?>

    <!--END CONTENT-->
</div>

    