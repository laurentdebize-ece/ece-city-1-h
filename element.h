#ifndef ECE_CITY_1_H_ELEMENT_H
#define ECE_CITY_1_H_ELEMENT_H
#include "stdbool.h"

#define NB_TYPE 4

#define MAX_LIGNES 30
#define MAX_COLONNES 30
#define MAX_CONSTRUCTION MAX_LIGNES*MAX_COLONNES
#define TYPE 4
#include "affichage.h"
#define PRIX_CENTRALE 100000
#define PRIX_CHATEAU 100000
#define PRIX_ROUTE 10
#define PRIX_CONSTRUCTION 1000
#define PRIX_ECOLE 1000
#define PRIX_MUSEE 1500
#define ACTIF 0
#define NON_ACTIF -1
#define NON_EVOLUTIF -1
#define EVOLUTIF 0
#define NON_CAPACITIF -1
#define LARGEUR_ROUTE 1
#define LONGUEUR_ROUTE 1
#define LARGEUR_CANAL 1
#define LONGUEUR_CANAL 1
#define LARGEUR_LIGNELEC 1
#define LONGUEUR_LIGNELEC 1
#define LARGEUR_CHATEAU 4
#define LONGUEUR_CHATEAU 6
#define LARGEUR_ECOLE 3
#define LONGUEUR_ECOLE 3
#define LARGEUR_CENTRALE 4
#define LONGUEUR_CENTRALE 6
#define LARGEUR_CONSTRUCTION 3
#define LONGUEUR_CONSTRUCTION 3

#define CAPA_CHATEAU 5000
#define GRILLE_X 45
#define GRILLE_Y 35
#define CAPA_CENTRALE 1900

enum type {CHATEAU, CENTRALE, CONSTRUCTION, ROUTE, ECOLE, MUSEE};


typedef struct {
    Affichage affichageElement;
    int type;
    int actif;//l'élement a-t-il été posé sur le plateau ?
    int niveau;//ssi c'est une construction
    int capacite;//ssi c'est un chateau ou une centrale
    int listeIndexElementsConnectes[MAX_CONSTRUCTION];
    int nbElementConnects;
    int nbHabitantElement;
    int niveauEduElement;//Si situé à proximité d'une école, le pourcentage d'édu augmente
    int tabDistanceAvecInfraConnectees[MAX_CONSTRUCTION];
    bool viable; // Est alimenté par une CENTRALE et un CHATEAU
    bool isPowered; // Est alimenté par une CENTRALE
    bool isWatered; // Est alimenté par un CHATEAU
}Element;










#endif //ECE_CITY_1_H_ELEMENT_H
