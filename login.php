<?php
session_start();
?>
<!--THIS PAGE IS A SPLASH SCREEN INDICATING THE CURRENT STATUS OF THE SESSION
    IS CALLED DIRECTLY AFTER LOGIN AND LOGOUT SHOWING A CORRESPONDING MESSAGE
-->
<!DOCTYPE html>
<html>
<head>
    <title>Session Status</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body id="normal">
<?php include_once 'include/bannerheading.inc' ?>
<div class="sessionstatusmessage">
    <?php
    /*
     * Determine status and present corresponding message
     */
    if (isset($_SESSION['loggedin'])) {
        echo "<h1>You've successfully logged in, click <a href='search.php'>here</a> to search</h1>";
    } else if (!isset($_SESSION['loggedin'])) {
        echo "<h1>You've successfully logged out. Thanks for visiting!</h1>";
    } else {
        echo "<h1>Error!</h1>";
    }
    ?>
</div>
</body>
</html>
