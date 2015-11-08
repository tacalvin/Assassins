<!DOCTYPE HTML> 
<?php

//error_reporting(E_ALL);
//ini_set('display_errors', 'on');

//Get data from submitted form
$name = $_POST["name"];
$loginPin = $_POST['loginPin'];
$action = $_POST['action'];
$kill = $_POST['kill'];
$targetPin = $_POST['targetPin'];
$start = $_GET('start');

switch ($action):
	case "login":
		$args = "./a.out " . $loginPin . " login";
		break;
	case "register":
		$args = "./a.out " . $loginPin . "add " . $name;
		break;
	case "kill":
		$args = "./a.out " . $loginPin . " kill " . $targetPin;
		break;
	endswitch;

if ($start == "true") {
	$args = "./a.out start";
}

$es_args = escapeshellcmd($args);

//echo $args;

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
		<?php echo shell_exec($es_args); ?>
	</body>
</html>




