<html> 
		<body>
<?php
//error_reporting(E_ALL);
//ini_set('display_errors', 'on');

//Get data from submitted form
$name = $_POST["name"];
$email = $_POST["email"];

//Helps prevent SQL Injection Attacks
//$name_es = sqlite_escape_string($name);
//$email_es = sqlite_escape_string($email);

if (!empty($name)) {

   $dbhandle = new SQLite3('./game1.db');
   
   $stm = "INSERT INTO Game(name, email) VALUES('$name', '$email')";
   $dbhandle->exec($stm);
}
?>


<?php echo "Welcome " . $name; ?>


</body>
</html>
