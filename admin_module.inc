<!--Task Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">Modules Data</h1>
<hr/>
<form method="POST" action="admin_home.php">
<p class="pararight">
<input name="add_module" type="submit" value="Add Module">
<input type="hidden" name="task" value="module">
</form>


<form method="POST" action="admin_home.php">
<p class="paraleft">
<input type="hidden" name="task" value="module">
<input name="searchi" type="submit" value="Search">
<input type="text" name="search_string">
<div style="display:none">
<input type="text" name="hiddenText"/>
</div>
</p>

</form>







<table width="1000" cellspacing="0" summary="Moduledata">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Name</th>
  <th scope="col" abbr="ID">Module code</th>
  <th scope="col" abbr="CD">Credits</th>
  <th scope="col" abbr="lt">Lecturer</th>
  <th scope="col" abbr="Del">Delete</th>
  </tr>
  <?php
  
   if(@$_POST['searchi'])
  {
  $name=$_POST['search_string'];
  $modules=search_modules($name);
  	
    }
  else
  
  
  
  $modules = all_modules();
  
  foreach($modules as $mod)
  {
  echo'<tr>
    <th scope="row" class="spec">'.module_name($mod).'</th>
    <td>'.$mod.'</td>
    <td>'.module_credits($mod).'</td>
     <td>'.get_name(module_lecturer($mod),'lecturer').'</td>
    
    <td>
     <form method="POST" action="admin_home.php">
	 <input name="view_module" type="submit" value="View">
	 <input type="hidden" name="task" value="module">
	  <input type="hidden" name="module_id_view" value="'.$mod.'">
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
<input name="add_module" type="submit" value="Add Module">
<input type="hidden" name="task" value="module">
</form>

<form method="POST" action="admin_home.php">
<p class="paraleft">
<input type="hidden" name="task" value="module">
<input name="searchi" type="submit" value="Search">
<input type="text" name="search_string">
</p>
<div style="display:none">
<input type="text" name="hiddenText"/>
</div>
</form>

</div>
<!--end Task Detail -->