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
<h3 class="h3body"><?php echo year().' - SEMESTER '.semester();?></h3>

<form method="POST" action="lt_modules.php">
<input type="hidden" name="edit_marks">
<input type="hidden" name="module_code" value="<?php echo $module_code;?>"
<p class="pararight"><input name="entermark" type="submit" value="Enter Marks"/></p>
</form>


<table width="1020px" cellspacing="0" summary="Modulemark">
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
  
  <?php
  
  $students = students_taken($module_code);
 
  foreach($students as $stu)
  {
   echo ' <tr>
    <th scope="row" class="spec">'.get_name($stu,'student').'</th>';
    for($i=1;$i<=num_courseworks($module_code);$i++)
  {
  	 echo' <td>'.cw_mark($stu,$module_code,$i).'</td>
	    ';
  	 
	 
  }
    echo'<td>'.exam_mark($stu,$module_code).'</td>
    <td>';
    if($x=total_marks($stu,$module_code))		
	echo round($x);
	
	'</td>
   
	</tr>
	
	
	';
	    
  }
  
  ?>
  
  
</table>
<form method="POST" action="lt_modules.php">
<input type="hidden" name="edit_marks">
<input type="hidden" name="module_code" value="<?php echo $module_code;?>"
<p class="pararight"><input name="entermark" type="submit" value="Enter Marks"></p>
</form>

<br><br><br>

<h3 class="h3body2">STATISTICS</h3>

<table width="1020px" cellspacing="0" summary="tier">
  <tr>
    <th>No. student - % First Class</th>
    <th>No. - % Second Upper</th>
    <th>No. - % Second Lower</th>
    <th>No. - % third class</th>
    <th>No. - % fail</th>
    <th>Total</th>
  </tr>
  <tr>
  <?php
  $no_students = count(students_taken($module_code));
  
  $first_class = no_student_above_mark($module_code,69.50,100);
 $second_upper = no_student_above_mark($module_code,59.50,69.49);
 $second_lower = no_student_above_mark($module_code,49.50,59.49);
  $third_class = no_student_above_mark($module_code,39.50,49.49);
   $fail = no_student_above_mark($module_code,0,39.49);
  
  if($no_students>0)
  echo'
  
    <td>'.$first_class.' - '.round((($first_class/$no_students)*100)).'%</td>
 <td>'.$second_upper.' - '.round((($second_upper/$no_students)*100)).'%</td>
  <td>'.$second_lower.' - '.round((($second_lower/$no_students)*100)).'%</td>
   <td>'.$third_class.' - '.round((($third_class/$no_students)*100)).'%</td>
    <td>'.$fail.' - '.round((($fail/$no_students)*100)).'%</td>
    <td>'.$no_students.'</td>
    
    ';
    ?>
  </tr>
</table><br><br>

<!--Please make below auto calculated-->
<table  cellspacing="0" summary="General">
  <tr>
    <th>Average Overall</th>
    <th>Maximum Overall</th>
    <th>Minimum Overall</th>
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
</table>

<br>
<h3 class="h3body2">GRAPH</h3><br>

<?php
 // Standard inclusions   
  include("pChart/pData.class");
  include("pChart/pChart.class");

  // Dataset definition 
  $DataSet = new pData;
  
  $fail+=.15;
  
  $third_class+=.15;
  
  $second_lower+=.15;

  $second_upper+=.15;

  $first_class+=.15;
  
  
  $DataSet->AddPoint(array($fail,$third_class,$second_lower,$second_upper,$first_class),"");
 
  
  
       $DataSet->AddPoint("FL(0%-39%)","XLabel");   
         $DataSet->AddPoint("3rd (40%-49%)","XLabel");  
    $DataSet->AddPoint("2.2(50%-59%)","XLabel");  
    $DataSet->AddPoint("2.1(60%-69%)","XLabel");   
        $DataSet->AddPoint("1st(>70%)","XLabel"); 

  $DataSet->AddAllSeries();
  $DataSet->SetAbsciseLabelSerie("XLabel");


  // Initialise the graph
  $Test = new pChart(700,230);
  if($no_students<1) $no_students=1;
  $Test->setFixedScale(0,$no_students,$no_students);
  $Test->setFontProperties("Fonts/tahoma.ttf",8);
  $Test->setGraphArea(50,30,585,200);
  $Test->drawFilledRoundedRectangle(7,7,693,223,5,240,240,240);
  $Test->drawRoundedRectangle(5,5,695,225,5,230,230,230);
  $Test->drawGraphArea(255,255,255,TRUE);	
  $Test->drawScale($DataSet->GetData(),$DataSet->GetDataDescription(),SCALE_NORMAL,150,150,150,TRUE,0,2);   
  $Test->drawGrid(4,TRUE,230,230,230,50);
$Test->setColorPalette(0,255,0,0);
  // Draw the 0 line
  $Test->setFontProperties("Fonts/tahoma.ttf",6);
  $Test->drawTreshold(0,143,55,72,TRUE,TRUE);

  // Draw the cubic curve graph
  $Test->drawCubicCurve($DataSet->GetData(),$DataSet->GetDataDescription(),.1);

  // Finish the graph	
  $Test->setFontProperties("Fonts/tahoma.ttf",8);
 // $Test->drawLegend(600,100,$DataSet->GetDataDescription("XLabel"),255,255,255);
  $Test->setFontProperties("Fonts/tahoma.ttf",10);
  $Test->drawTitle(50,22,"Result Analysis",50,50,50,585);
  $Test->Render("graph.png");

?>
<img src="graph.png">
<hr/>
<form method="POST" action="attendance_report.php" target="_blank">


<input type="hidden" name ="module_code" value ="<?php echo $module_code; ?>">

<input type="submit" name="report" value="Generate Report">
<input type="submit" name="attendance" value="Generate Attendance Sheet">

</form>

<form method="POST" action="lt_modules.php">
<br />
<input type="submit" value="Courseworks & Assessments">
<input type="hidden" name="courseworks"  value ="<?php echo $module_code; ?>">



</form>


	<p><select size="1" name="D1"><option>2005 - Semester 2</option><option>2006 - Semester 2</option><option>2007 - Semester 2</option><option>2008 - Semester 2</option></select>
	<input type="submit" onclick="javascript:alert('No data for selected year, try later in 1 year later :D ');" value="View this module's year" name="B1"></p>





</div>
<!--end Module Detail -->