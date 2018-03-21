<?php
	
	function auth($login, $passwd)
	{
		$passwd = hash('whirlpool', $passwd);

		$arr = unserialize(file_get_contents('../private/passwd'));

			if ($arr)
			{
				foreach ($arr as $elem)
				{
					if ($elem['login'] === $login && $elem['passwd'] === $passwd)
						return (TRUE);
				}
			}
	return (FALSE);
	}

?>