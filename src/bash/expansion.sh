#!/bin/bash

echo "create files"
touch 'myscript.txt' 'mybudget.xsl' 'hello.txt' '05 Between Angels and Insects.ogg' '07 Wake Up.ogg' 'img_88751.jpg' 'igpd_45qr.jpeg'

ls *

ls 0?' '*.ogg

ls [0-9]*

ls [[:digit:]][[:digit:]]*

ls [[:digit:]][[:digit:]]

echo "enable extended globs"
shopt -s extglob

ls +([:digit:])' '*.ogg

ls *.jp?(e)g

ls *.@(jpg|jpeg)

ls !(my*).txt

ls !(my)*.txt

echo "clean files"

rm -rv 'myscript.txt' 'mybudget.xsl' 'hello.txt' '05 Between Angels and Insects.ogg' '07 Wake Up.ogg' 'img_88751.jpg' 'igpd_45qr.jpeg'

echo 'home is: ' ~

echo 'root home is: ' ~root

echo 'Hello world.' > hello.txt

echo "The file <hello.txt> contains: $(cat hello.txt)"

rm -v hello.txt

greeting="hello"

echo "$greeting"

greeting+=" world"

echo "${greeting##* }"

echo "${greeting^}."

echo "${greeting/ / big }"

echo "$greeting" > "${greeting// /_}.txt"

rm -v "${greeting// /_}.txt"

greeting="${greeting/ / big }"
echo "${greeting}"
middle=${greeting% *};echo "${middle}"
middle=${middle#* };echo "${middle}"
echo "${greeting%% *} ${middle^^} ${greeting##* }"

echo "What is the environment and what is it used for?"

