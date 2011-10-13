<?php
$lecturer_id = $_POST['lecturer_id_edit'];

if(@$_POST['lecturer_delete_modules'])
{
	
	if(isset($_POST['delete_modules']))
	{
	
	foreach($_POST['delete_modules'] as $mod)
	{
		delete_lecturer_module($lecturer_id,$mod);	
	}
	}
}

if(@$_POST['lecturer_add_modules'])
{
	if(isset($_POST['add_modules']))
	{
	
	foreach($_POST['add_modules'] as $mod)
	{
		take_module_lecturer($lecturer_id,$mod);	
	}
	}
}

if(@$_POST['lecturer_update_details'])
{
	$name = $_POST['lecturer_name'];
	$login_id = $_POST['login_id'];

	
	edit_lecturer($lecturer_id,$login_id,$name);
	$lecturer_id = $login_id;
	
}


?>

<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Lecturer Name : <font color="blue"><?php echo get_name($lecturer_id,'lecturer');?></font></h1>

<br>
<table width="1200px" cellspacing="0" summary="Studentdata">

  <tr>
  <th scope="col" abbr="Lecturer Name" class="nobg">Name</th>
    <th scope="col" abbr="ID">Login ID</th>
  <th scope="col" abbr="ID">No. of modules</th>
  </tr>
  <form method="POST" action="admin_home.php">
  <?php

  echo'
  
  
  <tr>
    <th scope="row" class="spec"><input type="text" name="lecturer_name" value="'.get_name($lecturer_id,'lecturer').'"  size="30"></th>
        <td><input type="text" name="login_id" value="'.$lecturer_id.'" size="7"></td>
    <td>'.count(modules_teach($lecturer_id)).'</td>
  </tr>
  
  ';
  ?>

</table>
<br />
  <input type="Submit" name="lecturer_update_details" value="Update details">
    <?php
if(@$_POST['lecturer_update_details'])
echo'<font color="red">Details updated successfully</font>';
?>
  <input type="hidden" name="task" value="lecturer">
<input type="hidden" name="lecturer_id_edit" value="<?php echo $lecturer_id;?>">
 <input type="hidden" name="edit_lecturer" value="sds">
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
  $modules= modules_teach($lecturer_id);
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
<input type="submit" value="Delete checked module from this lecturer" name="lecturer_delete_modules"  onclick="return confirm('Really delete the selected modules ?')"><br><!--Put confirmation pop out after click delete-->



<h1 class="sideh1">* All Modules Available (Not Taken Yet) :</h1>
<table width="1200px" cellspacing="0" summary="all module">
  <tr>
  <th scope="col" abbr="Module Name" class="nobg">Module Name</th>
  <th scope="col" abbr="Module ID">Module ID</th>
  <th scope="col" abbr="Add">Add</th>
  </tr>
   <?php
  $modules = modules_available_not_taken_lecturer($lecturer_id);
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
<input type="submit" value="Add checked module to this lecturer" name="lecturer_add_modules"> <br>

<input type="hidden" name="task" value="lecturer">
<input type="hidden" name="lecturer_id_edit" value="<?php echo $lecturer_id;?>">
 <input type="hidden" name="edit_lecturer" value="sds">

</form>
<br />
 <form method="POST" action="admin_home.php">
	 <input name="view_lecturer" type="submit" value="Back">
	 <input type="hidden" name="task" value="lecturer">
	  <input type="hidden" name="lecturer_id_view" value="<?php echo $lecturer_id;?>">

	  
	  </form>

</div>
<!--end Task Detail -->
</div>
</body>
</html>