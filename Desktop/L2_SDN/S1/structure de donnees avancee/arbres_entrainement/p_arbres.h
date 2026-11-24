#ifndef P_ARBRES_H
#define P_ARBRES_H

#include "p_noeud.h"

typedef a_noeud t_arbre_binaire;

int est_arbre_vide(a_noeud ceci);
t_arbre_binaire nouveau_arbre_binaire(t_element etiquette, t_arbre_binaire gauche, t_arbre_binaire droite);
void afficher_arbre_binaire(t_arbre_binaire ceci, int decalage);

int hauteur_arbre_binaire(t_arbre_binaire ceci);
int hauteur_equilibre_arbre_binaire(t_arbre_binaire ceci);
int est_parfaitement_equilibre(t_arbre_binaire ceci);
int nb_elements_arbre_binaire(t_arbre_binaire ceci);
void detruire_arbre_binaire(t_arbre_binaire ceci);


#endif 