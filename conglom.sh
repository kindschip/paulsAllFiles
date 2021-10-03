#! /usr/bin/env bash

# Arguments
echo $1
echo $2

# need braces for n > 9
echo ${3}

# command used to call program
echo $0

# number of arguments
echo $#

# space separated string of args
echo $*



#! /usr/bin/env bash

# Array creation
simple_arr=(hello world)
simple_arr2=(1 2 3)

arr_ex2[2]=hello
arr_ex2[3]=world
arr_ex2[0]=sunny

# accessing array elements
echo ${simple_arr[0]}
echo ${simple_arr[1]}
echo ${arr_ex2[1]}

# array indices
echo "array indices"
echo ${!arr_ex2[@]}

# number of items
echo "number of items"
echo ${#arr_ex2[@]}

# concatenating arrays
arr_ex3=(
    snowy
    icy
    cold
)
arr_ex3+=(sunny hot rainy)
echo ${arr_ex3}
echo ${arr_ex3[5]}

# slicing
echo ${arr_ex3[@]:2:3}

# array of all elements
echo ${arr_ex3[@]}

# string representation of array
echo ${arr_ex3[*]}


# Associative arrays
declare -A aarr
aarr=(
    [rainy]=6
    [cloudy]=7
    [warm]=1
)
echo "---start associative---"

# getting array indices
echo ${!aarr[@]}

# looping through associative array
for key in ${!aarr[@]}
do
    echo "$key has value ${aarr[$key]}"
done
#! /usr/bin/env bash
# this is a comment
echo "hello world"
echo "goodbye world"
#! /usr/bin/env bash

# Conditionals

mynum=6
mynum2=4

if [ $mynum -eq $mynum2 ]; then
    echo "they are equal"
elif [ $mynum -lt $mynum2 ]; then
    echo "mynum < mynum2"
else
    echo "mynum > mynum2"
fi

# Combining conditionals
mynum3=6
if [ $mynum -eq $mynum2 ] && [ $mynum2 -eq $mynum3 ]; then
    echo "all three are equal"
fi

# Using Arithmetic for Conditionals
if ((mynum2 < mynum)); then
    echo "num2 less than num"
fi
#! /usr/bin/env bash

# function definition
hello_world () {
    echo "hello world"
}

hello_world () {
    echo "hello world $1 it is an $2 day"
}

# calling the function
hello_world
hello_world Bob awful
hello_world Alice good
#! /usr/bin/env bash

# Loops

for val in  0 1 2 3 4
do
    echo $val
done

for color in orange green blue yellow
do
    echo $color
done

for val in {1..11..2}
do
    echo $val
done

# Loop through argument array
for arg in $@
do
    echo $arg
done

# While loop
num=3
while [ $num -gt 0 ];
do
    echo $num
    num=$((num-1))
done

# While loop to shift through input
while (($# > 0))
do
    echo "$1, $#"
    shift
done
#! /usr/bin/env bash

# Variables
mynum=5
mynum2=2
mycolor=orange
mymsg="my number is $mynum"

echo $mynum
echo $mycolor
echo $mymsg
echo $mynum2

# Arithmetic Expansion
echo "1+1 = $((1+1))"
echo $((mynum+mynum2))
mysum=$((mynum-mynum2))
echo "my sub is $mysum"
