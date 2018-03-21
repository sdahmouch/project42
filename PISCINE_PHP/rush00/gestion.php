<?php
	session_start();
if (!($_SESSION["loggued_on_user"] === "admin"))
{
	header("Location: ./index.php");
}
else
{
	?>
	<html>
	<head>
		<meta charset="UTF-8">
		<title>Connexion</title>
	</head>
	<body style="text-align: center">
			<form method="post" action ="./addarticle.php" class="box">

				Image (chemin relatif): <input type="text" name ="img"/>
				<br />
				Nom: <input type="text" name ="nom"/>
				<br />
				Prix: <input type="text" name ="prix"/>
				<br/>
				Categorie: <input type="text" name ="categorie"/>
				<br />
				<br />
				<?php
			if (!(file_exists("./stock.csv")))
			{
				$fd = fopen("./stock.csv", 'w+');
			}
			else
			{
				$fd = fopen('stock.csv', 'r');
			}
			fgets($fd);
			$i = 0;
			while ($fd && !feof($fd))
			{
			    $a = explode(";", fgets($fd));
			    $db[$i]["img"] = $a[0];
			    $db[$i]["nom"] = $a[1];
			    $db[$i]["prix"] = $a[2];
			    $db[$i]["id"] = $a[3];
			    $db[$i]["categorie"] = $a[4];
			   	echo "$i: ".$db[$i]['nom']."<br />";
			    $i ++;
			}
		?>
		<input type="submit" name="submit" value="Ajouter un produit">
		</form>
		<form method="post" action="./index.php">
			<input type="submit" name="submit" value="Page d'accueil">
		</form>
		<hr />
		<form method="post" action="./delarticle.php">
			Article ID: <input type="text" name ="id"/>
				<br><br>
			<input type="submit" name="submit" value="Supprimer un article">
		</form>
	</body>
	</html>
<?php
}
?>


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