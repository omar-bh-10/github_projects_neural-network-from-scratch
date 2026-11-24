arbres.exe:p_arbres.o p_noeud.o main.o
	gcc -o arbres.exe p_arbres.o p_noeud.o main.o

main.o:main.c p_arbres.h p_noeud.h
	gcc -c main.c

p_arbres.o:p_arbres.c p_arbres.h p_noeud.h
	gcc -c p_arbres.c 

p_noeud.o:p_noeud.c p_noeud.h
	gcc -c p_noeud.c 