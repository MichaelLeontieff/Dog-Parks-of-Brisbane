<?php
session_start();
?>
<html>
<head>
    <title>You've Successfully Logged in...</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body id="normal">
<?php include_once 'include/bannerheading.inc' ?>
<div class="sessionstatusmessage">
    <?php
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
