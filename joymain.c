#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonction.h"

int main (int argc, char **argv[])
{
  int continuer= 1, temps;
    minimap m;
    background backg ;
    Personne perso;
    SDL_Surface * ecran = NULL;
    SDL_Event evenement;
    SDL_Rect position;
    int collision;

    position.x=0;
    position.y=0;

    SDL_Init(SDL_INIT_EVERYTHING);

    ecran = SDL_SetVideoMode(963, 600, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);

    initmap(&m);

    backg.Surf= IMG_Load("background.bmp");
    backg.surfM= IMG_Load("background.bmp");

    perso.image = IMG_Load("imge.bmp");
    perso.pos.x = 0;
    perso.pos.y = 400;

    m.position_bonhomme.x =300;
    m.position_bonhomme.y =105;

    SDL_BlitSurface (backg.surfM,NULL,ecran,&position);
    SDL_BlitSurface (backg.Surf,NULL,ecran,&position);
    SDL_BlitSurface (perso.image,NULL,ecran,&perso.pos);
    SDL_Flip(ecran);

    while(continuer)
    {
        SDL_PollEvent(&evenement);

        switch(evenement.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch(evenement.key.keysym.sym)
            {
            case SDLK_LEFT:
               perso.pos.x-=1;
	       m.position_bonhomme.x = m.position_bonhomme.x - 1;
                /*if(collisionPP(perso,backg.surfM))
                    perso.pos.x+=0;*/

                SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
                SDL_BlitSurface (backg.surfM,NULL,ecran,&position);
                SDL_BlitSurface (backg.Surf,NULL,ecran,&position);
                SDL_BlitSurface (perso.image,NULL,ecran,&perso.pos);
                SDL_Flip(ecran);
                break;
            case SDLK_RIGHT:
                perso.pos.x += 1;

                /*if(collisionPP(perso,backg.surfM))
                perso.pos.x+=0;
                    break;*/

                SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
                SDL_BlitSurface (backg.surfM,NULL,ecran,&position);
                SDL_BlitSurface (backg.Surf,NULL,ecran,&position);
                SDL_BlitSurface (perso.image,NULL,ecran,&perso.pos);


                break;
            case SDLK_l:
                MAJMinimap(m.position_bonhomme, 20);
                afficherminimap(m, ecran);

                break;
            }
        }
	liberer (&m);
        SDL_Flip(ecran);
    }


    return 0;
}

