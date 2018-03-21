<?php
	session_start();
?>
<html>
<head>
	<meta charset="UTF-8">
	<title>Attention</title>
</head>
<body>
	<form methode="post" action="" class="box">
		Merci de votre achat !<br>
		Rappel :
		<?php
		echo $_SESSION["loggued_on_user"];	
		echo "<br />";
		foreach ($_SESSION['panier'] as $elem)
		{
			echo $elem . "<br \>";
		}
		unset($_SESSION['panier']);
		$_SESSION['panier']= array();
		?>

	</form>
	<form method="post" action="./index.php">
		<input class="button1" type="submit" name="submit" value="Page d'accueil"/>
	</form>
</body>
</html>


<style type="text/css">
body
{
  margin:0px;
  text-align: center;
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