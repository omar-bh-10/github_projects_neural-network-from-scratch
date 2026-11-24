#ifndef P_ELEMENT_H
#define P_ELEMENT_H

typedef char t_element;

t_element nouveau_element(char valeur);
void detruire_element(t_element* ceci);
void afficher_element(t_element ceci);

#endif