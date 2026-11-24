#include <stdio.h>
#include "p_noeud.h"
#include "p_arbre.h"
#include "abo.h"

int main() {

    /*
        Construction de l’arbre :

                9
              /   \
             5     12
            / \
           3   7
    */

    /*t_arbre_binaire a = nouveau_feuille(3);
    t_arbre_binaire b = nouveau_feuille(7);
    t_arbre_binaire g = nouveau_arbre_binaire(5, a, b);
    t_arbre_binaire d = nouveau_feuille(12);
    t_arbre_binaire racine = nouveau_arbre_binaire(9, g, d);

    printf("=== Affichage de l'arbre ===\n");
    afficher_arbre_binaire(racine, 0);

    printf("\n=== Hauteurs ===\n");
    printf("Hauteur normale : %d\n", hauteur_arbre_binaire(racine));
    printf("Hauteur équilibrée : %d\n", hauteur_equilibre_arbre_binaire(racine));

    printf("\n=== Équilibre ===\n");
    printf("Parfaitement équilibré ? %d\n", est_parfaitement_equilibre(racine));
    printf("Déséquilibre (hd - hg) : %d\n", desequilibre(racine));

    printf("\n=== Comptages ===\n");
    printf("Nombre d'éléments : %d\n", nb_elements_arbre_binaire(racine));
    printf("Présence de 7 ? %d\n", est_present_arbre_binaire(7, racine));
    printf("Occurrences de 5 : %d\n", nb_occurences_arbre_binaire(5, racine));

    printf("\n=== Clone ===\n");
    t_arbre_binaire copie = clone(racine);
    afficher_arbre_binaire(copie, 0);

    printf("\n=== Destruction ===\n");
    finaliser_arbre_binaire(&racine);
    printf("Arbre racine vide ? %d\n", est_arbre_vide(racine));

    finaliser_arbre_binaire(&copie);
    printf("Arbre copie vide ? %d\n", est_arbre_vide(copie));

    return 0;*/



    t_arbre_binaire arbre = NULL;

    // Construction de l'arbre
    inserer_arbre(&arbre, 'F');
    inserer_arbre(&arbre, 'B');
    inserer_arbre(&arbre, 'A');
    inserer_arbre(&arbre, 'D');
    inserer_arbre(&arbre, 'C');
    inserer_arbre(&arbre, 'E');
    inserer_arbre(&arbre, 'G');
    inserer_arbre(&arbre, 'I');
    inserer_arbre(&arbre, 'H');

    printf("=== Arbre AVANT extraction ===\n");
    afficher_arbre_binaire(arbre, 0);

    t_element x = 'A';
    extraire_arbre(&arbre, &x);

    printf("\n=== Arbre APRES extraction de '%c' ===\n", x);
    afficher_arbre_binaire(arbre, 0);

    return 0;
}

