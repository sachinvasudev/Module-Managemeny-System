<!--Task Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">Lecturers Data</h1>
<hr/>
<form method="POST" action="admin_home.php">
<p class="pararight">
<input name="add_lecturer" type="submit" value="Add Lecturer">
<input type="hidden" name="task" value="lecturer">
</form>

<form method="POST" action="admin_home.php">
<p class="paraleft">
<input type="hidden" name="task" value="lecturer">
<input name="searchi" type="submit" value="Search">
<input type="text" name="search_string">
<div style="display:none">
<input type="text" name="hiddenText"/>
</div>
</p>

</form>


<table width="1000" cellspacing="0" summary="Lecturerdata">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Lecturer Name</th>
  <th scope="col" abbr="Name" class="nobg">Lecturer ID</th>
  <th scope="col" abbr="MD">No.	Modules</th>
  <th scope="col" abbr="Del">Edit</th>
  </tr>
  <?php
   if(@$_POST['searchi'])
  {
  $name=$_POST['search_string'];
  $lecturers=search_lecturers($name);
  	
    }
  else
  
  $lecturers = all_lecturers();
  
  foreach($lecturers as $lec)
  {
  
  echo'
    <tr>
    <th scope="row" class="spec">'.get_name($lec,'lecturer').'</th>
    <td>
    '.$lec.'
    </td>
    
    <td>'.count(modules_teach($lec)).'</td>
    <td>
	 <form method="POST" action="admin_home.php">
	 <input name="view_lecturer" type="submit" value="View">
	 <input type="hidden" name="task" value="lecturer">
	  <input type="hidden" name="lecturer_id_view" value="'.$lec.'">
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
<input name="add_lecturer" type="submit" value="Add Lecturer">
<input type="hidden" name="task" value="lecturer">

</form>

<form method="POST" action="admin_home.php">
<p class="paraleft">
<input type="hidden" name="task" value="lecturer">
<input name="searchi" type="submit" value="Search">
<input type="text" name="search_string">
<div style="display:none">
<input type="text" name="hiddenText"/>
</div>
</p>

</form>


</div>
<!--end Task Detail -->