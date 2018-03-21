#!/usr/bin/php  
<?php

$list = array (
   array('image;description;prix;id;categorie;'),
   array('img/1.jpg;Casquette Munar;20,90 €;1;casquette!'),
   array('img/2.jpg;Casquette Boox;19,90 €;2;casquette!'),
   array('img/3.jpg;Casquette Pima;23,90 €;3;casquette!'),
   array('img/4.jpg;Casquette Trolux;19,90 €;4;casquette!'),
   array('img/5.jpg;Casquette Boogie;19,90 €;5;casquette!'),
   array('img/6.jpg;Casquette Azur;32,24 €;6;casquette!'),
   array('img/7.jpg;T-Shirt Salomone;32,10 €;7;t-shirt!'),
   array('img/8.jpg;T-Shirt Fila Raw;48,50 €;8;t-shirt!'),
   array('img/9.jpg;T-Shirt Hook;40,90 €;9;t-shirt!'),
   array('img/10.jpg;T-Shirt Captain;40,90 €;10;t-shirt!'),
   array('img/11.jpg;T-Shirt Jacko;28,10 €;11;t-shirt!'),
   array('img/12.jpg;T-Shirt Uii;45,80 €;12;t-shirt!'),
   array('img/13.jpg;Jeans Armano;82,10 €;13;pant!'),
   array('img/14.jpg;Jeans Lewis;84,50 €;14;pant!'),
   array('img/15.jpg;Jeans Celia;89,90 €;15;pant!'),
   array('img/16.jpg;Jeans Essence;89,90 €;16;pant!'),
   array('img/17.jpg;Jeans Militano;89,90 €;17;pant!'),
   array('img/18.jpg;Jeans Kook;99,90 €;18;pant!'),
   array('img/19.jpg;T-Shirt Sweet;45,80 €;19;t-shirt!'),
   array('img/20.jpg;Jeans Skinny;90,90 €;20;pant!'),
   array('img/21.jpg;Jeans Tati;78,50 €;21;pant!'),
   array('img/22.jpg;T-Shirt Waze;40,90 €;22;t-shirt!'),
   array('img/23.jpg;Casquette Base-Ball;29,90 €;23;casquette!'),
   array('img/24.jpg;Casquette Base-Ball;29,90 €;24;casquette!')
);

$fp = fopen('stock.csv', 'w');

foreach ($list as $fields) {
    fputcsv($fp, $fields);
}

fclose($fp);
?>
