#ifndef P_GRILLE_H
#define P_GRILLE_H

typedef char t_element;

typedef struct s_grille{
    int le_nb_lignes;
    int le_nb_colonnes;
    t_element *les_cases;
}* t_grille;

typedef int t_indice;

t_grille nouvelles_grille(int nb_lignes,int nb_colonnes);
void detruire_grille(t_grille* ceci);
void afficher_grille(const t_grille ceci);
void ajouter_valeur_grille(t_grille ceci,char valeur,int ligne,int colonne);
t_indice ligne_colonne_2_position(t_grille ceci,t_indice ligne, t_indice colonne);
t_indice position_2_ligne_grille(t_grille ceci, t_indice position);
t_indice position_2_colonne_grille(t_grille ceci, t_indice position);
void vider_grille(t_grille ceci);



#endif 