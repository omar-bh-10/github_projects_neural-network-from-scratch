#include <stdio.h> //input output permet d'utiliser tout ce qui est ecrit dans le fichier stdio.h
#define NB_REPETITIONS 5 // c'est un symbole = le preprocesseur va remplaczer nb_repetitions par 5

int main(int argc, char** argv){ //ligne de commandes   //pointeur vers un chaine de caractere
    int i; //declaration
    for(i=0; i < NB_REPETITIONS ; i++){ //affectation
        printf("Hello World\n");
    }
    return 0; // lz programme est bien
}