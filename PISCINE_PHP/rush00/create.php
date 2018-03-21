<?php

if ($_POST["submit"] && ($_POST["login"]) && ($_POST["passwd"]))
{
	if ($_POST["passwd"] !== ($_POST["passverif"]))
	{
		header('Location: ./errormdp.html');
		exit();
	}
	if (!(file_exists("./private")))
	{
		mkdir("./private");
	}
	if (!(file_exists("./private/passwd")))
	{
		$fd = fopen("./private/passwd", 'w+');
	}
	$pass = unserialize(file_get_contents("./private/passwd"));
	$test = 0;
	if ($pass)
	{
		foreach ($pass as $key => $elem)
		{
			if ($elem["login"] === $_POST["login"])
				$test = 1;
		}
	}
	if ($test === 0)
	{
		$a["login"]= $_POST["login"];
		$a["passwd"] = hash("whirlpool", $_POST["passwd"]);
		$a["nom"] = $_POST["nom"];
		$a["prenom"] = $_POST["prenom"];
		$a["address"] = $_POST["address"];
		$pass[] = $a;
		file_put_contents("./private/passwd", serialize($pass));
		header('Location: index.php');
	}
	else if ($test === 1)
	{
		header('Location: errorlogi.html');
		exit();
	}
	else
	{
		header('Location: errorlog.html');
		exit();
	}
}
else
{
	header('Location: errorlog.html');
	exit();
}
