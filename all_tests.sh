#!/bin/bash

make clean
out=./data/final
mkdir -p $out

make ALG=bst_iter
make ALG=bst_recur
make ALG=list_iter
make ALG=list_recur

./benchmark.sh bst_iter > $out/bst_iter.log
./benchmark.sh bst_recur > $out/bst_recur.log

./benchmark.sh list_iter > $out/list_iter.log
./benchmark.sh list_recur > $out/list_recur.log
