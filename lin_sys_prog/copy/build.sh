clang -o sys_call sys_call.c
clang -o stdlib stdlib.c
clang -o mmap mmap.c

echo "system calls"
time ./sys_call
echo "----------------------"

echo "standard library"
time ./stdlib
echo "----------------------"

echo "mmap"
time ./mmap
echo "----------------------"
