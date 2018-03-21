<?php
	session_start();
	$array = $_SESSION['panier'];
	$i = 0;
	foreach ($array as $key => $ele)
	{
		if ($ele == $_GET['name'])
			$i = $key;
	}
	echo $_GET['name']."<br />";
	unset($array[$i]);
	unset($_SESSION['panier']);
	$_SESSION['panier'] = array_values($array);
	header("Location: ./panier.php");
?>