<?php
$student_id = $_POST['student_id_view'];

?>

<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Student Name : <font color="blue"><?php echo get_name($student_id,'student');?></font></h1>
<br>
<table width="1200px" cellspacing="0" summary="Studentdata">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Name</th>
  <th scope="col" abbr="ID">ID</th>
  <th scope="col" abbr="CC">Course Code</th>
  <th scope="col" abbr="Del">Year</th>
   <th scope="col" abbr="Del">Tutor</th>
  <th scope="col" abbr="MEFS">MEF Status</th>
  </tr>
  <tr>
  <?php
  if(mef_status($student_id,semester())==true)
  $status="Submitted";
  else
  $status="Not Submitted";
  
  echo'
    <th scope="row" class="spec">'.get_name($student_id,'student').'</th>
    <td>'.get_rollno($student_id).'</td>
    <td>'.get_course_code($student_id).'</td>
	<td>'.year_studying($student_id).'</td>
		<td>'.get_name(get_tutor($student_id),'lecturer').'</td>
    <td>'.$status.'</td>
    
    ';
    ?>
  </tr>
</table>
<h1 class="sideh1">* Current Modules(<?php echo year().' - Semester '.semester();?> ):</h1>
<table width="1200px" cellspacing="0" summary="current module">
  <tr>
  <th scope="col" abbr="Module Name" class="nobg">Module Name</th>
  <th scope="col" abbr="Module ID">Module ID</th>
  </tr>
  <?php
  $modules = modules_taken_sem($student_id,semester(),year_studying($student_id));
  foreach($modules as $mod)
  	
  echo'
  <tr>
    <th scope="row" class="spec">'.module_name($mod).'</th>
    <td>'.$mod.'</td>
  </tr>
  
  ';
  
  ?>
</table>
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

<form method="POST" action="admin_home.php">
<p class="pararight"><input name="delete_student" type="submit" onclick="return confirm('Really delete <?php echo get_name($student_id,'student');?>?')" value="Delete Student"></p>
<p class="pararight"><input name="edit_student" type="submit" value="Edit Student"></p>
 <input type="hidden" name="task" value="student">
<input type="hidden" name="student_id_edit" value="<?php echo $student_id;?>">

</form>

<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="back" type="submit" value="Back"></p>
 <input type="hidden" name="task" value="student">
</form>
</div>
<!--end Task Detail -->
