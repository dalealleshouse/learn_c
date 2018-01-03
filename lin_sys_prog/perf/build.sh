clang -o bufio bufio.c
clang -o rawio rawio.c

echo "bufio"
time ./bufio 1 1000000
echo "----------------------"

echo "rawio"
time ./rawio 1 1000000
echo "----------------------"
