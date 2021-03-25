cc -c stack.c vector.c list.c -D VECTOR -std=c99

ar cr libvector.a stack.o vector.o list.o

cc -o s_vector main.c -I. -L. -lvector -D VECTOR
