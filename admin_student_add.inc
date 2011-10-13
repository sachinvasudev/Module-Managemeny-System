<?php
if(isset($_POST['stu_name']))
{




for($i=0;$i<=count($_POST['stu_name'])-1;$i++)
{
    $stu_login = @$_POST['login_id'][$i];
	$stu_id = @$_POST['stu_id'][$i];

	$name = @$_POST['stu_name'][$i];
	$course = @$_POST['course'][$i];
	$year = @$_POST['year'][$i];
	$tutor = @$_POST['tutor'][$i];
	
	add_student($stu_login,$stu_id,$name,$course,$year,$tutor);
	stu_temp_password($stu_login);
	
	

	
}
	
	
echo'<form method="POST" action="admin_home.php" name="myform" id="myform">
<input type="hidden" name="task" value="student">

</form>
<script type=\'text/javascript\'>document.myform.submit();</script>


';


}



?>




<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Add Student</h1>
<br>
<h3 class="sideh3">
<form method="POST" action="admin_home.php">
How many students you want to add? 
<input type="text" name="numberof">
<input name="add_student" type="submit" value="Update table">
<input type="hidden" name="add_student">
<input type="hidden" name="task" value="student">
</form>
</h3>
<table width="1200px" cellspacing="0" summary="Studentadd">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Student Name</th>
  <th scope="col" abbr="ID">Student ID</th>
  <th scope="col" abbr="LID">Login ID</th>
  <th scope="col" abbr="CC">Course Code</th>
  <th scope="col" abbr="year">Year</th>
  <th scope="col" abbr="tutor">Tutor</th>
  </tr>

  
  <?php
  $numberof = @$_POST['numberof'];
  $lecturers = all_lecturers();
  $courses = all_courses();
  
  echo'<form method="POST" action="admin_home.php">
  ';
  for($i=1;$i<=$numberof;$i++)
  {
echo'  <tr>
    <th scope="row" class="spec"><input type="text" name="stu_name[]" value="" size="15"></th>
    <td><input type="text" name="stu_id[]" value="" size="8"></td>
    <td><input type="text" name="login_id[]" value="" size="10"></td>
    <td><select size="1" name="course[]">';
    foreach($courses as $cos)
    {
    
	echo'<option value="'.$cos.'">
	'.$cos.'
	</option>
	
	';
	}
	
	echo'</select>
	</td>
    <td><select size="1" name="year[]"><option value="1">First</option><option value="2">Second</option><option value="3">Third</option></select></td>
    <td><select size="1" name="tutor[]">
     ';
	foreach($lecturers as $lec)
	{
		echo '<option value="'.$lec.'">
		     '.get_name($lec,'lecturer').'
		     </option>
		';	
	}
	
	echo'
	
	
	</select></td>
  </tr>';
  }
  
?>


 
</table><br>
<p class="paraleft"><input name="Confirm" type="submit" value="Confirm"></p>


<input type="hidden" name="add_student" value="Add Student">
<input type="hidden" name="task" value="student">

</form>
<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="Cancel" type="submit" value="Cancel"></p>
<input type="hidden" name="task" value="student">
</form>
</div>
<!--end Task Detail -->



