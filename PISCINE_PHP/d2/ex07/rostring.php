#!/usr/bin/php 
<?php
function ft_split($str)
{
	$str =trim($str);
	$tab = preg_split("/[\s]+/", $str);
	return $tab;
}
if ($argc > 1)
{
	$tab = ft_split($argv[1]);
	for ($i = 1; $i < count($tab); $i++)
	{
		echo "$tab[$i]";
		echo " ";
	}
	echo "$tab[0]\n";
}