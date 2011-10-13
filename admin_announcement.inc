
<!--Task Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1">Announcements</h1>
<hr/>
<table width="1000" cellspacing="0" summary="Coursedata">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Location</th>
  <th scope="col" abbr="ID">Content</th>
  <th scope="col" abbr="ID">Update</th>

  </tr>
  <script src="nicEdit.js" type="text/javascript"></script>
<script type="text/javascript">bkLib.onDomLoaded(nicEditors.allTextAreas);</script>
						
  <?php
  if(isset($_POST['announcement']))
  {
  	  
  	  
  	  if(isset($_POST['announcement_home']))
  {
  	  $message = $_POST['announcement'];
  	  add_announcement($message,'home','admin');
	  
	    
  }  
  
  
  if(isset($_POST['announcement_student_modules']))
  {
  	   $message = $_POST['announcement'];
  	  add_announcement($message,'student_modules','admin');
  	  
	  
	    
  }  
  
  if(isset($_POST['announcement_student_mef']))
  {
  	   $message = $_POST['announcement'];
  	  add_announcement($message,'student_mef','admin');
  	  
	  
	    
  }  
  	  
	  
	    
  }  
  
  
  $no = get_latest_announcement_no('home');
  
    echo'
	
	<tr>
    <th scope="row" class="spec">Home page</th>
     <td>
	 <form method ="POST" action ="admin_home.php">
	 <textarea name ="announcement" rows="2" cols=60">'.(get_announcement($no)).'

</textarea>

	 
	 </td>
	 <td>
	 
	 <input type="hidden" name="task" value="announcement" >
<input name="announcement_home" type="submit" value="Update announcement">

</form>
	 
	 </td>
	 </tr>';
	   $no = get_latest_announcement_no('student_modules');
	 
	 
	echo'	<tr>
    <th scope="row" class="spec">Student Modules Page</th>
     <td>
	 <form method ="POST" action ="admin_home.php">
	 <textarea name ="announcement" rows="2" cols=60">'.(get_announcement($no)).'

</textarea>

	 
	 </td>
	 <td>
	 
	 <input type="hidden" name="task" value="announcement" >
<input name="announcement_student_modules" type="submit" value="Update announcement">

</form>
	 
	 </td>
	 </tr>
     ';
     
      $no = get_latest_announcement_no('student_mef');
	 
	 
	echo'	<tr>
    <th scope="row" class="spec">Student MEF Page</th>
     <td>
	 <form method ="POST" action ="admin_home.php">
	 <textarea name ="announcement" rows="2" cols=60">'.(get_announcement($no)).'

</textarea>

	 
	 </td>
	 <td>
	 
	 <input type="hidden" name="task" value="announcement" >
<input name="announcement_student_mef" type="submit" value="Update announcement">

</form>
	 
	 </td>
	 </tr>
     ';
     
     
       
  
  ?>
  
  </table>
<br><br>
<hr/>


</div>
<!--end Task Detail -->
  
  