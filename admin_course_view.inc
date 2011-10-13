<?php
$course_code = $_POST['course_id_view'];

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
  <?php

  
  echo'
    <th scope="row" class="spec">'.course_name($course_code).'</th>
    <td>'.$course_code.'</td>
    <td>'.count(students_taken_course($course_code)).'</td>
  
  
    
    ';
    ?>
  </tr>
</table>
<br /><br />

  <?php
$course_name = course_name($course_code);

  if(is_active_course($course_code))
  {
  	   $delete_value ="alert('Cannot delete active course.Remove any associated modules first by going to modules page for deleting this course.')";
  	   $type="button";
  }
  else
  {

  $delete_value = "return confirm('Really delete $course_name ?')";
  $type="submit";
  }
  
    
    
   for($i=1;$i<=3;$i++)
   { 
   	
   	for($j=1;$j<=2;$j++)
   	{
  $modules = modules_available($j,$course_code,$i);
  
  echo' 
  <h2 class="sideh1">Year '.$i.' - Semester '.$j.' :</h2>
<table width="1200px" cellspacing="0" summary="current module">
  <tr>
  <th scope="col" abbr="Student Name" class="nobg">Module Name</th>
  <th scope="col" abbr="ID">Module Code</th>
  <th scope="col" abbr="year">Credits</th>
  <th scope="col" abr="optional">Status</th> 
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
      
   
 echo '
  </td>
  </tr>';
  }
  
  
  

echo'</table>
<br /><br />
';
}
}
  ?>

<form method="POST" action="admin_home.php">
<p class="pararight"><input name="delete_course" type="<?php echo $type;?>" onclick="<?php echo $delete_value;?>" value="Delete Course"></p>
<p class="pararight"><input name="edit_course" type="submit" value="Edit Course"></p>
 <input type="hidden" name="task" value="course">
<input type="hidden" name="course_id_edit" value="<?php echo $course_code;?>">

</form>

<form method="POST" action="admin_home.php">
<p class="paraleft"><input name="back" type="submit" value="Back"></p>
 <input type="hidden" name="task" value="course">
</form>
</div>
<!--end Task Detail -->
