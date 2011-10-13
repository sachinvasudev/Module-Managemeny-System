
<!--Task Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">Course Data</h1>
<hr/>


<form method="POST" action="admin_home.php">
<p class="pararight">
<input name="add_course" type="submit" value="Add Course">
<input type="hidden" name="task" value="course">
</form>

<form method="POST" action="admin_home.php">
<p class="paraleft">
<input type="hidden" name="task" value="course">
<input name="searchi" type="submit" value="Search">
<input type="text" name="search_string">
<div style="display:none">
<input type="text" name="hiddenText"/>
</div>
</p>

</form>



<table width="1000" cellspacing="0" summary="Coursedata">
  <tr>
  <th scope="col" abbr="Course Name" class="nobg">Name</th>
  <th scope="col" abbr="ID">Course Code</th>
  <th scope="col" abbr="ST">No.Students</th>
  <th scope="col" abbr="Del">View</th>
  </tr>
  
   <?php
   
    if(@$_POST['searchi'])
  {
  $name=$_POST['search_string'];
  $courses=search_courses($name);
  	
    }
  else
  
  $courses = all_courses();
  
  foreach($courses as $cor)
  {
  echo'<tr>
    <th scope="row" class="spec">'.course_name($cor).'</th>
    <td>'.$cor.'</td>
    <td>'.count(students_taken_course($cor)).'</td>
  
    
     <td>
     <form method="POST" action="admin_home.php">
	 <input name="view_course" type="submit" value="View">
	 <input type="hidden" name="task" value="course">
	  <input type="hidden" name="course_id_view" value="'.$cor.'">
	  </form>
	 </td>
  </tr>
  
  ';
  
  }  
  

  
  ?>
  
  
  
</table>
<br>


<form method="POST" action="admin_home.php">
<p class="pararight">
<input name="add_course" type="submit" value="Add Course">
<input type="hidden" name="task" value="course">
</form>

<form method="POST" action="admin_home.php">
<p class="paraleft">
<input type="hidden" name="task" value="course">
<input name="searchi" type="submit" value="Search">
<input type="text" name="search_string">
<div style="display:none">
<input type="text" name="hiddenText"/>
</div>
</p>

</form>


</div>
<!--end Task Detail -->