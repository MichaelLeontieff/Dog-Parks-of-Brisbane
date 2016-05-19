<?php
/**
 * Created by PhpStorm.
 * User: michaelleontieff
 * Date: 16/05/2016
 * Time: 2:04 PM
 */
session_start();
require_once 'include/php_header_location_info.inc';
unset($_SESSION['loggedin']);
header($header_location_string);
/*
 * ends the users session and redirects to splash screen
 */