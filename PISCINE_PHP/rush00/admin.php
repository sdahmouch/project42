<?php
session_start();
require('authadmin.php');

if ($_POST["login"] && $_POST["passwd"] && autha($_POST["login"], $_POST["passwd"]))
{
	$_SESSION["loggued_on_user"] = $_POST["login"];
	header('Location: ./pageadmin.php');
}
else
{
	$_SESSION["loggued_on_user"] = "";
	header('Location: ./admin.html');
}
?>
