arbres.exe: p_element.o noeud.o
    gcc -o arbres.exe p_element.o noeud.o

noeud.o: noeud.c noeud.h
    gcc -c noeud.c



sc_grille.exe: sc_grille.o p_grille.o p_element.o
	gcc -o sc_grille.exe sc_grille.o p_grille.o p_element.o 



sc_grille.o: sc_grille.c  p_grille.h
	gcc -c sc_grille.c 

p_grille.o: p_grille.c  p_grille.h
	gcc -c p_grille.c

p_element.o:p_element.c p_element.h
	gcc -c p_element.c

p_grille2.o:p_grille2.c p_grille2.h
	gcc -c p_grille2.c