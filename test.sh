#!/bin/sh

mkdir -p bin/
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./bin/$1.out


         # --log-file=bin/valgrind-$1.log \
