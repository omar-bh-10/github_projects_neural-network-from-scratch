#include "p_noeud.h"

a_noeud nouveau_noeud(t_element etiquette, a_noeud gauche, a_noeud droite) {
    a_noeud n = malloc(sizeof(t_noeud));
    if (!n) {
        fprintf(stderr, "Erreur allocation noeud\n");
        exit(EXIT_FAILURE);
    }
    n->l_etiquette = etiquette;
    n->la_gauche = gauche;
    n->la_droite = droite;
    return n;
}

a_noeud nouveau_feuille(t_element etiquette) {
    return nouveau_noeud(etiquette, ARBRE_VIDE, ARBRE_VIDE);
}

void liberer_noeud(a_noeud ceci) {
    if (ceci == ARBRE_VIDE)
        return;

    liberer_noeud(ceci->la_gauche);
    liberer_noeud(ceci->la_droite);
    free(ceci);
}

void afficher_noeud(a_noeud ceci) {
    if (ceci == ARBRE_VIDE) {
        printf("∅ ");
        return;
    }

    printf("(%d ", ceci->l_etiquette);
    afficher_noeud(ceci->la_gauche);
    afficher_noeud(ceci->la_droite);
    printf(") ");
}

int est_feuille(a_noeud ceci) {
    return (ceci != ARBRE_VIDE &&
            ceci->la_gauche == ARBRE_VIDE &&
            ceci->la_droite == ARBRE_VIDE);
}
