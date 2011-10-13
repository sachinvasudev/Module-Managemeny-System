<?php
$module_code = $_POST['courseworks'];

if(isset($_POST['cw_no']))
{




for($i=0;$i<=count($_POST['cw_no'])-1;$i++)
{
$cw_no = $_POST['cw_no'][$i];
$weightage = $_POST['weightage'][$i];
$weightage /= 100;


$total_marks = $_POST['total_marks'][$i];
add_cw($module_code,$cw_no,$weightage,$total_marks);


	
}
	
	
echo'<form method="POST" action="lt_modules.php" name="myform" id="myform">
<input type="hidden" name="courseworks" value="'.$module_code.'">

</form>
<script type=\'text/javascript\'>document.myform.submit();</script>


';


}



?>




<!--Task Navigation-->
<!--Module Detail -->
<div class="big_wrapper_side">
<h1 class="sideh1"><?php echo $module_code.' - '.module_name($module_code);?></h1>
<hr/>

<h2>Coursework and Assessments</h2><br><br>

<form method="POST" action="lt_modules.php">
How many courseworks you want to add? 
<input type="text" name="numberof">
<input name="add" type="submit" value="Update table">
<input type="hidden" name="courseworks" value="<?php echo $module_code;?>">
</form>
</h3>
<table width="1020px" cellspacing="0" summary="Studentadd">
  <tr>
  <th scope="col" abbr="Name" class="nobg">Coursework No.</th>
  <th scope="col" abbr="ID">Weightage(%)</th>
  <th scope="col" abbr="LID">Total Marks</th>
  </tr>

  
  <?php
  $numberof = @$_POST['numberof'];
  $num_cw = num_courseworks($module_code);

  
  echo'<form method="POST" action="lt_modules.php">
  ';
  for($i=1;$i<=$numberof;$i++)
  {
echo'  <tr>
    <th scope="row" class="spec"><input type="text" name="cw_no[]" value="'.($num_cw+$i).'" size="15" readonly="readonly"></th>
    <td><input type="text" name="weightage[]" value="" size="8"></td>
    <td><input type="text" name="total_marks[]" value="" size="10"></td>
    
  </tr>';
  }
  
?>


 
</table><br>
<p class="paraleft"><input name="add" type="submit" value="Confirm"></p>



<input type="hidden" name="courseworks" value="<?php echo $module_code;?>">

</form>

   <form method="POST" action="lt_modules.php">
   <input name="cancel" type="submit" value="Back">
   <input type="hidden" name="courseworks" value="<?php echo $module_code;?>">

   
   </form>
   
 
</div>
<!--end Task Detail -->



