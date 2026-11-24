#include "p_avl.h"
#include "string.h"
#include <stdio.h>

int hauteur_avl(t_avl ceci){
    if(ceci == AVL_VIDE){
        return -1;
    }
    return ceci->la_hauteur;

}

void afficher_avl_2_aux(t_avl ceci) {
    if (ceci != AVL_VIDE) {
        afficher_avl_2_aux(ceci->la_gauche);

        printf("Valeur : %s | Hauteur : %d\n", ceci->l_etiquette, ceci->la_hauteur);

        afficher_avl_2_aux(ceci->la_droite);
    }
}

void afficher_avl_2(t_avl ceci){
    afficher_avl_2_aux(ceci);
}

a_noeud_avl nouveau_noeud(t_element etiquette, t_avl gauche, t_avl droite){
    a_noeud_avl res = malloc(sizeof(t_noeud_avl));
    res->l_etiquette = etiquette;
    res->la_gauche = gauche;
    res->la_droite = droite;
    mettre_a_jour_hauteur(res);
    return res;
}


void afficher_avl(t_avl ceci, int decalage){


    if(ceci != AVL_VIDE){
        afficher_avl(ceci->la_droite, decalage + 4);

        for(int i=0;i<decalage;i++){
            printf(" ");
        }

        printf("%s (%d)\n",ceci->l_etiquette, ceci->la_hauteur);

        afficher_avl(ceci->la_gauche, decalage + 4);
    }
}

void mettre_a_jour_hauteur(t_avl ceci){
    int hg = hauteur_avl(ceci->la_gauche);
    int hd = hauteur_avl(ceci->la_droite);
     
    ceci->la_hauteur = 1 + (hg > hd ? hg : hd);

}

int desequilibre(t_avl ceci){
    return hauteur_avl(ceci->la_gauche) - hauteur_avl(ceci->la_droite);
}


void rotation_droite(t_avl* ceci){
    t_avl pivot= (*ceci)->la_gauche;

    (*ceci)->la_gauche = pivot->la_droite;
    pivot->la_droite = *ceci;

    mettre_a_jour_hauteur(*ceci);
    mettre_a_jour_hauteur(pivot);

    *ceci = pivot;

}

void rotation_gauche(t_avl* ceci){
    t_avl nouvelle_racine = (*ceci)->la_droite;
    (*ceci)->la_droite = nouvelle_racine->la_gauche;
    nouvelle_racine->la_gauche = *ceci;

    mettre_a_jour_hauteur(*ceci);
    mettre_a_jour_hauteur(nouvelle_racine);

    *ceci = nouvelle_racine;

}

void rotation_gauche_droite(t_avl* ceci) {
    rotation_gauche(&((*ceci)->la_gauche));
    rotation_droite(ceci);
}

void rotation_droite_gauche(t_avl* ceci) {
    rotation_droite(&((*ceci)->la_droite));
    rotation_gauche(ceci);
}

void requilibrer_avl(t_avl* ceci){

    mettre_a_jour_hauteur(*ceci);

    if(desequilibre(*ceci)== 2){
        if(desequilibre((*ceci)->la_gauche) >=0){
            rotation_droite(ceci);
        }
        else{
            rotation_droite_gauche(ceci);
        }
    }

    else if(desequilibre(*ceci) == -2){
        if(desequilibre((*ceci)->la_gauche) <= 0 ){
            rotation_gauche(ceci);
        }
        else{
            rotation_gauche_droite(ceci);
        }
    }
}

void inserer_avl(t_element quoi, t_avl* dans){
    if(*dans == AVL_VIDE){
        *dans = nouveau_noeud(quoi, AVL_VIDE, AVL_VIDE);
    }

    else if(quoi < (*dans)->l_etiquette){
        inserer_avl(quoi, &((*dans)->la_gauche));
    }
    else{
        inserer_avl(quoi, &((*dans)->la_droite));
    }
    requilibrer_avl(dans);

}

int extraire_plus_petit(t_avl* ceci, t_element* dans){
    if(*ceci == AVL_VIDE){
        return 0;
    }
    if((*ceci)->la_gauche == AVL_VIDE){
        t_avl nouvelle_racine = (*ceci)->la_droite;
        *dans = (*ceci)->l_etiquette;
        free(*ceci);
        *ceci = nouvelle_racine;

        return 1;
    }
    else{
        return extraire_plus_petit(&((*ceci)->la_gauche), dans);

    }
}















