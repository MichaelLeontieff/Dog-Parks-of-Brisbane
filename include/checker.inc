<?php
require_once 'pdo_connect.inc';

/*
 * function to check password against supplied username
 */
function checkPassword($username, $password)
{
    $pdo = createConnection();
    $stmt = $pdo->prepare('SELECT * FROM members WHERE username = :username and
            password = SHA2(CONCAT(:password, salt), 0)');
    $stmt->bindValue(':username', $username);
    $stmt->bindValue(':password', $password);
    $stmt->execute();
    if ($stmt->rowCount() > 0) {
        return true;
    } else {
        return false;
    }
}

/*
 * count errors in array (redundant, keeping it anyway)
 */
function Counterrors($errors)
{
    $counter = 0;
    foreach ($errors as $field => $error) {
        $counter++;
    }
    return $counter;
}

/*
 * outputs the errors residing within array into red error messages
 */
function writeLoginErrors($errors)
{
    $errorCount = Counterrors($errors);
    echo '<div class="loginvalidationerror">';
    echo '<p class="validationerrortitle">The following ' . $errorCount . ' error(s) were found:<br></p>';
    foreach ($errors as $field => $error) {
        echo "- $error<br>";
    }
    echo '</div>';
}

/*
 * if login fails, function checks if username exists
 * but password isn't right or if the username doesn't exist
 * then ouputs error messages for display
 */
function checkUsername(&$errors, $username)
{
    $username = htmlspecialchars($username);
    $pdo = createConnection();
    $stmt = $pdo->prepare('SELECT * FROM members WHERE username = :username');
    $stmt->bindValue(':username', $username);
    $stmt->execute();
    if ($stmt->rowCount() > 0) {
        $errors['password'] = "Password doesn't match given username";
        return true;
    } else {
        $errors['username'] = "Username doesn't exist";
        return false;
    }
}


