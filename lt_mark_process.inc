<?php


$module_code = $_POST['module_code'];

$exam_marks = $_POST['exam_mark'];
$students = students_taken($module_code);
 

for($i=1;$i<=num_courseworks($module_code);$i++)
	
{
	
	${"cw{$i}"} = $_POST["cw{$i}"];
	
		
}

$j=0;

 foreach($students as $stu)
  {
   
   for($i=1;$i<=num_courseworks($module_code);$i++)
   {
   	$cw_mark = ${"cw{$i}"}[$j];
   	set_cw_mark($stu,$module_code,$i,$cw_mark);
  	
	  	      
   }
   $exam_mark = $exam_marks[$j];
 
   set_exam_mark($stu,$module_code,$exam_mark);



$j++;
  }





//include('lt_module_detail.inc');



?>