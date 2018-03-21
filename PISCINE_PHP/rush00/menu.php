<?php session_start();
?>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="menu.css">
	<link href="https://fonts.googleapis.com/css?family=Raleway" rel="stylesheet">
	<title>SHOP</title>
	<meta charset="utf-8">
</head>
<body>
	<style type="text/css">

body
{
  margin:0px;
   padding-bottom: 100px;
  background-image: linear-gradient(#001063 0%, black 60%);;
  background-size: cover;
  color:#fff;
  font-weight:300;
  text-align: center;
  font-family: 'Raleway', sans-serif;
 /* overflow: hidden;*/

}

#menu{
	margin-bottom: 100px;
	margin-top: 0;
	box-shadow: 10px 10px 5px rgba(0,0,0,0.5);
}

img.sample {
    width: 400px;
}

header {
  text-align: center;
}

footer {
    float: right;
    font-style: italic;
}

ul {
    list-style-type: none;
    overflow: hidden;
    background-color: rgba(255,255,255,0.9);
    color: #000!important;
}

li {
    display: inline-block;
    color: #000;
}

li a {
    display: block;
    color: white;
    padding: 20px 150px;
    text-decoration: none;
    font-family: Verdana;
    font-size: 20px;
     color: #000!important;
}

li a:hover {
    background-color: #3AADDE;
    color: #fff;
}

img.logo {
	width: 500px;
}
nav{
    margin-bottom: 3vw;
    margin-top: 0: 
}

.center {
    text-align: center;
}
h1{
	color:#000;
}
</style>
	<header style="background: #f7f7f7; padding: 10px;">
		<a href="index.php">
<img src="https://cdn4.iconfinder.com/data/icons/popular-social-service/110/four-square.png" title="shop" alt="shop" style="display: block;margin: 1vw auto;"></a>

<h1> V Blue Shop </h1> </header>
<!--<?php/*

if ($_SESSION["loggued_on_user"] === "" || !($_SESSION["loggued_on_user"]))
{
	?><form style="display: inline-block;" method="post" action="login.html">
		<input type="submit" name="submit" value="se connecter">
	</form>
	<?
}
else
{
	?><form style="display: inline-block;" method="post" action="logout.php">
		<input type="submit" name="submit" value="se deconnecter">
	</form>
	<form style="display: inline-block;" class="panier" method="post" action="./account.php">
		<input type="submit" name="submit" value="Mon compte">
	</form>
	<?php
}
?>
	<form class="Panier" style="display: inline-block;" method="post" action="./panier.php">
		<input type="submit" name="submit" value="Panier">
	</form>
	<form class="Panier" style="display: inline-block;" method="post" action="./inscript.html">
		<input type="submit" name="submit" value="S'inscrire">
	</form>
	<form class="admin" style="display: inline-block;" method="post" action="./admin.html">
		<input type="submit" name="submit" value="Admin">
	</form>
	</header>
	<?php echo $_SESSION["loggued_on_user"]*/?>
	<nav>
		<ul style="display: inline-block;" >
			<li style="display: inline-block;" class="casquette"><a href="index.php?name=casquette">Casquette</a>
			</li>
		</ul>
		<ul style="display: inline-block;">
			<li style="display: block;" class="t-shirt"><a href="index.php?name=t-shirt">Categorie 2</a>
			</li>
		</ul>
		<ul style="display: inline-block;">
			<li  style="display: inline-block;" class="pant"><a href="index.php?name=pant">Categorie 3</a>
			</li>
		</ul>
	</nav>-->
<ul id="menu">
	        <li class="affiche">
	           <a href="index.php?name=casquette">Casquette</a>


	        </li>	

	        <li class="affiche">
	          <a href="index.php?name=t-shirt">T-Shirt</a>

	        </li>

	        <li class="affiche">
	          <a href="index.php?name=pant">Jeans</a>
	
	        </li>	
	    </ul>
</nav>