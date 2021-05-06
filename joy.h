/** 
* @file fonction.h 
* @brief Les entete 
* @author Joy Giovanni 
* @version 1.0 
* @date Mai 01, 2021 
* 
* Testing program for Minimap Temp CollisionPP * 
*/


#ifndef Karim_Akkari_1A30_H_
#define Karim_Akkari_1A30_H_
#include <time.h>

/** 
* @struc personne 
* @brief struct pour les personnages 
*/ 

typedef struct
{
	SDL_Rect position_perso; /*!< position*/
	SDL_Surface *sprite; /*!< image*/
} Personne;

/** 
* @struct minimap 
* @brief structure pour la minimap
*/ 

typedef struct
{
	SDL_Rect position_mini; /*!< Rectangle*/
	SDL_Surface *sprite; /*!< image*/
} minimap;

/** 
* @struct temps 
* @brief structure pour le temps
*/ 

typedef struct temps
{
	SDL_Surface *texte; /*!< texte*/
	SDL_Rect position; /*!< position*/

	TTF_Font *police; /*!< police*/

	char entree[100]; /*!<chaine de caractere*/
	int secondesEcoulees; /*!< entier*/
	SDL_Color couleurBlanche; /*!< couleur*/
	time_t t1, t2; /*!< temps*/
	int min, sec; /*!< entier*/
} temps;

void initmap(minimap *m);
void afficherminimap(minimap m, SDL_Surface *screen);
void free_minimap(minimap *m);
void majminimap (Personne *p, minimap *m ,SDL_Rect camera ,int redimensionnement);

void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t, SDL_Surface *ecran);

SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP(Personne p, SDL_Surface *Masque);

#endif

