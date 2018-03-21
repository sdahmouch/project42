<?php
	session_start();
?>
<html>
<head>
	<meta charset="UTF-8">
	<title>Attention</title>
</head>
<body>
	<form method="post" action="./delete.php" class="box">

		Vous etes sur de vouloir supprimer votre compte: <?php echo $_SESSION["loggued_on_user"]."<BR?>"?>
		<input type="submit" value="OUI"/>

	</form>
<form method="post" action="./index.php">
	<input class="button2" type="submit" value="Retour Menu"/>
</form>
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