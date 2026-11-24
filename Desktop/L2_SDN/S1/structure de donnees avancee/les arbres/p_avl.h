#ifndef P_AVL_INCLUDED_H
#define P_AVL_INCLUDED_H

/**
 * \file p_avl.h
 *
 *
 * \brief les éléments sont des chaines de caractères.
 *   on dispose d'une relation d'ordre sur les chaines : l'ordre lexicographique.
 *   il s'agit de l'ordre du dictionnaire (appelé de manière impropre l'ordre alphabétiques).
 *   on pourra utiliser :
 *       - soit la fonction compare_chaine faite en tp de remise en route.
 *       - soit la fonction strcmp disponible dans la bibliothèque string.h
 *
 * \author weinberg benjamin
 * \version 0.5
 * \date septembre 2019


 * la structure en avl, permet de gérer des abo.
 * dont le déséquilibre n'est pas trop important
 * on doit cette structure à Adelson-Velskii et Landis

 * \warning attention cette bibliotheque manipule des pointeurs.
    il faut faire attention qu'on libère correctement la mémoire
    on veuillera également à ne pas utiliser pas un pointeur qui pointe sur zone mémoire non allouée (ou qui n'est plus allouée).

 * \warning dans ce tp, on ne mettra pas en place tous les mecanismes permettant de garantir l'intégrité des processus.
    en effet, le langage c fournit trop de moyen de détourner les securités qu'on vourdrait mettre en place.

 */


#include <stdlib.h>
#include "p_element.h"

#define AVL_VIDE NULL

typedef struct s_noeud_avl{
    t_element l_etiquette;
    struct s_noeud_avl* la_gauche;
    struct s_noeud_avl* la_droite;
    int la_hauteur;
}t_noeud_avl;

typedef t_noeud_avl* a_noeud_avl;
typedef a_noeud_avl t_avl;

/**
 * \brief alloue un noeud et rempli les différents champs.
 * cette fonction devrait être utilisér uniquement pour créer une feuille
 * cette fonction devait donc être masquée à terme.
 *
 * \param etiquette : t_element : la valeur à la racine.
 * \param gauche : t_avl : le sous arbre gauche.
 * \param droite : t_avl : le sous arbre droit.
 * \return a_noeud_avl : le nouveau noeud construit
 */
a_noeud_avl nouveau_noeud(t_element etiquette, t_avl gauche, t_avl droite);


/**
 * \brief affiche un avl un peu comme un arbre mais avec en faisant apparaitre l'information de hauteur en plus.
 *
 * \param ceci: t_avl : l'arbre à afficher.
 * \param décalage : int : le niveau d'indentation de l'arbre.
 * \return rien.
 */
void afficher_avl(t_avl ceci, int decalage);

/**
 * \brief retourne la hauteur de ceci.
 * la fonction est simple car l'information est généralement disponible dans la racine.
 *
 * \param ceci: t_avl : l'arbre dont on cherche la hauteur.
 * \return rien.
 */
int hauteur_avl(t_avl ceci);

/**
 * \brief met à jour la hauteur de ceci.
 * dans un arbre non vide la hauteur d'un avl est déduite de la hauteur de ses fils.
 *
 * \param ceci: t_avl : l'arbre dont on met à jour la hauteur.
 * \warning : ceci est non vide !
 * \return rien.
 */
void mettre_a_jour_hauteur(t_avl ceci);

/**
 * \brief retourne la différence de hauteur entre le fils droit et le fils gauche.
 * \warning dans un avl le déséquibre doit être compris entre +1 (l'arbre penche à gauche) et -1 (l'arbre penche à droite)
 *
 * \param ceci: t_avl : l'arbre dont on calcule le déséquilibre.
 * \return int : le déséquilibre.
 */
int desequilibre(t_avl ceci);


/**
 * \brief modifie *ceci pour qu'il pointe sur arbre avec les mêmes informations mais penchant moins à droite.
 * les rotations préservent la structure d'abo mais change l'équilibrage.
 * elles sont utilisées pour rééquilibrer un avl lors d'une insertion
 *
 * \param *ceci : t_avl à modifier
 * \return : rien
 */
void rotation_gauche(t_avl* ceci);

/**
 * \brief modifie *ceci pour qu'il pointe sur arbre avec les mêmes informations mais penchant moins à gauche.
 * les rotations préservent la structure d'abo mais change l'équilibrage.
 * elles sont utilisées pour rééquilibrer un avl lors d'une insertion
 *
 * \param *ceci : t_avl à modifier
 * \return : rien
 */
void rotation_droite(t_avl* ceci);

/**
 * \brief modifie *ceci pour qu'il pointe sur arbre avec les mêmes informations mais penchant moins à droite.
 * les rotations préservent la structure d'abo mais change l'équilibrage.
 * elles sont utilisées pour rééquilibrer un avl lors d'une insertion
 *
 * \param *ceci : t_avl à modifier
 * \return : rien
 */
void rotation_droite_gauche(t_avl* ceci);

/**
 * \brief modifie *ceci pour qu'il pointe sur arbre avec les mêmes informations mais penchant moins à gauche.
 * les rotations préservent la structure d'abo mais change l'équilibrage.
 * elles sont utilisées pour rééquilibrer un avl lors d'une insertion
 *
 * \param *ceci : t_avl à modifier
 * \return : rien
 */
void rotation_gauche_droite(t_avl* ceci);

/**
 * \brief insert un élément comme une feuille de l'arbre *dans comme un abo
 * et rééquilibre le long de la branche d'insertion pour que la struction avl soit respectée.
 *
 * \param *ceci : t_avl à modifier
 * \return : rien
 */
void inserer_avl(t_element quoi, t_avl* dans);

/**
 * \brief cette fonction supprime le plus petit élément de *<ceci> et place la valeur dans *<dans>.
 *
 * \param ceci : t_avl* : un pointeur vers un abo.
 * \param quoi : t_element* : un pointeur vers un élément permettant de recevoir la valeur supprimée.
 * \return int : 0 si *ceci est vide;
 * \return int : 1 sinon.
 */
int extraire_plus_petit(t_avl* ceci, t_element* dans);

#endif // P_AVL_INCLUDED_H
