#ifndef P_GRILLE_2_H
#define P_GRILLE_2_H

typedef char t_element;


typedef struct s_grille2 {
    int le_nb_lignes;
    int le_nb_colonnes;
    t_element **les_lignes;   // tableau de lignes
} * t_grille2;

typedef int t_indice;

t_grille2 nouvelle_grille2(int nb_lignes, int nb_colonnes);

void detruire_grille2(t_grille2 *ceci);

void afficher_grille2(const t_grille2 ceci);

void ajouter_valeur_grille(t_grille2 ceci,char valeur,int ligne,int colonne);

t_indice ligne_colonne_2_position(t_grille2 ceci,t_indice ligne, t_indice colonne);

t_indice position_2_ligne_grille(t_grille2 ceci, t_indice position);

t_indice position_2_colonne_grille(t_grille2 ceci, t_indice position);

void changer_grille2(t_grille2 ceci, int ligne, int colonne, t_element valeur);


void vider_grille2(t_grille2 ceci);




#endif