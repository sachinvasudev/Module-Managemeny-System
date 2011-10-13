
<?php




require('functions.inc');

require('functions_db.inc');
db_connect();

if(login_check())
{
		
redirect('homepage');
	
}

@$userid = $_POST['userid'];
@$password= $_POST['password'] ;



if(!(empty($userid)||empty($password)))
{
		

db_connect();


if(maintenance())
{
	if(id_check($userid,$password,'admin'))
{
	$_SESSION['valid_user']=$userid;
	$_SESSION['type']='admin';
	redirect('homepage');
	
}

	
}
else
{

if(id_check($userid,$password,'lecturer'))
{
	$_SESSION['valid_user']=$userid;
	$_SESSION['type']='lecturer';
	redirect('homepage');
	
}
else


if(id_check($userid,$password,'admin'))
{
	$_SESSION['valid_user']=$userid;
	$_SESSION['type']='admin';
	redirect('homepage');
	
}

else 
if(id_check($userid,$password,'student'))
{
	$_SESSION['valid_user']=$userid;
	$_SESSION['type']='student';
	redirect('homepage');
	
}

else
{
if(ad_check($userid,$password))
{
	
if(id_is_lecturer($userid))
{
$_SESSION['type']='lecturer';
$_SESSION['valid_user']=$userid;
	redirect('homepage');
}
else if(id_is_student($userid))
{
$_SESSION['type']='student';
$_SESSION['valid_user']=$userid;
	redirect('homepage');	
}




}
	
}
		
	

}

}




show_header('login');

	

?>
<div id="banner">&nbsp;</div>

<div id="wrapper">
<!-- start page -->
<div id="page">
	<!-- start content -->
	<!--<div id="section">-->
	<!-- <IMG src="./images/signin.png" alt="Signin"> -->
	
	
<!--	</div>-->
	<div id="content">
		<div class="post">
		
			<?php
			if(maintenance())
			echo'<h2><font color="red"> System currently in maintenance mode. Please try after some time.</font></h2>';
			else
			{
			$no = get_latest_announcement_no('home');
			if($no)
			{
			$time = get_announcement_time($no);
			 
			
			echo '
				<h1 class="title"> Welcome to MMS!</h1>
			<p class="byline"><small>Posted on '.get_announcement_date($no).' by '.get_announcement_author($no).'
			at '.$time['hours'].':'.$time['minutes'].':'.$time['seconds'].'
			 </a></small></p>
			<div class="entry">
				<p>'.nl2br(get_announcement($no)).'  </p>
				
				';
				}
				}
			?>
				
			</div>
		</div>
	</div>
	<!-- end content -->
	<!-- start sidebars -->
	<div id="sidebar1" class="sidebar">
		<ul>
			<li>
				<h2>Status</h2>
				

<form method="POST" action="index.php" name="Auth">
	<?php
				if((isset($userid)||isset($password)))
				{
					if(maintenance())
					echo'<strong><font color="red">System in maintenance mode.Only admins can login. </font></strong>	<br> <br>';
					else
					echo'<strong><font color="red"> Invalid username/password </font></strong>	<br> <br>';				
				}
				
				?>
				

<p>Username : <input type="text" name="userid" size="8"  maxlength="256"/></p>
<p>Password : <input type="password" name="password" size="8"  maxlength="256"/></p>
<a class="button" onclick="parentNode.submit();this.blur();" href="#nothing"><span>Sign in</span></a>
<input type="submit" style="height: 0px; width: 0px; border: none; padding: 0px;" hidefocus="true" />



</form>
<script language="JavaScript" type="text/javascript">
   document.Auth.userid.focus();
</script>
		    	</li>	
		</ul>	
	</div>
	<!-- end sidebars -->
<?php show_footer()?>