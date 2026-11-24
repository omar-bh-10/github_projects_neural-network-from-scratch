#include "noeud.h"

int main() {
    a_noeud a = nouveau_feuille(5);
    a_noeud b = nouveau_feuille(7);
    a_noeud racine = nouveau_noeud(9, a, b);

    afficher_noeud(racine);
    printf("\n");

    liberer_noeud(racine);
    return 0;
}
