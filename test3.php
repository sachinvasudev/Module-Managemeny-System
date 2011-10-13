<?php


if(!empty($_POST['to']))
{
	
	$to = $_POST['to'];
	$subject = $_POST['subject'];
	$from = $_POST['from'];
	$message = $_POST['message'];
	$cc = $_POST['cc'];
	
	$headers = "MIME-Version: 1.0" . "\r\n";
$headers .= "Content-type:text/html;charset=iso-8859-1" . "\r\n";
$headers = "From: $from" . "\r\n" .
"CC: $cc";
	
if(mail($to,$subject,$message,$headers))
echo 'Message sent successfully';
else
echo 'Error in sending message. ';


}
	






?>

<form method="POST" action="test3.php">
To
<input type="text" name="to"><br />
CC
<input type="text" name="cc"><br />
Subject
<input type="text" name="subject"<br>
From
<input type="text" name="from"<br>
Message<br />
<TEXTAREA NAME="message" COLS=40 ROWS=6></TEXTAREA>
<br>
<input type="submit" value="Send E-mail">
</form>


