#include "p_grille.h"
#include "p_element.h"

int main(){
    t_grille sudoku = nouvelles_grille(5,6);
    vider_grille(sudoku);
    afficher_grille(sudoku);
    ajouter_valeur_grille(sudoku,41,2,3);
    afficher_grille(sudoku);
    ajouter_valeur_grille(sudoku, nouveau_element(41),3,1);
    detruire_grille(&sudoku);

    /*t_grille* sudoku = nouvelles_grille(5,6);
    detruire_grille(sudoku);*/



    return 0;


}