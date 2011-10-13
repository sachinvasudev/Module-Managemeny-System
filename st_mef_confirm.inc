
<div id="wrapper">
<!-- start page -->
<div id="page">
	<!-- start content -->
	<div id="section">
	<img src="./images/MEF.png" alt="MEF"/>
	</div>
	<div id="content">
		<h1 class="title" align="center">Please confirm the modules you have taken</h1>
	<table id="table" cellspacing="0" summary="MEF form">
<caption class="caption2"><a href="logout.php">Log out</a></caption>
<tr>
  <th scope="col" abbr="Module Code" class="nobg">Module Code</th>
  <th scope="col" abbr="Module Name">Module Name</th>
  <th scope="col" abbr="Status">Status</th>
  <th scope="col" abbr="Credits">Credits</th>
  
</tr>
<?php


$student_id = $_SESSION['valid_user'];
$course_code = course_code($student_id);
$year = year_studying($student_id);
$modules  = $_POST["modules_selected"];	

echo '<form method ="POST" action ="st_home.php" name="mef_confirm">';
$total =0;
foreach($modules as $module_code)
{
$module_credit =  module_credits($module_code);
if($module_credit>10)
$module_credit = $module_credit/2;
echo'

  <tr>
  <th scope="row" class="spec">'.$module_code.'</th>
  <td>'.module_name($module_code).'</td>
  <td>';
  if(optional($module_code,$course_code,$year,semester()))
  echo 'Optional';
  else
  echo 'Compulsory';
  
  echo'</td>
  <td>'.$module_credit.'</td>
  
</tr>	
<input type ="hidden" name ="modules_confirm[]" value ="'.$module_code.'"

';


$total = $total + $module_credit;

}

?>

</table><br />
<table id="table" cellspacing="20" summary="total">
<tr>	
  <th class="specalt">Total Credits:</th>
  <td class="alt" align="right"><?php echo $total; ?></td>
</tr>
	</table><br/>
	<a class="button"  href="st_home.php"><span>Cancel</span></a>
	<a class="button" onclick="document.mef_confirm.submit()" href="#"><span>Confirm</span></a>
	
</form>




</div>
	<!-- end content -->