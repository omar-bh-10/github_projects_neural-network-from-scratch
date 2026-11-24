#include <stdio.h>
#include <stdlib.h>
#define PREMIERS_JOUR DIMANCHE


typedef enum e_jouer{
		DIMANCHE,
		LUNDI,
		MARDI,
		MERCREDI,
		JEUDI,
		VENDREDI,
		SAMEDI,
		NB_JOURS
}t_jours ;

int main(){
    const char* mes_jours_image[NB_JOURS] = {"DIMANCHE" , "LUNDI","MARDI", "MERCREDI", "JEUDI" , "VENDREDI" , "SAMEDI"};

    
/*le mot cle const un signe que les caractères pointéés par une case du tableau mes_jours_image sont constants */

    for(t_jours j=PREMIERS_JOUR; j<NB_JOURS;j++){
        printf("%s\n",mes_jours_image[j]);
    }
    switch (mon_jour){
        case DIMANCHE:
            reviser();
            break();
        case LUNDI:
        case MARDI:
        case MERCREDI:
        case JEUDI:
        case VENDREDI:  
            travailler();
            break;
        case SAMEDI:
            Flaner();
        default:
            exit(1);

    }

    
    

}


