#ifndef ECE_CITY_1_H_JEU_H
#define ECE_CITY_1_H_JEU_H
//#define MAX_CONSTRUCTION 50
#define NIVEAU_BATIMENT 5
#define ARGENT_INIT 500000
#define NB_HABITANT_INIT 0
#define NB_HAB_RUINE 0
#define NB_HAB_CABANE 10
#define NB_HAB_MAISON 50
#define NB_HAB_IMMEUBLE 100
#define NB_HAB_GRATTE_CIEL 1000
#define CYCLE_INIT 0
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define IMPOT_PAR_HABITANT 10
#define MODE_COMMUNISTE 0
#define MODE_CAPITALISTE 1
#define MODE_NON_CHOISI -1
#define IMPOT_PAR_HAB 10
#include "element.h"
#define MAX_PARCOURS 50
#define LG_MAX_PARCOURS 50
#define MAX_PARCOURS_CONSTRUCTION 50
#define MAX_PARCOURS_CHATEAU 50
#define MAX_PARCOURS_CENTRALE 50
#include "stdbool.h"


enum niveauConstruction {RUINE, TERRAIN_VAGUE ,CABANE, MAISON, IMMEUBLE, GRATTE_CIEL};


typedef struct {

}BoiteOutils;

typedef struct {
    int source; // Index de la source dans le tableau monJeu.elements
    int destination; // Index de la destination dans le tableau monJeu.elements
    int lgParcours; // Longueur du PARCOURS en comptant la source et la destination, soit la distance + 2
    bool estPlusCourt; // Est ce que le parcours pointé par INDEXPARCOURS est le plus court des parcours entre SOURCE et DEST
    int indexParcours; // Index du PARCOURS dans le tableau monJeu.tabParcours
}InfoParcours;

typedef struct {
    Element element[MAX_CONSTRUCTION];
    Affichage affichage;
    BoiteOutils boiteOutils;
    int argent;
    int cycle;
    int coutConstruction[NIVEAU_BATIMENT];
    int nbHabitantParConstruction[NIVEAU_BATIMENT];
    int modeJeu;
    int nbElements;
    int nbhabitants;
    //ALLEGRO_BITMAP* bitmapConstruction[NIVEAU_BATIMENT];
    int tabParcours[MAX_PARCOURS][LG_MAX_PARCOURS]; // Tableau qui contient TOUS les PARCOURS depuis les INFRA vers d'autres INFRA
    InfoParcours tabParcoursConstruction[MAX_PARCOURS_CONSTRUCTION]; // Toutes les STRUCT d'INFO sur les PARCOURS qui ne concernent que les CONSTRUCTION
    InfoParcours tabParcoursCentrale[MAX_PARCOURS_CENTRALE]; // .. idem CENTRALE
    InfoParcours tabParcoursChateau[MAX_PARCOURS_CHATEAU]; // idem CHATEAU
    int nbParcours;
    int nbParcoursConstruction;
    int nbParcoursChateau;
    int nbParcoursCentrale;

}Jeu;


Jeu monJeu;



void initialisationJeu();






#endif //ECE_CITY_1_H_JEU_H
