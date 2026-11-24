#include <stdio.h>
#include <stdlib.h>
#include "p_noeud.h"


a_noeud nouveau_noeud(t_element etiquette, a_noeud gauche, a_noeud droite){
    a_noeud nouveau = malloc(sizeof(t_noeud));

    nouveau->l_etiquette = etiquette;
    nouveau->la_gauche = gauche;
    nouveau->la_droite = droite;
}

a_noeud nouveau_feuille(t_element etiquette){
    return nouveau_noeud(etiquette,NULL,NULL);
}

void liberer_noeud(a_noeud ceci){
    if(ceci == NULL){
        return;
        
    }

    liberer_noeud(ceci->la_droite);
    liberer_noeud(ceci->la_gauche);
    free(ceci);
}

void afficher_noeud(a_noeud ceci){
    if(ceci == NULL){
        printf("rien");
        return;
    }

    printf("(%d ",ceci->l_etiquette);
    afficher_noeud(ceci->la_gauche);
    afficher_noeud(ceci->la_droite);
    printf(") ");
}

int est_feuille(a_noeud ceci){
    return ceci->la_droite == NULL && ceci->la_gauche == NULL && ceci==NULL;
}