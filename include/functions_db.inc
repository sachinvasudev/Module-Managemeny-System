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

function course_name($coursecode)
{
	$query = "select course_name
from courses
where course_code ='g400'
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

function modules_taken($studentid)
{
		$query = "select module_code
from takes
where student_id = '$studentid'";

mysql_query($query);

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
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
and year = '1'
and takes.module_code = courses_and_modules.module_code
and takes.student_id ='sachin'
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


mysql_query($query);

$result =  mysql_query($query);

while($row = mysql_fetch_array($result))
{
	$modules[] =  $row['module_code'];
}

return $modules;

	
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
	if((exam_mark($studentid,$modulecode)!==NULL)		)
	{

	
	$total =0;
	for($i=1;$i<=num_courseworks($modulecode);$i++)
	{
		
     $total = cw_weightage($modulecode,$i)*cw_mark($studentid,$modulecode,$i)+$total;
			
	}
	
	$total = (exam_weightage($modulecode)*exam_mark($studentid,$modulecode))+$total;
	
    return $total;
    	
    
    }
    
    else return NULL;
    
	

	
	
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
	
     $query = "
	 INSERT INTO announcements
(message,type,author,date,time)
values
('$message','$type','$author',$date,$time)
	 
	 ";
	 mysql_query($query);
	
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



?>