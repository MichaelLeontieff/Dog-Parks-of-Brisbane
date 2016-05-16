<?php
require_once 'pdo_connect.inc';
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

// check if user is registered
function matchingCredentials(&$errors, $field_list, $username_field, $password_field, $username_label, $password_label)
{
    $passwordhash = password_hash($field_list[$password_field], PASSWORD_DEFAULT);
    $username = $field_list[$username_field];
    $pdo = createConnection();
    $stmt = $pdo->prepare('SELECT * FROM members WHERE username = :username');
    $stmt->bindValue(':username', $username);
    $stmt->execute();
    // if user doesn't exist
    if ($stmt->rowCount() == 0) {
        $errors[$username_field] = $username_label . ' does not match any existing user';
    } else {
        // if user does exist but password doesn't match\
        foreach ($stmt as $row) {
            if ($row['password'] != $passwordhash) {
                $errors[$password_field] = $password_label . ' does not match given username';
            }
        }
    }
}

