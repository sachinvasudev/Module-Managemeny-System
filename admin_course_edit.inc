<?php
$course_code= $_POST['course_id_edit'];

if(@$_POST['course_delete_module'])
{
	
	$year = $_POST['year'];
	$semester = $_POST['sem'];
    if(isset($_POST['delete_modules']))
    {

	foreach($_POST['delete_modules'] as $mod_del)
	{
		delete_module_course($mod_del,$course_code,$year,$semester);
		
		
	
	
	}
	
	}
	

}



if(@$_POST['course_update_details'])
{

	$name = $_POST['course_name'];
	$course_code_new = $_POST['course_code'];
	

	edit_course($course_code,$course_code_new,$name);
	
	$course_code=$course_code_new;
}



?>


<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Course Name : <font color="blue"><?php echo course_name($course_code);?></font></h1>

<br>
<table width="1200px" cellspacing="0" summary="Studentdata">
  <tr>
  <th scope="col" abbr="Course Name" class="nobg">Name</th>
  <th scope="col" abbr="ID">Course Code</th>
  <th scope="col" abbr="ST">No.Students</th>

  </tr>
  <tr>
  <form method="POST" action="admin_home.php">
  <?php

  
  echo'
  
    <th scope="row" class="spec"><input type="text" name="course_name" value="'.course_name($course_code).'"  size="40"></th>
    <td><input type="text" name="course_code" value="'.$course_code.'" size="6"></td>
      <td>'.count(students_taken_course($course_code)).'</td>
  
  
    ';
    ?>
  </tr>
</table>
<br />
  
  <input type="Submit" name="course_update_details" value="Update details">
    <?php
if(@$_POST['course_update_details'])
echo'<font color="red">Details updated successfully</font>';
?>
  <input type="hidden" name="task" value="course">
<input type="hidden" name="course_id_edit" value="<?php echo $course_code;?>">
 <input type="hidden" name="edit_course" value="sds">
  </form>
  <br /><br />
  <form method="POST" action="admin_home.php">
 <input type="hidden" name="task" value="course">
<input type="hidden" name="course_add_module" value="sd">
<input type="hidden" name="course_id_edit" value="<?php echo $course_code;?>">
<input type="submit" value="Add module to course">

</form>
  
  
 <?php
 
   for($i=1;$i<=3;$i++)
   { 
   	
   	for($j=1;$j<=2;$j++)
   	{
  $modules = modules_available($j,$course_code,$i);
  
  echo' 
  <form method="POST" action="admin_home.php">
  <h2 class="sideh1">Year '.$i.' - Semester '.$j.' :</h2>
<table width="1200px" cellspacing="0" summary="current module">
  <tr>
  <th scope="col" abbr="Student Name" class="nobg">Module Name</th>
  <th scope="col" abbr="ID">Module Code</th>
  <th scope="col" abbr="year">Credits</th>
  <th scope="col" abr="optional">Status</th> 
   <th scope="col" abbr="year">Delete</th>
  </tr>';
  foreach($modules as $mod)
  {
  	
  echo'
 
    <tr>
    <th scope="row" class="spec">'.module_name($mod).'</th>
    <td>'.$mod.'</td>
      <td>'.module_credits($mod).'</td>
	  <td>';
	  
      if(optional($mod,$course_code,$i,$j))
      echo 'Optional';
      else echo 'Compulsory';
      
      echo'</td>
	  <td><input type="checkbox" name="delete_modules[]" value="'.$mod.'"></td>
  </tr>';
  }
  
  
  

echo'</table>
<br/>
';

 echo'
 <input type="submit" value="Delete checked module from this semester" name="course_delete_module"
 onclick="return confirm(\'Really delete selected modules?\')"
 >
 
 <input type="hidden" name="year" value="'.$i.'">
 <input type="hidden" name="sem" value="'.$j.'">
 
 
 <input type="hidden" name="task" value="course">
<input type="hidden" name="course_id_edit" value="'.$course_code.'">
 <input type="hidden" name="edit_course" value="sds">

</form>';


}




echo'<br /><br /><br />
';

}
 

 
 
 
 ?>
  




<br/>

<form method="POST" action="admin_home.php">
 <input type="hidden" name="task" value="course">
<input type="hidden" name="course_add_module" value="sd">
<input type="hidden" name="course_id_edit" value="<?php echo $course_code;?>">
<input type="submit" value="Add module to course">

</form>

<br />
 <form method="POST" action="admin_home.php">
	 <input name="view_course" type="submit" value="Back">
	 <input type="hidden" name="task" value="course">
	  <input type="hidden" name="course_id_view" value="<?php echo $course_code;?>">

	  
	  </form>

</div>
<!--end Task Detail -->
</div>
</body>
</html>