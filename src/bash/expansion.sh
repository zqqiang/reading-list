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

names() {
    echo "The Name Script"
    echo "usage: names 'My Full Name'"; echo
    first=${1%% *} last=${1##* } middle=${1#$first} middle=${middle%$last}
    echo "Your first name is: $first"
    echo "Your last name is: $last"
    echo "Your middle names are: $middle"
}

names 'Zhaoqing Bill Qiang'

set -- 'New First Argument' Second Third 'Fourth Argument'
echo "1: $1, 2: $2, 4: $4"

shift 2
echo "1: $1, 2: $2, 4: $4"

bash -cv 'echo "1: $1, 2: $2, 4: $4"' -- 'New First Argument' Second Third 'Fourth Argument'