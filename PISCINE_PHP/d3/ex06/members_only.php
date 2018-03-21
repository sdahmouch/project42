<?php
if (($_SERVER['PHP_AUTH_USER'] != 'zaz') || ($_SERVER['PHP_AUTH_PW'] != 'jaimelespetitsponeys')) {
    header('Content-Type:text/html');
    header("WWW-Authenticate: Basic realm=''Espace membres''");
    header('HTTP/1.0 401 Unauthorized');
    echo '<html><body>Cette zone est accessible uniquement aux membres du site</body></html>'."\n";
    exit;
} else {
	header('Content-Type:text/plain');
    echo "<html><body>\nBonjour Zaz<br />\n";
    $imgData = base64_encode(file_get_contents('../img/42.png'));
    echo "<img src='data:image/png;base64,$imgData'>\n</body></html>\n";
}
?>