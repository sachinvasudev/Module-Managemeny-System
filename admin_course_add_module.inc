<?php
$course_code= $_POST['course_id_edit'];


if(isset($_POST['module_code']))
{



for($i=0;$i<=count($_POST['module_code'])-1;$i++)
{
    $module_code = @$_POST['module_code'][$i];

	$year = $_POST['year'][$i];

	
	$semester = @$_POST['semester'][$i];
	$status = @$_POST['status'][$i];
	
	if($semester==3)
	{
		add_module_course($course_code,$module_code,1,$year,$status);
		add_module_course($course_code,$module_code,2,$year,$status);
			
	}
	else
	{
	
add_module_course($course_code,$module_code,$semester,$year,$status);


}
	

	
	

	
}
	
	
echo'<form method="POST" action="admin_home.php" name="myform" id="myform">
<input type="hidden" name="task" value="course">
<input name="edit_course" type="hidden" value="Edit Course"></p>
 <input type="hidden" name="task" value="course">
<input type="hidden" name="course_id_edit" value="'.$course_code.'">

</form>
<script type=\'text/javascript\'>document.myform.submit();</script>


';


}



?>




<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Add Modules to Course - <?php echo course_name($course_code);?></h1>
<br>
<h3 class="sideh3">
<form method="POST" action="admin_home.php">
How many modules you want to add? 
<input type="text" name="numberof">
<input name="course_add_module" type="submit" value="Update table">
<input type="hidden" name="task" value="course">
<input type="hidden" name="course_id_edit" value="<?php echo $course_code;?>">
</form>
</h3>
<table width="1020px" cellspacing="0" summary="Studentadd">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Module Name</th>
  <th scope="col" abbr="ID">Year</th>
  <th scope="col" abbr="LID">Semester</th>
   <th scope="col" abbr="LID">Status</th>

  </tr>

  
  <?php
  $numberof = @$_POST['numberof'];
  $modules = all_modules();
  
  
  echo'<form method="POST" action="admin_home.php">
  ';
  for($i=1;$i<=$numberof;$i++)
  {
  	
echo'  <tr>
    <td><select size="1" name="module_code[]">';
    foreach($modules as $mod)
    {
    
	echo'<option value="'.$mod.'">
	'.module_name($mod).' ('.$mod.')
	</option>
	
	';
	}
    
    
    
   echo' 
   
   <td><select size="1" name="year[]"><option value="1">1</option><option value="2">2</option><option value="3">3</option></select></td>
   
    <td><select size="1" name="semester[]"><option value="1">First</option><option value="2">Second</option><option value="3">Both</option></select></td>
    
     <td><select size="1" name="status[]"><option value="0">Compuslory</option><option value="1">Optional</option></select></td>
    
 
  
  </tr>';
  }
  
?>


 
</table><br>
<p class="paraleft"><input name="Confirm" type="submit" value="Confirm"></p>

<input type="hidden" name="course_id_edit" value="<?php echo $course_code;?>">
<input type="hidden" name="course_add_module" value="Add Module">
<input type="hidden" name="task" value="course">

</form>
<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="edit_course" type="submit" value="Cancel"></p>
<input type="hidden" name="task" value="course">

<input type="hidden" name="course_id_edit" value="<?php echo $course_code;?>">
</form>
</div>
<!--end Task Detail -->



