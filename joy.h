typedef struct
{
    SDL_Rect pos;
    SDL_Surface * image;
} Personne;

typedef struct
{
    SDL_Surface * Surf;
    SDL_Surface * surfM;
} background;

typedef struct
{
    SDL_Surface* image_miniature;
    SDL_Rect position_minimap;
    SDL_Surface* image_bonhomme;
    SDL_Rect position_bonhomme;
}minimap;


SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);
int collisionPP( Personne p, SDL_Surface * backgroundMasque);
SDL_Rect MAJMinimap(SDL_Rect posJouer, int redimensionnement);
void initmap(minimap *m);
void afficherminimap(minimap m, SDL_Surface *screen);
void liberer (minimap *m);
