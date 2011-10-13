<?php

/**
 * @author Sachin
 * @copyright 2009
 */

require('functions.inc');
require('functions_db.inc');
//require('fpdf.php');
db_connect();
session_start();

if(isset($_POST['report']))
report($_POST['module_code']);

if(isset($_POST['attendance']))
attendance_list($_POST['module_code']);


echo'$_SESSION[\'authentication_id\']  
<br><br>
feeling lucky?';






?>