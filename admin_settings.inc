

<?php

if(isset($_POST['semester'])||isset($_POST['exam_officer']))
{
update_semester($_POST['semester']);
update_exam_officer($_POST['exam_officer']);
update_year($_POST['year']);
update_maintenance($_POST['maintenance']);
update_show_year_total($_POST['show_year_total']);

}




?>


<!--Task Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">MMS Settings</h1>
<hr/>
<table width="1000" cellspacing="0" summary="Coursedata">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Setting</th>
  <th scope="col" abbr="ID">Value</th>

  </tr>
  
<form method="POST" action="admin_home.php">

  
  <tr>
    <th scope="row" class="spec">Year</th>
    
    <td>
	<input type="text" name="year" value="<?php echo year();?>">
	</td>
   
  </tr>


<tr>
    <th scope="row" class="spec">Semester</th>
    
   
	
<td><select size="1" name="semester">
<option value="1"<?php if(semester()==2) echo '"selected="selected"';?>>First</option>

<option value="2"<?php if(semester()==2) echo '"selected="selected"';?>>Second</option></select></td>
   
  </tr>
  
  <tr>
    <th scope="row" class="spec">Examination officer</th>
    
  
	<td><select size="1" name="exam_officer">
	<?php
	$lecturers=all_lecturers();
	foreach($lecturers as $lec)
	{
			echo '<option value="'.$lec.'"
		';
		if($lec==exam_officer())
		echo'selected="selected"';
		echo'>
		     '.get_name($lec,'lecturer').'
		     </option>
		';	
	}
	?>
	
		</select></td>
   
  </tr>
  
   
  <tr>
    <th scope="row" class="spec">Maintenance Mode</th>
    
 	
<td><select size="1" name="maintenance">
<option value="1"<?php if(maintenance()) echo 'selected="selected"';?>>Maintenance Mode</option>

<option value="0"<?php if(!maintenance()) echo 'selected="selected"';?>>Normal Mode</option></select></td>
   
  </tr>
  
  
  <tr>
    <th scope="row" class="spec">Display Year Total</th>
    
 	
<td><select size="1" name="show_year_total">
<option value="1"<?php if(show_year_total()) echo 'selected="selected"';?>>Show</option>

<option value="0"<?php if(!show_year_total()) echo 'selected="selected"';?>>Don't Show</option></select></td>
   
  </tr>
  
  
   </table>
   
   	
   
<br><br>
<hr/>

<input type="hidden" name="task" value="settings">
  <input type="submit" value="Update settings">
    <?php
if(@$_POST['semester'])
echo'<font color="red">Settings updated successfully</font>';
?>
  </form>
</div>
<!--end Task Detail -->
  
  
  
