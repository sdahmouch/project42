<?php
if (!(file_exists("./stock.csv")))
{
	$fd = fopen("./stock.csv", 'w+');
}
else
{
	$fd = fopen('stock.csv', 'r+');
}
$line[0] = fgets($fd);
$i = 0;
while ($fd && !feof($fd))
{
    $line[0] = $line[0].fgets($fd);
    $i++;
}
$line[1] = $_POST['img'].";".$_POST['nom'].";".$_POST['prix'].";".$_POST['categorie']."!";
file_put_contents("./stock.csv", implode("\n", $line));
header('Location: ./gestion.php');
?>