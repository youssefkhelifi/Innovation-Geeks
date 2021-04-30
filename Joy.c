#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonction.h"

SDL_Rect MAJMinimap(SDL_Rect posJouer, int redimensionnement)
{
Personne per;

posJouer.x=per.pos.x*(redimensionnement/100);
posJouer.y=per.pos.y*(redimensionnement/100);

return per.pos;
}

void initmap(minimap *m)
{
Personne per;
 m->image_miniature=IMG_Load("minibackground.bmp");

 m->position_minimap.x =300;
 m->position_minimap.y =0;

 m->image_bonhomme=IMG_Load("miniimge.bmp");
 m->position_bonhomme.x =300;
 m->position_bonhomme.y =100;
}

void afficherminimap(minimap m, SDL_Surface *screen)
{
SDL_BlitSurface(m.image_miniature,NULL,screen,&m.position_minimap);
SDL_BlitSurface(m.image_bonhomme,NULL,screen,&m.position_bonhomme);
}

void liberer (minimap *m)
{
    SDL_Flip(m->image_bonhomme);
    SDL_Flip(m->image_miniature);
}

SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{

    SDL_Color color;
    Uint32 col = 0;
    //Determine position

    char *pixelPosition = (char *)Background->pixels;
    //Offset by Y
    pixelPosition += (Background->pitch * y);
    //Offset by X
    pixelPosition += (Background->format->BytesPerPixel * x);
    //Copy pixel data
    memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
    //Convert to color
    SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

    return (color);
}

int collisionPP(Personne p, SDL_Surface * backgroundMasque)
{
    int collision = 0, i;
    SDL_Color couleur_obstacle = {0,0,0};
    SDL_Color couleur;
    SDL_Rect pos [8];

    pos[0].x = p.pos.x;
    pos[0].y = p.pos.y;

    pos[1].x = p.pos.x + (p.image->w)/2;
    pos[1].y = p.pos.y;

    pos[2].x = p.pos.x + p.image->w ;
    pos[2].y = p.pos.y;

    pos[3].x = p.pos.x ;
    pos[3].y = p.pos.y + p.image->h ;

    pos[4].x = p.pos.x ;
    pos[4].y = p.pos.y +( p.image->h)/2;

    pos[5].x = p.pos.x + (p.image->w)/2;
    pos[5].y = p.pos.y + p.image->h;

    pos[6].x = p.pos.x + p.image->w;
    pos[6].y = p.pos.y + p.image->h;

    pos[7].x = p.pos.x + p.image->w;
    pos[7].y = p.pos.y + (p.image->h)/2;

    for (i=0; i<8; i++)
    {

        couleur=GetPixel(p.image, pos[i].x, pos[i].y);
        if(couleur.b==0 && couleur.g==0 && couleur.r==0)
        {
            collision=1;
            break;
        }
    }
    return collision;
}
