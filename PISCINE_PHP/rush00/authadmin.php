<?php
function autha($login, $passwd)
{
	if (!(file_exists("./private/")))
	{
		mdkir("./private");
	}
	if (!(file_exists("./private/admin")))
	{
		fopen("./private/admin", 'x+');
		return (FALSE);
	}
	else
	{
		$pass = unserialize(file_get_contents("./private/admin"));
	}
	if ($pass)	
	{
		foreach ($pass as  $elem)
		{
			if (($elem["login"] === $login) && ($elem["passwd"] === hash('whirlpool', $passwd)))
			{
				return (TRUE);
			}
		}
	}
	return (FALSE);
}
?>