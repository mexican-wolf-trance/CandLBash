#!/bin/bash

echo 'enter 1 2 or 3'
read num
function1 ()
{
 echo 'You typed one you idiot!'
}
function2 ()
{
 echo 'You typed two, but it wasn't good enough!'
}
function3 ()
{
 echo 'Now that's more like it!'
}
if [[ $num > 3 ]]
 then
   echo "That isn't an option. It never was..."
else
 function$num   
fi

