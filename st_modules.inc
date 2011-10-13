<div id="wrapper">
<!-- start page -->
<div id="page">
	<!-- start content -->
	<div id="section">
	<IMG src="./images/sthome.png" alt="Student Homepage">
	</div>
	<div id="content">
		<h1 class="title" align="center">View your modules marks</h1>
		
			<?php
			$no = get_latest_announcement_no('student_modules');
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
				echo '<h2 class="toph2">Current year: '.year().' - Semester '.semester().'</h2>';	
			?>
		
		
		
		

<?php
$student_id = $_SESSION['valid_user'];
$course_code = course_code($student_id);
$year = year_studying($student_id);

if(semester()==2 &&!isset($_POST['show_sem1']))
{

	
echo'	<table id="table" cellspacing="0" summary="MEF form">
<caption class="caption2">Semester 2</caption>
<tr>
  <th scope="col" abbr="Module Code" class="nobg">Module Code</th>
  <th scope="col" abbr="Module Name">Module Name</th>
  <th scope="col" abbr="CW">Coursework Mark</th>
  <th scope="col" abbr="CW_W">Coursework Weightage</th>
  <th scope="col" abbr="Final">Final Exam</th>
  <th scope="col" abbr="Total">Total</th>
</tr>
';
	
	
$modules  = modules_taken_sem($student_id,2,year_studying($student_id));
	
foreach($modules as $module_code)
{

echo'

  <tr>
  <th scope="row" class="spec">'.$module_code.'</th>
  <td>'.module_name($module_code).'</td>
  <td>';
  for($i=1;$i<=num_courseworks($module_code);$i++)
  {
  $cw_mark = cw_mark($student_id,$module_code,$i);
  	$cw_total = cw_total($module_code,$i);
  	echo '';
  	if(!empty($cw_mark))
  	{
  		echo "$cw_mark/$cw_total";
  		//$cw_perc = ($cw_mark/$cw_total)*100;
  		//echo ",$cw_perc%";
  		
  		  	
  	}
  	else
  	{
  		echo "N/A";  	
  	}
  	echo '';
  	
  	if(($i!=num_courseworks($module_code)))
  	echo ',';
  	else echo '&nbsp';
  	
  }
  
  echo'</td>';
  
  echo '<td>';
  for($i=1;$i<=num_courseworks($module_code);$i++)
  {
   
   echo (cw_weightage($module_code,$i)*100).'%';
  
  
  if(($i!=num_courseworks($module_code)))
  	echo ',';
  	else echo '&nbsp';
  	
  }
  
  
  echo '</td>';
  
  
  
  
  
  
  
  echo '<td>';
   echo $b = exam_mark($student_id,$module_code);
   if(empty($b))
   echo '&nbsp';
  echo'</td>
  
  <td>';
  echo $c = total_marks($student_id,$module_code);
  if(empty($c))
   echo '&nbsp';
  
  echo '</td>
</tr>	

';

}	
	
	
	echo'	</table><br>';
	
	echo'	
<form method="POST" action="st_home.php">
<input type="submit" name ="show_sem1" value="View Semester 1">
</form>	';
	
}





if(semester()==1||isset($_POST['show_sem1']))
{


$modules  = modules_taken_sem($student_id,1,year_studying($student_id));
echo'	<table id="table" cellspacing="0" summary="MEF form">
<caption class="caption2">Semester 1</caption>
<tr>
  <th scope="col" abbr="Module Code" class="nobg">Module Code</th>
  <th scope="col" abbr="Module Name">Module Name</th>
  <th scope="col" abbr="CW">Coursework Mark</th>
  <th scope="col" abbr="CW_W">Coursework Weightage</th>
  <th scope="col" abbr="Final">Final Exam</th>
  <th scope="col" abbr="Total">Total</th>
</tr>
';

foreach($modules as $module_code)
{

echo'

  <tr>
  <th scope="row" class="spec">'.$module_code.'</th>
  <td>'.module_name($module_code).'</td>
  <td>';
  for($i=1;$i<=num_courseworks($module_code);$i++)
  {
  $cw_mark = cw_mark($student_id,$module_code,$i);
  	$cw_total = cw_total($module_code,$i);
  	echo '';
  	if(!empty($cw_mark))
  	{
  		echo "$cw_mark/$cw_total";
  //		$cw_perc = ($cw_mark/$cw_total)*100;
  	//	echo ",$cw_perc%";
  		
  		  	
  	}
  	else
  	{
  		echo "N/A";  	
  	}
  	echo '';
  	
  	if(($i!=num_courseworks($module_code)))
  	echo ',';
  	else echo '&nbsp';
  	
  }
  
  echo'</td>';
  
  echo '<td>';
  for($i=1;$i<=num_courseworks($module_code);$i++)
  {
   
   echo (cw_weightage($module_code,$i)*100).'%';
  
  
  if(($i!=num_courseworks($module_code)))
  	echo ',';
  	else echo '&nbsp';
  	
  }
  
  
  echo '</td>';
  
  
  
  
  
  
  
  echo '<td>';
   echo $b = exam_mark($student_id,$module_code);
   if(empty($b))
   echo '';
  echo'</td>
  
  <td>';
  echo $c = total_marks($student_id,$module_code);
  if(empty($c))
   echo '';
  
  echo '</td>
</tr>	

';

}

}
echo'	</table><br>';
if(isset($_POST['show_sem1']))
{
	echo '
	<form method="POST" action="st_home.php"
	<input type="submit" value="Back">
	</form>
	
	';
	
}

?>







	</div>
	<!-- end content -->
