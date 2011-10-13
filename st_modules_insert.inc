<?php


db_connect();
@session_start();
$student_id = $_SESSION['valid_user'];
$modules_selected = $_POST["modules_confirm"];

foreach($modules_selected as $mod)
{
	take_module($student_id,$mod);
	
}


mef_submitted($student_id,semester(),true);


echo'
<br><br><br>
<center><h1> MEF submitted successfully</h1>
<meta http-equiv="Refresh" content="2;
URL=st_home.php">
';


exit;
?>

