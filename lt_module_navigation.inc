<!--Module Navigation-->
<div class="big_wrapper">
<h1 class="sideh1">Modules</h1>
<hr/>



<?php
@session_start();

db_connect();
$lecturer_id = $_SESSION['valid_user'];
$modules = modules_teach_sem($lecturer_id,1);

echo'<h3 class="sideh3">'.year().' - SEMESTER 1</h3>

';


foreach($modules as $mod)
{

	
echo'
<form method ="POST" action ="lt_modules.php">
	<a class="mdl_link" href="#" onclick="parentNode.submit()">
<!--Pull lecturer module code here-->
'.$mod.'
</a>
<input type="hidden" name ="module_code" value ="'.$mod.'">
</form>
';
	
}

if(semester()==2)
{
	
	$modules = modules_teach_sem($lecturer_id,2);

echo'<h3 class="sideh3">'.year().' - SEMESTER 2</h3>

';


foreach($modules as $mod)
{

	
echo'
<form method ="POST" action ="lt_modules.php">
	<a class="mdl_link" href="#" onclick="parentNode.submit()">
<!--Pull lecturer module code here-->
'.$mod.'
</a>
<input type="hidden" name ="module_code" value ="'.$mod.'">
</form>
';
	
}
	
	
}



if(is_exam_officer($lecturer_id))
{
	

	echo '	
	 <h3 class="sideh3">Other Modules:</h3>

	
'

	;

$modules = all_modules();

foreach($modules as $mod)
{

echo'
<form method ="POST" action ="lt_modules.php">
	<a class="mdl_link" href="#" onclick="parentNode.submit()">
<!--Pull lecturer module code here-->
'.$mod.'
</a>
<input type="hidden" name ="module_code" value ="'.$mod.'">
</form>
';
	
}

}
?>
<h3 class="sideh3">Tutees</h3>
<form method="POST" action="lt_modules.php" >
<a class="mdl_link" href="#" onclick="parentNode.submit()">
<!--Pull student code here-->
View Tutees</a>
<input type="hidden" name="tutees"> 
</form>
</div>
<!--end Module Navigation-->