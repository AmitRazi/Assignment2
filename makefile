CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=mylib.o
FLAGS= -Wall -g

all:connections my_mat.a
connections: main.o my_mat.h my_mat.a
	$(CC) $(FLAGS) -o connections main.o my_mat.a -lm
main.o: main.c
	$(CC) $(FLAGS) -c main.c
my_mat.a: my_mat.o
	$(AR) -rcs my_mat.a my_mat.o
my_mat.o: my_mat.c
	$(CC) $(FLAGS) -c my_mat.c
.PHONY: clean all connections
clean:
	rm -f *.o *.a connections
