<?php




$userid = @$_POST['userid'];
$password =@$_POST['password'];
if($userid)
{

// LDAP variables
$ldaphost = "localhost";  // your ldap servers
$ldapport = 750;    

             // your ldap server's port number


  $ldaprdn  = "CN=keay7sva,OU=STUDENTS,OU=USERS,OU=SOCS,OU=FOS,OU=UNIVERSITY,DC=nottingham,DC=edu,DC=my";     // ldap rdn or dn
         $ldappass = 'guardian@17';  // associated password



// Connecting to LDAP
$ldapconn = ldap_connect($ldaphost, $ldapport)
          or die("Could not connect to $ldaphost");




if ($ldapconn) {

    // binding to ldap server
    $ldapbind = ldap_bind($ldapconn, $ldaprdn, $ldappass);

    // verify binding
    if ($ldapbind) {
        echo "LDAP bind successful...";
    } else {
        echo "LDAP bind failed...";
    }

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

echo '</br></br>';

 for ($i=0; $i < $info["count"]; $i++)
    {
    	
   		echo 'Userid: '.$info[$i]["cn"][0]."<br />";
    	echo 'Name: '.$info[$i]["displayname"][0]."<br />";
        echo 'Email: '.$info[$i]["mail"][0]."<br />";
        $category = $info[$i]["physicaldeliveryofficename"][0];
       
        if($category=='STUDENTS')
        {
         echo 'Userid: '.$info[$i]["postofficebox"][0]."<br />";
         echo 'Description: '.$info[$i]["description"][0]."<br />";
         
         }
         echo 'Category: '.$category."<br />";
         $distingu = $info[$i]["distinguishedname"][0];
        echo 'Distinguished name: '.$distingu."<br />";
        // ldap_unbind($ldapconn);
         
        
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
	echo '<form action="test.php" method="POST">
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


