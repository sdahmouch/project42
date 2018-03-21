<?php
	session_start();
if ($_SESSION["loggued_on_user"] === "" || !($_SESSION["loggued_on_user"]))
{
	header("Location: ./login.html");
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
		<form method="post" action="create.php" class="box">
			<?php
			if (!(file_exists("./private"))) {
				mkdir("./private");
			}
			if (!(file_exists("./private/passwd"))) {
				$fd = fopen("./private/passwd", 'w+');
			}
			$pass = unserialize(file_get_contents("./private/passwd"));
			if ($pass) {
				foreach ($pass as $key => $elem)
				{
					if ($elem["login"] === $_SESSION["loggued_on_user"])
						$i = $key;
				}
			}
			echo "BONJOUR : ".$_SESSION["loggued_on_user"]."<BR /><h3>Voici vos informations : </h3>";
			echo "Nom : ".$pass[$i]["nom"]."<BR/>";
			echo "Prenom : ".$pass[$i]["prenom"]."<BR/>";
			echo "Adresse : ".$pass[$i]["address"]."<BR/>";
			?>
		</form>
		<form method="post" action="./deleteok.php">
			<input type="submit" name="submit" value="Supprimer le compte">
		</form>
		<form method="post" action="./index.php">
			<input type="submit" name="submit" value="Page d'accueil">
		</form>
		<form method="post" action="./modifinfo.html">
			<input type="submit" name="submit" value="Modifier vos informations">
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