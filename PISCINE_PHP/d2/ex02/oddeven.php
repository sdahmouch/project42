#!/usr/bin/php  
<?php 
while (True)
{
	echo "Entrez un nombre: ";	
	if ($line = fgets(STDIN))
	{
		$i = trim($line);
		if (is_numeric($i))
		{
			if ($i >= "9223372036854775808" || $i <= "-9223372036854775808")
				echo "Depassement d'entier\n";
			else
			{
				if ($i % 2)
					echo "Le chiffre ".$i." est Impair\n";
				else
					echo "Le chiffre ".$i." est Pair\n";
			}			
		}
		else
			echo "'".$i."' n'est pas un chiffre\n";
	}
	else
	{
		echo "\n";
		break;
	}
}
?>