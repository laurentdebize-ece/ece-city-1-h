#include "element.h"
#define ECE_CITY_1_H_AFFICHAGE_H
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#define ECRAN_LONGUEUR 2880
#define ECRAN_LARGEUR 1694
#define COLONNES_TAB 45
#define LIGNES_TAB 35
#define TAILLE_CASE 42
#define X_TAB 30
#define Y_TAB 211

typedef struct {
    int positionX;
    int positionY;
    int largeurX;
    int largeurY;
    //A
}Affichage;

typedef struct {
    float x,y;
}Case;

typedef struct {
    ALLEGRO_BITMAP *chateaudeau,*centraleelec,*caserne;
    ALLEGRO_BITMAP *terrainVague;
    ALLEGRO_BITMAP *cabane;
    ALLEGRO_BITMAP *maison1;
    ALLEGRO_BITMAP *immeuble;
    ALLEGRO_BITMAP *gc1;
    ALLEGRO_BITMAP *routehd,*routehg,*routebd,*routebg,*routegd,*routehb;
    ALLEGRO_BITMAP *pave,*pave2;
    ALLEGRO_BITMAP *fond;
    ALLEGRO_BITMAP* cap;
    ALLEGRO_BITMAP* commu;
    ALLEGRO_BITMAP* menu;
    ALLEGRO_BITMAP* sauvegarde;
}Image;



void affichage(Case tabCase[LIGNES_TAB][COLONNES_TAB],int tabTXT[LIGNES_TAB][COLONNES_TAB + 1],Image image,int ligneSouris,int colonneSouris, int xSouris, int ySouris, ALLEGRO_FONT* text, int construction, int centrale, int route, int chateau, int returnClic, ALLEGRO_FONT* reseauEau, int conteur);
int carte();

//#endif //UNTITLED3_TABLEAU_H
