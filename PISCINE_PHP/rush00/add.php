<?php
session_start();
$_SESSION["panier"][] = $_GET["name"];
header('Location: index.php');
?>