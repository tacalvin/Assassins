<html> 
	<head> 
		<title> Login Information Gathered </title> 
	</head>

	<body> 
		<?php
			$usersName = $_POST['usermail'];
			$password = $_POST['password'];
			$gameName = $_POST['GameName'];
			
			echo $usersName. "</br>";
			echo $password. "</br>";
			echo $gameName. "</br>";
			
			
			
		?> 
	</body> 
</html> 