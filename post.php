<!DOCTYPE HTML> 
<?php
error_reporting(E_ALL);
ini_set('display_errors', 'on');

// Including the game logic
//require 'GameManager.php';

//Get data from submitted form
$name = $_POST["name"];
$email = $_POST["email"];
$password = $_POST["password"];
$kill = $_POST["kill"];
if(!empty($_POST["password"])){
	$pin = $_POST["password"];
}
else {
	$pin = 0;
}

//Helps prevent SQL Injection Attacks
//$name_es = sqlite_escape_string($name);
//$email_es = sqlite_escape_string($email);
if (!empty($name)) {
	if ()
	$args = "./a.out " . $pin . " " . $action . " " . $aux;

   // Thank user for logging in / registering
   	echo "Welcome " . $name;

   	// Helps with debugging :)
	echo "You entered: " . $name . " " . $email . " " . $password;
	
	// They need to know their pin to play
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




