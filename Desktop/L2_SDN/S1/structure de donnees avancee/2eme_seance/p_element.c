#include "p_element.h"
#include <stdio.h>

t_element nouveau_element(char valeur){
    return valeur;

}

void detruire_element(t_element* ceci){
    //*ceci = '\0';

}

void afficher_element(t_element ceci){
    printf("%c", ceci);

}