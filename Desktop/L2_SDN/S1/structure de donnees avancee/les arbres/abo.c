
#include <stdio.h>
#include <stdlib.h>
#include "abo.h"
#include "p_arbre.h"
#include <time.h>

#define TAILLE_TAB 20

t_element mon_tableau[TAILLE_TAB];

void afficher(t_arbre_binaire ceci);

void afficher_tab() {
    printf("[ ");

    for (int i = 0; i < TAILLE_TAB; i++) {
        printf("%d ", mon_tableau[i]);
    }

    printf("]\n");
}

/* Initialiser le tableau */
void initialiser_tab() {
    for (int i = 0; i < TAILLE_TAB; i++) {
        mon_tableau[i] = rand() % 100;
    }
}

/* Insertion dans un ABR */
void inserer_arbre(t_arbre_binaire *ceci, t_element valeur) {

    if (est_arbre_vide(*ceci)) {
        *ceci = nouveau_arbre_binaire(valeur, NULL, NULL);
        return;
    }

    if (valeur < (*ceci)->l_etiquette) {
        inserer_arbre(&(*ceci)->la_gauche, valeur);
    }
    else if (valeur > (*ceci)->l_etiquette) {
        inserer_arbre(&(*ceci)->la_droite, valeur);
    }
}

/* Suppression dans un ABR */
void extraire_arbre(t_arbre_binaire *ceci, t_element *valeur) {

    if (est_arbre_vide(*ceci))
        return;

    if (*valeur < (*ceci)->l_etiquette) {
        extraire_arbre(&(*ceci)->la_gauche, valeur);
    }
    else if (*valeur > (*ceci)->l_etiquette) {
        extraire_arbre(&(*ceci)->la_droite, valeur);
    }
    else {

        /* Cas 1 : feuille */
        if ((*ceci)->la_gauche == NULL &&
            (*ceci)->la_droite == NULL) {

            liberer_noeud(*ceci);
            *ceci = NULL;
        }

        /* Cas 2 : un seul fils droit */
        else if ((*ceci)->la_gauche == NULL) {

            t_arbre_binaire tmp = (*ceci)->la_droite;

            liberer_noeud(*ceci);
            *ceci = tmp;
        }

        /* Cas 3 : un seul fils gauche */
        else if ((*ceci)->la_droite == NULL) {

            t_arbre_binaire tmp = (*ceci)->la_gauche;

            liberer_noeud(*ceci);
            *ceci = tmp;
        }

        /* Cas 4 : deux fils */
        else {

            t_arbre_binaire min = (*ceci)->la_droite;

            while (min->la_gauche != NULL) {
                min = min->la_gauche;
            }

            (*ceci)->l_etiquette = min->l_etiquette;

            t_element val_min = min->l_etiquette;

            extraire_arbre(&(*ceci)->la_droite, &val_min);
        }
    }
}

int main() {

    srand(time(NULL));

    t_arbre_binaire mon_abo = ARBRE_VIDE;

    initialiser_tab();

    printf("Tableau initial :\n");
    afficher_tab();

    for (int i = 0; i < TAILLE_TAB; i++) {

        inserer_arbre(&mon_abo, mon_tableau[i]);

    }

    printf("\nArbre apres insertion :\n");
    afficher(mon_abo);

    for (int i = 0; i < TAILLE_TAB; i++) {

        extraire_arbre(&mon_abo, &mon_tableau[i]);

        printf("\nApres suppression de %d :\n", mon_tableau[i]);

        afficher(mon_abo);
    }

    return 0;
}
