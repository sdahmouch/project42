<?php
function ft_split($str)
{
	$str = trim($str);
	$str = preg_split("/[\s,]+/", $str);
	sort($str);
	return $str;
}
?>