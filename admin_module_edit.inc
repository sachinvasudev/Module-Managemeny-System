<?php
$module_code= $_POST['module_id_edit'];

if(@$_POST['module_delete_students'])
{
	if(isset($_POST['delete_students']))
	{
	foreach($_POST['delete_students'] as $stu)
	{
		delete_student_module($stu,$module_code);	
	}
	}
}

if(@$_POST['module_add_students'])
{
	if(isset($_POST['add_students']))
	{
	foreach($_POST['add_students'] as $stu)
	{
		take_module($stu,$module_code);	
	}
	}
}

if(@$_POST['module_update_details'])
{
	$name = $_POST['module_name'];
	$module_code_new = $_POST['module_code'];
	

	$credits = $_POST['credits'];
	$weightage  = $_POST['weightage'];
	$weightage = $weightage/100;
	
	$lecturer = $_POST['lecturer'];
	
    edit_module($name,$module_code_new,$module_code,$credits,$weightage,$lecturer);
		$module_code = $module_code_new;
}



?>

<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Module Name : <font color="blue"><?php echo module_name($module_code);?></font></h1>

<br>
<table width="1200px" cellspacing="0" summary="Studentdata">

  <tr>
  <th scope="col" abbr="Name" class="nobg">Name</th>
  <th scope="col" abbr="ID">Module Code</th>
  <th scope="col" abbr="CC">Credits</th>
  <th scope="col" abbr="Del">Exam Weightage(%)</th>
  <th scope="col" abbr="MEFS">Lecturer</th>
  </tr>
  <form method="POST" action="admin_home.php">
  <?php
  $lecturers = all_lecturers();
  
  echo'
  
  
  <tr>
    <th scope="row" class="spec"><input type="text" name="module_name" value="'.module_name($module_code).'"  size="40"></th>
    <td><input type="text" name="module_code" value="'.$module_code.'" size="6"></td>
<td><input type="text" name="credits" value="'.module_credits($module_code).'" size="4"></td>
<td><input type="text" name="weightage" value="'.(exam_weightage($module_code)*100).'" size="4"></td>

	 <td><select size="1" name="lecturer">
     ';
	foreach($lecturers as $lec)
	{
			echo '<option value="'.$lec.'"
		';
		if($lec==module_lecturer($module_code))
		echo'selected="selected"';
		echo'>
		     '.get_name($lec,'lecturer').'
		     </option>
		';	
	}
	
	echo'
	
	
	</select></td>
   
   
   
  </tr>
  
  ';
  ?>

</table>
<br />
  <input type="Submit" name="module_update_details" value="Update details">
    <?php
if(@$_POST['module_update_details'])
echo'<font color="red">Details updated successfully</font>';
?>
  <input type="hidden" name="task" value="module">
<input type="hidden" name="module_id_edit" value="<?php echo $module_code;?>">
 <input type="hidden" name="edit_module" value="sds">
  </form>
  
 <form method="POST" action="admin_home.php"> 



<h1 class="sideh1">* Current Students :</h1>
<table width="1200px" cellspacing="0" summary="current module">
  <tr>
  <th scope="col" abbr="Student Name" class="nobg">Student Name</th>
  <th scope="col" abbr="ID">ID</th>
  <th scope="col" abbr="year">Year</th>
    <th scope="col" abbr="year">Delete</th>
  </tr>
  <?php
  $students = students_taken($module_code);
  foreach($students  as $stu)
  	
  echo'
  <tr>
    <th scope="row" class="spec">'.get_name($stu,'student').'</th>
    <td>'.get_rollno($stu).'</td>
      <td>'.year_studying($stu).'</td>
    <td><input type="checkbox" name="delete_students[]" value="'.$stu.'"></td>
  </tr>
  
  ';
  
  ?>
</table><br>
<input type="submit" value="Delete checked student from this module" name="module_delete_students" onclick="return confirm('Really delete selected students?')" ><br><!--Put confirmation pop out after click delete-->
<h1 class="sideh1">* All Students Available :</h1>
<table width="1200px" cellspacing="0" summary="all module">
  <tr>
   <th scope="col" abbr="Student Name" class="nobg">Student Name</th>
  <th scope="col" abbr="ID">ID</th>
  <th scope="col" abbr="year">Year</th>
  <th scope="col" abbr="Add">Add</th>
  </tr>
   <?php
   $students = students_not_taken_module($module_code);
   foreach($students as $stu)
  	
  echo'
 <tr>
    <th scope="row" class="spec">'.get_name($stu,'student').'</th>
    <td>'.get_rollno($stu).'</td>
      <td>'.year_studying($stu).'</td>
    <td><input type="checkbox" name="add_students[]" value="'.$stu.'"></td>
  </tr>
  
  ';
  
  ?>
</table><br>
<input type="submit" value="Add checked student to this module" name="module_add_students"><br>


<input type="hidden" name="task" value="module">
<input type="hidden" name="module_id_edit" value="<?php echo $module_code?>">
 <input type="hidden" name="edit_module" value="sds">

</form>

<br/>
 <form method="POST" action="admin_home.php">
	 <input name="view_module" type="submit" value="Back">
	 <input type="hidden" name="task" value="module">
	  <input type="hidden" name="module_id_view" value="<?php echo $module_code;?>">

	  
	  </form>

</div>
<!--end Task Detail -->
</div>
</body>
</html>