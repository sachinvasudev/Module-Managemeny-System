<?php
$module_code = $_POST['module_id_view'];

?>

<!--Task Navigation-->
<hr/>
<h1 class="sideh1">Module Name : <font color="blue"><?php echo module_name($module_code);?></font></h1>
<br>
<table width="1200px" cellspacing="0" summary="Studentdata">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Name</th>
  <th scope="col" abbr="Module code">ID</th>
  <th scope="col" abbr="CC">Credits</th>
    <th scope="col" abbr="CC">Exam Weightage(%)</th>
  <th scope="col" abbr="Del">Lecturer</th>
  </tr>
  <tr>
  <?php

  
  echo'
    <th scope="row" class="spec">'.module_name($module_code).'</th>
    <td>'.$module_code.'</td>
    <td>'.module_credits($module_code).'</td>
     <td>'.(exam_weightage($module_code)*100).'</td>
	<td>'.get_name(module_lecturer($module_code),'lecturer').'</td>
  
    
    ';
    ?>
  </tr>
</table>
<h1 class="sideh1">* Current Students :</h1>
<table width="1200px" cellspacing="0" summary="current module">
  <tr>
  <th scope="col" abbr="Student Name" class="nobg">Student Name</th>
  <th scope="col" abbr="ID">ID</th>
  <th scope="col" abbr="year">Year</th>
  </tr>
  <?php
  $students = students_taken($module_code);
  $module_name = module_name($module_code);
  
  if(is_active_module($module_code))
  {
  	   $delete_value ="alert('Cannot delete active module.Remove any associated students first by going to students page for deleting this module.')";
  	   $type="button";
  }
  else
  {

  $delete_value = "return confirm('Really delete $module_name ?')";
  $type="submit";
  }
  
  
  
  foreach($students as $stu)
  	
  echo'
  <tr>
    <th scope="row" class="spec">'.get_name($stu,'student').'</th>
    <td>'.get_rollno($stu).'</td>
      <td>'.year_studying($stu).'</td>
  </tr>
  
  ';
  
  ?>
</table>


<form method="POST" action="admin_home.php">
<p class="pararight"><input name="delete_module" type="<?php echo $type;?>" onclick="<?php echo $delete_value;?>" value="Delete Module"></p>
<p class="pararight"><input name="edit_module" type="submit" value="Edit Module"></p>
 <input type="hidden" name="task" value="module">
<input type="hidden" name="module_id_edit" value="<?php echo $module_code;?>">

</form>

<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="back" type="submit" value="Back"></p>
 <input type="hidden" name="task" value="module">
</form>
</div>
<!--end Task Detail -->
