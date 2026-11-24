#include "p_b_arbre.h"
#include <stdio.h>
#include <stdlib.h>


void afficher_tab(t_element* ceci, int taille){
    printf("[");
    for(int i=0;i<taille-1;i++){
        printf("%d ,",ceci[i]);
    }
    
    printf("%d ]\n",ceci[taille]);
  

}

void decaler_tab_gauche(t_element* ceci, int taille){
    for(int i=0;i<taille - 1;i++){
        ceci[i] = ceci[i+1];
    }
}

void decaler_tab_droite(t_element* ceci, int taille){
    for(int i=taille;i>0;i--){
        ceci[i] = ceci[i-1];
    }
}

void inserer_tab_apres(t_element ceci, t_element* dans, t_indice position, t_element* premier){

    *premier = dans[0];

    decaler_tab_gauche(dans, position + 1);

    dans[position] = ceci;
}

void inserer_tab_avant(t_element ceci, t_element* dans, int* taille, t_indice position){

    decaler_tab_droite(dans, position);

    dans[position] = ceci;
    (*taille)++ ;

}

t_indice position_insertion(t_element ceci, t_element* dans, int taille){
    int i=0;

    while(i<taille && dans[i] <ceci){
        i++;
    }

    return i;
}

void inserer_tab(t_element ceci, t_element* dans, int* taille){
    int position = position_insertion(ceci, dans, *taille);

    inserer_tab_avant(ceci, dans, taille, position);
}


void debugguer_noeud(a_noeud ceci){

    if(ceci == NULL){
        printf("NULL\n");
        return;
    }

    printf("[");

    for(int i=0 ; i< ceci->le_nb_elements; i++){
        printf("%d ",ceci->les_etiquettes[i]);
    }

    printf("]");
}

int est_noeud_sature(a_noeud ceci){
    return (ceci->le_nb_elements > 2 * K);
}

void exploser_noeud(a_noeud ceci, t_element* median, a_noeud* nouveau){
    int milieu = K;

    *median = ceci->les_etiquettes[milieu];

    *nouveau = malloc(sizeof(t_noeud));

    (*nouveau)->le_nb_elements = K;

    for(int i=0;i< K; i++){
        (*nouveau)->les_etiquettes[i] = ceci->les_etiquettes[i + milieu + 1];
    }

    for(int i=0 ; i<= K; i++){
        (*nouveau)->les_fils[i] = ceci->les_fils[i + milieu + 1];

    }

    ceci->le_nb_elements = K;
}

void inserer_noeud(t_element* ceci, a_noeud dans, a_noeud* nouveau){
    inserer_tab(*ceci, dans->les_etiquettes, &(dans)->le_nb_elements);
}

t_b_arbre nouvelle_racine_b_arbre(t_element racine){
    t_b_arbre arbre = (t_b_arbre)malloc(sizeof(t_noeud));

    arbre->le_nb_elements = 1;
    arbre->les_etiquettes[0] = racine;

    for(int i=0;i< 2*K +1 ;i++){
        arbre->les_fils[i] = NULL;
    }

    return arbre;

}

void inserer_b_arbre(t_b_arbre *ceci, t_element quoi){
    if(*ceci == NULL ){
        *ceci = nouvelle_racine_b_arbre(quoi);
        return;

    }

    inserer_tab(quoi, (*ceci)->les_etiquettes, &((*ceci)->le_nb_elements));
}


void afficher_b_arbre(t_b_arbre ceci, int decalage){

    if(ceci == NULL)
        return;

    for(int i = 0; i < decalage; i++)
        printf("   ");

    printf("[");

    for(int i = 0; i < ceci->le_nb_elements; i++)
    {
        printf("%d", ceci->les_etiquettes[i]);

        if(i < ceci->le_nb_elements - 1)
            printf(" | ");
    }

    printf("]\n");

    for(int i = 0; i <= ceci->le_nb_elements; i++)
        afficher_b_arbre(
                ceci->les_fils[i],
                decalage + 1);
}