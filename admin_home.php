<?php

require('functions.inc');
require('functions_db.inc');
db_connect();
show_header('lecturer');
login_message('admin');
@session_start();
$admin_id = $_SESSION['valid_user'];
echo '<h2 class="toph2">Current year: '.year().' - Semester '.semester().'</h2>';

if(!(
isset($_POST['add_student'])
||isset($_POST['view_student'])
||isset($_POST['edit_student'])

||isset($_POST['add_lecturer'])
||isset($_POST['view_lecturer'])
||isset($_POST['edit_lecturer'])

||isset($_POST['add_module'])
||isset($_POST['view_module'])
||isset($_POST['edit_module'])

||isset($_POST['add_course'])
||isset($_POST['view_course'])
||isset($_POST['edit_course'])
||isset($_POST['course_add_module'])
||isset($_POST['search'])
))
show_admin_navigation();





   if(isset($_POST['task']))
   {
	$task = $_POST['task'];
	if($task=='student')
	{
	if(isset($_POST['add_student']))
	include('admin_student_add.inc');
	else if(isset($_POST['view_student']))
	include('admin_student_view.inc');
	else if(isset($_POST['edit_student']))
	include('admin_student_edit.inc');
	else if(isset($_POST['search']))
	include('admin_student_search.inc');
    else if(isset($_POST['delete_student']))
	{
	$student_id_delete = $_POST['student_id_edit'];
	delete_student($student_id_delete);
	include('admin_student.inc');
			
	}
	else
	include('admin_student.inc');		
	}
	
	
	if($task=='lecturer')
	{
	if(isset($_POST['add_lecturer']))
	include('admin_lecturer_add.inc');
	else if(isset($_POST['view_lecturer']))
	include('admin_lecturer_view.inc');
	else if(isset($_POST['edit_lecturer']))
	include('admin_lecturer_edit.inc');
	
	else if(isset($_POST['delete_lecturer']))
	{
		$lecturer_id_delete = $_POST['lecturer_id_edit'];
	delete_lecturer($lecturer_id_delete);
	include('admin_lecturer.inc');
			
	}
	
	else	
	include('admin_lecturer.inc');
	
	}
	
	if($task=='module')
	{
	if(isset($_POST['add_module']))
	include('admin_module_add.inc');
	else if (isset($_POST['view_module']))
	include('admin_module_view.inc');
	else if (isset($_POST['add_module']))
	include('admin_module_add.inc');
	else if (isset($_POST['edit_module']))
	include('admin_module_edit.inc');
	
	 else if(isset($_POST['delete_module']))
	{
		
	$module_id_delete = $_POST['module_id_edit'];
	delete_module($module_id_delete);
	include('admin_module.inc');
			
	}
	 	
	else
	include('admin_module.inc');
	}
	
	
	if($task=='course')
	{
	if(isset($_POST['add_course']))
	include('admin_course_add.inc');
	else if (isset($_POST['view_course']))
	include('admin_course_view.inc');
	else if (isset($_POST['edit_course']))
	include('admin_course_edit.inc');
	else if (isset($_POST['course_add_module']))
	include('admin_course_add_module.inc');
	
    else
	include('admin_course.inc');
	
	}
	
	if($task=='announcement')
	include('admin_announcement.inc');
	
	if($task=='settings')
	include('admin_settings.inc');
	}
   
   else
   {
   	   echo'
<!--Task Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">Welcome to admin homepage</h1>
<hr/>
<p align="left"><h3>Instruction</h3>
<ul>
<li>Please select your Task on the left navigation bar.</li>
<li>There are 5 option: Students - students\'s detail; Modules - Modules\'s detail; Lecturers\'s detail; Courses\'s detail and Settings</li>
<li>If you have any queries, please kindly reply us by the IT support contact email.Thank you.</li>
</ul> 
</p>
</div>
<!--end Task Detail -->';
   }
	




?>




<?php show_footer();?>
</div>
</body>
</html>