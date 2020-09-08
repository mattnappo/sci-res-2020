#!/bin/sh

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-$1.log \
         ./bin/$1.out
