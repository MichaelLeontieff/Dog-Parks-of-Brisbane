<?php

function createConnection()
{
    $host = "fastapps04.qut.edu.au";
    $username = "n9455396";
    $password = "password123";
    $dbname = "n9455396";

    $pdo = new PDO('mysql:host=' . $host . ';dbname=' . $dbname, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    return $pdo;

}
