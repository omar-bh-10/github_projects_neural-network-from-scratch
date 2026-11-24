#ifndef ABO_H
#define ABO_H

#include "p_arbre.h"

void inserer_arbre(t_arbre_binaire* ceci,t_element valeur);
void extraire_arbre(t_arbre_binaire *ceci, t_element *valeur);

t_element retire_plus_petit(t_arbre_binaire ceci);



#endif