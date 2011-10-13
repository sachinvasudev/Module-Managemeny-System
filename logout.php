<?php
require('functions.inc');

show_header('normal');
?>




<?php

/**
 * @author Sachin
 * @copyright 2009
 */
@session_start();
unset ($_SESSION['valid user']);
unset ($_SESSION['type']);
session_destroy();
echo '
<div id="page" align="center">
<h2>

You have successfully logged out<br/>';
echo 'You will be redirected in 1 seconds';





?>

<meta http-equiv="Refresh" content="1;
URL=index.php">


<?php
require('footer.inc');
?>