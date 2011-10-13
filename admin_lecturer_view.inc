<?php
$lecturer_id = $_POST['lecturer_id_view'];

?>

<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Lecturer Name : <font color="blue"><?php echo get_name($lecturer_id,'lecturer');?></font></h1>
<br>
<table width="1200px" cellspacing="0" summary="Studentdata">
  <tr>
  <th scope="col" abbr="Lecturer Name" class="nobg">Name</th>
  <th scope="col" abbr="ID">No. modules</th>

  </tr>
  <tr>
  <?php
    
  echo'
    <th scope="row" class="spec">'.get_name($lecturer_id,'lecturer').'</th>
    <td>'.count(modules_teach($lecturer_id)).'</td>
   
    
    ';
    ?>
  </tr>
</table>
<h1 class="sideh1">* Current Modules :</h1>
<table width="1200px" cellspacing="0" summary="current module">
  <tr>
  <th scope="col" abbr="Module Name" class="nobg">Module Name</th>
  <th scope="col" abbr="Module ID">Module ID</th>
    <th scope="col" abbr="Credits">Credit</th>
  </tr>
  <?php
  $modules= modules_teach($lecturer_id);
  $lecturer_name = get_name($lecturer_id,'lecturer');
  if(is_active_lecturer($lecturer_id))
  {
  	   $delete_value ="alert('Cannot delete active lecturer.Remove any associated modules first by going to modules page for deleting this lecturer.')";
  	   $type="button";
  }
  else
  {

  $delete_value = "return confirm('Really delete $lecturer_name ?')";
  $type="submit";
  }
  
 
  foreach($modules as $mod)
  	
  echo'
  <tr>
    <th scope="row" class="spec">'.module_name($mod).'</th>
    <td>'.$mod.'</td>
    <td>'.module_credits($mod).'</td>
    
  </tr>
  
  ';
  
  ?>
  </table>


<form method="POST" action="admin_home.php">
<p class="pararight"><input name="delete_lecturer" type="<?php echo $type;?>" onclick="<?php echo $delete_value;?>" value="Delete Lecturer"></p>
<p class="pararight"><input name="edit_lecturer" type="submit" value="Edit Lecturer"></p>
 <input type="hidden" name="task" value="lecturer">
<input type="hidden" name="lecturer_id_edit" value="<?php echo $lecturer_id;?>">

</form>

<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="back" type="submit" value="Back"></p>
 <input type="hidden" name="task" value="lecturer">
</form>
</div>
<!--end Task Detail -->
