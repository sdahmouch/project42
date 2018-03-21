#!/usr/bin/php
<?php
function ft_split($str)
{
	$str = trim($str);
	$str = preg_split("/[\s]+/", $str);
	sort($str);
	return $str;
}

for ($i = 1; $i < $argc; $i++){
	if ($i + 1 < $argc)
		$argv[1] = $argv[1]." ".$argv[$i + 1];
}
if ($argc > 1){
	$tab = ft_split($argv[1]);
	for ($i = 0; $i < count($tab); $i++){
		if ($i < count($tab)){
			echo "$tab[$i]\n";
		} 
	}
}
?>