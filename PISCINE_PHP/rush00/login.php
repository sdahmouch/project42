<?php
session_start();

require('auth.php');

if ($_POST["login"] && $_POST["passwd"] && auth($_POST["login"], $_POST["passwd"]))
{
	$_SESSION["loggued_on_user"] = $_POST["login"];
	header('Location: ./index.php');
}
else
{
	$_SESSION["loggued_on_user"] = "";
	header('Location: ./errorlogin.html');
}
?>