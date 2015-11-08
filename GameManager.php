<html> 
	<head> 
		<title> PHP GAME MANAGER </title> 
	</head> 
	
	<body> 
		<?php
			class Player
			{
				public $name;
				public $email;
				public $pin;
				public $kills;
				public $status;
				public $killer;
				public $target;
				
public function addAssassins(&$killer, &$target)
{
	
	$this->target = $target;
	$this->killer = $killer;
}

public function die($playerpin, &$actingkiller)
{
	if ($this->pin == playerpin && $this->getKiller() == actingkiller)
	{
		$this->status = false;
		
		print "Player Killed";
		return $this->&target;
	}

	else
		print "Invalid Kill";
}

				public function kill($pin, &$killer, &$target)
				{	
	
					if ($killer->status)
					{
					print "checking kill";
					$target->die($pin, $killer);
		
					}
				}
			}
			
			class GameManager
			{
				public $PlayerList;
				public $CurrentGameName;
				
				public function loadPlayers($gameName)
				{
				
				}
				public function addPlayer($Player)
				{
				
				}
				public function start()
				{
				//assigns targets
				}
				public function save()
				{
				
				}
			}
		?>

	</body> 
</html> 

