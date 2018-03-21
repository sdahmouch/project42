<?php
	session_start();
?>

<html>
<head>
	<meta charset="UTF-8">
	<title>Panier</title>
</head>
<body  style="text-align: center">
	<form method="post" action="./clear.php" class="box">
	<?php
	if (count($_SESSION['panier']))
	{
		foreach ($_SESSION['panier'] as $elem)
		{
			echo "$elem<br /><br>";
		}
	}
	else
	{
		echo "Votre panier est vide<br /><br />";
	}
	?>
		<input class="button1" type="submit" name="submit" value="Vider Panier">
	</form>
 	<form method="post" action="./index.php">
		<input class="button2" type="submit" name="submit" value="Page d'accueil">
	</form>
	<?php
	if ($_SESSION["loggued_on_user"] === "" || !($_SESSION["loggued_on_user"]))
	{
		echo "<form method=\"post\" action=\"./login.html\"><input type=\"submit\" name=\"submit\" value=\"Connexion\"></form>";
	}
	else if ((count($_SESSION['panier'])))
	{
		echo "<form method=\"post\" action=\"./buy.php\"><input type=\"submit\" name=\"submit\" value=\"Valider\"></form>";
	}
	?>
</body>
</html>

<style type="text/css">
body
{
  margin:0px;
  padding:0px;
   font-family: 'Raleway', sans-serif;
  background-image: linear-gradient(#9E9C31 0%, black 60%);;
  background-size: cover;
  color:#fff;
  font-weight:300;
 /* overflow: hidden;*/
}
.box{
	border: 10px solid #fff;
	width: 25%;
	margin: 100px auto;
	border-radius: 10px;
	line-height: 30px;
	font-size: 20px;
}
input{
	height: 20px;
}
input[type="submit"]{
 cursor:pointer;
 height: 50px!important;
     font-size: 50px!important;
}
</style>