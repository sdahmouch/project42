<?php session_start();
?>

<!DOCTYPE html>

<html>

<head>

<meta charset="utf-8"/>
<meta http-equiv="X-UA-Compatible" content=="IE=edge"/>
<meta name="google" value="notranslate"/>
<link rel="stylesheet" type="text/css" href="menu.css">
<link href="https://fonts.googleapis.com/css?family=Raleway" rel="stylesheet">
<title>Shop</title>

</head>
<body>

<nav class="main-menu">


<div class="settings" style="padding-top: 20px;font-size: 30px;"><a style="color: #fff!important;text-decoration: none;"><?php echo $_SESSION["loggued_on_user"]?>
    </a> </div>
<div class="scrollbar" id="style-1">
      
<ul>
<?php

if ($_SESSION["loggued_on_user"] === "" || !($_SESSION["loggued_on_user"]))
{ 
	?> 
<li>     
<a href="login.html">                              
<img src="https://cdn2.iconfinder.com/data/icons/font-awesome/1792/user-48.png">
<span class="nav-text"  style="">
	Se Connecter</span>
</a>
</li>  

<li>                                 
<a href="./inscript.html">
<img src="https://cdn2.iconfinder.com/data/icons/font-awesome/1792/sign-in-48.png">
<span class="nav-text">S'inscrire</span>
</a>
</li>  
<?
}
else
{
?> 
   
<li>                                 
<a href="logout.php">
<img src="https://cdn2.iconfinder.com/data/icons/font-awesome/1792/user-48.png">
<span class="nav-text">Se Deconnecter</span></a>

</li>   

    
<li>                                 
<a href="./account.php">
<img src="https://cdn4.iconfinder.com/data/icons/developer-set-3/128/settings-48.png">
<span class="nav-text">Mon compte</span>
</a>
</li>   
  
<?php
}
?>
  
<li class="darkerlishadowdown">
<span class="nav-text" style="height:48px;">
</span>
</li>
   
</ul>

 
<li style="background: yellow;">                                 
<a href="./panier.php">
<img src="https://cdn2.iconfinder.com/data/icons/e-commerce-glyph-2/614/8_-_Shopping_Cart-48.png">
<span class="nav-text">Panier</span>
</a>
</li>                         


<li style="background: red;">                                 
<a href="./admin.html">
<img src="https://cdn1.iconfinder.com/data/icons/ios-11-glyphs/30/attention-48.png">
<span style="color:#fff;" class="nav-text">ADMIN</span>
</a>
</li>  


</nav>

</body>
</html>

<style type="text/css">
body
{
  margin:0px;
   padding-bottom: 100px;
  background-image: linear-gradient(#001063 0%, black 60%);;
  background-size: cover;
  color:#fff;
  font-weight:300;
   font-family: 'Raleway', sans-serif;
 /* overflow: hidden;*/

}


@import url(//netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css);
}
@import url(https://fonts.googleapis.com/css?family=Titillium+Web:300);

.adm{
	font-size: 20px;
	height: 50px;
}

.logo{
  
}

.settings {
  
  height:73px; 
  float:left;
  background:black;
  background-repeat:no-repeat;
  width:250px;
  margin:0px;
 text-align: center;
font-size:20px;
font-family: 'Strait', sans-serif;

}

.scrollbar
{

height: 90%;
width: 100%;
overflow-y: hidden;
overflow-x: hidden;
}

.scrollbar:hover
{

height: 90%;
width: 100%;
overflow-y: scroll;
overflow-x: hidden;
}

#style-1::-webkit-scrollbar-track
{
border-radius: 2px;
}

#style-1::-webkit-scrollbar
{
width: 5px;
background-color: #F7F7F7;
}

#style-1::-webkit-scrollbar-thumb
{
border-radius: 10px;
-webkit-box-shadow: inset 0 0 6px rgba(0,0,0,.3);
background-color: #BFBFBF;
}

.fa-lg {
font-size: 1em;
  
}
.fa {
position: relative;
display: table-cell;
width: 55px;
height: 36px;
text-align: center;
top:12px; 
font-size:20px;

}



.main-menu:hover, nav.main-menu.expanded {
width:250px;
overflow:hidden;
opacity:1;

}

.main-menu {
background:#F7F7F7;
position:fixed;
top:0;
bottom:0;
height:100%;
left:0;
width:65px;
overflow:hidden;
-webkit-transition:width .2s linear;
transition:width .2s linear;
-webkit-transform:translateZ(0) scale(1,1);
box-shadow: 1px 0 15px rgba(0, 0, 0, 0.07);
  opacity:1;
}

.main-menu>ul {
margin:7px 0;

}

.main-menu li {
position:relative;
display:block;
width:250px;
  


}

.main-menu li>a {
position:relative;
width:255px;
display:table;
border-collapse:collapse;
border-spacing:0;
color:#8a8a8a;
font-size: 13px;
text-decoration:none;
-webkit-transform:translateZ(0) scale(1,1);
-webkit-transition:all .14s linear;
transition:all .14s linear;
font-family: 'Strait', sans-serif;
border-top:1px solid #f2f2f2;

text-shadow: 1px 1px 1px  #fff;  
}



.main-menu .nav-icon {
  
position:relative;
display:table-cell;
width:55px;
height:36px;
text-align:center;
vertical-align:middle;
font-size:18px;

}

.main-menu .nav-text  {
   
position:relative;
display:table-cell;
vertical-align:middle;
width:190px;
font-family: 'Titillium Web', sans-serif;
}

.main-menu .share {
}



.main-menu .fb-like {

left: 180px;
position:absolute;
top: 15px;
}

.main-menu>ul.logout {
position:absolute;
left:0;
bottom:0;
  
}

.no-touch .scrollable.hover {
overflow-y:hidden;

}

.no-touch .scrollable.hover:hover {
overflow-y:auto;
overflow:visible;
  
}


/* Logo Hover Property */


.settings:hover, settings:focus {   
  background:black;
  -webkit-transition: all 0.2s ease-in-out, width 0, height 0, top 0, left 0;
-moz-transition: all 0.2s ease-in-out, width 0, height 0, top 0, left 0;
-o-transition: all 0.2s ease-in-out, width 0, height 0, top 0, left 0;
transition: all 0.2s ease-in-out, width 0, height 0, top 0, left 0; 
}

.settings:active, settings:focus {   
  background:black;
  -webkit-transition: all 0.1s ease-in-out, width 0, height 0, top 0, left 0;
-moz-transition: all 0.1s ease-in-out, width 0, height 0, top 0, left 0;
-o-transition: all 0.1s ease-in-out, width 0, height 0, top 0, left 0;
transition: all 0.1s ease-in-out, width 0, height 0, top 0, left 0; 
}


a:hover,a:focus {
text-decoration:none;
border-left:0px solid #F7F7F7;



}

nav {
-webkit-user-select:none;
-moz-user-select:none;
-ms-user-select:none;
-o-user-select:none;
user-select:none;
  
}

nav ul,nav li {
outline:0;
margin:0;
padding:0;
text-transform: uppercase;
}




/* Darker element side menu Start*/


.darkerli
{
background-color:#ededed;
text-transform:capitalize;  
}

.darkerlishadow
{
background-color:#ededed;
text-transform:capitalize;  
-webkit-box-shadow: inset 0px 5px 5px -4px rgba(50, 50, 50, 0.55);
-moz-box-shadow:    inset 0px 5px 5px -4px rgba(50, 50, 50, 0.55);
box-shadow:         inset 0px 5px 5px -4px rgba(50, 50, 50, 0.55);
}


.darkerlishadowdown
{
background-color:#ededed;
text-transform:capitalize;  
-webkit-box-shadow: inset 0px -4px 5px -4px rgba(50, 50, 50, 0.55);
-moz-box-shadow:    inset 0px -4px 5px -4px rgba(50, 50, 50, 0.55);
box-shadow:         inset 0px -4px 5px -4px rgba(50, 50, 50, 0.55);
}

/* Darker element side menu End*/




.main-menu li:hover>a,nav.main-menu li.active>a,.dropdown-menu>li>a:hover,.dropdown-menu>li>a:focus,.dropdown-menu>.active>a,.dropdown-menu>.active>a:hover,.dropdown-menu>.active>a:focus,.no-touch .dashboard-page nav.dashboard-menu ul li:hover a,.dashboard-page nav.dashboard-menu ul li.active a {
color:#fff;
background-color:#3AADDE;
text-shadow: 0px 0px 0px; 
}
.area {
float: left;
background: #e2e2e2;
width: 100%;
height: 100%;
}
@font-face {
  font-family: 'Titillium Web';
  font-style: normal;
  font-weight: 300;
  src: local('Titillium WebLight'), local('TitilliumWeb-Light'), url(http://themes.googleusercontent.com/static/fonts/titilliumweb/v2/anMUvcNT0H1YN4FII8wpr24bNCNEoFTpS2BTjF6FB5E.woff) format('woff');
}

</style>