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
		<link rel="stylesheet" type="text/css" href="menu.css">
	</head>
	<body >
			<form method="post" class="box">
			Liste des comptes:
			<h1>
			admin <br \><?php
			if (!(file_exists("./private")))
			{
				mkdir("./private");
			}
			if (!(file_exists("./private/passwd")))
			{
				$fd = fopen("./private/passwd", 'w+');
			}
			$pass = unserialize(file_get_contents("./private/passwd"));
			if ($pass)
			{
				foreach ($pass as $key => $elem)
				{
					echo $elem['login']."<BR/>";
				}
			}
		?>
		</h1>
		</form>
		<form method="post" action="./modifadmin.html" class="box">
			<input type="submit" name="submit" value="Modifier un compte">
			</form>
		<form method="post" action="./index.php">
			<input type="submit" name="submit" value="Page d'accueil">
		</form>
		<form method="post" action="./gestion.php">
			<input type="submit" name="submit" value="Gerer articles">
		</form>
	
	</div>	
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