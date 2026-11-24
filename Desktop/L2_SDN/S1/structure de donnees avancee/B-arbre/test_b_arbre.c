#include <stdlib.h>
#include <stdio.h>
#include "p_b_arbre.h"

#define TAILLE 10

t_element mon_tableau[TAILLE+1];
int ma_taille;

void initialiser_tab(){
    for(t_indice i = 0; i < TAILLE; i++){
        mon_tableau[i] = 2*i;
    }
    ma_taille = TAILLE;
}

a_noeud mon_arbre = B_ARBRE_VIDE;
a_noeud mon_fils = B_ARBRE_VIDE;
t_element out;
t_element in;
t_element mon_element;

int main(){

    initialiser_tab();
    afficher_tab(mon_tableau, TAILLE);
    decaler_tab_gauche(mon_tableau,3);
    afficher_tab(mon_tableau, TAILLE);
    initialiser_tab();
    afficher_tab(mon_tableau, TAILLE);
    decaler_tab_droite(mon_tableau, TAILLE);
    afficher_tab(mon_tableau, TAILLE);
    initialiser_tab();
    afficher_tab(mon_tableau, TAILLE);
    inserer_tab_apres(5, mon_tableau, 2, &out);
    printf("out : %d\n", out);
    afficher_tab(mon_tableau, TAILLE);

    initialiser_tab();
    afficher_tab(mon_tableau, TAILLE);
    inserer_tab_avant(5, mon_tableau, &ma_taille, 3);
    printf("out : %d\n", out);
    afficher_tab(mon_tableau, TAILLE);

    for(t_element i = -1; i < 2*TAILLE; i++){
        printf("insertion de %d à la position %d\n", i, position_insertion(i, mon_tableau, TAILLE));
    }

    for(t_element i = -1; i < 2*TAILLE; i++){
        initialiser_tab();
        printf("Avant : ");
        afficher_tab(mon_tableau, ma_taille);
        inserer_tab(i, mon_tableau, &ma_taille);
        printf("Apres : ");
        afficher_tab(mon_tableau, ma_taille);
    }
    mon_arbre = nouvelle_racine_b_arbre(55);
    afficher_b_arbre(mon_arbre, 0);
    printf("=====\n");
    for(int i=0; i < 50; i++){
        mon_element = 7 * i % 101;
        inserer_b_arbre(&mon_arbre, mon_element);
        afficher_b_arbre(mon_arbre, 0);
        printf("=====\n");
    }

    return 0;
}
