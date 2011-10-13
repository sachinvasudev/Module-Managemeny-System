<?php
$student_id = $_POST['student_id_edit'];

if(@$_POST['student_delete_modules'])
{
	if(isset($_POST['delete_modules']))
	{
	foreach($_POST['delete_modules'] as $mod)
	{
		delete_student_module($student_id,$mod);	
	}
	
	}
}

if(@$_POST['student_add_modules'])
{
	if(isset($_POST['add_modules']))
	{
	
	
	foreach($_POST['add_modules'] as $mod)
	{
		take_module($student_id,$mod);	
	}
	
	}
}

if(@$_POST['student_update_details'])
{
	$name = $_POST['student_name'];
	$roll_no = $_POST['roll_no'];
	$course = $_POST['course'];
	$year  = $_POST['year'];
	$mef_status = $_POST['mef_status'];
	$tutor = $_POST['tutor'];
	$login_id = $_POST['login_id'];
	
	edit_student($student_id,$name,$roll_no,$login_id,$course,$year,$tutor,$mef_status,semester());
	
	$student_id=$login_id;
	
}


?>

<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Student Name : <font color="blue"><?php echo get_name($student_id,'student');?></font></h1>


<br>
<table width="1200px" cellspacing="0" summary="Studentdata">

  <tr>
  <th scope="col" abbr="Student Name" class="nobg">Student Name</th>
  <th scope="col" abbr="ID">ID</th>
    <th scope="col" abbr="ID">Login ID</th>
    <th scope="col" abbr="ID">Course Code</th>
  <th scope="col" abbr="year">Year</th>
  <th scope="col" abbr="year">Tutor</th>
   <th scope="col" abbr="year">Mef Status</th>
    
  </tr>
  <form method="POST" action="admin_home.php">
  <?php
  $courses = all_courses();
  $lecturers = all_lecturers();
  echo'
  
  
  <tr>
    <th scope="row" class="spec"><input type="text" name="student_name" value="'.get_name($student_id,'student').'"  size="30"></th>
    <td><input type="text" name="roll_no" value="'.get_rollno($student_id).'" size="4"></td>
       <td><input type="text" name="login_id" value="'.$student_id.'" size="7"></td>
   <td><select size="1" name="course">';
   
   
    foreach($courses as $cos)
    {
    
	echo'<option value="'.$cos.'">
	'.$cos.'
	</option>
	
	';
	}
	
	if(mef_status($student_id,semester())==true)
	$option = '<option value="1" selected="selected">Submitted</option>
	<option value="0">Not Submitted</option>';
	else
	$option = '<option value="1" >Submitted</option>
	<option value="0" selected="selected">Not Submitted</option>';
	
	echo'</select>
	<td><select size="1" name="year">';
	
	$year_studying = year_studying($student_id);
	
	if($year_studying==1)
	{
		
	echo'<option value="1" selected="selected">First</option>
	<option value="2">Second</option>
	<option value ="3">Third</option>';	
	}
	
		if($year_studying==2)
	{
		
	echo'<option value="1" >First</option>
	<option value="2" selected="selected">Second</option>
	<option value ="3">Third</option>';	
	}
		if($year_studying==3)
	{
		
	echo'<option value="1" >First</option>
	<option value="2">Second</option>
	<option value ="3" selected="selected">Third</option>';	
	}
	


	
	
echo'	</select></td>
	
	
			 <td><select size="1" name="tutor" >
     ';
	foreach($lecturers as $lec)
	{
		echo '<option value="'.$lec.'"
		';
		if($lec==get_tutor($student_id))
		echo'selected="selected"';
		echo'>
		     '.get_name($lec,'lecturer').'
		     </option>
		';	
	}
	
	echo'
	
	
	</select></td>
	
	
	
	
	
    <td><select size="1" name="mef_status">
    '.$option.'
    
	</select></td>
	
	
	
	
	
  </tr>
  
  ';
  ?>

</table>
<br />
  <input type="Submit" name="student_update_details" value="Update details">
  <?php
if(@$_POST['student_update_details'])
echo'<font color="red">Details updated successfully</font>';
?>
  
  <input type="hidden" name="task" value="student">
<input type="hidden" name="student_id_edit" value="<?php echo $student_id;?>">
 <input type="hidden" name="edit_student" value="sds">
  </form>
  
 <form method="POST" action="admin_home.php"> 



<h1 class="sideh1">* Current Modules :</h1>
<table width="1200px" cellspacing="0" summary="current module">
  <tr>
  <th scope="col" abbr="Module Name" class="nobg">Module Name</th>
  <th scope="col" abbr="Module ID">Module ID</th>
  <th scope="col" abbr="Delete">Delete</th>
  </tr>
  <?php
  $modules = modules_taken_sem($student_id,semester(),year_studying($student_id));
  foreach($modules as $mod)
  	
  echo'
  <tr>
    <th scope="row" class="spec">'.module_name($mod).'</th>
    <td>'.$mod.'</td>
    <td><input type="checkbox" name="delete_modules[]" value="'.$mod.'"></td>
  </tr>
  
  ';
  
  ?>
</table><br>
<input type="submit" value="Delete checked module from this student" name="student_delete_modules"  onclick="return confirm('Really delete selected modules')"><br><!--Put confirmation pop out after click delete-->
<h1 class="sideh1">* All Modules Available (Not Enrolled Yet) :</h1>
<table width="1200px" cellspacing="0" summary="all module">
  <tr>
  <th scope="col" abbr="Module Name" class="nobg">Module Name</th>
  <th scope="col" abbr="Module ID">Module ID</th>
  <th scope="col" abbr="Add">Add</th>
  </tr>
   <?php
  $modules = modules_available_not_taken(semester(),get_course_code($student_id),year_studying($student_id),$student_id);
  foreach($modules as $mod)
  	
  echo'
  <tr>
    <th scope="row" class="spec">'.module_name($mod).'</th>
    <td>'.$mod.'</td>
    <td><input type="checkbox" name="add_modules[]" value="'.$mod.'"></td>
  </tr>
  
  ';
  
  ?>
</table><br>
<input type="submit" value="Add checked module to this student" name="student_add_modules"><br>
<h1 class="sideh1">* Past Modules :</h1>
<table width="500px" cellspacing="0" summary="current module">
<?php
if(semester()==2)
{
	$modules = modules_taken_sem($student_id,1,year_studying($student_id));

foreach($modules as $mod)
  	
  echo'
  <tr>
    <th scope="row" class="spec">'.module_name($mod).'</th>
    <td>'.$mod.'</td>
  </tr>
  
  ';
  
  }
    ?>
</table><br>

<input type="hidden" name="task" value="student">
<input type="hidden" name="student_id_edit" value="<?php echo $student_id;?>">
 <input type="hidden" name="edit_student" value="sds">

</form>
 <form method="POST" action="admin_home.php">
	 <input name="view_student" type="submit" value="Back">
	 <input type="hidden" name="task" value="student">
	  <input type="hidden" name="student_id_view" value="<?php echo $student_id;?>">

	  
	  </form>

</div>
<!--end Task Detail -->
</div>
</body>
</html>