<?php
$module_code = $_POST['courseworks'];

if(isset($_POST['edit_courseworks']))
{

$exam_mark_total = $_POST['exam_total_mark'];
$exam_weightage = $_POST['exam_weightage'];
$exam_weightage /=100;
set_module_total_marks($module_code,$exam_mark_total);	
set_module_exam_weightage($module_code,$exam_weightage);

for($i=0;$i<num_courseworks($module_code);$i++)
{
$weightage = 	$_POST['weightage'][$i];
$weightage /=100;
$cw_total= $_POST['cw_total'][$i];


edit_cw($module_code,$i+1,$weightage,$cw_total);

echo'<form method="POST" action="lt_modules.php" name="myform" id="myform">
<input type="hidden" name="courseworks" value="'.$module_code.'">

</form>
<script type=\'text/javascript\'>document.myform.submit();</script>


';

	
}


}

?>


<!--Module Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1"><?php echo $module_code.' - '.module_name($module_code);?></h1>
<hr/>

<h2>Coursework and Assessments</h2><br><br>


<table width="1020px" cellspacing="0" summary="Coursework">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Name</th>
  <th scope="col" abbr="Pcen">Weightage %</th>
  <th scope="col" abbr="Markall">Marks Allocated</th>

  </tr>
  <form method="POST" action="lt_modules.php">
  <?php
  $total=0;
   for($i=1;$i<=num_courseworks($module_code);$i++)
   
   {
   	  echo'<tr>
    <th scope="row" class="spec">Coursework '.$i.'</th>
    <td><input type="text" name="weightage[]" value="'.(cw_weightage($module_code,$i)*100).'"></td>
    <td><input type="text" name="cw_total[]" value="'.cw_total($module_code,$i).'"></td>
    
  
  </tr>';
 
    $total = $total+ cw_weightage($module_code,$i);
   	   
   }
   
   echo' <tr>
    <th scope="row" class="spec">Final Exam</th>
<td><input type="text" name="exam_weightage" value="'.(exam_weightage($module_code)*100).'"></td>
     <td><input type="text" name="exam_total_mark" value="'.exam_total_marks($module_code).'"></td>

  </tr>
     </table>
	 <br />
	 <br />
	 ';
     
     $total = $total+exam_weightage($module_code);
     
     echo'
	 
	 <table cellspacing="0" summary="total">
  <tr>
    <th>Total Percentage</th>
  </tr>
  <tr>
    <td>'.($total*100).'</td>
  </tr>
</table>';

if(($total*100)<100)
echo'<br>
<font color="red">Total is not equal to 100%</font>
';

if(($total*100)>100)
echo'<br>
<font color="red">Total is over 100%</font>
';

echo'
<br><br>
<input name="edit" type="submit" value="Update">
<input type="hidden" name="courseworks" value="'.$module_code.'">

<input type="hidden" name= "edit_courseworks" value="">




</form>
	<br />
 
 
	 ';
     
         
     
   ?>
   <form method="POST" action="lt_modules.php">
   <br /><input name="cancel" type="submit" value="Back">
   <input type="hidden" name="courseworks" value="<?php echo $module_code;?>">

   
   </form>
   
 
  