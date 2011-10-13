<?php
if(isset($_POST['mod_name']))
{




for($i=0;$i<=count($_POST['mod_name'])-1;$i++)
{
    $mod_name = @$_POST['mod_name'][$i];

	$mod_id = @$_POST['mod_id'][$i];

	
	$credits = @$_POST['mod_credits'][$i];
	$weightage = @$_POST['weightage'][$i];
	$weightage = $weightage/100;
	
	$lecturer = @$_POST['lecturer'][$i];
	
	add_module($mod_id,$mod_name,$credits,$weightage,$lecturer);
	

	
	

	
}
	
	
echo'<form method="POST" action="admin_home.php" name="myform" id="myform">
<input type="hidden" name="task" value="module">

</form>
<script type=\'text/javascript\'>document.myform.submit();</script>


';


}



?>




<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Add Module</h1>
<br>
<h3 class="sideh3">
<form method="POST" action="admin_home.php">
How many modules you want to add? 
<input type="text" name="numberof">
<input name="add_module" type="submit" value="Update table">
<input type="hidden" name="add_module">
<input type="hidden" name="task" value="module">
</form>
</h3>
<table width="1200px" cellspacing="0" summary="Studentadd">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Module Name</th>
  <th scope="col" abbr="ID">Module Code</th>
  <th scope="col" abbr="LID">Credits</th>
   <th scope="col" abbr="LID">Exam Weightage(%)</th>
  <th scope="col" abbr="CC">Lecturer</th>

  </tr>

  
  <?php
  $numberof = @$_POST['numberof'];
  $lecturers = all_lecturers();
  
  
  echo'<form method="POST" action="admin_home.php">
  ';
  for($i=1;$i<=$numberof;$i++)
  {
echo'  <tr>
    <th scope="row" class="spec"><input type="text" name="mod_name[]" value="" size="15"></th>
    <td><input type="text" name="mod_id[]" value="" size="8"></td>
    <td><input type="text" name="mod_credits[]" value="" size="10"></td>
    <td><input type="text" name="weightage[]" value="" size="10"></td>
  <td><select size="1" name="lecturer[]">
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


<input type="hidden" name="add_module" value="Add Student">
<input type="hidden" name="task" value="module">

</form>
<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="Cancel" type="submit" value="Cancel"></p>
<input type="hidden" name="task" value="module">
</form>
</div>
<!--end Task Detail -->



