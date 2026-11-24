#include <stdio.h>
#include "p_arbres.h"
#include "p_noeud.h"


int main(){
    t_arbre_binaire arbre = nouveau_arbre_binaire(10, 
    nouveau_arbre_binaire(8,nouveau_feuille(12), nouveau_feuille(15)),
    nouveau_arbre_binaire(99,nouveau_feuille(8),nouveau_feuille(7))
);
    afficher_arbre_binaire(arbre,0);

}