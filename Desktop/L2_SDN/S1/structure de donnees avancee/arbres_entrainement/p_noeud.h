#ifndef P_NOEUD_H
#define P_NOEUD_H
typedef int t_element;

typedef struct t_noeud{
    t_element l_etiquette;
    struct t_noeud* la_gauche;
    struct t_noeud* la_droite;

}t_noeud;

typedef t_noeud* a_noeud;//pointeur vers un noeud (arbre)

a_noeud nouveau_noeud(t_element etiquette, a_noeud gauche, a_noeud droite);
a_noeud nouveau_feuille(t_element etiquette);
void afficher_noeud(a_noeud ceci);
int est_feuille(a_noeud ceci);



#endif