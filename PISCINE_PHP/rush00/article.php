<?php
$fd = fopen('stock.csv', 'r');
fgets($fd);
$i = 0;
$db = array();
while ($fd && !feof($fd))
{
	$a = explode(";", fgets($fd));
	$a = str_replace('"', '', $a);
	$db[$i]["img"] = $a[0];
	$db[$i]["nom"] = $a[1];
	$db[$i]["prix"] = $a[2];
	$db[$i]["id"] = $a[3];
	$db[$i]["categorie"] = $a[4];
	$i++;
}
$i = 0;
foreach ($db as $ele)
{
	if (!$_GET["name"])
	{
		echo "<tr style=\"display: inline-block; text-align: center; width: 30%;\"><td><figure><img src=".$ele["img"]."><figcaption><p>".$ele["nom"]."<br><strong>".$ele["prix"]."</strong></p>
<form action=\"./add.php\"><input type=\"submit\" name =\"name\" class=\"panier\" value=\"".$ele['nom']."  ".$ele["prix"]."\"></form></figcaption></figure></td></tr>";
	}
	else
	{
		if (strstr($ele["categorie"], $_GET["name"]) == true)
		{
			echo "<tr style=\"display: inline-block; text-align: center\"><td><figure><img src=".$ele["img"]."><figcaption><p>".$ele["nom"]."<br><strong>".$ele["prix"]."</strong>
</p><form action=\"./add.php\"><input type=\"submit\" name =\"name\" class=\"panier\" value=\"".$ele['nom']."  ".$ele["prix"]."\"></form></figcaption></figure></td></tr>";
		}
	}
	$i++;
}

?>

<style type="text/css">
body
{
  margin:0px;
  padding-bottom: 100px;
   font-family: 'Raleway', sans-serif;
  background-image: linear-gradient(#3AADDE 0%, black 60%);;
  background-size: cover;
  color:#fff;
  font-weight:300;
  min-height: 100%;
  position: relative;
 /* overflow: hidden;*/

}
figure{
	margin:auto; 
	display: inline-block;
}
figure {
    /*border: 5px solid #000;*/
    background: #fff;
    color: #000;
   width: 20%;
    margin: 10px 10px;
    display: inline-block;
    box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);
}
figure:hover{
	/*border: 5px solid #A9D740;*/
	box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);
}
.panier{
	font-size: 1.1vw;
	width: 100%;
	margin: auto;
	cursor: pointer;
	background: #3AADDE;
	color:#fff;
	border: none;
}
.panier:hover{
	background: #A9D740;
	color:#000;
	border: none;
}
.image{
	font-size: 20px;
	width: 50%;
	margin: 0 auto;
}
</style>