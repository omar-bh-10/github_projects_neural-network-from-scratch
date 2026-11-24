#include <stdio.h>
#include <stdlib.h>
#include "p_grille2.h"
#include "p_element.h"

t_grille2 nouvelles_grille(int nb_lignes,int nb_colonnes){
    t_grille2 res = malloc(sizeof(struct s_grille2));
    res->le_nb_lignes= nb_lignes;
    res->le_nb_colonnes = nb_colonnes;
    res->les_lignes = malloc(nb_lignes * sizeof(t_element*));

    for(t_indice i=0;i<nb_lignes;i++){
        res->les_lignes[i] = malloc(nb_colonnes *sizeof(t_element));

    }
    return res;
}


void detruire_grille2(t_grille2 *ceci){
    for(t_indice i=0; i<(*ceci)->le_nb_lignes;i++){
        free((*ceci) -> les_lignes[i]);
    }

    free((*ceci)->les_lignes);


    free(*ceci);
    *ceci = NULL;

}


void afficher_grille2(const t_grille2 ceci){
    for(t_indice i = 0; i < ceci->le_nb_lignes; i++){
        for(t_indice j = 0; j < ceci->le_nb_colonnes; j++){
            afficher_element(ceci->les_lignes[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

void ajouter_valeur_grille(t_grille2 ceci, char valeur , int ligne,int colonne){
    ceci->les_lignes[ligne][colonne] = valeur;

}

t_indice ligne_colonne_2_position(t_grille2 ceci, t_indice ligne, t_indice colonne){
    return ligne * ceci->le_nb_colonnes + colonne;
}

t_indice position_2_ligne_grille(t_grille2 ceci, t_indice position){
    return position / ceci->le_nb_colonnes;
}

t_indice position_2_colonne_grille(t_grille2 ceci, t_indice position){
    return position % ceci->le_nb_colonnes;
}

void vider_grille2(t_grille2 ceci){
    for(t_indice i=0;i<ceci->le_nb_lignes;i++){
        for(t_indice j=0;j<ceci->le_nb_colonnes;j++){
        // ceci->les_lignes[i][j] = nouveau_element(".");
        ajouter_valeur_grille(ceci, nouveau_element('.'),i,j);
        }
    }

}

