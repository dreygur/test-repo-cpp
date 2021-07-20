#!/bin/bash
rm -rf $1/clang_tidy_output.txt
touch $1/clang_tidy_output.txt
for FILE in $(find $1 -name "*.c" -or -name "*.cpp"); 

# for FILE in $(find $1 -name "*.c" -or -name "*.cpp" -or -name "*.h"); 
do 
    clang-tidy $FILE >> $1/clang_tidy_output.txt;
  done  
