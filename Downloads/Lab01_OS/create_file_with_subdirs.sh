#   Chaker Baloch
#   Operating System
#   Lab01
#   April 23, 2025


#!/bin/bash

# date as the name of main directory
main_name=$(date +"%Y-%m-%d_%H-%M-%S")

#list of languages
languages=(C C++ Java Python JavaScript Go Ruby Rust TypeScript Kotlin)

#check if the directory already exists
if [ -d "$main_name" ]; then 
    echo "Directory '$main_name' already exists."
else
    #create main directory
    mkdir "$main_name"

    for i in {101..110}; do
        # create the subdirectory
        subdir="$main_name/files$i"
        mkdir -p "$subdir"


        # compute the single file name (101→501)
        j=$(( i + 400 ))
        filename="tuser${j}.txt"

        # create *.txt files in the subdirectory
        touch "$subdir/$filename"

        filepath="$subdir/$filename"

        idx=$(( i - 101 ))   # 101→0, 102→1, …, 110→9

        # pick the language and write it into the file
        lang="${languages[$idx]}"
        echo "$lang" > "$filepath" 
    done
fi


