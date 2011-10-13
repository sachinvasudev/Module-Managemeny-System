
<div id="wrapper">
<!-- start page -->
<div id="page">
	<!-- start content -->
	<div id="section">
	<IMG src="./images/MEF.png" alt="MEF">
	</div>
	<div id="content">
	<h1 class="title" align="center">Submit MEF</h1>

		
		
				<?php
			$no = get_latest_announcement_no('student_mef');
			if($no)
			{
			$time = get_announcement_time($no);
			 
			
			echo '
			<p><small>Posted on '.get_announcement_date($no).' by '.get_announcement_author($no).'
			at '.$time['hours'].':'.$time['minutes'].':'.$time['seconds'].'
			 </a></small></p>
			
				<p>'.(get_announcement($no)).'  </p>
				
				';
				}
			?>
		
		
		
		
		
		
		
		<?php
		
		$student_id = $_SESSION['valid_user'];
$course_code = course_code($student_id);
$year = year_studying($student_id);
$modules  = modules_available(semester(),$course_code,$year);

$max_credits = 60;
$initial_total=0;
echo '<form method ="POST" action ="st_home.php" name ="mef">';

foreach($modules as $module_code)
{

$module_credit =  module_credits($module_code);
if($module_credit>10)
{


echo'<table id="table" cellspacing="0" summary="fullyear">
<caption>Full Year</caption>
<tr>
  <th scope="col" abbr="Module Code" class="nobg">Module Code</th>
  <th scope="col" abbr="Module Name">Module Name</th>
  <th scope="col" abbr="Status">Status</th>
  <th scope="col" abbr="Credits">Credits</th>
  <th scope="col" abbr="Checkbox">Check Box</th>
</tr>

<tr 
  title ="Lecturer:'.get_name(get_lecturer($module_code),'lecturer').'">
  
  <th scope="row" class="spec">'.$module_code.'</th>
  <td>'.module_name($module_code).'</td>
  <td>';
  if(optional($module_code,$course_code,$year,semester()))
  echo 'Optional';
  else
  echo 'Compulsory';
  
  echo'</td>
  <td>'.$module_credit.'</td>
  <td><input type="checkbox" name="modules_selected[]" onclick="check_total();display_total()" value="'.$module_code.'" ';
  if(!optional($module_code,$course_code,$year,semester()))
  {
  
  echo 'disabled ="disabled" checked>
  <input type ="hidden" name ="modules_selected[]" value ="'.$module_code.'">
  </td>
  </div>
  ';
  $initial_total+=$module_credit/2;
  
 
  
  }
  else
  echo'></td>
</tr>








</table><br>

		';
		break;

	
	
}

$module_credit = $module_credit/2;

}
		
		
		;
		
		?>
		
	<table id="table" cellspacing="0" summary="MEF form">
<caption>Semester <?echo semester();?> </caption>
<tr>
  <th scope="col" abbr="Module Code" class="nobg">Module Code</th>
  <th scope="col" abbr="Module Name">Module Name</th>
  <th scope="col" abbr="Status">Status</th>
  <th scope="col" abbr="Credits">Credits</th>
  <th scope="col" abbr="Checkbox">Check Box</th>
</tr>
<?php
if(isset($_POST["modules_selected"]))
{
	echo 'submit njekki';
	exit;
}






foreach($modules as $module_code)
{

$module_credit =  module_credits($module_code);
if($module_credit>10)
continue;

echo'
     
  <tr 
  title ="Lecturer:'.get_name(get_lecturer($module_code),'lecturer').'">
  
  <th scope="row" class="spec">'.$module_code.'</th>
  <td>'.module_name($module_code).'</td>
  <td>';
  if(optional($module_code,$course_code,$year,semester()))
  echo 'Optional';
  else
  echo 'Compulsory';
  
  echo'</td>
  <td>'.$module_credit.'</td>
  <td><input type="checkbox" name="modules_selected[]" onclick="check_total();display_total()" value="'.$module_code.'" ';
  if(!optional($module_code,$course_code,$year,semester()))
  {
  
  echo 'disabled ="disabled" checked>
  <input type ="hidden" name ="modules_selected[]" value ="'.$module_code.'">
  </td>
  </div>
  ';
  $initial_total+=$module_credit;
  
 
  
  }
  else
  echo'></td>
</tr>

';

}

?>



</form>
	</table><br>
	
	
	<table id="table" cellspacing="20" summary="total">
<tr>
  <th class="specalt">Total Credits :</th>
  <td class="alt" align="right" id="credits"> <?php echo $initial_total;?></td>
  
</tr>
	</table><br>
	
	  <a class="button" onclick="notify_credits()" href="#nothing" ><span>Submit</span></a>
	</div>
	<!-- end content -->
	
	
	 <script type="text/javascript">
  
  
  function display_total()
  {
  total_credits =0;
  	
  		
    for (var i=0;i<document.mef["modules_selected[]"].length;i++)
	{
		
		
if (document.mef["modules_selected[]"][i].checked)
{
  var module_code =  document.mef["modules_selected[]"][i].value;
  total_credits = total_credits + get_module_credit(module_code);
 	
}


 }
 document.getElementById("credits").innerHTML=total_credits;


  
  }
  
  
 function check_total()
 
 
 {
 	var total_credits = 0;
	<?php echo"var max_credits = $max_credits;";?>
    		

 	
    for (var i=0;i<document.mef["modules_selected[]"].length;i++)
	{
		
		
if (document.mef["modules_selected[]"][i].checked)
{
  var module_code =  document.mef["modules_selected[]"][i].value;
  total_credits = total_credits + get_module_credit(module_code);
 	
}

	
  


 }
 
 if(total_credits==max_credits)
 {
 	 for (var i=0;i<document.mef["modules_selected[]"].length;i++)
	{
		
		
if ((document.mef["modules_selected[]"][i].checked==false) && (document.mef["modules_selected[]"][i].type=="checkbox"))
{
 document.mef["modules_selected[]"][i].disabled=true;
}

	
  


 }
	  
 }
 
 else
 {
 		 for (var i=0;i<document.mef["modules_selected[]"].length;i++)
	{
		
		
if (!document.mef["modules_selected[]"][i].checked)
{
 document.mef["modules_selected[]"][i].disabled=false;
}

	
  


 }
	  
 	
	  
 }
 
   


 }
 
 function get_module_credit($modulecode)
 {
 		<?php
 	echo"var module_credits = new Array();";
 	foreach($modules as $modi)
 	{
 		$credits = module_credits($modi);
 		if($credits>10)
 		$credits = $credits/2;
		echo "module_credits[\"$modi\"] =$credits; ";
		

 		 	
 	} 
 	
 		
 	?>
 	return module_credits[$modulecode];
	 
	  
 }
 
 function notify_credits()
 {
 	var total_credits =0;
 		<?php echo"var max_credits = $max_credits;";?>
 	    for (var i=0;i<document.mef["modules_selected[]"].length;i++)
	{
		
		
if (document.mef["modules_selected[]"][i].checked)
{
   
  var module_code =  document.mef["modules_selected[]"][i].value;
  total_credits = total_credits + get_module_credit(module_code);
 	
}


 }
 if(total_credits<max_credits)
{
alert("You have not selected the required number of modules");



	
}
else
{
	document.mef.submit()
}
 }
 
 </script>