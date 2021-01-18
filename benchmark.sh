#!/bin/bash

echo "# # # # # # # # # # # # # # # # # # # #"
echo "#     TESTING ${1}            #"
echo "# # # # # # # # # # # # # # # # # # # #"

echo "# # # # # # # # # # # # # # # # # # # #"
echo "#             COMPILING               #"
echo "# # # # # # # # # # # # # # # # # # # #"
make ALG=$1

echo "# # # # # # # # # # # # # # # # # # # #"
echo "#           VALGRIND TESTS            #"
echo "# # # # # # # # # # # # # # # # # # # #"
./memtest.sh ./bin/$1.out

echo "# # # # # # # # # # # # # # # # # # # #"
echo "#           RUNNING TESTS             #"
echo "# # # # # # # # # # # # # # # # # # # #"
for i in {0..10}
do
    echo $(time ./bin/$1.out)
done
