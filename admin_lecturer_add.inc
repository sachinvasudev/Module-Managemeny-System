<?php
if(isset($_POST['lec_name']))
{


for($i=0;$i<=count($_POST['lec_name'])-1;$i++)
{
    $lec_login = @$_POST['login_id'][$i];

	$name = @$_POST['lec_name'][$i];

	add_lecturer($lec_login,$name);
	

	
}
	
	
echo'<form method="POST" action="admin_home.php" name="myform" id="myform">
<input type="hidden" name="task" value="lecturer">

</form>
<script type=\'text/javascript\'>document.myform.submit();</script>


';


}



?>




<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Add Lecturer</h1>
<br>
<h3 class="sideh3">
<form method="POST" action="admin_home.php">
How many lecturers you want to add? 
<input type="text" name="numberof">
<input name="add_lecturer" type="submit" value="Update table">
<input type="hidden" name="add_lecturer">
<input type="hidden" name="task" value="lecturer">
</form>
</h3>
<table width="1200px" cellspacing="0" summary="lecturer_add">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Lecturer Name</th>
  <th scope="col" abbr="LID">Login ID</th>
  </tr>

  
  <?php
  $numberof = @$_POST['numberof'];

  
  echo'<form method="POST" action="admin_home.php">
  ';
  for($i=1;$i<=$numberof;$i++)
  {
echo'  <tr>
    <th scope="row" class="spec">
	<input type="text" name="lec_name[]" value="" size="15"></th>
    <td><input type="text" name="login_id[]" value="" size="8"></td>

  </tr>';
  }
  
?>


 
</table><br>
<p class="paraleft"><input name="Confirm" type="submit" value="Confirm"></p>


<input type="hidden" name="add_lecturer" value="Add Lecturer">
<input type="hidden" name="task" value="lecturer">

</form>
<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="Cancel" type="submit" value="Cancel"></p>
<input type="hidden" name="task" value="lecturer">
</form>
</div>
<!--end Task Detail -->



