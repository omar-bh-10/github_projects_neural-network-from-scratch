#include "p_arbre.h"


int est_arbre_vide(t_arbre_binaire ceci){
    return ceci == NULL;
}

t_arbre_binaire nouveau_arbre_binaire(t_element etiquette, t_arbre_binaire gauche, t_arbre_binaire droite){
    return nouveau_noeud(etiquette,gauche,droite);
}

void afficher_arbre_binaire(t_arbre_binaire ceci, int decalage){
    if(!est_arbre_vide(ceci)){
        // Sous-arbre droit
        afficher_arbre_binaire(ceci->la_droite, decalage + 1);

        // Indentation
        for(int i = 0; i < decalage; i++)
            printf("    ");  // 4 espaces

        // Affichage du nœud
        afficher_element(ceci->l_etiquette);
        printf("\n");

        // Sous-arbre gauche
        afficher_arbre_binaire(ceci->la_gauche, decalage + 1);
    }
}

void (*afficher)(t_arbre_binaire);

afficher = afficher_arbre_binaire_2;

typedef void(*t_afficheur)(t_arbre_binaire);
t_afficheur afficher;

void afficher_arbre_binaire(){
    afficher_arbre_binaire_2(ceci);
}

int hauteur_arbre_binaire(t_arbre_binaire ceci){
    if(est_arbre_vide(ceci)){
        return -1;

    }

    int hg = hauteur_arbre_binaire(ceci->la_gauche);
    int hd = hauteur_arbre_binaire(ceci->la_droite);

    return 1 + (hg > hd ? hg : hd);
}

int hauteur_equilibre_arbre_binaire(t_arbre_binaire ceci) {
    if (est_arbre_vide(ceci))
        return -1;

    int hg = hauteur_equilibre_arbre_binaire(ceci->la_gauche);
    int hd = hauteur_equilibre_arbre_binaire(ceci->la_droite);

    if (hg == -2 || hd == -2 || abs(hg - hd) > 1)
        return -2;

    return 1 + (hg > hd ? hg : hd);
}


int est_parfaitement_equilibre(t_arbre_binaire ceci) {
    int h = hauteur_equilibre_arbre_binaire(ceci);
    return h >= 0;
}

int nb_elements_arbre_binaire(t_arbre_binaire ceci) {
    if (est_arbre_vide(ceci))
        return 0;
    return 1 + nb_elements_arbre_binaire(ceci->la_gauche)
             + nb_elements_arbre_binaire(ceci->la_droite);
}

void detruire_arbre_binaire(t_arbre_binaire ceci) {
    if(!est_arbre_vide(ceci)) {
        detruire_arbre_binaire(ceci->la_gauche);
        detruire_arbre_binaire(ceci->la_droite);
        liberer_noeud(ceci);
    }
}


void finaliser_arbre_binaire(t_arbre_binaire* ceci) {
    detruire_arbre_binaire(*ceci);
    *ceci = ARBRE_VIDE;
}

int est_present_arbre_binaire(t_element quoi, t_arbre_binaire dans) {
    if (est_arbre_vide(dans))
        return 0;

    if (dans->l_etiquette == quoi)
        return 1;

    return est_present_arbre_binaire(quoi, dans->la_gauche)
         || est_present_arbre_binaire(quoi, dans->la_droite);
}

int nb_occurences_arbre_binaire(t_element quoi, t_arbre_binaire dans) {
    if (est_arbre_vide(dans))
        return 0;

    return (dans->l_etiquette == quoi)
         + nb_occurences_arbre_binaire(quoi, dans->la_gauche)
         + nb_occurences_arbre_binaire(quoi, dans->la_droite);
}

int desequilibre(t_arbre_binaire ceci) {
    if (est_arbre_vide(ceci))
        return 0;

    return hauteur_arbre_binaire(ceci->la_droite)
         - hauteur_arbre_binaire(ceci->la_gauche);
}


t_arbre_binaire clone(t_arbre_binaire ceci) {
    if (est_arbre_vide(ceci))
        return ARBRE_VIDE;

    return nouveau_arbre_binaire(
        ceci->l_etiquette,
        clone(ceci->la_gauche),
        clone(ceci->la_droite)
    );
}


/*
void afficher_arbre_binaire(t_arbre_binaire ceci, int decalage);

void afficher_arbre_binaire(t_arbre_binaire ceci){
    afficher_arbre_binaire(ceci,0);
}*/