#ifndef P_NOEUD_H
#define P_NOEUD_H

#include <stdio.h>
#include <stdlib.h>

/* ----- Types ----- */

/* t_element : dérivé de int */
typedef int t_element;

/* Structure d’un nœud */
typedef struct t_noeud {
    t_element l_etiquette;
    struct t_noeud* la_gauche;
    struct t_noeud* la_droite;
} t_noeud;

/* a_noeud : pointeur sur un t_noeud */
typedef t_noeud* a_noeud;

/* ----- Fonctions ----- */

a_noeud nouveau_noeud(t_element etiquette, a_noeud gauche, a_noeud droite);
a_noeud nouveau_feuille(t_element etiquette);
void liberer_noeud(a_noeud ceci);
void afficher_noeud(a_noeud ceci);
int est_feuille(a_noeud ceci);

#endif

