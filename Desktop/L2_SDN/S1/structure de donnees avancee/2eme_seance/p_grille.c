#include <stdio.h>
#include <stdlib.h>
#include "p_grille.h"
#include "p_element.h"


t_grille nouvelles_grille(int nb_lignes,int nb_colonnes){
    t_grille res = malloc(sizeof(struct s_grille));
    res->le_nb_lignes= nb_lignes;
    res->le_nb_colonnes = nb_colonnes;
    res->les_cases = malloc(nb_lignes * nb_colonnes * sizeof(char));
    return res;

}

void detruire_grille(t_grille* ceci){
    free((*ceci)->les_cases);
    free(*ceci);
    *ceci = NULL;
    //les pointeurs : allocation dynamique d'objet , les tableaux , les parametres in/out dans les ,
    
}

t_indice ligne_colonne_2_position_grille(t_grille ceci,t_indice ligne,t_indice colonne){
    return ligne * ceci->le_nb_colonnes + colonne;

}

t_indice position_2_ligne_grille(t_grille ceci, t_indice position){
    return position / ceci->le_nb_colonnes;

}

t_indice position_2_colonne_grille(t_grille ceci, t_indice position){
    return position % ceci->le_nb_colonnes;

}

void afficher_grille(const t_grille ceci){
    for(int i=0;i<ceci->le_nb_colonnes;i++){
        for(int j=0;j<ceci->le_nb_colonnes;j++){
            // printf("%d ",ceci->les_cases[i *ceci->le_nb_colonnes + j]);
            afficher_element(ceci->les_cases[i* (ceci->le_nb_colonnes) + j]);
        }
        printf("\n");
    }
}

void ajouter_valeur_grille(t_grille ceci,char valeur,t_indice ligne,t_indice colonne){
    if (ligne < 0 || ligne >= ceci->le_nb_lignes ||
        colonne < 0 || colonne >= ceci->le_nb_colonnes) {
        fprintf(stderr, "Erreur: position (%d,%d) hors limites.\n", ligne, colonne);
        return;
    }

    int index = ligne * ceci->le_nb_colonnes + colonne;
    ceci->les_cases[index] = valeur;
}

void vider_grille(t_grille ceci){
    /*for(int i=0; i<ceci->le_nb_lignes;i++){
        for(int j=0; j<ceci->le_nb_colonnes; j++){
            //ceci->les_cases[i * ceci->le_nb_colonnes + j] = ".";

            ajouter_valeur_grille(ceci,'.',i,j);
        }
    }*/
    t_indice N =ceci->le_nb_lignes * ceci->le_nb_colonnes;
    for(int i=0; i < N;i++){
        ceci->les_cases[i] = '.';


        
    }
}
