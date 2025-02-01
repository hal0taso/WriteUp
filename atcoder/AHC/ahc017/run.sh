#!/usr/bin/env bash
cd "/Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/ABC/ahc017/"
g++ sa.cpp -std=c++17 -o sa

for input in `ls /Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/ABC/ahc017/in`
do
echo $input
"/Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/ABC/ahc017/"sa < "/Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/ABC/ahc017/in/"$input 1> '/Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/ABC/ahc017/out7/'$input 2> '/Users/hal0taso/.ghq/github.com/hal0taso/WriteUp/atcoder/ABC/ahc017/err/'$input
done