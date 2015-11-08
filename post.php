<!DOCTYPE HTML> 
<?php
error_reporting(E_ALL);
ini_set('display_errors', 'on');

//Get data from submitted form
$name = $_POST["name"];
$email = $_POST["email"];
$password = $_POST["password"];



//Helps prevent SQL Injection Attacks
//$name_es = sqlite_escape_string($name);
//$email_es = sqlite_escape_string($email);
if (!empty($name)) {

   $dbhandle = new SQLite3('db/game1.db');

   //$dbhandle->exec('CREATE TABLE game (name(255), email(255), pin(255))');
   
   $stm = "INSERT INTO game (name, email, pin) VALUES('$name', '$email', 0)";
   $dbhandle->exec($stm);

   	echo "Welcome " . $name;

	echo "You entered: " . $name . " " . $email . " " . $password;
	$yourpin = $dbhandle->querySingle("SELECT pin FROM game WHERE email='$email'");
	echo "Your pin is: " . $yourpin;
}
?>

<html> 
	<head> 
		<meta charset='utf-8'>
	   <meta http-equiv="X-UA-Compatible" content="IE=edge">
	   <meta name="viewport" content="width=device-width, initial-scale=1">
	   <link rel="stylesheet" href="main.css">
	   <script src="http://code.jquery.com/jquery-latest.min.js" type="text/javascript"></script>
	   <script src="script.js"></script>
	   <title>HomePage</title>
	</head> 
	
	<body> 

		<div id='cssmenu'>
			<ul>
			   <li class='active'><a href='index.html'>Home</a></li>
			   <li><a href='AboutGame.html'>About Game</a></li>
			   <li><a href='AboutHackTeam.html'>About Hack Team</a></li>
			   <li><a href='Registration.html'>Register</a></li>
			</ul>
		</div>

	</body>
</html>




