#include "p_arbres.h"
#include <stdio.h>
#include <stdlib.h>

int est_arbre_vide(a_noeud ceci){
    return ceci == NULL;
}

t_arbre_binaire nouveau_arbre_binaire(t_element etiquette, t_arbre_binaire gauche, t_arbre_binaire droite){
    return nouveau_noeud(etiquette,gauche,droite);

}

void afficher_arbre_binaire(t_arbre_binaire ceci, int decalage){
    if(!est_arbre_vide(ceci)){
        afficher_arbre_binaire(ceci->la_droite, decalage + 1);

        for(int i=0;i<decalage;i++){
            printf("    ");
        } 

        printf("%d\n",ceci->l_etiquette);

        afficher_arbre_binaire(ceci->la_gauche,decalage +1);
        
    }
}

int hauteur_arbre_binaire(t_arbre_binaire ceci){
    if(est_arbre_vide(ceci)){
        return -1;
    }

    int hg = hauteur_arbre_binaire(ceci->la_gauche);
    int hd = hauteur_arbre_binaire(ceci->la_droite);

    return 1 + (hg > hd ? hg : hd );
}

int hauteur_equilibre_arbre_binaire(t_arbre_binaire ceci){
    if(est_arbre_vide(ceci)) return -1;

    int hg = hauteur_equilibre_arbre_binaire(ceci->la_gauche);
    int hd = hauteur_equilibre_arbre_binaire(ceci->la_droite);

    if(hg == -2 || hd == -2 || abs(hg - hd)>1){
        return -2;
    }

    return 1 + (hg > hd ? hg : hd );
}

int est_parfaitement_equilibre(t_arbre_binaire ceci){
    int h = hauteur_equilibre_arbre_binaire(ceci);
    return h>=0;
}

int nb_elements_arbre_binaire(t_arbre_binaire ceci){
    if(est_arbre_vide(ceci)) return 0;
    return 1 + nb_elements_arbre_binaire(ceci->la_gauche) + nb_elements_arbre_binaire(ceci->la_droite);
}

void detruire_arbre_binaire(t_arbre_binaire ceci){
    if(!est_arbre_vide(ceci)){
        
    }
}