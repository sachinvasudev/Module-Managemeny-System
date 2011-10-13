<?php
if(isset($_POST['course_name']))
{



for($i=0;$i<=count($_POST['course_name'])-1;$i++)
{
    $course_name= @$_POST['course_name'][$i];


	$course_id = @$_POST['course_id'][$i];

	
	
	add_course($course_id,$course_name);
	

	
	

	
}
	
	
echo'<form method="POST" action="admin_home.php" name="myform" id="myform">
<input type="hidden" name="task" value="course">

</form>
<script type=\'text/javascript\'>document.myform.submit();</script>


';


}



?>




<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Add Course</h1>
<br>
<h3 class="sideh3">
<form method="POST" action="admin_home.php">
How many courses you want to add? 
<input type="text" name="numberof">
<input name="add_course" type="submit" value="Update table">
<input type="hidden" name="add_course">
<input type="hidden" name="task" value="course">
</form>
</h3>
<table width="1200px" cellspacing="0" summary="Studentadd">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Course Name</th>
  <th scope="col" abbr="ID">Course Code</th>
  

  </tr>

  
  <?php
  $numberof = @$_POST['numberof'];

  
  
  echo'<form method="POST" action="admin_home.php">
  ';
  for($i=1;$i<=$numberof;$i++)
  {
echo'  <tr>
    <th scope="row" class="spec"><input type="text" name="course_name[]" value="" size="30"></th>
    <td><input type="text" name="course_id[]" value="" size="8"></td>
    
     
	
  </tr>';
  }
  
?>


 
</table><br>
<p class="paraleft"><input name="Confirm" type="submit" value="Confirm"></p>


<input type="hidden" name="add_course" value="Add Student">
<input type="hidden" name="task" value="course">

</form>
<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="Cancel" type="submit" value="Cancel"></p>
<input type="hidden" name="task" value="course">
</form>
</div>
<!--end Task Detail -->



