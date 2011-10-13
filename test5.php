<?php
// Download the given file to local inside the domain
require('functions_db.inc');
$LogFile='log.txt';
$Activity='login';

LogUserActivity($LogFile, $Activity);

 ReadUserActivity($LogFile);

?>