#ifndef P_B_ARBRE_H
#define P_B_ARBRE_H
#include <stdlib.h>

typedef int t_element;

/* TABLEAUX TRIES */

typedef int t_indice;

void afficher_tab(t_element* ceci, int taille);

void decaler_tab_gauche(t_element* ceci, int taille);

void decaler_tab_droite(t_element* ceci, int taille);

/**
    Avec decalage des éléments précédents vers la gauche
    Le 1er élément du tableau est placé dans *<premier>
    */
void inserer_tab_apres(t_element ceci, t_element* dans, t_indice position, t_element* premier);

void inserer_tab_avant(t_element ceci, t_element* dans, int* taille, t_indice position);

t_indice position_insertion(t_element ceci, t_element* dans, int taille);

void inserer_tab(t_element ceci, t_element* dans, int* taille);

/* NOEUD */
#define K 2

typedef struct s_noeud{
    t_element les_etiquettes[2 * K + 1]; /* Un element de plus pour le confort des insertions */
    int le_nb_elements;
    struct s_noeud* les_fils[2 * K + 2];
}t_noeud;

typedef t_noeud* a_noeud;

void debugguer_noeud(a_noeud ceci);

int est_noeud_sature(a_noeud ceci);

void exploser_noeud(a_noeud ceci, t_element* median, a_noeud* nouveau);

void inserer_noeud(t_element* ceci, a_noeud dans, a_noeud* nouveau);



/* B_ARBRE */
#define B_ARBRE_VIDE NULL

typedef a_noeud t_b_arbre;

t_b_arbre nouvelle_racine_b_arbre(t_element racine);

void inserer_b_arbre(t_b_arbre *ceci, t_element quoi);

void afficher_b_arbre(t_b_arbre ceci, int decalage);

#endif