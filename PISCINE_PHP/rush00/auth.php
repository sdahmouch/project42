<?php
function auth($login, $passwd)
{
	if (!(file_exists("./private/")))
	{
		mdkir("./private");
	}
	if (!(file_exists("./private/passwd")))
	{
		fopen("./private/passwd", 'x+');
		return (FALSE);
	}
	else
	{
		$pass = unserialize(file_get_contents("./private/passwd"));
	}
	if ($login === "deleted")
	{
		return (FALSE);
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