.RECIPEPREFIX := >a

arbres.exe: main.o p_arbre.o p_noeud.o p_element.o abo.o
>gcc -o arbres.exe main.o p_arbre.o p_noeud.o p_element.o abo.o

main.o: main.c p_arbre.h p_noeud.h abo.h
>gcc -c main.c

abo.o:abo.c abo.h p_arbre.h
>gcc -c abo.c

p_arbre.o: p_arbre.c p_arbre.h p_noeud.h p_element.h
>gcc -c p_arbre.c

p_element.o: p_element.c p_element.h
>gcc -c p_element.c

p_noeud.o: p_noeud.c p_noeud.h p_element.h
>gcc -c p_noeud.c


