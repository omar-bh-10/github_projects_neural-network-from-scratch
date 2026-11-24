#ifndef P_ARBRE_H
#define P_ARBRE_H

#include "p_noeud.h"
#include "p_element.h"

typedef a_noeud t_arbre_binaire;

/* Fonctions */
void afficher_element();
int est_arbre_vide(t_arbre_binaire ceci);
t_arbre_binaire nouveau_arbre_binaire(t_element etiquette, t_arbre_binaire gauche, t_arbre_binaire droite);
void afficher_arbre_binaire(t_arbre_binaire ceci, int decalage);
int hauteur_arbre_binaire(t_arbre_binaire ceci);
int hauteur_equilibre_arbre_binaire(t_arbre_binaire ceci);
int est_parfaitement_equilibre(t_arbre_binaire ceci);
int nb_elements_arbre_binaire(t_arbre_binaire ceci);
void detruire_arbre_binaire(t_arbre_binaire ceci);
void finaliser_arbre_binaire(t_arbre_binaire* ceci);
int est_present_arbre_binaire(t_element quoi, t_arbre_binaire dans);
int nb_occurences_arbre_binaire(t_element quoi, t_arbre_binaire dans);
int desequilibre(t_arbre_binaire ceci);
t_arbre_binaire clone(t_arbre_binaire ceci);

#endif
