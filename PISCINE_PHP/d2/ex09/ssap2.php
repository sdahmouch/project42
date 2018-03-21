#!/usr/bin/php
<?php
    if (!$argv[1])
        exit;
    $i = 0;
    $arr = [];
    while (++$i < $argc)
    {
        $tmp = explode(' ', $argv[$i]);
        $j = -1;
        while ($tmp[++$j])
        {
            $arr[] = $tmp[$j];
        }
    }
    foreach ($arr as $val)
        if (ctype_alpha($val[0]))
            $string[] = $val;
    if (!is_array($string))
        $string = str_split('');
    sort($string, SORT_NATURAL | SORT_FLAG_CASE);
    foreach ($arr as $val)
        if (is_numeric($val[0]))
            $number[] = $val;
    if (!is_array($number))
        $number = str_split('');
    sort($number, SORT_STRING);
    foreach ($arr as $val)
        if (!is_numeric($val) && !ctype_alpha($val[0]))
            $other[] = $val;
    if (!is_array($other))
        $other = str_split('');
    sort($other);
    foreach ($string as $val)
        if ($val)
            echo $val."\n";
    foreach ($number as $val)
        if ($val)
            echo $val."\n";
    foreach ($other as $val)
        if ($val)
            echo $val."\n";