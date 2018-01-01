clang -o sys_call sys_call.c
clang -o stdlib stdlib.c
clang -o mmap mmap.c

time sys_call
time stdlib
time mmap
