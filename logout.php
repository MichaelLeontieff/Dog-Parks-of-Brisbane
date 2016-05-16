<?php
/**
 * Created by PhpStorm.
 * User: michaelleontieff
 * Date: 16/05/2016
 * Time: 2:04 PM
 */
session_start();
unset($_SESSION['loggedin']);
header("Location: http://{$_SERVER['HTTP_HOST']}/CAB230-WebDevelopmentMajorAssignment/login.php");