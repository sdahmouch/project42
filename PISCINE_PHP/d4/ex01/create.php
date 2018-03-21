<?php
	if ($_POST['login'] && $_POST['passwd'] && $_POST['submit'] === "OK")
	{
		$login = $_POST['login'];
		$passwd = $_POST['passwd'];
		if (!file_exists("../private"))
    	{
        	mkdir("../private");   
    	}
    	if (file_exists("../private/passwd"))
    	{
    		$create = file_get_contents("../private/passwd");
    		$create = unserialize($create);
    		if ($create)
    		{
    			foreach ($create as $tab)
    			{
    				if ($tab['login'] === $login)
    				{
    					echo "ERROR\n";
    					return ;
    				}
    			}
    		}
    	}
    	$create[] = ["login" => $login, "passwd" => hash("whirlpool", $passwd)];
    	file_put_contents("../private/passwd", serialize($create));
    	echo "OK\n";
	}
	else
	{
		echo "ERROR\n";
	}
?>