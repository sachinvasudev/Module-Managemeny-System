<?php

require('functions.inc');
require('functions_db.inc');
show_header('lecturer');
login_message('lecturer');
@session_start();
db_connect();
$lecturer_id = $_SESSION['valid_user'];


if(isset($_POST['attendance']))
{
	attendance_list($_POST['module_code']);
}
echo '<h2 class="toph2">Current year: '.year().' - Semester '.semester().'</h2>';
show_module_navigation();

	
	
if(isset($_POST['exam_mark']))
include('lt_mark_process.inc');
if(isset($_POST['tutees']))
include('lt_tutees.inc');
else if(isset($_POST['edit_marks']))
include('lt_module_detail_edit.inc');
else if(isset($_POST['module_code']))
include('lt_module_detail.inc');

else if(isset($_POST['courseworks']))
{
if(@$_POST['delete'])
{
include('lt_modules_cw_view.inc');
}

else if(@$_POST['edit'])
include('lt_modules_cw_edit.inc');
else if(@$_POST['add'])
include('lt_modules_cw_add.inc');


else	
include('lt_modules_cw_view.inc');

}



else
{

echo'
<!--Module Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">Welcome to lecturer homepage</h1>
<hr/>
<p align="left"><h3 class="h3body">Instruction</h3>
<ul>
<li>Please select your module on the left navigation bar. Those module are your teaching module</li>
<li>Please select the tutees below module to see your tutees detail.</li>
<li>If you have any queries, please kindly reply us by the IT support contact email.Thank you.</li>
</ul> 
</p>

</div>
<!--end Module Detail -->
';


}





?>







<?php show_footer();?>
</div>
</body>
</html>