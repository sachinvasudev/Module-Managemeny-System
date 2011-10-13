<?php




$userid = @$_POST['userid'];
$password =@$_POST['password'];
if($userid)
{

// LDAP variables
$ldaphost = "ad.nottingham.edu.my";  // your ldap servers
$ldapport = 389;    

             // your l$dap server's port number


  $ldaprdn  = "kxldap";     // ldap rdn or dn
         $ldappass = 'N0ttingh4m';  // associated password



// Connecting to LDAP
$ldapconn = ldap_connect($ldaphost, $ldapport)
          or die("Could not connect to $ldaphost");




if ($ldapconn) {

    // binding to ldap server
    $ldapbind = ldap_bind($ldapconn, $ldaprdn, $ldappass);

    // verify binding
   
}


// $ds is a valid link identifier for a directory server

// $person is all or part of a person's name, eg "Jo"

$dn = "ou=university, dc=nottingham, dc=edu, dc=my";
$filter="(&(objectClass=user)(sAMAccountName=$userid))";

$justthese = array("ou", "sn", "displayname", "mail","postOfficeBox","physicalDeliveryOfficeName",
"description","cn","distinguishedName"

);

$sr=ldap_search($ldapconn, $dn, $filter, $justthese);

$info = ldap_get_entries($ldapconn,$sr);


if($info["count"]<1)
echo "Password or username incorrect";

 for ($i=0; $i < $info["count"]; $i++)
    {
    	
   	
         $distingu = $info[$i]["distinguishedname"][0];
             
        $ldaprdn  = "$distingu";     // ldap rdn or dn
         $ldappass = $password;  // associated password

         // binding to ldap server
    $ldapbind = @ldap_bind($ldapconn, $ldaprdn, $ldappass);

    // verify binding
    if ($ldapbind) {
        echo "Password and username correct";
    } else {
        echo "Password or username incorrect";
    }
        
        
        
    }

    //never forget to unbind!
    
    
    ldap_unbind($ldapconn);
}
else
{
	echo '<form action="more_surprise.php" method="POST">
Enter user id
<input type="text" name="userid">
<br/>
Enter password

<input type="password" name="password">
<br/>
<input type = "submit" value = "Verify">




</form>
';
}




?>


