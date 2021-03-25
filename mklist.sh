cc -c stack.c vector.c list.c -D LIST -std=c99

ar cr liblist.a stack.o vector.o list.o

cc -o s_list main.c -I. -L. -llist -D LIST
