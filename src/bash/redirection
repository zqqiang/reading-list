#!/bin/bash

# error redirection
ls -l a b >myfiles.ls 2>myfiles.ls

# right
ls -l a b >myfiles.ls 2>&1

# imporve
ls -l a b &>myfiles.ls

# here string
cat <<<"Hello world.
Since I started learning bash, you suddenly seem so much bigger than you were before."
# Here strings are very similar to here documents but more concise. They are generally preferred over here documents.

# Open FD x for both reading and writing to file.
exec 5<>/dev/tcp/ifconfig.me/80

echo "GET /ip HTTP/1.1
> Host: ifconfig.me
> " >&5
cat <&5
HTTP/1.1 403 Forbidden
Date: Sun, 26 Aug 2018 03:18:09 GMT
Server: Apache
Vary: Accept-Encoding
Content-Length: 204
Connection: close
Content-Type: text/html; charset=iso-8859-1

<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
<html><head>
<title>403 Forbidden</title>
</head><body>
<h1>Forbidden</h1>
<p>You don't have permission to access /ip
on this server.</p>
</body></html>
