<?php
session_start();
if ($_SESSION["loggued_on_user"] === "" || !($_SESSION["loggued_on_user"]))
{
	header("Location: ./login.html");
}
else
{
	if ($_POST["oldpw"] && $_POST["newpw"])
	{
	    if (!(file_exists("./private/passwd")))
	    {
	    	header("Location: ./logout.php");
	    	exit();
	    }
	  	$pass = unserialize(file_get_contents("./private/passwd"));
	    if ($pass)
	    {
	        $test = 0;
	        foreach ($pass as $key => $elem)
	        {
	        	if ($elem["login"] === $_SESSION["loggued_on_user"] && $elem["passwd"] === hash('whirlpool', $_POST["oldpw"]))
	            {
	                $test = 1;
	                if (!($_POST["newpw"] === ""))
					{
						$pass[$key]["passwd"] = hash('whirlpool', $_POST["newpw"]);
					}
	                if (!($_POST["nom"] === ""))
	               	{
	               		$pass[$key]["nom"] = $_POST["nom"];
	               	}
	               	if (!($_POST["prenom"] === ""))
	               	{
	               		$pass[$key]["prenom"] = $_POST["prenom"];
	               	}
	               	if (!($_POST["address"] === ""))
	               	{
	               		$pass[$key]["address"] = $_POST["address"];
	             	}  
	            }
	        }
	        if ($test)
	        {
	            file_put_contents("./private/passwd", serialize($pass));
	            header('Location: ./index.php');
	            session_destroy();
	            exit();
	        }
	        else
	        {
	        	header("Location: ./modifinfo.html");
	        	exit();
	        }
	    }
	    else
	    {
	    	header("Location: ./modifinfo.html");
	    	exit();
	    }
	}
	else
	{
		header("Location: ./modifinfo.html");
	    exit();
	}
}
?>