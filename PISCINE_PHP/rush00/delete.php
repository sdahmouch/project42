<?php
	session_start();
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
		$i = 0;
		foreach ($pass as $key => $elem)
		{
			if ($elem["login"] === $_SESSION["loggued_on_user"])
			{
				unset($pass[$i]);
			}
			$i++;
		}
		file_put_contents("./private/passwd", serialize($pass1));
	}
	unset($_SESSION["loggued_on_user"]);
	session_destroy();
	header('Location: ./index.php');
?>
<html>
<head>
	<meta charset="UTF-8">
	<title>Attention</title>
</head>
<body>
	<form method="post" action="./index.php" class="box">
		Compte supprimé !
		<input class="button" type="submit" value="Retour Menu"/>
	</form>
</div>	
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