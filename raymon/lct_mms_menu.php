<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html lang="en"><head>
<meta content="text/html; charset=UTF-8" http-equiv="content-type"><title>lct_mdl_lst</title>
<title>Welcome to MMS</title>
<link rel="stylesheet" href="styles.css" type="text/css">
</head>
<body style="direction: ltr;">
<div class="big_wrapper">
<h1 class="h1">Modules</h1>
<hr/>
<!--Insert nav script for the modules-->

<!--<span class="boxed">-->
<?php
@session_start();
require('functions.inc');
require('functions_db.inc');
db_connect();
	$lecturerid = $_SESSION['valid_user'];
		
	    $query3 = "select modules.module_code,modules.module_name
                   from modules, teaches
                   where lecturer_id ='$lecturerid'
                   and modules.module_code = teaches.module_code";
     
      $result3 = mysql_query($query3);
      $num_results = mysql_num_rows($result3);
      
      for($i=0;$i<$num_results;$i++)
      {
      		$row3 = mysql_fetch_array($result3);
      	echo '
		  <a class="mdl_link" href="#">
<!--Pull lecturer module code here-->
'.$row3['module_code'].'</a>
		  ';
		        
      }

?>


</div>
</body></html>