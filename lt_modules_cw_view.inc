<?php
$module_code = $_POST['courseworks'];

if(isset($_POST['delete_cw']))
{
 foreach($_POST['delete_cw'] as $del_cw)
 {
 	delete_cw($module_code,$del_cw);	  
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
  <th scope="col" abbr="del">Delete</th>
  </tr>
  <form method="POST" action="lt_modules.php">
  <?php
  $total=0;
   for($i=1;$i<=num_courseworks($module_code);$i++)
   
   {
   	  echo'<tr>
    <th scope="row" class="spec">Coursework '.$i.'</th>
    <td>'.(cw_weightage($module_code,$i)*100).'</td>
    <td>'.cw_total($module_code,$i).'</td>
    <td><input type="checkbox" name="delete_cw[]" value="'.$i.'"></td>
  </tr>';
 
    $total = $total+ cw_weightage($module_code,$i);
   	   
   }
   
   echo' <tr>
    <th scope="row" class="spec">Final Exam</th>
    <td>'.(exam_weightage($module_code)*100).'</td>
    <td>'.exam_total_marks($module_code).'</td>
    <td><input type="checkbox" disabled="disabled" name="b3" value="b3"></td>
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
<br><br><input name="edit" type="submit" value="Edit Current Assessments">
<input name="add" type="submit" value="Add Assessments">
<input name="delete" type="submit" value="Delete Checked Assessments" onclick="return confirm(\'Really delete selected courseworks\')" ><br><br>
<input type="hidden" name="courseworks" value="'.$module_code.'">


</form>
	 
 
	 ';
     
         
     
   ?>
   <form method="POST" action="lt_modules.php">
   <input name="cancel" type="submit" value="Back">
   <input type="hidden" name="module_code" value="<?php echo $module_code;?>">
   
   </form>
   
 
  