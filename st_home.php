<?php
require('functions.inc');
require('functions_db.inc');


show_header('normal');
login_message('student');

@session_start();
$student_id = $_SESSION['valid_user'];
db_connect();

if(show_year_total())
require('st_modules_year.inc');
else
if(mef_status($student_id,semester()))
require('st_modules.inc');
else
{
if(isset($_POST["modules_confirm"]))
{
	require('st_modules_insert.inc');
	
}	
	
else if(isset($_POST["modules_selected"]))
{
	require('st_mef_confirm.inc');
	
}
else
require('st_mef.inc');

}
?>









     <?php 
     if(!isset($_POST['modules_selected']))
	 show_sidebar();
	 ?>
	<div style="clear: both;">&nbsp;</div>
<!-- end page -->
</div>
<div id="footer">
	<p>&copy;2009 All Rights Reserved.</p>
</div>
</body>
</html>
