opt= -c -Wall -Wextra -std=gnu11

test_b_arbre.exe : test_b_arbre.o p_b_arbre.o
	gcc -o test_b_arbre.exe test_b_arbre.o p_b_arbre.o

test_b_arbre.o : test_b_arbre.c p_b_arbre.h
	gcc ${opt} test_b_arbre.c

p_b_arbre.o : p_b_arbre.h p_b_arbre.c
	gcc ${opt} p_b_arbre.c

all : test_b_arbre.exe

clean :
	rm *.o
	rm *.exe


