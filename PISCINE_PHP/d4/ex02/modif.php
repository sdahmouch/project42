<?php

if ($_POST['login'] && $_POST['oldpw'] && $_POST['newpw'] && $_POST['submit'] === "OK" && file_exists('../private/passwd'))
    {
        
        $login = $_POST['login'];
        $oldpass = hash("whirlpool", $_POST['oldpw']);
        $newpass = hash("whirlpool", $_POST['newpw']);

        $modif = unserialize(file_get_contents("../private/passwd"));

        if ($modif)
        {
            foreach ($modif as &$tab)
            {
                if ($tab['login'] === $login && $tab['passwd'] === $oldpass)
                {
                    $tab['passwd'] = $newpass;
                    file_put_contents("../private/passwd", serialize($modif));
                    echo "OK\n";
                    return ;
                }
            }
        }
    }
    echo "ERROR\n";