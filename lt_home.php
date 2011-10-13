<?php
require('functions.inc');
require('functions_db.inc');
show_header('normal');
login_message('lecturer');
@session_start();
$userid = $_SESSION['valid_user'];
db_connect();


?>


<div id="wrapper">
<!-- start page -->
<div id="page">
	<!-- start content -->
	<div id="section">
	<IMG src="./images/lthome.png" alt="Lecturer Homepage">
	</div>
	<div id="content">
		<h1 class="title" align="center">View your current teaching modules</h1>
		<p><h3 class="h3body">Intructions:</h3> <ul><li>If you wish to proceed to module management page, please click the below image</li><li>If you have any questions, please send to our contact mailbox. Thank you</li></ul></p>
	<a href="lt_modules.php"><img src="images/bigpic.png"></a>
	</div>
	<!-- end content -->
	<?php show_sidebar();?>

	<?php show_footer()?>

