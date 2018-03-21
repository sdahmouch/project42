<?php
	session_start();
	unset($_SESSION['panier']);
	$_SESSION['panier'] = array();
	header("Location: panier.php");
?>