#include "noeud.h"
#include <stdlib.h>
#include <stdio.h>
a_noeud nouveau_noeud(t_element etiquette, a_noeud gauche, a_noeud droite){
    a_noeud t =malloc(sizeof(t_noeud));
       if(t==NULL){
        printf("pb d allocation de noeud");
        exit(1);
    }
    t->l_etiquette =etiquette;
    t->la_gauche=gauche;
    t->la_droite=droite;
    return t;

}

a_noeud nouveau_feuille(t_element etiquette){
    return nouveau_noeud(etiquette,NULL,NULL);

}

void liberer_noeud(a_noeud ceci){
    free(ceci); 
}
void afficher_noeud(a_noeud ceci){
        if(ceci->l_etiquette==NULL){
            printf("[ \n]");
        }else{
        printf("C%p",ceci);
        afficher_noeud(ceci->l_etiquette);
        printf("%p,%p\n",ceci->la_gauche,ceci->la_droite);
        }
}
int est_feuille(a_noeud ceci){
    if(ceci==NULL)return 0;
    return ceci->la_gauche==NULL && ceci->la_droite==NULL;
}

