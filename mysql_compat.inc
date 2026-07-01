<?php
// Compatibility shim: old ext/mysql API (removed in PHP 7) reimplemented on mysqli,
// so this legacy codebase can run unmodified on PHP 8.

$GLOBALS['__mysql_link'] = null;

function mysql_connect($host, $user, $pass)
{
    $GLOBALS['__mysql_link'] = mysqli_connect($host, $user, $pass);
    return $GLOBALS['__mysql_link'];
}

function mysql_select_db($dbname, $link = null)
{
    $link = $link ?: $GLOBALS['__mysql_link'];
    return mysqli_select_db($link, $dbname);
}

function mysql_query($query, $link = null)
{
    $link = $link ?: $GLOBALS['__mysql_link'];
    return mysqli_query($link, $query);
}

function mysql_error($link = null)
{
    $link = $link ?: $GLOBALS['__mysql_link'];
    return $link ? mysqli_error($link) : mysqli_connect_error();
}

function mysql_fetch_array($result, $type = MYSQLI_BOTH)
{
    return $result ? mysqli_fetch_array($result, $type) : false;
}

function mysql_num_rows($result)
{
    return $result ? mysqli_num_rows($result) : 0;
}

function mysql_result($result, $row, $field = 0)
{
    if (!$result || !mysqli_data_seek($result, $row)) {
        return false;
    }
    $data = mysqli_fetch_array($result);
    return $data[$field] ?? false;
}
