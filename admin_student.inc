
<!--Task Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">Students Data</h1>
<hr/>
<form method="POST" action="admin_home.php">
<p class="pararight">
<input name="add_student" type="submit" value="Add Student">
<input type="hidden" name="task" value="student">
</form>
</p>

<p class="paraleft">
<form method="POST" action="admin_home.php">
<input type="hidden" name="task" value="student"/>
<input name="searchi" type="submit" value="Search"/>
<input type="text" name="search_string"/>
<div style="display:none">
<input type="text" name="hiddenText"/>
</div>


</form>
</p>

<br class="br1">
<table width="1000" cellspacing="0" summary="Studentdata">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Name</th>
  <th scope="col" abbr="ID">ID</th>
  <th scope="col" abbr="CC">Course Code</th>
  <th scope="col" abbr="MEFS">Year</th>
  <th scope="col" abbr="MEFS">MEF Status</th>
  <th scope="col" abbr="Del">Edit</th>
  </tr>
  <?php
  if(@$_POST['searchi'])
  {
  $name=$_POST['search_string'];
  $students=search_students($name);
  	
  
  }
  else
  $students = all_students();
  
  foreach($students as $stu)
  {
  echo'<tr>
    <th scope="row" class="spec">'.get_name($stu,'student').'</th>
    <td>'.get_rollno($stu).'</td>
    <td>'.get_course_code($stu).'</td>
    
    	<td>
	'.year_studying($stu).'
	</td>
	<td>
	';
    
	if(mef_status($stu,semester()))
	echo 'Submitted';
	else
	echo 'Not submitted';
	echo '</td>
     <td>
     <form method="POST" action="admin_home.php">
	 <input name="view_student" type="submit" value="View">
	 <input type="hidden" name="task" value="student">
	  <input type="hidden" name="student_id_view" value="'.$stu.'">
	  </form>
	 </td>
  </tr>
  
  ';
  
  }  
  ?>
</table>
<br/>


<form method="POST" action="admin_home.php">
<p class="pararight">
<input name="add_student" type="submit" value="Add Student">
</form>

<form method="POST" action="admin_home.php">
<p class="paraleft">
<input type="hidden" name="task" value="student">
<input name="searchi" type="submit" value="Search">
<input type="text" name="search_string">
<div style="display:none">
<input type="text" name="hiddenText"/>
</div>

</p>

</form>



</div>
<!--end Task Detail -->