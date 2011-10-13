<?php


function test()
{
	echo"Test executed<br>";
}


function show_header($type)
{
if($type=='login')
require('header_login.inc');

if($type=='normal')
require('header_normal.inc');

if($type =='lecturer')
{
require('header_lecturer.inc');
}

if($type=='admin')
{
	require('header_lecturer.inc');
}
	
}



function show_footer()
{
	require('footer.inc');
}

function id_check($userid,$password,$category)
{
	$password = md5($password);
	if($category=='student')
	{
	
	$query = "select count(*) from students where
          Student_ID='$userid' and password = '$password'";
      
    }
    
    	if($category=='lecturer')
	{
	
	$query = "select count(*) from lecturers where
          Lecturer_ID='$userid' and password = '$password'";
      
    }
    
    if($category=='admin')
    {
    	$query = "select count(*) from admins where
          admin_id='$userid' and password = '$password'";
    	    
    }
          

          

          
$result=mysql_query($query);


if(!$result)
{
	echo "Cannot run query";
	exit;
}

$count = mysql_result($result,0,0);


if($count>0)
{
	
return true;	

}
else
{
	return false;
	
}



	
	
	
}






function  login_check()
{
	
@session_start();
	

if(!isset($_SESSION['valid_user']))
{
	return false;
}
else
return true;
}





function login_message($type)
{
@	session_start();
	

if(!isset($_SESSION['valid_user']))
{
	echo '<h1><center>You are not logged in'; 
	redirect('login_page_delay');
	exit;
	
}

else if(!($_SESSION['type']==$type))
{
		
	echo '
	<div id="page" align="center">
<h2>
	You are not authorized to view this page '; 
	redirect('homepage_delay');	
	exit;
}

}





function is_student()
{
	@	session_start();
	if(	$_SESSION['type']=='student')
	return true;
	else false;

}

function is_lecturer()
{
	@	session_start();
	if(	$_SESSION['type']=='lecturer')
	return true;
	else false;

}

function is_admin()
{
	@	session_start();
	if(	$_SESSION['type']=='admin')
	return true;
	else false;

}





function redirect($where)
{
	@	session_start();
	
	if($where=='login_page_delay')
	{
		echo'<meta http-equiv="Refresh" content="1;
        URL=index.php">';

			
	}
	
	if($where == 'homepage')
	{
	   if (is_lecturer())
	   {
	   		header( 'location:lt_home.php' );

	   		   
	   }
	   
	   if (is_student())
	   {
	   		header( 'location:st_home.php' );

	   		   
	   }
	   
	    if (is_admin())
	   {
	   		header( 'location:admin_home.php' );

	   		   
	   }
	   
	   
			
	}
	
	if($where=='homepage_delay')
	{
		if (is_lecturer())
	   {
	   	echo'<meta http-equiv="Refresh" content="1;
        URL=lt_home.php">';

	   		   
	   }
	   else
	   if (is_student())
	   {
	   		echo'<meta http-equiv="Refresh" content="1;
        URL=st_home.php">';

	   		   
	   }
	   else
	    if (is_admin())
	   {
	   	echo'<meta http-equiv="Refresh" content="1;
        URL=admin_home.php">';


	   		   
	   }
	   
		
			
	}
	
	
}

function show_module_navigation()
{
	include('lt_module_navigation.inc');
}

function show_admin_navigation()
{
	include('admin_navigation.inc');
}




function db_connect()
{	$host = 'butterbur.nottingham.edu.my';
	$user = 'keay7sva';
	$pass = 'keay7sva_db';
	$dbname = 'keay7sva';
	
	
	@$db = mysql_connect($host,$user,$pass) or die('Could not connect to database');

mysql_select_db($dbname);
	
}

function show_sidebar()
{
	include('sidebar.inc');
}




?>
