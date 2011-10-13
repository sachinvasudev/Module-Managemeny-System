<?php


function get_name($userid,$type)
{
	if($type=='student')
	{
		$query = "select student_givenname 
		from students
		where 
		student_id ='$userid'";
		
				
	}
	if($type=='lecturer')
	{
			$query = "select lecturer_name 
		from lecturers
		where 
		lecturer_id ='$userid'";
	}
	
	$result = mysql_query($query);
	return  mysql_result($result,0,0);
	
	
	
	
}

function get_rollno($studentid)
{
	$query = "select roll_no
from students
where student_id = '$studentid'
";

$result = mysql_query($query);
	return  mysql_result($result,0,0);
		
}


function get_course_code($studentid)
{
	$query = "select course_code
	from students
	where student_id = '$studentid'
	";
	$result = mysql_query($query);
	return  mysql_result($result,0,0);
}


function delete_student($studentid)
{
$query="	delete
from students
where student_id='$studentid'";

mysql_query($query);


$query ="delete from
takes
where student_id ='$studentid'";

mysql_query($query);


$query ="delete from courseworks
where student_id='$studentid'";

mysql_query($query);

	
	
}




function add_student($stu_login,$stu_id,$name,$course,$year,$tutor)
{
	
		$query = "
	INSERT INTO students
(student_id,roll_no,student_givenname,course_code,year,tutor_id)
values
('$stu_login',$stu_id,'$name','$course',$year,'$tutor')
	
	";
	mysql_query($query);
	
	
}

function stu_temp_password($studentid)
{
	$password = md5($studentid);
	$query = "update students
	set password ='$password'
	where student_id='$studentid'
	";
	mysql_query($query);
	
}

function add_lecturer($lec_login,$name)
{
	$query = "INSERT INTO lecturers

(lecturer_id,lecturer_name)
VALUES
('$lec_login','$name')";

mysql_query($query);


	
}

function lec_tem_password($lecturerid)
{
	$password = md5($lecturerid);
	$query = "
	update lecturers
	set password='$password'
	where lecturer_id='$lecturerid'
	
	";
	mysql_query($query);
}



function delete_lecturer($lecturerid)
{
	$query ="DELETE
FROM lecturers
where lecturer_id = '$lecturerid'

";

mysql_query($query);
	
}

function add_module($module_code,$module_name,$credits,$weightage,$convenor)
{
	
			$query_add_module = "INSERT INTO modules
		 set module_code ='$module_code',
		  module_name ='$module_name',
		  credits =$credits,
		   FinalExam_Weightage=$weightage 
";


mysql_query($query_add_module);

$query_add_module_convenor = "insert into teaches
set lecturer_id='$convenor',
module_code ='$module_code'

";
mysql_query($query_add_module_convenor);
	
}

function exam_total_marks($modulecode)
{
	$query="select total_marks
from modules
where module_code='$modulecode'";

$result = mysql_query($query);
	return  mysql_result($result,0,0);
	
	
	
}


function delete_module($modulecode)
{
	$query = "delete
from modules
where module_code ='$modulecode'
";
mysql_query($query);


	$query = "delete
from courses_and_modules
where module_code='$modulecode'
";
mysql_query($query);

	$query = "delete from courseworks
where module_code='$modulecode'
";
mysql_query($query);


	$query = "delete from courseworks_weightage
where module_code='$modulecode'
";
mysql_query($query);

	$query = "delete from teaches
where module_code='$modulecode'
";
mysql_query($query);



	
}

function add_course($courseid,$coursename)
{
	$query ="
	insert into courses
set course_code='$courseid',
course_name= '$coursename'";

	mysql_query($query);
}

function add_module_course($courseid,$moduleid,$semester,$year,$optional)
{
	
	if($semester==1)
	{
	
	$query = "INSERT INTO courses_and_modules
set course_code='$courseid',
module_code='$moduleid',
year='$year',
`Optional?`=$optional,
`InSemester1?`=1

on duplicate key update
course_code='$courseid',
module_code='$moduleid',
year='$year',
`Optional?`=$optional,
`InSemester1?`=1
";
}

	if($semester==2)
	{
	
	$query = "INSERT INTO courses_and_modules
set course_code='$courseid',
module_code='$moduleid',
year='$year',
`Optional?`=$optional,
`InSemester2?`=1

on duplicate key update
course_code='$courseid',
module_code='$moduleid',
year='$year',
`Optional?`=$optional,
`InSemester2?`=1
";
}


mysql_query($query);




	
	
}


function delete_module_course($modulecode,$coursecode,$year,$semester)

{
	
	if($semester==1)
	{
	
	$query ="
delete 
from courses_and_modules
where course_code='$coursecode'
and module_code='$modulecode'
AND year='$year'
AND `InSemester1?`=1";

}

	
	if($semester==2)
	{
	$query ="
delete 
from courses_and_modules
where course_code='$coursecode'
and module_code='$modulecode'
AND year='$year'
AND `InSemester2?`=1";
	
	
}

mysql_query($query);

}





function is_active_lecturer($lecturerid)
{
$result = count(modules_teach($lecturerid));

if($result>0)
return true;
else
return false;
	
}

function is_active_module($modulecode)
{
$result = 	count(students_taken($modulecode));
if($result>0)
return true;
else
return false;
	
	
}

function is_active_course($coursecode)
{
	$result = 	count(students_taken_course($coursecode));
if($result>0)
return true;
else
return false;
	
}

function course_name($coursecode)
{
	$query = "select course_name
from courses
where course_code ='$coursecode'
";

$result = mysql_query($query);
	return  mysql_result($result,0,0);
	
}

function semester()
{
	$query = "select semester
from universal";

$result = mysql_query($query);
return  mysql_result($result,0,0);

}

function year()
{
	
	$query = "select year
	from universal";
	
	$result = mysql_query($query);
return  mysql_result($result,0,0);

}

function students_taken_course($coursecode)
{
	$query = "select student_id
from students
where course_code ='$coursecode'

";


$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['student_id'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;
	
}

function mef_status($studentid,$semester)
{
if($semester==1)
{
	$query = "select `Completed_Sem1_MEF`
from students
where `Student_ID` ='$studentid' ";

}

if($semester==2)
{
	$query = "select `Completed_Sem2_MEF`
from students
where `Student_ID` ='$studentid' ";

}
$result = mysql_query($query);
$result = mysql_result($result,0,0);

if($result==1)
return true;
else
return false;
	
}

function get_tutor($studentid)
{
	$query = "select tutor_id
from students
where student_id='$studentid'
";

$result = mysql_query($query);
return mysql_result($result,0,0);
}




function modules_teach($lecturerid)
{
	$query = "select module_code
from teaches
where lecturer_id = '$lecturerid'";

mysql_query($query);

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}

 if(empty($modules))
  {
  $modules = array();
  }

return $modules;

}

function modules_teach_sem($lecturerid,$sem)
{
	
	
	
	if($sem==1)
	{
		$query = "
		select distinct(teaches.module_code)
from teaches,courses_and_modules

where teaches.lecturer_id = '$lecturerid'

and `InSemester1?` = 1
and teaches.module_code = courses_and_modules.module_code
		
		
		";	
	}
	
		
	if($sem==2)
	{
		$query = "
		select distinct(teaches.module_code)
from teaches,courses_and_modules

where teaches.lecturer_id = '$lecturerid'

and `InSemester2?` = 1
and teaches.module_code = courses_and_modules.module_code
		
		
		";	
	}
	

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}

if(empty($modules))
  {
  $modules = array();
  }

return $modules;
	
	
}

function modules_taken($studentid)
{
		$query = "select module_code
from takes
where student_id = '$studentid'";



$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}

if(empty($modules))
  {
  $modules = array();
  }

return $modules;

	
}

function students_taken($modulecode)
{
	
	$query = "
select takes.student_id
from takes,students
where module_code ='$modulecode'
and students.student_id  = takes.student_id
order by student_givenname

	";
	


$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['student_id'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;
	
}

function all_students()
{
	$query = "select student_id 
from students
order by `Student_Givenname`
";

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['student_id'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;
	
}




function all_courses()
{
	$query = "
	select course_code from 
courses
	";
	
	$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$courses[] =  $row['course_code'];
}
 if(empty($courses))
  {
  $courses = array();
  }
return $courses;
	
}

function all_modules()
{
	$query = "
	select module_code
from modules
order by module_name
	";
	
	$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}
 if(empty($modules))
  {
  $modules = array();
  }
return $modules;
	
	
}


function all_lecturers()
{
	$query = "select lecturer_id 
from lecturers
order by `lecturer_name`
";

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['lecturer_id'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;
	
}


function modules_taken_sem($studentid,$semester,$year)
{
	if($semester==1)
		$query = "select takes.module_code
from takes,courses_and_modules

where `InSemester1?` = '1'
and year = '$year'
and takes.module_code = courses_and_modules.module_code
and takes.student_id ='$studentid'
order by `Optional?`";

	if($semester==2)
		$query = "select takes.module_code
from takes,courses_and_modules

where `InSemester2?` = '1'
and year = '$year'
and takes.module_code = courses_and_modules.module_code
and takes.student_id ='$studentid'
order by `Optional?`";


mysql_query($query);

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}

if(empty($modules))
  {
  $modules = array();
  }

return $modules;

	
}



function modules_taken_year($studentid,$year)
{

		$query = "select takes.module_code
from takes,courses_and_modules


where year = '$year'
and takes.module_code = courses_and_modules.module_code
and takes.student_id ='$studentid'
order by `InSemester1?` desc,'Optional?' desc
";




mysql_query($query);

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}

if(empty($modules))
  {
  $modules = array();
  }

return $modules;

	
}



function modules_available($semester,$coursecode,$year)
{
	if($semester==1)
		$query = "select module_code
from courses_and_modules
where course_code = '$coursecode'
and `InSemester1?` = '1'
and year = '$year'
order by `Optional?`";

if($semester==2)
		$query = "select module_code
from courses_and_modules
where course_code = '$coursecode'
and `InSemester2?` = '1'
and year = '$year'
order by `Optional?`";




$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}


if(empty($modules))
  {
  $modules = array();
  }

return $modules;

	
}

function course_modules($coursecode)
{
	$query = "select module_code
from courses_and_modules
where course_code='$coursecode'";

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}


if(empty($modules))
  {
  $modules = array();
  }
  
return $modules;


	
}

function module_year_course($coursecode,$modulecode)
{
	$query = "select year
from courses_and_modules
where course_code='$coursecode'
and module_code ='$modulecode'";

	$result = mysql_query($query);
	return mysql_result($result,0,0);


	
}

function module_sem_course($coursecode,$modulecode)
{
	$sem1=0;
	$sem2=0;
	$query = "select count(*)
from courses_and_modules
where course_code ='$coursecode'
and module_code='$modulecode'
and `InSemester1?`=1
";

$result = mysql_query($query);
$sem1 =  mysql_result($result,0,0);

	$query = "select count(*)
from courses_and_modules
where course_code ='$coursecode'
and module_code='$modulecode'
and `InSemester2?`=1
";

$result = mysql_query($query);
$sem2=  mysql_result($result,0,0);

if($sem1==1  && $sem2==0)
{
	return 1;
}


if($sem1==0  && $sem2==1)
{
	return 2;
}

if($sem1==1  && $sem2==1)
{
	return "1 & 2";
}


	
	
	
}



function modules_available_not_taken($semester,$coursecode,$year,$student_id)
{
	
	$all_modules = modules_available($semester,$coursecode,$year);
	
	$modules_taken = modules_taken_sem($student_id,$semester,$year);
	
	foreach($all_modules as $all)
	{
		$count=0;
		foreach($modules_taken as $taken)
		{
			if($all==$taken)
			{
				$count++;
							
			}								
		}
		if($count==0)
		{
			$not_taken[]=$all;		
		}
			
	}
	
	if(empty($not_taken))
  {
  $not_taken = array();
  }
  
  return $not_taken;
	
	
}


function modules_available_not_taken_lecturer($lecturerid)
{
$all_modules = all_modules();
$modules_teach = modules_teach($lecturerid);


	foreach($all_modules as $all)
	{
		if(!is_module_taken($all))
        $not_taken[]=$all;
		
			
	}
	
	if(empty($not_taken))
  {
  $not_taken = array();
  }
  
  return $not_taken;




	
	
}

function is_module_taken($modulecode)
{
	
	$query = "select count(*)
from teaches where
module_code='$modulecode'";

	$result = mysql_query($query);
	$result =  mysql_result($result,0,0);
	
	if($result>0)
	return true;
	else
	return false;

}

function students_not_taken_module($modulecode)
{
   $all_students = all_students();
   $students_taken = students_taken($modulecode);
   
   
   
	foreach($all_students as $all)
	{
		$count=0;
		foreach($students_taken as $taken)
		{
			if($all==$taken)
			{
				$count++;
							
			}								
		}
		if($count==0)
		{
			$not_taken[]=$all;		
		}
			
	}
	
	if(empty($not_taken))
  {
  $not_taken = array();
  }
  
  return $not_taken;

   
   
   
   
	
}

function delete_student_module($studentid,$modulecode)
{
	
	$query = "delete
FROM TAKES
WHERE student_id='$studentid'
and module_code = '$modulecode'

";

mysql_query($query);

	$query = "delete
FROM courseworks
WHERE student_id='$studentid'
and module_code = '$modulecode'

";

mysql_query($query);



	
}

function delete_lecturer_module($lecturerid,$modulecode)
{
	$query = "delete from teaches
where lecturer_id='$lecturerid'
and module_code='$modulecode'";

mysql_query($query);
	
	
}


function edit_student($student_id,$name,$roll_no,$login_id,$course,$year,$tutor,$mef_status,$semester)
{

	if($semester==1)
	{
				
	
		$query = "
		
		UPDATE students
set student_givenname = '$name',
roll_no = '$roll_no',
course_code = '$course',
year = '$year',
tutor_id ='$tutor',
completed_sem1_mef=$mef_status
where student_id='$student_id'
		
		";	
	}
	
	
		if($semester==2)
	{
		$query = "
		
		UPDATE students
set student_givenname = '$name',
roll_no = '$roll_no',
course_code = '$course',
year = '$year',
tutor_id ='$tutor',
completed_sem2_mef=$mef_status

where student_id='$student_id'
		
		";	
	}
	
	mysql_query($query);
	
	if($student_id!=$login_id)
	{
	 $query = "update students
	 set student_id='$login_id'
	 where student_id='$student_id';
	 
	 ";
	 mysql_query($query);
	 
	 $query = "update takes
	 set student_id='$login_id'
	 where student_id='$student_id';
	 
	 ";
	 mysql_query($query);
	 
	 $query = "update courseworks
	 set student_id='$login_id'
	 where student_id='$student_id';
	 
	 ";
	 mysql_query($query);
			
	}
	
	
}


function edit_lecturer($lecturerid,$login_id,$name)
{
$query="	update lecturers
set lecturer_name='$name'
where lecturer_id='$lecturerid'
	";
	
mysql_query($query);


if($lecturerid!=$login_id)
	{
	 $query = "update lecturers
	 set lecturer_id='$login_id'
	 where lecturer_id='$lecturerid';
	 
	 ";
	 mysql_query($query);
	 
	 $query = "update teaches
	 set lecturer_id='$login_id'
	 where lecturer_id='$lecturerid';
	 
	 ";
	 mysql_query($query);
	 
	 $query = "update students
	 set tutor_id='$login_id'
	 where tutor_id='$lecturerid';
	 
	 ";
	 mysql_query($query);
	
			
	}

	
}

function  edit_module($name,$module_code_new,$module_code,$credits,$weightage,$lecturer)
{
	
	$query = "update modules
set module_name ='$name',
module_code='$module_code_new',
credits='$credits',
finalexam_weightage=$weightage
where module_code='$module_code'

";
mysql_query($query);

$query = "
UPDATE TAKES 
set module_code ='$module_code_new'
where module_code='$module_code'
";
mysql_query($query);

$query = "
update teaches
set module_code ='$module_code_new',
lecturer_id = '$lecturer'
where module_code='$module_code'
";

mysql_query($query) ;


$query = "
update courseworks_weightage
set module_code ='$module_code_new'
where module_code='$module_code'
";

mysql_query($query);

$query = "
update courseworks
set module_code ='$module_code_new'
where module_code='$module_code'
";

mysql_query($query);

	
$query = "
update courses_and_modules
set module_code ='$module_code_new'
where module_code='$module_code'
";

mysql_query($query);

	
	
}

function add_cw($modulecode,$cwno,$weightage,$total_marks)
{
	$query = "insert into courseworks_weightage

set module_code='$modulecode',
coursework_number=$cwno,
weightage=$weightage,
total=$total_marks

";

mysql_query($query);
	
	
}


function edit_cw($modulecode,$cwno,$weightage,$total_marks)
{
	$query = "update courseworks_weightage

set weightage=$weightage,
total=$total_marks
where module_code='$modulecode'
and coursework_number=$cwno";


mysql_query($query);

	
	
}



function delete_cw($modulecode,$cwno)
{
	$query = "delete
from courseworks_weightage
where module_code='$modulecode'
and coursework_number=$cwno
";

mysql_query($query);

$query = "delete from courseworks
where module_code-'$modulecode'
and coursework_number=$cwno
";

mysql_query($query);



}

function set_module_total_marks($modulecode,$mark)
{
	$query ="update modules
set total_marks=$mark
where module_code='$modulecode'";

mysql_query($query);

	
}

function set_module_exam_weightage($modulecode,$weightage)
{
	
		$query ="update modules
set FinalExam_Weightage=$weightage
where module_code='$modulecode'";

mysql_query($query);
}


function edit_course($coursecode,$coursecode_new,$coursename)
{
	$query = "update courses
set course_code='$coursecode_new',
course_name='$coursename'
where course_code='$coursecode'";

mysql_query($query);

$query = "update courses_and_modules
set course_code='$coursecode_new'
where course_code='$coursecode'";

mysql_query($query);
	
	
}





function module_name($modulecode)
{
	$query = "	
	select module_name from modules
	where module_code = '$modulecode'
	
	";
	
	$result = mysql_query($query);
	return mysql_result($result,0,0);
	
}

function module_credits($modulecode)
{
	$query = "
	select credits from modules
	where module_code = '$modulecode'
	
	";
		$result = mysql_query($query);
	return mysql_result($result,0,0);
	
}

function module_lecturer($modulecode)
{
	$query = "
select lecturer_id
from teaches
where module_code ='$modulecode'
	
	";
		$result = mysql_query($query);
	return mysql_result($result,0,0);
	
}

function course_code($studentid)
{
	$query = "select course_code
	from students 
	where student_id = '$studentid'
	";
	
	$result = mysql_query($query);
	return mysql_result($result,0,0);
	
}

function year_studying($studentid)
{
	$query = "select year
	from students 
	where student_id = '$studentid'
	";
	
	$result = mysql_query($query);
	return mysql_result($result,0,0);
	
}

function optional($modulecode,$coursecode,$year,$semester)
{
	if($semester==1)
	$query = "select `Optional?`
from courses_and_modules
where module_code ='$modulecode'
and year ='$year'
and course_code = '$coursecode'
and `InSemester1?` =1";
    if($semester==2)
    $query = "select `Optional?`
from courses_and_modules
where module_code ='$modulecode'
and year ='$year'
and course_code = '$coursecode'
and `InSemester2?` =1";
$result = mysql_query($query);
$result = mysql_result($result,0,0);
if($result==1)
return true;
if($result==0)
return false;

	
}

function exam_mark($studentid,$modulecode)
{
	$query = "
	select `FinalExam_Mark`
from takes
where `Student_ID` = '$studentid'
AND `Module_Code` = '$modulecode'
	";
	
$result = mysql_query($query);
	return mysql_result($result,0,0);
	
	
}

function exam_mark_perc($studentid,$modulecode)
{
if(exam_mark($studentid,$modulecode)!=NULL)	
return  (exam_mark($studentid,$modulecode)/exam_total_marks($modulecode) )*100;
else
return NULL;
}


function set_exam_mark($studentid,$modulecode,$mark)
{
	if(!($mark<0))
	{
	
	if($mark=="")
	{
		$query = "
	update takes
set finalexam_mark =NULL
where module_code ='$modulecode'
AND student_id = '$studentid'

	";
	}
	else
	$query = "
	update takes
set finalexam_mark = $mark
where module_code ='$modulecode'
AND student_id = '$studentid'

	";
	mysql_query($query);
	}
}


function num_courseworks($modulecode)
{
 $query = "
 select count(*) from
courseworks_weightage
where courseworks_weightage.module_code = '$modulecode'
 ";
 
 $result = mysql_query($query);
return mysql_result($result,0,0);
	
	
}


function cw_mark($studentid,$modulecode,$cwno)
{
	$query = "select coursework_mark
from courseworks
where student_id ='$studentid'
and module_code ='$modulecode'
and coursework_number ='$cwno'";

 $result = mysql_query($query);
$result = @mysql_result($result,0,0);
if($result==0)
return $result;

if(!$result)
return NULL;
else return $result;	
}

function cw_mark_perc($studentid,$modulecode,$cwno)
{
	return ( cw_mark($studentid,$modulecode,$cwno)/cw_total($modulecode,$cwno) *100 );
	
}

function cw_total($modulecode,$cwno)
{	
	
	$query = "
	select total 
from 
courseworks_weightage
where module_code ='$modulecode'
AND coursework_number=$cwno
	";
	
	 $result = mysql_query($query);
return @mysql_result($result,0,0);
}

function set_cw_mark($studentid,$modulecode,$cwno,$cwmark)
{
	if(!($cwmark<0))
	{
	if($cwmark=="")
	$query  = "
	insert into courseworks

set coursework_number ='$cwno',
module_code ='$modulecode',
student_id ='$studentid',
coursework_mark =NULL

on duplicate key update
coursework_number ='$cwno',
module_code ='$modulecode',
student_id ='$studentid',
coursework_mark = NULL
	
	";
	
	else
	$query  = "
	insert into courseworks

set coursework_number ='$cwno',
module_code ='$modulecode',
student_id ='$studentid',
coursework_mark ='$cwmark'

on duplicate key update
coursework_number ='$cwno',
module_code ='$modulecode',
student_id ='$studentid',
coursework_mark = '$cwmark'
	
	";
$query = mysql_query($query);
}
	
}


function cw_weightage($modulecode,$cwno)
{
	$query = "
	select weightage
from courseworks_weightage
where module_code ='$modulecode'
and coursework_number ='$cwno'
	
	";
	
 $result = mysql_query($query);
return @mysql_result($result,0,0);
	
}

function exam_weightage($modulecode)
{
	$query = "
	select finalexam_weightage
from modules
where module_code ='$modulecode'
	";
	$result = mysql_query($query);
return mysql_result($result,0,0);
}


function total_marks($studentid,$modulecode)
{
	if((exam_mark_perc($studentid,$modulecode)!==NULL)		)
	{

	
	$total =0;
	for($i=1;$i<=num_courseworks($modulecode);$i++)
	{
		
     $total = cw_weightage($modulecode,$i)*cw_mark_perc($studentid,$modulecode,$i)+$total;
			
	}
	
	$total = (exam_weightage($modulecode)*exam_mark_perc($studentid,$modulecode))+$total;
	
    return $total;
    	
    
    }
    
    else return NULL;
    
	

	
	
}

function year_average($studentid,$year)
{
	$modules = modules_taken_year($studentid,$year);
	
	$total=0;
	foreach($modules as $mod)
	{
		
		$total+= total_marks($studentid,$mod);
			
	}
     
	$num_modules= count(modules_taken_year($studentid,$year));
  
	$avg = ($total/$num_modules);
	return $avg;
	
	
}

function no_student_above_mark($module_code,$mark_above,$mark_below)
{
	$students = students_taken($module_code);
	$count =0;
	foreach($students as $stu)
	{
		$mark = total_marks($stu,$module_code);
		if($mark!=NULL)
		if( ($mark>=$mark_above) && ($mark<=$mark_below))
		{
			$count++;
			
					
		}
		
			
	}
	return $count;
	
	
}


function take_module($studentid,$modulecode)
{
	$query = "
	insert into takes(student_id,module_code) values
(
'$studentid','$modulecode'
)
	";
	
   mysql_query($query);
	
}

function take_module_lecturer($lecturerid,$modulecode)
{
	
		$query = "
	insert into teaches(lecturer_id,module_code) values
(
'$lecturerid','$modulecode'
)
	";
	
   mysql_query($query);
	
}

function mef_submitted($studentid,$semester,$value)
{
if($value)
$value = 1;
else
$value =0;	

if($semester==1)
$query = "
update students
set completed_sem1_mef = '$value'
where student_id = '$studentid'
";	
if($semester==2)
$query = "
update students
set completed_sem2_mef = '$value'
where student_id = '$studentid'
";	

mysql_query($query);
}

function verify_module($modulecode,$lecturerid)
{
$query = "
select count(*)
from teaches
where lecturer_id = '$lecturerid'
and module_code ='$modulecode'
";
	$result = mysql_query($query);
$result =  mysql_result($result,0,0);
if($result==1)
return true;
else
return false;

	
}

function get_tutees($lecturerid)
{
	$query = "
	SELECT student_id
FROM students
WHERE tutor_id = '$lecturerid'
	";
	$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['student_id'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;
	
	
}

function average($modulecode)
{
	$i=0;
	$total=0;
	$students = students_taken($modulecode);
		if(count($students)>0)
	{
	$a=0;
	foreach($students as $stu)
	{
		$stu_total = total_marks($stu,$modulecode);
		if($stu_total!==NULL)
		{
		$a=1;
		$total = $total + $stu_total;
			$i++;
		}
	
	}
	if($a==1)
	return @($total/$i);
	else
	 return NULL;
	}
	else return NULL;
}

function maximum($modulecode)
{   
	
    $maximum =0;
	$students = students_taken($modulecode);
	if(count($students)>0)
	{
    $a=0;
	foreach($students as $stu)
	{
		$total = total_marks($stu,$modulecode);
		if($total!==NULL)
		{
		$a=1;
		if($total>$maximum)
		$maximum=$total;
		}
	}
	if($a==1)	
	return $maximum;
	else
	return NULL;
	}
	else return NULL;
}

function minimum($modulecode)
{
   
	$students = students_taken($modulecode);
	if(count($students)>0)
	{
 		$a=0;
	$minimum  = pow(10,10);
	foreach($students as $stu)
	{
		$total = total_marks($stu,$modulecode);
		
		if(!is_null($total))
		{
			$a=1;	
			if($total<$minimum)
			$minimum=$total;	
		}
		
        
	
	}
	if($a==1)	
	return $minimum;
	else
	return NULL;
	}
	else return NULL;
}

function is_exam_officer($lecturerid)
{
	$query ="
	select exam_officer
from universal
";
	$result = mysql_query($query);
$result =  mysql_result($result,0,0);

if($result==$lecturerid)
return true;
else false;


	
}

function exam_officer()
{
		$query ="
	select exam_officer
from universal
";

	$result = mysql_query($query);
return  mysql_result($result,0,0);
	
}

function update_exam_officer($lecturerid)
{
	$query = "update universal
set exam_officer = '$lecturerid'";
mysql_query($query);
}

function update_semester($value)
{
	$query = "update universal
set semester ='$value'
";
mysql_query($query);

}

function update_year($value)
{
	$query = "update universal
	set year='$value'
	";
	mysql_query($query);
}


function get_latest_announcement_no($type)
{
	$query = "
	select no
from announcements
where type = '$type'
order by no desc
limit 1
	
	";
	
		$result = mysql_query($query);
$result =  @mysql_result($result,0,0);
if(!$result)
return NULL;
else return $result;
	
}

function add_announcement($message,$type,$author)
{
	$date = date('Ymd');
	$time = date('U');
	$message = addslashes($message);
	
     $query = "
	 INSERT INTO announcements
(message,type,author,date,time)
values
('$message','$type','$author',$date,$time)
	 
	 ";
	 mysql_query($query) or die(mysql_error());
	
}

function get_announcement($no)
{
	$query = "
	select message
from announcements 
where no = '$no'

";

	$result = mysql_query($query);
	
return mysql_result($result,0,0);
	
	
	
}

function get_announcement_date($no)
{
	$query = "select DATE_FORMAT(date,'%D %M, %Y')
from announcements
where no = '$no'
";

$result = mysql_query($query);
	
return mysql_result($result,0,0);
	

	
}

function get_announcement_time($no)
{
	$query = "
	select time
from announcements
where no ='$no'

";

$result = mysql_query($query);
	
$result =  mysql_result($result,0,0);

return  getdate($result);	

}

function get_announcement_author($no)
{
	$query = "select author
	from announcements
	where no = '$no'
	";
	$result = mysql_query($query);
	return  mysql_result($result,0,0);


}
function attendance_list($modulecode)
{
	$module_code = $modulecode;
	include('attendance_list.inc');
	
}

function report($modulecode)
{
	$module_code = $modulecode;
	include('report.inc');
	
}


function get_lecturer($modulecode)
{
	
	$query = "select lecturer_id from
teaches
where module_code = '$modulecode'";
	$result = mysql_query($query);
	return  mysql_result($result,0,0);

	
}

function search_students($name)
{

	
	$query = "SELECT student_id FROM students
WHERE student_id LIKE '%$name%'
or student_givenname like '%$name%'
or course_code like '%$name%'
or roll_no like '%$name%'
"

;


$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['student_id'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;


}


function search_lecturers($name)
{
	$query = "SELECT lecturer_id FROM lecturers
WHERE lecturer_id LIKE '%$name%'
or lecturer_name like '%$name%'

"
;	

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['lecturer_id'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;


}


function search_modules($name)
{
	$query = "SELECT module_code FROM modules
WHERE module_code LIKE '%$name%'
or module_name like '%$name%'

"
;	

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['module_code'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;


}



function search_courses($name)
{
	$query = "SELECT course_code FROM courses
WHERE course_code LIKE '%$name%'
or course_name like '%$name%'

"
;	

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$students[] =  $row['course_code'];
}
 if(empty($students))
  {
  $students = array();
  }
return $students;


}



Function LogUserActivity($LogFile, $Activity){

$UserIp = $_SERVER['REMOTE_ADDR'];

$TimeRef = date('d-m-Y H:i T');

 $path="logs";

$Handle = fopen($path."/".$LogFile, 'a');

$Data = $UserIp.'|'.$TimeRef.'|'.$Activity.'~';

fwrite($Handle, $Data);

fclose($Handle);

 

}



Function ReadUserActivity($LogFile){

$path="logs";

$LogFile = file_get_contents($path."/".$LogFile);

$ExplodedLogFile = explode("~", $LogFile);

$ArrayNum = count($ExplodedLogFile);

$i = 0;

while ( $i < $ArrayNum ){
    
	$log[$i] = explode("|", $ExplodedLogFile[$i]);
	echo $log[$i][1].'</br>';
	$i++;
	
}

}

function id_is_lecturer($lecturerid)
{
	$query ="select count(*) from 
lecturers
where lecturer_id='$lecturerid'";

$result = mysql_query($query);

$result =  mysql_result($result,0,0);

if($result>0)
return true;
else
return false;
	
}


function id_is_student($studentid)
{
	$query ="select count(*) from 
students
where student_id='$studentid'";

$result = mysql_query($query);

$result =  mysql_result($result,0,0);

if($result>0)
return true;
else
return false;
	
}

function maintenance()

{
$query = "select maintenance
from universal";

$result = mysql_query($query);

$result =  mysql_result($result,0,0);

if($result==1)
return true;
else
return false;

	
}


function update_maintenance($value)

{
$query = "
update universal
set maintenance=$value
";

mysql_query($query);

	
}

function show_year_total()
{
	$query="select show_year_total
from universal";

$result = mysql_query($query);

$result =  mysql_result($result,0,0);

if($result==1)
return true;
else
return false;

	
	
}


function update_show_year_total($value)

{
$query = "
update universal
set show_year_total=$value
";

mysql_query($query);

	
}



	

function std_deviation ($modulecode){
   
    $students = students_taken($modulecode);
	 
   
    $avg = average($modulecode);
    foreach ($students as $stu) {
    	$mark = total_marks($stu,$modulecode);
    	
        $variance[] = pow($mark-$avg, 2);
    }
    $deviation = sqrt(average($variance));
    return $deviation;
}





?>