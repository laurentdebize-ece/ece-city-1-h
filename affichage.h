#include "element.h"
#define ECE_CITY_1_H_AFFICHAGE_H
#define MAX_X 44
#define MAX_Y 34

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
#define COLONNES_TAB 40
#define LIGNES_TAB 25
#define TAILLE_CASE 67
#define X_TAB 15
#define Y_TAB 10

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
    ALLEGRO_BITMAP *maison1,*maisonombre,*maison2,*maison2ombre,*maison3,*maison3ombre;
    ALLEGRO_BITMAP *gc1,*gc1ombre,*gc2,*gc2ombre,*gc3,*gc3ombre;
    ALLEGRO_BITMAP *routehd,*routehg,*routebd,*routebg,*routegd,*routehb;
    ALLEGRO_BITMAP *fond;
}Image;



//void affichage(Case tabCase[LIGNES_TAB][COLONNES_TAB],int tabTXT[LIGNES_TAB][COLONNES_TAB + 1],Image image,int ligneSouris,int colonneSouris);
//void toto();
//void carteTest();

//#endif //UNTITLED3_TABLEAU_H







