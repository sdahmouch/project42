<?php
if ($_POST['id'] !== NULL && $_POST['id'] !== "" && is_numeric($_POST['id']) == true)
{
	if (!(file_exists("./stock.csv"))) {
		$fd = fopen("./stock.csv", 'w+');
	} else {
		$fd = fopen('stock.csv', 'r+');
	}
	$tmp = file_get_contents("./stock.csv");
	$tmp = explode('!', $tmp);
	$new = [];
	foreach ($tmp as $key => $value) {
		if ($key != $_POST['id'])
			$new[] = $value;
	}
	file_put_contents("./stock.csv", implode("!", $new));
}
header('Location: ./gestion.php');
?>