


<?php






$lecturer_id = $_SESSION['valid_user'];
$module_code = $_POST['module_code'];
if(!is_exam_officer($lecturer_id))
{
if(!verify_module($module_code,$lecturer_id))
{
	echo'<center><h1>You are not authorized to view this module';
	exit;
}
}


?>

<!--Module Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1"><?php echo $module_code.' - '.module_name($module_code);?></h1>
<hr/>
<table width="1000" cellspacing="0" summary="Modulemark">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Name</th>
  <?php
  for($i=1;$i<=num_courseworks($module_code);$i++)
  {
  	  echo' <th scope="col" abbr="CW'.$i.'">CW'.$i.'('.(cw_weightage($module_code,$i)*100).'%)</th>
		';
  }
  
  ?>
  
    
  <th scope="col" abbr="EXAM">Exam(<?php echo exam_weightage($module_code)*100;?>%)</th>
  <th scope="col" abbr="Overall">Overall</th>
  </tr>
  <form method="POST" action="lt_modules.php">
  <?php
  $students = students_taken($module_code);
  $count=1;
  
  foreach($students as $stu)
  {
  	$count_this = $count;
  	
   echo ' <tr>
    <th scope="row" class="spec">'.get_name($stu,'student').'</th>';
    for($i=1;$i<=num_courseworks($module_code);$i++)
  {
  	$count++;	
  		
  	 echo' <td><input type="text" id="'.$count.'" onchange="showTotal(\''.$count_this.'\')"  name="cw'.$i.'[]" value="'.cw_mark($stu,$module_code,$i).'" size="2"></td>
	    ';
  	 
	 
  }
    $count++;
    echo'<td><input type="text" id="'.$count.'"  name="exam_mark[]" onchange="showTotal(\''.$count_this.'\')"  value="'.exam_mark($stu,$module_code).'" size="2"></td>
    <td><input type="text" id="'.++$count.'" name="mark1" value="'.total_marks($stu,$module_code).'" readonly="readonly" size="2"></td>
    <input type ="hidden" name ="module_code" value = "'.$module_code.'"
	</tr>
	
	
	';
	   
	   $count++; 
  }
  
  ?>
  
  
</table>
<br><br><br>
<!--Please make below auto calculated-->
<table width="250" cellspacing="0" summary="General">
  <tr>
    <th>Average</th>
    <th>Maximum</th>
    <th>Minimum</th>
  </tr>
  <tr>
    <?php
	echo
	'<td>'.round(average($module_code)).'</td>
    <td>'.round(maximum($module_code)).'</td>
    <td>'.round(minimum($module_code)).'</td>
    
    ';
    ?>
  </tr>
</table><br />
<hr/>
<p class="paraleft1"><input name="Submit" type="submit" value="Submit"><p>
</form>
<form method="POST" action="lt_modules.php">
<p class="paraleft1"><input type="submit" value="Back" ></p>
<input type="hidden" name ="module_code" value ="<?php echo $module_code; ?>">
</form>



</div>
<!--end Module Detail -->





<script type="text/javascript">
	 
	 
	 	 
function isnum(s) 
{
return (s.toString().search(/^[0-9]+$/) == 0);
//s= s.toString();

}

	 
	 
	 
	 
	 
	 
	 
	 
	 
	 function showTotal(x)
	 {
	 	
	 	var exam_weightage = <?php echo exam_weightage($module_code);?>;
	 	var exam_total = <?php echo exam_total_marks($module_code);?>;
	 	var cw_weightages = [];
	 	var cw_totals =[];
	 	
 	    cw_weightages[0] =1;
	 	<?php
	 	echo 'var num_courseworks = '.num_courseworks($module_code).';
		 ';
	 	for($i=1;$i<=num_courseworks($module_code);$i++)
  {
    echo 'cw_weightages['.$i.'] ='.cw_weightage($module_code,$i).';
         cw_totals['.$i.'] ='.cw_total($module_code,$i).';
	';
  }
  
  	
	 	
	 	
	 	?>
	 	x=parseInt(x);
	 	var total=0;
	 	var mark = 0;
	 	
	 	var till = x+num_courseworks;
	 
	 
	 	var cw_no=1;
		 for(var i=x+1;i<=till;i++)
	 	{
	 		mark = document.getElementById(i).value;
	 		if(isnum(mark))
	 		{
 		   mark = parseInt(mark);
 		   	if(mark>cw_totals[cw_no])
	 	{
	 		alert('Coursework mark entered exceeds the total marks allocated for this coursework');
			 exit;	 	
	 	}
	 			
	 		total = total+ (mark*cw_weightages[cw_no])
	 		}
	 		cw_no++
	 	}
	 	 
	 	mark =document.getElementById(till+1).value;
		if(isnum(mark))
	 		{
	 	mark = parseInt(mark);
	 	if(mark>exam_total)
	 	{
	 		alert('Exam mark entered exceeds the total exam marks allocated for this module');
			 exit;	 	
	 	}
	 	total = total + ((mark/exam_total)*100*exam_weightage);
	 	}
		 
	 	document.getElementById(till+2).value=total;
		 	 
	 }
	 
	 function update_average()
	 {
	 	var num_students = <?php echo count(students_taken($module_code));?>;
	 	var num_courseworks = <?php echo num_courseworks($module_code);?>;
	 
	 	
		 	 
	 }

	 
	  </script>







