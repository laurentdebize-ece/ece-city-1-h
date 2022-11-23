#ifndef ECE_CITY_1_H_JEU_H
#define ECE_CITY_1_H_JEU_H

#include "stdbool.h"
#include "element.h"

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
#define MAX_PARCOURS 100
#define LG_MAX_PARCOURS 50
#define MAX_PARCOURS_CONSTRUCTION 50
#define MAX_PARCOURS_CHATEAU 100
#define MAX_PARCOURS_CENTRALE 100

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
    int niveauEducation;
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
    int tabTXT[LIGNES_TAB][COLONNES_TAB + 1]; // Grille du jeu
    int tabParcoursChateauActif[MAX_PARCOURS_CHATEAU]; // Contient 0 si ce PARCOURS n'est pas utilisé pour fournir de l'eau et 1 sinon
    int tabParcoursCentraleActif[MAX_PARCOURS_CENTRALE]; // Contient 0 si ce PARCOURS n'est pas utilisé pour fournir de l'éléectricité et 1 sinon

}Jeu;


Jeu monJeu;



void initialisationJeu();
void initTabParcours();
void initTabParcoursConstruction();
void initTabParcoursCentrale();
void initTabParcoursChateau();
void afficheParcours(int indexParcours, int lgParcours);
void afficheTabParcoursConstruction();
void afficheTabParcoursChateau();
void afficheTabParcoursCentrale();
int ajouteParcours (int *ptrParcours, int lgParcours);
int setParcoursCourantPlusCourt (int indexEltSource, int indexEltDest);
void ajouterElement(int typeElement, int positionX, int positionY);
int distanceEntre2Routes(int Element1, int Element2);
void UpdateaffichageConsole();
void regresserConstruction(int numeroElement);
void ameliorerConstruction(int numeroElement);
void initConstruction(int numeroElement, int ameliorer);//-1 si regresse, 0 si ameliore
void ChangerNiveauConstruction(int numeroElement, int ameliorer);//0 On améliore pas, 1 oui, -1 l'élement regresse
// En MODE_COMMUNISTE :
// Si la CONSTRUCTION n'est pas viable, elle REGRESSE au lieu d'évoluer
// En MODE_CAPITALISTE : on evolue quoi qu'il arrive
int evolutionConstruction();
void insererDansTableau(int racine, int branche);
bool estDansZone (int k, int x, int y);
void detectionElementsConnectes(int numeroElement);
void test();
void afficherEltConnectes(int numeroElement);
void afficheRoute(int *ptrRoute, int distance);
void initRoute(int *ptrRoute);
void initCheminParcouru (int *tabCheminParcouru);
void calculeDistanceAvecLesInfraConnectees(int source, int routeCourante, int *ptrDistanceCouranteDepuisSource, int *ptrTabCheminParcouru, int *ptrRoute);
void afficherTabDistanceInfraConnectees (int numeroElement);
void detecteConstructionsViables();
void detecteConstructionAlimenteesparChateau();//affecte la varibale isWatered et maj de la capacité restante
void detecteConstructionsAlimenteesParCentrale();
void classePacoursConstruction();
void classeParcoursCentrale();
void classeParcoursChateau();
void jeu();
// Fonctions nécessaires pour mettre à jour le jeu avec un TIC_TIMER
void majApresEvolutionNiveauConstruction(); // A appeler après un EVENT_TIMER d'1 sec
void recenseParcours();
void afficheStatutDesRessourcesParConstruction();
// Fonction nécessaires après l'ajout d'une CONSTRUCTION
void majApresAjoutConstruction(int i); // A appeler lorsque l'on ajoute une construction dont l'index est i
void majApresAjoutElement(int numElt);
void initCapaciteChateauxEtCentrales();
int rechercheReseauxEaux(int indexElt, char *ptr);
void afficheReseauxEaux();


/// FIN



#endif //ECE_CITY_1_H_JEU_H