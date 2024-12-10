#!/bin/bash

# Compile the C code
cc -Wextra -Wall -Werror test/*.c srcs/*.c -o c.exe

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    clear
    echo " ********** Compilation successful. Running c.exe... ********** "
    valgrind ./c.exe | cat -e
    #./c.exe | cat -e
else
    echo "Compilation failed. Please fix the errors and try again."
fi