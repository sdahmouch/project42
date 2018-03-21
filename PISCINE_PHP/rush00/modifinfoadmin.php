<?php
	session_start();
if (!($_SESSION["loggued_on_user"] === "admin"))
{
	header("Location: ./index.php");
}
else
{
	if ($_POST["login"])
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
	            if ($elem["login"] === $_POST["login"])
	            {
	                $test = 1;
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
	            exit();
	        }
	        else
	        {
	        	header("Location: ./modifadmin.html");
	        	exit();
	        }
	    }
	    else
	    {
	    	header("Location: ./modifadmin.html");
	    	exit();
	    }
	}
	else
	{
		header("Location: ./modifadmin.html");
	    exit();
	}
}
?>