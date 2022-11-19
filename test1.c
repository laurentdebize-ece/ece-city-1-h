#include <stdio.h>
#include "stdlib.h"
#include "jeu.h"
#define TRACE 0
#define LARGEUR 2880
#define HAUTEUR 1694
#define ECRAN_LONGUEUR 2880
#define ECRAN_LARGEUR 1694
#define OR2 al_map_rgb(255,235,20)
#define BLANC al_map_rgb(255,255,255)
#define NOIR al_map_rgb(0,0,0)

///////////////////////// AFFICHAGE.C ////////////////////

void surpassageCase (int xSouris, int ySouris){
    //centrale passage souris
    int x1 = 2505;
    int y1 = 276;
    int x2 = x1+130;
    int y2 = y1 + 135;
    if(xSouris >= x1 && xSouris <= x2){
        if(ySouris >= y1 && ySouris <= y2){
            al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgba(20,20,20,200));
        }

    }
}


int clicDansCase (int xSouris, int ySouris){
    //centrale passage souris
    int x1 = 2505;
    int y1 = 276;
    int x2 = x1+130;
    int y2 = y1 + 135;
    if(xSouris >= x1 && xSouris <= x2){
        if(ySouris >= y1 && ySouris <= y2){ //si souris dedans on return
            return CENTRALE;
            //printf("centrale");
        }

    }
}

//imaginons on return centrale avec clicDansCase
//on lui passe clicDansCase (int clicDansCase, xSouris, y Souris), en ligneSouris, colonnes souris, calculées juste avant
int ajouterElementGraphique(int typeconstruction, int xSouris, ySouris){
    ajouterElement(typeconstruction, xSouris, ySouris);
}


//#include "affichage.h"
//#define ECE_CITY_1_H_AFFICHAGE_H

void dessinerFilledRectangle2(float x, float y, float largeur, float hauteur, ALLEGRO_COLOR color){
    al_draw_filled_rectangle(x, y, x+largeur, y+hauteur, color);
}

void affichageModeJeu(){
    ALLEGRO_BITMAP *ecranChargement = al_load_bitmap("../images/modeJeu.jpg");
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    al_flip_display();
}

void affichageInterfaceJeu(){
    ALLEGRO_BITMAP *interfaceModeJeu = al_load_bitmap("../images/interfaceJeu.png");
    al_draw_bitmap(interfaceModeJeu, 0, 0, 0);
    al_flip_display();


}

void affichageChargement(){
    ALLEGRO_BITMAP *ecranChargement = al_load_bitmap("../images/FondEcran.jpeg");

    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 50, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 400, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 1000, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 2300, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargement, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, LARGEUR-160, 60, OR2);
    al_flip_display();
    sleep(1);
}

void affichage(Case tabCase[LIGNES_TAB][COLONNES_TAB],int tabTXT[LIGNES_TAB][COLONNES_TAB + 1],Image image,int ligneSouris,int colonneSouris, int xSouris, int ySouris) {
    //al_clear_to_color(al_map_rgb(159,232,85));
    //al_clear_to_color(al_map_rgb(255,255,255));

    //FOND :
    //al_draw_scaled_bitmap(image.fond,0,0,356,304,0,0,ECRAN_LONGUEUR,ECRAN_LARGEUR,0);
    al_draw_bitmap(image.fond, 0, 0, 0);

    //TABLEAUX :
    for (int i = 0; i <= LIGNES_TAB; ++i) {
        al_draw_line(X_TAB,Y_TAB+i*TAILLE_CASE,
                     X_TAB+TAILLE_CASE*COLONNES_TAB,Y_TAB+i*TAILLE_CASE,
                     al_map_rgb(0,0,0),2);
    }
    for (int j = 0; j <= COLONNES_TAB; ++j) {
        al_draw_line(X_TAB+j*TAILLE_CASE,Y_TAB,
                     X_TAB+j*TAILLE_CASE,Y_TAB+TAILLE_CASE*LIGNES_TAB,
                     al_map_rgb(0,0,0),2);
    }

    //MAP :
    for (int i = 0; i < LIGNES_TAB; ++i) {
        for (int j = 0; j < COLONNES_TAB + 1; ++j) {
            if (tabTXT[i][j] == 0 || j == 40) {}
            if (tabTXT[i][j] == 1) {
                al_draw_scaled_bitmap(image.routegd,0,0,118,118,tabCase[i][j].x,tabCase[i][j].y,TAILLE_CASE,TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 2) {
                al_draw_scaled_bitmap(image.routehb,0,0,118,118,tabCase[i][j].x,tabCase[i][j].y,TAILLE_CASE,TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 3) {
                al_draw_scaled_bitmap(image.routehd,0,0,118,118,tabCase[i][j].x,tabCase[i][j].y,TAILLE_CASE,TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 4) {
                al_draw_scaled_bitmap(image.routehg,0,0,118,118,tabCase[i][j].x,tabCase[i][j].y,TAILLE_CASE,TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 5) {
                al_draw_scaled_bitmap(image.routebd,0,0,118,118,tabCase[i][j].x,tabCase[i][j].y,TAILLE_CASE,TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 6) {
                al_draw_scaled_bitmap(image.routebg,0,0,118,118,tabCase[i][j].x,tabCase[i][j].y,TAILLE_CASE,TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 7) {
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+4*TAILLE_CASE,tabCase[i][j].y+6*TAILLE_CASE,
                                         al_map_rgba(0,70,255,200));
                al_draw_scaled_bitmap(image.chateaudeau,0,0,256,275,tabCase[i][j].x,tabCase[i][j].y,3*TAILLE_CASE,3*TAILLE_CASE,0);

            }
            if (tabTXT[i][j] == 8) {
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+4*TAILLE_CASE,tabCase[i][j].y+6*TAILLE_CASE,
                                         al_map_rgba(189,255,0,200));
                al_draw_scaled_bitmap(image.centraleelec,0,0,291,175,tabCase[i][j].x,tabCase[i][j].y,4*TAILLE_CASE,3*TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 9) {
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));
                al_draw_scaled_bitmap(image.maison1,0,0,118,354,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,6*TAILLE_CASE,0);

            }

            if (tabTXT[i][j] == 12) {
                al_draw_scaled_bitmap(image.gc1,0,0,118,354,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,6*TAILLE_CASE,0);
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));
            }
            if (tabTXT[i][j] == 13) {
                al_draw_scaled_bitmap(image.gc2,0,0,118,354,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,6*TAILLE_CASE,0);
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));
            }
            if (tabTXT[i][j] == 14) {
                al_draw_scaled_bitmap(image.gc3,0,0,118,354,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,6*TAILLE_CASE,0);
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));
            }
        }
    }

    //SOURIS :
    al_draw_filled_rectangle(tabCase[ligneSouris][colonneSouris].x+3,tabCase[ligneSouris][colonneSouris].y+3,
                             tabCase[ligneSouris][colonneSouris].x+TAILLE_CASE-4,tabCase[ligneSouris][colonneSouris].y+TAILLE_CASE-4,
                             al_map_rgba(20,20,20,200));










    /*for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabTXT[ligneSouris - i][colonneSouris - j] == 9) {
                al_draw_scaled_bitmap(image.maisonombre,0,0,291,293,tabCase[ligneSouris - i][colonneSouris - j].x,tabCase[ligneSouris - i][colonneSouris - j].y,3*TAILLE_CASE,3*TAILLE_CASE,0);
            }
            if (tabTXT[ligneSouris - i][colonneSouris - j] == 10) {
                al_draw_scaled_bitmap(image.maison2ombre,0,0,175,202,tabCase[ligneSouris - i][colonneSouris - j].x,tabCase[ligneSouris - i][colonneSouris - j].y,3*TAILLE_CASE,3*TAILLE_CASE,0);
            }
            if (tabTXT[ligneSouris - i][colonneSouris - j] == 11) {
                al_draw_scaled_bitmap(image.maison3ombre,0,0,172,200,tabCase[ligneSouris - i][colonneSouris - j].x,tabCase[ligneSouris - i][colonneSouris - j].y,3*TAILLE_CASE,3*TAILLE_CASE,0);

            }
            else if (tabTXT[ligneSouris][colonneSouris] == 0)
                al_draw_scaled_bitmap(image.maison2ombre,0,0,175,202,tabCase[ligneSouris][colonneSouris].x,tabCase[ligneSouris][colonneSouris].y,3*TAILLE_CASE,3*TAILLE_CASE,0);
            al_draw_filled_rectangle(tabCase[ligneSouris][colonneSouris].x+3,tabCase[ligneSouris][colonneSouris].y+3,
                                     tabCase[ligneSouris][colonneSouris].x+TAILLE_CASE-4,tabCase[ligneSouris][colonneSouris].y+TAILLE_CASE-4,
                                     al_map_rgba(20,20,20,200));
        }
    }*/

    surpassageCase(xSouris, ySouris);

    al_flip_display();
}




void carte() {
    bool end1 = false;
    bool end2 = false;
    bool end3 = false;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_EVENT event;
    FILE *file;

    Case tabCase[LIGNES_TAB][COLONNES_TAB] = {0};
    int tabTXT[LIGNES_TAB][COLONNES_TAB + 1] = {0};
    Image image;
    int xCase,yCase = Y_TAB;
    int ligneSouris = 0,colonneSouris = 0;
    int xSouris,ySouris;

    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_mouse();
    al_init_font_addon();
    al_init_ttf_addon();

    display = al_create_display(ECRAN_LONGUEUR,ECRAN_LARGEUR);
    timer = al_create_timer(1.0/60.0);
    queue = al_create_event_queue();
    al_register_event_source(queue,al_get_display_event_source(display));
    al_register_event_source(queue,al_get_mouse_event_source());
    al_register_event_source(queue,al_get_timer_event_source(timer));

    for (int i = 0; i < LIGNES_TAB; ++i) {
        xCase = X_TAB;
        for (int j = 0; j < COLONNES_TAB; ++j) {
            tabCase[i][j].x = (float)xCase;
            tabCase[i][j].y = (float)yCase;
            xCase += TAILLE_CASE;
        }
        yCase += TAILLE_CASE;
    }

    image.chateaudeau = al_load_bitmap("../images/piscine.png");
    image.centraleelec = al_load_bitmap("../images/centrale 3.png");
    image.caserne = al_load_bitmap("../images/caserne.png");
    image.routehb = al_load_bitmap("../images/route hb.png");
    image.routegd = al_load_bitmap("../images/route gd.png");
    image.routehd = al_load_bitmap("../images/route dh.png");
    image.routehg = al_load_bitmap("../images/route gh.png");
    image.routebd = al_load_bitmap("../images/route db.png");
    image.routebg = al_load_bitmap("../images/route gb.png");
    //image.fond = al_load_bitmap("../images/fond.png");
    image.fond = al_load_bitmap("../images/fond.png");
    image.maison1 = al_load_bitmap("../images/maison 1.png");
    image.maisonombre = al_load_bitmap("../images/maison 1 ombre.png");
    image.maison2 = al_load_bitmap("../images/maison 2.png");
    image.maison2ombre = al_load_bitmap("../images/maison 2 ombre.png");
    image.maison3 = al_load_bitmap("../images/maison 3.png");
    image.maison3ombre = al_load_bitmap("../images/maison 3 ombre.png");
    image.gc1 = al_load_bitmap("../images/g-c 1.png");
    image.gc1ombre = al_load_bitmap("../images/g-c 1 ombre.png");
    image.gc2 = al_load_bitmap("../images/g-c 2.png");
    image.gc2ombre = al_load_bitmap("../images/g-c 2 ombre.png");
    image.gc3 = al_load_bitmap("../images/g-c 3.png");
    image.gc3ombre = al_load_bitmap("../images/g-c 3 ombre.png");

    file = fopen("../test.txt","r");
    for (int i = 0; i < LIGNES_TAB; ++i) {
        for (int j = 0; j < COLONNES_TAB + 1; ++j) {
            tabTXT[i][j] = fgetc(file) - '0';
            if (tabTXT[i][j] == 9) {
                tabTXT[i][j] += rand()%3;
            }
        }
    }
    fclose(file);
    for (int i = 0; i < LIGNES_TAB; ++i) {
        for (int j = 0; j < COLONNES_TAB + 1; ++j) {
            //if(TRACE)printf("%d ",tabTXT[i][j]);
        }
        //if(TRACE)printf("\n");
    }

    //al_clear_to_color(al_map_rgb(255,255,255));
    al_flip_display();

    //affichageChargement();

    al_start_timer(timer);

    // Création d'un sous compteur pour cadencer l'évolution de la ville. Il s'active tous les 10 cycles de timer
    int counter = 0;
    int rapportReduction = 60;
    double currentTime = 0;

    //Choisir mode de Jeu (capitaliste, communiste)
    while (!end1){
        //affichageModeJeu();
        end1 = true;
    }
    while(!end2){
        //affichageInterfaceJeu();
        end2 = true;
    }
    while (!end3) {
        //Dans le cas ou l'utilisateur fait rien, il est inactif, spectateur du jeu
        if ((counter++)%rapportReduction == 0) {

            // Dans cette partie on va faire évoluer la ville
            // Améliorer toutes les constructions actives
            // payer les impots
            // mettre a jour le flouzz
            evolutionConstruction();
            currentTime = al_get_time();
            if(TRACE)printf("%2f ", currentTime);

        }
        al_wait_for_event(queue,&event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                end3 = true;
                break;

            case ALLEGRO_EVENT_MOUSE_AXES:
                xSouris = event.mouse.x;
                ySouris = event.mouse.y;
                for (int i = 0; i < LIGNES_TAB; ++i) {
                    for (int j = 0; j < COLONNES_TAB; ++j) {
                        if ((float)tabCase[i][j].y < (float)ySouris && (float)ySouris < (float)tabCase[i][j].y+TAILLE_CASE &&
                            (float)tabCase[i][j].x < (float)xSouris && (float) xSouris < (float)tabCase[i][j].x+TAILLE_CASE) {
                            ligneSouris = i;
                            colonneSouris = j;
                        }
                    }
                }
                if(TRACE)printf("%d,%d\n",ligneSouris,colonneSouris);
                break;

            case ALLEGRO_EVENT_TIMER:
                //affichage(tabCase,tabTXT,image,ligneSouris,colonneSouris);
                affichage(tabCase,monJeu.tabTXT,image,ligneSouris,colonneSouris,xSouris,ySouris);
                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                    //centrale passage souris
                clicDansCase(xSouris, ySouris);
                            if(TRACE)printf("centrale\n");

        }
    }
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
}

///////////////////////// FIN AFFICHAGE.C ////////////////////

///////////////////////// JEU.C ////////////////////
/*
#include <stdio.h>
#include "element.h"
#include "stdbool.h"
*/

void initTabParcours(){
    for (int i=0;i<MAX_PARCOURS;i++){
        for (int j=0; j<LG_MAX_PARCOURS; j++) {
            monJeu.tabParcours[i][j] = -1;
        }
    }
}

void initTabParcoursConstruction(){
    for (int i=0;i<MAX_PARCOURS_CONSTRUCTION;i++){
        monJeu.tabParcoursConstruction[i].source = -1;
        monJeu.tabParcoursConstruction[i].destination = -1;
        monJeu.tabParcoursConstruction[i].lgParcours = -1;
        monJeu.tabParcoursConstruction[i].estPlusCourt = 0;
    }
}
void initTabParcoursCentrale(){
    for (int i=0;i<MAX_PARCOURS_CENTRALE;i++){
        monJeu.tabParcoursCentrale[i].source = -1;
        monJeu.tabParcoursCentrale[i].destination = -1;
        monJeu.tabParcoursCentrale[i].lgParcours = -1;
        monJeu.tabParcoursCentrale[i].estPlusCourt = 0;
    }
}

void initTabParcoursChateau(){
    for (int i=0;i<MAX_PARCOURS_CHATEAU;i++){
        monJeu.tabParcoursChateau[i].source = -1;
        monJeu.tabParcoursChateau[i].destination = -1;
        monJeu.tabParcoursChateau[i].lgParcours = -1;
        monJeu.tabParcoursChateau[i].estPlusCourt = 0;
    }
}

void initialisationJeu(){

    monJeu.argent = ARGENT_INIT;
    monJeu.niveauEducation = 0;//niveau edu global = moyenne entre toutes les zones, édu et non édu
    monJeu.nbhabitants = NB_HABITANT_INIT;
    monJeu.nbHabitantParConstruction[RUINE] = NB_HAB_RUINE;
    monJeu.nbHabitantParConstruction[TERRAIN_VAGUE] = NB_HAB_RUINE;//mm habitants que terrain vague
    monJeu.nbHabitantParConstruction[CABANE] = NB_HAB_CABANE;
    monJeu.nbHabitantParConstruction[MAISON] = NB_HAB_MAISON;
    monJeu.nbHabitantParConstruction[IMMEUBLE] = NB_HAB_IMMEUBLE;
    monJeu.nbHabitantParConstruction[GRATTE_CIEL] = NB_HAB_GRATTE_CIEL;

    monJeu.cycle = CYCLE_INIT;
    monJeu.modeJeu = MODE_NON_CHOISI;
    monJeu.coutConstruction[TERRAIN_VAGUE] = PRIX_CONSTRUCTION;
    monJeu.coutConstruction[CENTRALE] = PRIX_CENTRALE;
    monJeu.coutConstruction[CHATEAU] = PRIX_CHATEAU;
    monJeu.coutConstruction[ROUTE] = PRIX_ROUTE;
    monJeu.nbElements = 0;


    for (int j = 0; j < MAX_CONSTRUCTION; j++) {
        monJeu.element[j].viable = false;
        monJeu.element[j].isPowered = false;
        monJeu.element[j].isWatered = false;
        monJeu.element[j].waterLevel = 0;
        monJeu.element[j].niveau = TERRAIN_VAGUE;
        monJeu.element[j].nbElementConnects = 0;
        //Initialise les tableaux de connexité des constructions à -1
        for (int i = 0; i < MAX_CONSTRUCTION ; i++) {
            monJeu.element[j].listeIndexElementsConnectes[i] = -1;
            monJeu.element[j].tabDistanceAvecInfraConnectees[i] = -1;
            monJeu.element[j].tabFournitureRessources[i] = -1;
        }
    }
    // Initialisation des PARCOURS
    monJeu.nbParcours = 0;
    monJeu.nbParcoursCentrale = 0;
    monJeu.nbParcoursChateau = 0;
    monJeu.nbParcoursChateau = 0;
    initTabParcours();
    initTabParcoursCentrale();
    initTabParcoursChateau();
    initTabParcoursConstruction();
}


void afficheParcours(int indexParcours, int lgParcours){
    for(int i=0; i<lgParcours; i++){
        if(TRACE)printf("%d_",monJeu.tabParcours[indexParcours][i]);
    }
    puts("");
}

void afficheTabParcoursConstruction(){
    // Si aucun parcours on sort
    if (!monJeu.nbParcoursConstruction) return;
    if(TRACE)printf("%2d PARCOURS DEPUIS CONSTRUCTION\n", monJeu.nbParcoursConstruction);
    for (int i=0;i<monJeu.nbParcoursConstruction;i++){
        if (monJeu.tabParcoursConstruction[i].source == -1) continue;
        if(TRACE)printf ("SOURCE:%d / DEST:%d / LG:%d / +COURT:%d / ",
                monJeu.tabParcoursConstruction[i].source,
                monJeu.tabParcoursConstruction[i].destination,
                monJeu.tabParcoursConstruction[i].lgParcours,
                monJeu.tabParcoursConstruction[i].estPlusCourt);
        afficheParcours(monJeu.tabParcoursConstruction[i].indexParcours, monJeu.tabParcoursConstruction[i].lgParcours);
    }
}
void afficheTabParcoursChateau(){
    // Si aucun parcours on sort
    if (!monJeu.nbParcoursChateau) return;
    if(TRACE)printf("%2d PARCOURS DEPUIS CHATEAU\n", monJeu.nbParcoursChateau);
    for (int i=0;i<monJeu.nbParcoursChateau;i++){
        if (monJeu.tabParcoursChateau[i].source == -1) continue;
        if(TRACE)printf ("SOURCE:%d / DEST:%d / LG:%d / +COURT:%d / ",
                monJeu.tabParcoursChateau[i].source,
                monJeu.tabParcoursChateau[i].destination,
                monJeu.tabParcoursChateau[i].lgParcours,
                monJeu.tabParcoursChateau[i].estPlusCourt);
        afficheParcours(monJeu.tabParcoursChateau[i].indexParcours, monJeu.tabParcoursChateau[i].lgParcours);
    }
}
void afficheTabParcoursCentrale(){
    // Si aucun parcours on sort
    if (!monJeu.nbParcoursCentrale) return;
    if(TRACE)printf("%2d PARCOURS DEPUIS CENTRALE\n", monJeu.nbParcoursCentrale);
    for (int i=0;i<monJeu.nbParcoursCentrale;i++){
        if (monJeu.tabParcoursCentrale[i].source == -1) continue;
        if(TRACE)printf ("SOURCE:%d / DEST:%d / LG:%d / +COURT:%d / ",
                monJeu.tabParcoursCentrale[i].source,
                monJeu.tabParcoursCentrale[i].destination,
                monJeu.tabParcoursCentrale[i].lgParcours,
                monJeu.tabParcoursCentrale[i].estPlusCourt);
        afficheParcours(monJeu.tabParcoursCentrale[i].indexParcours, monJeu.tabParcoursCentrale[i].lgParcours);
    }
}

int ajouteParcours (int *ptrParcours, int lgParcours){
    if (monJeu.nbParcours == MAX_PARCOURS) {
        if(TRACE)printf("ERREUR AJOUTPARCOURS : MAX_PARCOURS atteint\n");
        return -1;
    }
    if (lgParcours > LG_MAX_PARCOURS) {
        if(TRACE)printf("ERREUR AJOUTPARCOURS : LG_MAX_PARCOURS atteint\n");
        return -1;
    }
    // On cherche le type de PARCOURS
    // D'abord on recupere la SOURCE du PARCOURS
    Element source = monJeu.element[ptrParcours[0]];
    int typeParcours = source.type;
    // On ajoute le parcours en fonction du type de parcours rencontrés
    switch(typeParcours){
        case CONSTRUCTION:
            if (monJeu.nbParcoursConstruction > MAX_PARCOURS_CONSTRUCTION) {
                if(TRACE)printf("ERREUR AJOUTPARCOURS : MAX_PARCOURS_CONSTRUCTION atteint\n");
                return -1;
            }
            monJeu.tabParcoursConstruction[monJeu.nbParcoursConstruction].source = ptrParcours[0];
            monJeu.tabParcoursConstruction[monJeu.nbParcoursConstruction].destination = ptrParcours[lgParcours-1];
            monJeu.tabParcoursConstruction[monJeu.nbParcoursConstruction].lgParcours = lgParcours;
            monJeu.tabParcoursConstruction[monJeu.nbParcoursConstruction].estPlusCourt = false;
            monJeu.tabParcoursConstruction[monJeu.nbParcoursConstruction].indexParcours = monJeu.nbParcours;
            monJeu.nbParcoursConstruction++;
            break;
        case CHATEAU:
            if (monJeu.nbParcoursChateau > MAX_PARCOURS_CHATEAU) {
                if(TRACE)printf("ERREUR AJOUTPARCOURS : MAX_PARCOURS_CHATEAU atteint\n");
                return -1;
            }
            monJeu.tabParcoursChateau[monJeu.nbParcoursChateau].source = ptrParcours[0];
            monJeu.tabParcoursChateau[monJeu.nbParcoursChateau].destination = ptrParcours[lgParcours-1];
            monJeu.tabParcoursChateau[monJeu.nbParcoursChateau].lgParcours = lgParcours;
            monJeu.tabParcoursChateau[monJeu.nbParcoursChateau].estPlusCourt = false;
            monJeu.tabParcoursChateau[monJeu.nbParcoursChateau].indexParcours = monJeu.nbParcours;
            monJeu.nbParcoursChateau++;
            break;
        case CENTRALE:
            if (monJeu.nbParcoursCentrale > MAX_PARCOURS_CENTRALE) {
                if(TRACE)printf("ERREUR AJOUTPARCOURS : MAX_PARCOURS_CENTRALE atteint\n");
                return -1;
            }
            monJeu.tabParcoursCentrale[monJeu.nbParcoursCentrale].source = ptrParcours[0];
            monJeu.tabParcoursCentrale[monJeu.nbParcoursCentrale].destination = ptrParcours[lgParcours-1];
            monJeu.tabParcoursCentrale[monJeu.nbParcoursCentrale].lgParcours = lgParcours;
            monJeu.tabParcoursCentrale[monJeu.nbParcoursCentrale].estPlusCourt = false;
            monJeu.tabParcoursCentrale[monJeu.nbParcoursCentrale].indexParcours = monJeu.nbParcours;
            monJeu.nbParcoursCentrale++;
            break;
    }
    // On copie le parcours dans le tableau de parcours du jeu
    for (int i=0;i<lgParcours;i++){
        monJeu.tabParcours[monJeu.nbParcours][i] = ptrParcours[i];
    }
    monJeu.nbParcours ++;
    // Affichage des parcours pour DEBUGGAGE
    afficheTabParcoursConstruction();
    afficheTabParcoursChateau();
    afficheTabParcoursCentrale();
    // si nous arrivons justqu'ici, tout s'est bien passé
    return 0;
}

int setParcoursCourantPlusCourt (int indexEltSource, int indexEltDest){
    if (monJeu.nbParcours == 0) {
        if(TRACE)printf("ERREUR SETPARCOURSCOURANTPLUSCOURT : Pas de parcours\n");
        return -1;
    }
    // En fonction du TYPE, nous allons renseigner la table d'information concernée
    int type = monJeu.element[indexEltSource].type;
    switch (type){
        case CONSTRUCTION:
            // 1. On REINIT tous les PARCOURS.ESTPLUSCOURT qui match avec SOURCE et DEST
            for (int i=0; i<monJeu.nbParcoursConstruction;i++){
                if (monJeu.tabParcoursConstruction[i].source == indexEltSource &&
                    monJeu.tabParcoursConstruction[i].destination == indexEltDest){
                    monJeu.tabParcoursConstruction[i].estPlusCourt = false;
                }
            }
            // Maintenance on renseigne le PARCOURS courant comme le plus court
            monJeu.tabParcoursConstruction[monJeu.nbParcoursConstruction-1].estPlusCourt = true;
            break;
        case CHATEAU:
            // 1. On REINIT tous les PARCOURS.ESTPLUSCOURT qui match avec SOURCE et DEST
            for (int i=0; i<monJeu.nbParcoursChateau;i++){
                if (monJeu.tabParcoursChateau[i].source == indexEltSource &&
                    monJeu.tabParcoursChateau[i].destination == indexEltDest){
                    monJeu.tabParcoursChateau[i].estPlusCourt = false;
                }
            }
            // Maintenance on renseigne le PARCOURS courant comme le plus court
            monJeu.tabParcoursChateau[monJeu.nbParcoursChateau-1].estPlusCourt = 1;
            break;
        case CENTRALE:
            // 1. On REINIT tous les PARCOURS.ESTPLUSCOURT qui match avec SOURCE et DEST
            for (int i=0; i<monJeu.nbParcoursCentrale;i++){
                if (monJeu.tabParcoursCentrale[i].source == indexEltSource &&
                    monJeu.tabParcoursCentrale[i].destination == indexEltDest){
                    monJeu.tabParcoursCentrale[i].estPlusCourt = false;
                }
            }
            // Maintenance on renseigne le PARCOURS courant comme le plus court
            monJeu.tabParcoursCentrale[monJeu.nbParcoursCentrale-1].estPlusCourt = 1;
            break;
    }
    return 0;
}

void ajouterElement(int typeElement, int positionX, int positionY){
    // Vérification de l'intégrité des variables X, Y
    if (positionX >= MAX_LIGNES || positionY >= MAX_COLONNES) {
        puts("Erreur position dans AJOUTERELEMENT\n");
        return;
    }
    switch (typeElement) {
        case ROUTE :
            monJeu.element[monJeu.nbElements].actif = ACTIF;
            monJeu.argent = monJeu.argent - PRIX_ROUTE;
            monJeu.element[monJeu.nbElements].affichageElement.positionX = positionX;
            monJeu.element[monJeu.nbElements].affichageElement.positionY = positionY;
            monJeu.element[monJeu.nbElements].affichageElement.largeurX = LARGEUR_ROUTE;
            monJeu.element[monJeu.nbElements].affichageElement.largeurY = LONGUEUR_ROUTE;
            monJeu.element[monJeu.nbElements].type = ROUTE;
            monJeu.element[monJeu.nbElements].niveau = NON_EVOLUTIF;//il n'évolue pas en niveau
            monJeu.element[monJeu.nbElements].capacite = NON_CAPACITIF;
            monJeu.element[monJeu.nbElements].nbHabitantElement = 0;
            monJeu.nbElements++; //On rajoute 1 élement au jeu global
            monJeu.tabTXT[positionY][positionX]=1;
            break;

        case CHATEAU:
            monJeu.element[monJeu.nbElements].actif = ACTIF;
            monJeu.argent = monJeu.argent - PRIX_CHATEAU;
            monJeu.element[monJeu.nbElements].affichageElement.positionX = positionX;
            monJeu.element[monJeu.nbElements].affichageElement.positionY = positionY;
            monJeu.element[monJeu.nbElements].affichageElement.largeurX = LARGEUR_CHATEAU;
            monJeu.element[monJeu.nbElements].affichageElement.largeurY = LONGUEUR_CHATEAU;
            monJeu.element[monJeu.nbElements].type = CHATEAU;
            monJeu.element[monJeu.nbElements].niveau = NON_EVOLUTIF;//il n'évolue pas en niveau
            monJeu.element[monJeu.nbElements].capacite = CAPA_CHATEAU;
            monJeu.element[monJeu.nbElements].nbHabitantElement = 0;
            monJeu.nbElements++;
            monJeu.tabTXT[positionY][positionX]=7;
            break;

        case CENTRALE:
            monJeu.element[monJeu.nbElements].actif = ACTIF;
            monJeu.argent = monJeu.argent - PRIX_CENTRALE;
            monJeu.element[monJeu.nbElements].affichageElement.positionX = positionX;
            monJeu.element[monJeu.nbElements].affichageElement.positionY = positionY;
            monJeu.element[monJeu.nbElements].affichageElement.largeurX = LARGEUR_CENTRALE;
            monJeu.element[monJeu.nbElements].affichageElement.largeurY = LONGUEUR_CENTRALE;
            monJeu.element[monJeu.nbElements].type = CENTRALE;
            monJeu.element[monJeu.nbElements].niveau = NON_EVOLUTIF;//il n'évolue pas en niveau
            monJeu.element[monJeu.nbElements].capacite = CAPA_CENTRALE;
            monJeu.element[monJeu.nbElements].nbHabitantElement = 0;
            monJeu.nbElements++;
            monJeu.tabTXT[positionY][positionX]=8;
            break;

        case CONSTRUCTION:
            monJeu.element[monJeu.nbElements].actif = ACTIF;
            monJeu.argent = monJeu.argent - PRIX_CONSTRUCTION;
            monJeu.element[monJeu.nbElements].affichageElement.positionX = positionX;
            monJeu.element[monJeu.nbElements].affichageElement.positionY = positionY;
            monJeu.element[monJeu.nbElements].affichageElement.largeurX = LARGEUR_CONSTRUCTION;
            monJeu.element[monJeu.nbElements].affichageElement.largeurY = LONGUEUR_CONSTRUCTION;
            monJeu.element[monJeu.nbElements].type = CONSTRUCTION;
            monJeu.element[monJeu.nbElements].niveau = EVOLUTIF;
            monJeu.element[monJeu.nbElements].capacite = NON_CAPACITIF;
            monJeu.element[monJeu.nbElements].nbHabitantElement = 0;
            monJeu.tabTXT[positionY][positionX]=14;
            monJeu.nbElements++;
            break;

        case ECOLE: // On fera spawn une bibliothèque qui pourra s'améliorer en école d'ingé (3x3 cases)
            monJeu.element[monJeu.nbElements].actif = ACTIF;
            monJeu.argent = monJeu.argent - PRIX_ECOLE;
            monJeu.element[monJeu.nbElements].affichageElement.positionX = positionX;
            monJeu.element[monJeu.nbElements].affichageElement.positionY = positionY;
            monJeu.element[monJeu.nbElements].affichageElement.largeurX = LARGEUR_ECOLE;
            monJeu.element[monJeu.nbElements].affichageElement.largeurY = LONGUEUR_ECOLE;
            monJeu.element[monJeu.nbElements].type = ECOLE;
            monJeu.element[monJeu.nbElements].niveau = EVOLUTIF;
            monJeu.element[monJeu.nbElements].niveauEduElement = 1;
            monJeu.niveauEducation++;
            //le nv global est 1 quand on pose une école
            monJeu.element[monJeu.nbElements].capacite = NON_CAPACITIF;
            monJeu.element[monJeu.nbElements].nbHabitantElement = 0;
            monJeu.nbElements++;
            break;

        case MUSEE: // On fera spawn un musée, qui rapportera 2 points d'éducation + de l'argent à chaque cycle
            monJeu.element[monJeu.nbElements].actif = ACTIF;
            monJeu.argent = monJeu.argent - PRIX_MUSEE;
            //toute les cycles ça rapporte de l'argent, mais y'a que quand on le pose que ça rapporte de l'éducation
            monJeu.element[monJeu.nbElements].affichageElement.positionX = positionX;
            monJeu.element[monJeu.nbElements].affichageElement.positionY = positionY;
            monJeu.element[monJeu.nbElements].affichageElement.largeurX = LARGEUR_ECOLE;
            monJeu.element[monJeu.nbElements].affichageElement.largeurY = LONGUEUR_ECOLE;
            monJeu.element[monJeu.nbElements].type = MUSEE;
            monJeu.element[monJeu.nbElements].niveau = NON_EVOLUTIF;
            monJeu.element[monJeu.nbElements].niveauEduElement = 2;
            monJeu.niveauEducation = monJeu.niveauEducation +monJeu.element[monJeu.nbElements].niveauEduElement;
            //le nv global est 1 quand on pose une école
            monJeu.element[monJeu.nbElements].capacite = NON_CAPACITIF;
            monJeu.element[monJeu.nbElements].nbHabitantElement = 0;
            monJeu.nbElements++;
            break;
    }
}


int distanceEntre2Routes(int Element1, int Element2){
    int x1 = monJeu.element[Element1].affichageElement.positionX;
    int x2 = monJeu.element[Element2].affichageElement.positionX;
    int y1 = monJeu.element[Element1].affichageElement.positionY;
    int y2 = monJeu.element[Element2].affichageElement.positionY;
    int distanceX = MAX(x1,x2)- MIN(x1,x2);
    int distanceY = MAX(y1,y2)- MIN(y1,y2);
    if(TRACE)printf("%d\n", distanceX+distanceY-1);//-1 car on ne prend pas en compte la route elle-même
    return distanceX+distanceY-1;
}

void UpdateaffichageConsole(){
    if(TRACE)printf("argent courant : \n", monJeu.argent);
    if(TRACE)printf("nombre élements placés : %d", monJeu.nbElements);
    if(TRACE)printf("nombre habitants actuel (non fait)\n", monJeu.nbhabitants);
}


void regresserConstruction(int numeroElement){
    monJeu.element[numeroElement].niveau = monJeu.element[numeroElement].niveau-1;
}

void ameliorerConstruction(int numeroElement){
    monJeu.element[numeroElement].niveau = monJeu.element[numeroElement].niveau+1;
}

void initConstruction(int numeroElement, int ameliorer){//-1 si regresse, 0 si ameliore
    int niveau = monJeu.element[numeroElement].niveau;
    if (monJeu.element[numeroElement].type == CONSTRUCTION){
        switch (niveau) {
            case RUINE :
                monJeu.element[numeroElement].nbHabitantElement = 0;
                break;
            case TERRAIN_VAGUE:
                monJeu.element[numeroElement].nbHabitantElement = 0;
                break;
            case CABANE:
                monJeu.element[numeroElement].nbHabitantElement = 10;
                break;
            case MAISON:
                monJeu.element[numeroElement].nbHabitantElement = 50;
                break;
            case IMMEUBLE:
                monJeu.element[numeroElement].nbHabitantElement = 100;
                break;
            case GRATTE_CIEL:
                monJeu.element[numeroElement].nbHabitantElement = 1000;
                break;
        }
        if(ameliorer == 0){
            monJeu.nbhabitants = monJeu.nbhabitants + monJeu.element[numeroElement].nbHabitantElement; //on met à jour les habitants totaux
        }
        if(ameliorer == -1){//Cas de régression. On regarde cb d'habitant on enlève au total
            if(monJeu.element[numeroElement].niveau == RUINE || TERRAIN_VAGUE){
                monJeu.nbhabitants = monJeu.nbhabitants - NB_HAB_CABANE;
            }
            if(monJeu.element[numeroElement].niveau == CABANE){
                monJeu.nbhabitants = monJeu.nbhabitants - 40;
            }
            if(monJeu.element[numeroElement].niveau == MAISON){
                monJeu.nbhabitants = monJeu.nbhabitants - 50;
            }
            if(monJeu.element[numeroElement].niveau == IMMEUBLE){
                monJeu.nbhabitants = monJeu.nbhabitants - 900;
            }
        }

    }
    if (monJeu.element[numeroElement].type == ECOLE){//On a fait monter d'un niveau la bibliothèque pour que ce soit une école d'ingé
        if(monJeu.element[numeroElement].niveau == 1){// si c'est une école d'ingé et plus une bibliothèque
            puts("ecole d'ingé");
            monJeu.element[numeroElement].niveauEduElement++;//les gens dans l'élement sont plus éduqués
            // on va l'initialiser à 1 quand on pose une biblio, à 2 quand il passe école d'ingé
            monJeu.niveauEducation++;//la ville globale améliore son nv d'édu

        }
    }
}


void ChangerNiveauConstruction(int numeroElement, int ameliorer){//0 On améliore pas, 1 oui, -1 l'élement regresse
    if(monJeu.element[numeroElement].type == CONSTRUCTION || monJeu.element[numeroElement].type == ECOLE){//On vérifie que ce ne soit pas un chateau, centrale, école
        if(ameliorer == -1){
            regresserConstruction(numeroElement);
            initConstruction(numeroElement,-1);
        }
        if(ameliorer == 1){
            ameliorerConstruction(numeroElement);
            initConstruction(numeroElement, 0);
        } else{
            if(TRACE)printf("Erreur amélioration niveau, mauvais chiffre renseigné\n");
            return;
        }
    }
    puts("Fonction changer niveau : ");
    if(TRACE)printf("bâtiment position [%d][%d] est passé niveau : %d\n", monJeu.element[numeroElement].affichageElement.positionX, monJeu.element[numeroElement].affichageElement.positionX, monJeu.element[numeroElement].niveau);
    puts("");
}


// En MODE_COMMUNISTE :
// Si la CONSTRUCTION n'est pas viable, elle REGRESSE au lieu d'évoluer
// En MODE_CAPITALISTE : on evolue quoi qu'il arrive

//renvoie le total des impots a percevoir après évolution
int evolutionConstruction(){
    int impots = 0;
    // Pour chaque CONSTRUCTION, on evolue en fonction du MODE
    if (MODE_NON_CHOISI== monJeu.modeJeu) {
        if(TRACE)printf("ERREUR : Mode JEU NON CHOISI\n");
        return 0;
    }
    for (int i=0;i<monJeu.nbElements;i++){
        if(monJeu.element[i].actif != ACTIF) continue;
        if (monJeu.modeJeu == MODE_COMMUNISTE && !monJeu.element[i].viable) ChangerNiveauConstruction(i,-1);
        else ChangerNiveauConstruction(i,1);
        impots += monJeu.element[i].nbHabitantElement;
    }
    return impots;
}


void insererDansTableau(int racine, int branche){
    //if(TRACE)printf("insererDansTableau (%d;%d)\n", racine, branche);
    // Verifie que la branche n'est pas déjà renseignée dans le tab des elts connectés
    for (int i = 0; i < MAX_CONSTRUCTION ;i++) {
        if(monJeu.element[racine].listeIndexElementsConnectes[i] == branche){// pour pas le faire plusieurs fois
            // si l'elt est déjà présent on sort de la fonction insererDans Tableau
            //if(TRACE)printf("je sors car la branche est déjà présnte en %d", i);
            return;
        }
    }
    //if(TRACE)printf(".");
    for(int j = 0; j<MAX_CONSTRUCTION; j++){
        if(monJeu.element[racine].listeIndexElementsConnectes[j] == -1){
            monJeu.element[racine].listeIndexElementsConnectes[j]=branche;
            monJeu.element[racine].nbElementConnects = monJeu.element[racine].nbElementConnects+1;
            //puts("Fonction connexité : ");
            //if(TRACE)printf("element %d connecté à element %d\n",racine, branche);
            break;//pour sortir car sinn ca remplit tt le tableau
        }
    }
}

bool estDansZone (int k, int x, int y){
    // Vérifie si les coordonnées x, y sont comprises dans la zone occupée par l'element K
    if (x >= monJeu.element[k].affichageElement.positionX && x < monJeu.element[k].affichageElement.positionX + monJeu.element[k].affichageElement.largeurX){
        if(y >= monJeu.element[k].affichageElement.positionY && y < monJeu.element[k].affichageElement.positionY + monJeu.element[k].affichageElement.largeurY){
            return true;
        }
    }
    return false;
}


void detectionElementsConnectes(int numeroElement, int tailleX, int tailleY){
    int positioncurseurX = monJeu.element[numeroElement].affichageElement.positionX-1;
    int positioncurseurY = monJeu.element[numeroElement].affichageElement.positionY-1;
    //ON commence par X
    //if(TRACE)printf("detectionElement\n");
    for (int x = positioncurseurX; x < positioncurseurX+tailleX+2;x++) {
        for(int y = positioncurseurY; y<positioncurseurY+tailleY+2;y++){
            for(int k = 0; k<monJeu.nbElements; k++){
                // Suppression des recherches dans les coins
                if (x == positioncurseurX && y == positioncurseurY) continue;
                if (x == positioncurseurX && y == positioncurseurY+tailleY+1) continue;
                if (x == positioncurseurX+tailleX+1 && y == positioncurseurY) continue;
                if (x == positioncurseurX+tailleX+1 && y == positioncurseurY+tailleY+1) continue;
                // Fin de la suppression des recherches dans les coins
                if(numeroElement != k && monJeu.element[k].actif == ACTIF){
                    //if(TRACE)printf("Test interco : %d en (%d,%d) avec %d en %d,%d)\n", numeroElement,x,y,k,monJeu.element[k].affichageElement.positionX,monJeu.element[k].affichageElement.positionY);
                    if(estDansZone (k, x, y)){ // == monJeu.element[k].affichageElement.positionX && y == monJeu.element[k].affichageElement.positionY){
                        insererDansTableau(numeroElement, k);
                    }
                }
            }
        }
    }
}
void lireFichierTextePourAjouterElement(char *nomFichier) {
    FILE *ifs = fopen(nomFichier, "r");
    int typeElement, positionX, positionY , taille, numeroPartie;

    if (!ifs) {
        if(TRACE)printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    fscanf(ifs, "%d", &numeroPartie);
    fscanf(ifs, "%d", &taille);

    // creer les aretes du graphe
    for (int i = 0; i < taille; ++i) {
        fscanf(ifs, "%d%d%d", &typeElement, &positionX, &positionY);
        ajouterElement(typeElement, positionX, positionY);
    }
    fclose(ifs);
}
void ecrireFichierTextePOurSauvegarderPartie(char *nomFichier, int typeNouvelElement, int positionX, int positionY){
    FILE *ifs = fopen(nomFichier, "a");
    if (!ifs) {
        if(TRACE)printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    fprintf(ifs, "%d %d %d", typeNouvelElement, positionX, positionY);
    fclose(ifs);
    //pour ajouter un seul nouvel element à la fois dans le fichier texte
}

void test(){
    lireFichierTextePourAjouterElement("../fichierTexteTest1.txt");

    ajouterElement(CONSTRUCTION, 1, 1);//0
    ajouterElement(ROUTE, 2, 4);
    ajouterElement(ROUTE, 4,2);
    ajouterElement(ROUTE, 4, 4);
    ajouterElement(ROUTE, 3, 6);
    ajouterElement(CHATEAU, 5, 7);
    ajouterElement(ROUTE, 5, 6);//6
    ajouterElement(ROUTE, 5, 4);
    ajouterElement(ROUTE, 5, 5);
    ajouterElement(ROUTE, 5, 2);
    ajouterElement(ROUTE, 6, 2);//10
    ajouterElement(ROUTE, 7, 2);
    ajouterElement(ROUTE, 7, 3);
    ajouterElement(ROUTE, 7, 4);
    ajouterElement(ROUTE, 7, 5);
    ajouterElement(ROUTE, 7, 6);//15
    ajouterElement(CENTRALE, 8, 0);
    ajouterElement(ROUTE, 2, 5);
    ajouterElement(ROUTE, 2, 6);
    ajouterElement(ROUTE, 3, 7);
    ajouterElement(ROUTE, 4, 8);//20
    ajouterElement(ROUTE, 3, 8);
    ajouterElement(ROUTE, 3, 4);
    ajouterElement(CONSTRUCTION, 15,12 );//23
    ajouterElement(ROUTE, 8,13 );
    ajouterElement(ROUTE, 9,13 );
    ajouterElement(ROUTE, 10,13 );
    ajouterElement(ROUTE, 10,12 );
    ajouterElement(ROUTE, 10,11 );
    ajouterElement(ROUTE, 10,14 );
    ajouterElement(ROUTE, 11,14 );//30
    ajouterElement(ROUTE, 12,14 );
    ajouterElement(ROUTE, 13,14 );
    ajouterElement(ROUTE, 14,14 );
    ajouterElement(ROUTE, 10,10 );
    ajouterElement(ROUTE, 10,9 );
    ajouterElement(ROUTE, 11,9 );
    ajouterElement(ROUTE, 12,9 );
    ajouterElement(CONSTRUCTION,13 ,7 );//38
    ajouterElement(ROUTE, 16,11 );
    ajouterElement(ROUTE, 16,10 );//40
    ajouterElement(ROUTE, 16,9 );
    ajouterElement(CENTRALE, 20, 1);
    //ajouterElement(CHATEAU, 20, 1);
    ajouterElement(ROUTE, 12, 4);
    ajouterElement(ROUTE, 13, 4);
    ajouterElement(ROUTE, 14, 4);//45
    ajouterElement(ROUTE, 14,5 );
    ajouterElement(ROUTE, 14,6 );
    ajouterElement(ROUTE, 19,6 );
    ajouterElement(ROUTE, 19,7 );
    ajouterElement(ROUTE, 19,8 );//50
    ajouterElement(ROUTE, 19,9 );
    ajouterElement(ROUTE, 19,10 );
    ajouterElement(ROUTE, 19,11 );
    ajouterElement(ROUTE, 19,12 );
    ajouterElement(ROUTE, 18,12 );//55
    ajouterElement(ROUTE, 11,6 );//56
    ajouterElement(ROUTE, 11,7 );//57
    ajouterElement(ROUTE, 12,7 );//58
    ajouterElement(CHATEAU, 24,13 );//59
    ajouterElement(ROUTE, 23,16 );
    ajouterElement(ROUTE, 22,16 );
    ajouterElement(ROUTE, 21,16 );
    ajouterElement(ROUTE, 20,16 );
    ajouterElement(ROUTE, 19,16 );
    ajouterElement(ROUTE, 18, 16);
    ajouterElement(ROUTE, 17,16 );
    ajouterElement(ROUTE, 16,16 );
    ajouterElement(ROUTE, 15,16 );
    ajouterElement(ROUTE, 15,15 );
    //ajouterElement(CHATEAU, 17,16 );//67
    ajouterElement(ROUTE, 9,9 );

    //ajouterElement(ECOLE, 1, 1);
    //ajouterElement(ROUTE, 4, 5);
    //ajouterElement(MUSEE, 5, 6);
}


void afficherEltConnectes(int numeroElement){
    if(TRACE)printf("Element %d connecté à elements : ", numeroElement);
    for(int i = 0; i < MAX_CONSTRUCTION ; i++){
        if(monJeu.element[numeroElement].listeIndexElementsConnectes[i] != -1){
            if(TRACE)printf("%d, ", monJeu.element[numeroElement].listeIndexElementsConnectes[i]);
        }
    }
    puts("");
}
int cpt = 0;


void afficheRoute(int *ptrRoute, int distance){
    //return;
    for(int i=0; i<distance+1; i++){
        if (-1 != ptrRoute[i]) if(TRACE)printf("%d_",ptrRoute[i]);
    }
    puts("");
}
void initRoute(int *ptrRoute){
    for (int p=0; p<MAX_CONSTRUCTION; p++){
        ptrRoute[p]=-1;
    }
}

void initCheminParcouru (int *tabCheminParcouru){
    // On initialise le tabCheminParcouru pour éviter de boucler et route pour mémoriser les routes empruntées
    for (int j=0; j<MAX_CONSTRUCTION;j++){
        tabCheminParcouru[j]=-1; // on le met à zéro quand on passe dessus
    }
}

void calculeDistanceAvecLesInfraConnectees(int source, int routeCourante, int *ptrDistanceCouranteDepuisSource, int *ptrTabCheminParcouru, int *ptrRoute) {
// Calcule la distance  couverte par des routes entre la Source et les INFRA connectées à partir de la route courante

    //afficheRoute(ptrRoute,*ptrDistanceCouranteDepuisSource);
    //if(TRACE)printf("calculeDistanceAvecLesInfraConnectees : Source = %d ; index Route courante = %d; distance Courante = %d\n", source, routeCourante, *ptrDistanceCouranteDepuisSource);
    //if(TRACE)printf("%d",ptrTabCheminParcouru[0]);
    cpt++;
    //if (cpt ==10) abort();

    // Renvoie le nombre de construction connectées via des routes
    int nbConstructionsConnectees = 0;
    int indexEltConnecte = -1;
    // on parcourt tous les elts connectés à l'elt
    // si l'elt connecté est une construction, on renseigne la distance (avec la valeur en cours) et on ajoute 1 construction connectee
    // si l'elt connecté n'est pas une construction (c'est une route), alors on ajoute 1 à la distance, puis on parcourt tous les elts connectées à cette route et on boucle

    // On va boucler sur tous les elts connectes pour explorer les différentes ROUTES
    // A chaque fois on repart de ptrDistanceCouranteDepuisSource
    int valeurdavant = *ptrDistanceCouranteDepuisSource;
    for(int i=0; i<MAX_CONSTRUCTION; i++){
        // Pour permettre à tous le spoints de connexion d'une INFRA de se connecter à un chemin meme s'il a déjà été emprunté
        if (routeCourante == source){
            initRoute(ptrRoute);
            ptrRoute[0]=source;
            initCheminParcouru(ptrTabCheminParcouru);
            ptrTabCheminParcouru[source]=0;
        }
        *ptrDistanceCouranteDepuisSource = valeurdavant;
        indexEltConnecte = monJeu.element[routeCourante].listeIndexElementsConnectes[i];
        if (indexEltConnecte == source) continue; // Permet de ne pas identifier les routes pour aller de la SOURCE à la SOURCE
        if (-1 == indexEltConnecte) break;
        if (ROUTE == monJeu.element[indexEltConnecte].type) {
            if (ptrTabCheminParcouru[indexEltConnecte] == 0) continue;
            ptrTabCheminParcouru[indexEltConnecte]=0;
            (*ptrDistanceCouranteDepuisSource) ++;
            ptrRoute[*ptrDistanceCouranteDepuisSource]=indexEltConnecte;
            //if(TRACE)printf("ROUTE trouvée %d\n", indexEltConnecte);
            calculeDistanceAvecLesInfraConnectees(source, indexEltConnecte, ptrDistanceCouranteDepuisSource, ptrTabCheminParcouru, ptrRoute);
        }
            // Cas où on a une CONSTRUCTION ou un CHATEAU ou une CENTRALE
            // On vérifie si la distance avec cet elt a déjà été renseignée
        else {
            //if(TRACE)printf("******* INFRA TROUVEE\n");
            (*ptrDistanceCouranteDepuisSource) ++;
            ptrRoute[*ptrDistanceCouranteDepuisSource]=indexEltConnecte;
            afficheRoute(ptrRoute,*ptrDistanceCouranteDepuisSource);
            ajouteParcours(ptrRoute, *ptrDistanceCouranteDepuisSource+1);
            if (-1 == monJeu.element[source].tabDistanceAvecInfraConnectees[indexEltConnecte] ||
                (*ptrDistanceCouranteDepuisSource-1) < monJeu.element[source].tabDistanceAvecInfraConnectees[indexEltConnecte]) {
                monJeu.element[source].tabDistanceAvecInfraConnectees[indexEltConnecte] = *ptrDistanceCouranteDepuisSource-1;
                //if(TRACE)printf("INFRA trouvée %d via %d (ROUTE) à distance %d\n", indexEltConnecte, routeCourante, *ptrDistanceCouranteDepuisSource);
                //if(TRACE)printf("ROUTE GAGNANTE EN %d coups (SOURCE=%d DEST=%d): ", *ptrDistanceCouranteDepuisSource, source, indexEltConnecte);
                //afficheRoute(ptrRoute,*ptrDistanceCouranteDepuisSource);
                setParcoursCourantPlusCourt(source, indexEltConnecte);
                puts("SET ROUTE PLUS COURTE");
                //afficheTabParcoursConstruction();
                //afficheTabParcoursChateau();
                //afficheTabParcoursCentrale();
                //initRoute(ptrRoute);
                //ptrRoute[0]=source;
            }
            else {
                //if(TRACE)printf("INFRA DEJA trouvée %d via %d (ROUTE) à distance %d\n", indexEltConnecte, routeCourante, *ptrDistanceCouranteDepuisSource);
            }
        }
    }
}

void afficherTabDistanceInfraConnectees (int numeroElement){
    if(TRACE)printf("Distance des INFRA connectées à %d : ", numeroElement);
    for(int i = 0; i < MAX_CONSTRUCTION ; i++){
        if(monJeu.element[numeroElement].tabDistanceAvecInfraConnectees[i] != -1){
            if(TRACE)printf("INFRA %d à %d cases, ", i, monJeu.element[numeroElement].tabDistanceAvecInfraConnectees[i]);
        }
    }
    puts("");
}

void detecteConstructionsViables(){
    // Parcourir TOUTES les CONSTRUCTIONS pour savoir si ELLES sont viables cad CONNECTEES à un CHATEAU et à une CENTRALE
    int indexSource = -1;
    bool hasDestCentrale = false;
    bool hasDestChateau = false;
    int indexDest;

    for (int i=0; i<monJeu.nbElements;i++){
        if (monJeu.element[i].type == CONSTRUCTION){
            if (monJeu.element[i].isWatered && monJeu.element[i].isPowered){
                monJeu.element[i].viable = true;
                if(TRACE)printf("CONSTRUCTION n°%02d VIABLE\n",i);
            }
        }
    }
}



void detecteConstructionAlimenteesparChateau(){//affecte la varibale isWatered et maj de la capacité restante
    //voir ttes les constructions alimentées par des châteaux d'eaux
    int indexChateauCourant = -1;
    int indexDestination = -1;

    for (int i=0; i<monJeu.nbParcoursChateau; i++){
        // Est ce que c'est toujours le mm chateau
        if(indexChateauCourant != monJeu.tabParcoursChateau[i].source){
            //monJeu.element[i].capacite = CAPA_CHATEAU;
            indexChateauCourant = monJeu.tabParcoursChateau[i].source;
        }
        // Si pour cette CHATEAU la capacite restante est NULLE on passe le tour
        //if(TRACE)printf ("monJeu.element[%d].capacite =%d\n",i,monJeu.element[i].capacite);
        if (monJeu.element[indexChateauCourant].capacite == 0) continue;

        //Est ce que c'est une construction ?
        indexDestination = monJeu.tabParcoursChateau[i].destination;
        if(monJeu.element[indexDestination].type == CONSTRUCTION) {
            if (!monJeu.element[indexDestination].isWatered){
                // Dans ce cas, le CHATEAU va fournir TOUT ou PARTIE de sa capacité en eau restante à cette construction
                if(monJeu.element[indexChateauCourant].capacite >= (monJeu.element[indexDestination].nbHabitantElement-monJeu.element[indexDestination].waterLevel)){// est ce que la capacité le permet
                    // Le CHATEAU fournit la CAPACITE nécessaire pour alimenter completement la CONSTRUCTION
                    // La CAPACITE du CHATEAU est réduite d'autant
                    monJeu.element[indexChateauCourant].capacite -= (monJeu.element[indexDestination].nbHabitantElement-monJeu.element[indexDestination].waterLevel);
                    // La CONSTRUCTION devient completement ALIMENTEE en EAU
                    monJeu.element[indexDestination].isWatered = true;
                    // On reneigne le tabFournitureRessources de la CONSTRUCTION en cours
                    monJeu.element[indexDestination].tabFournitureRessources[indexChateauCourant] = (monJeu.element[indexDestination].nbHabitantElement-monJeu.element[indexDestination].waterLevel);
                    monJeu.element[indexDestination].waterLevel = monJeu.element[indexDestination].nbHabitantElement;
                    if(TRACE)printf ("CONSTRUCTION n°%02d (%3d ha) alimentée en eau à %3d/%3d par Chateau n°%2d (capa restante %3d sur château %2d)\n",
                            indexDestination, monJeu.element[indexDestination].nbHabitantElement,
                            monJeu.element[indexDestination].tabFournitureRessources[indexChateauCourant],
                            monJeu.element[indexDestination].nbHabitantElement, indexChateauCourant,
                            monJeu.element[indexChateauCourant].capacite, indexChateauCourant);
                }
                else {
                    // Dans ce cas, la capacité restante n'est pas suffisante pour alimenter complètement la CONSTRUCTION
                    // Le CHATEAU va alimenter partiellement cette CONSTRUCTION
                    monJeu.element[indexDestination].isWatered = false;
                    monJeu.element[indexDestination].waterLevel += monJeu.element[indexChateauCourant].capacite;
                    // On reneigne le tabFournitureRessources de la CONSTRUCTION en cours
                    monJeu.element[indexDestination].tabFournitureRessources[indexChateauCourant] = monJeu.element[indexChateauCourant].capacite;
                    // Il va fournir tout le reste de son eau à cette CONSTRUCTION
                    monJeu.element[indexChateauCourant].capacite = 0;
                    if(TRACE)printf ("CONSTRUCTION n°%02d (%3d ha) alimentée en eau à %3d/%3d par Chateau n°%2d (capa restante %3d sur château %2d)\n",
                            indexDestination, monJeu.element[indexDestination].nbHabitantElement,
                            monJeu.element[indexDestination].tabFournitureRessources[indexChateauCourant],
                            monJeu.element[indexDestination].nbHabitantElement, indexChateauCourant,
                            monJeu.element[indexChateauCourant].capacite, indexChateauCourant);
                }
            }
        }
    }
}

void detecteConstructionsAlimenteesParCentrale(){
    // Une CONSTRUCTION peut etre raccordée à une CENTRALE mais non ALIMENTée si la CENTRALE alimente déjà 5000 personnes
    // On va parcourir chacune des CENTRALES
    // Pour chaque CENTRALE on va regarder les CONSTRUCTIONS connectées en partant du plus PROCHE et définir lesquelles
    // sont alimentées
    int indexCentraleCourante = -1;
    int indexDestination = -1;
    for (int i=0; i<monJeu.nbParcoursCentrale; i++){
        // On vérifie si on traite toujours la même CENTRALE
        if (indexCentraleCourante != monJeu.tabParcoursCentrale[i].source){
            //monJeu.element[i].capacite = CAPA_CENTRALE;
            indexCentraleCourante = monJeu.tabParcoursCentrale[i].source;
        }
        // Si pour cette CENTRALE la capacite restante est NULLE on passe le tour
        if (monJeu.element[indexCentraleCourante].capacite == 0) continue;
        // On GET la DEST pour savoir si c'est une CONSTRUCTION
        indexDestination = monJeu.tabParcoursCentrale[i].destination;
        // On vérifie s'il s'agit d'une CONSTRUCTION
        if (monJeu.element[indexDestination].type == CONSTRUCTION && !monJeu.element[indexDestination].isPowered){
            if (monJeu.element[indexCentraleCourante].capacite >= monJeu.element[indexDestination].nbHabitantElement){
                monJeu.element[indexDestination].isPowered = true;
                // On reneigne le tabFournitureRessources de la CONSTRUCTION en cours
                monJeu.element[indexDestination].tabFournitureRessources[indexCentraleCourante] = monJeu.element[indexCentraleCourante].capacite;
                monJeu.element[indexCentraleCourante].capacite -= monJeu.element[indexDestination].nbHabitantElement;
                if(TRACE)printf ("CONSTRUCTION n°%02d (%3d ha) alimentée électriquement (capa restante %3d sur Centrale %2d)\n",
                        indexDestination, monJeu.element[indexDestination].nbHabitantElement,
                        monJeu.element[indexCentraleCourante].capacite, indexCentraleCourante);
            }
        }
    }
}

void classeParcoursConstruction(){
    InfoParcours tabTemp[MAX_PARCOURS_CONSTRUCTION];
    int nbParcoursTabTemp = 0;
    // On va boucler dans que la lg du PARCOURS est inférieure à LG_MAX_PARCOURS et ranger par LG croissantes dans le tableau temporaire
    for (int lg=0;lg<LG_MAX_PARCOURS;lg++){
        for (int index=0; index<monJeu.nbParcoursConstruction;index++){
            if (lg == monJeu.tabParcoursConstruction[index].lgParcours) {
                tabTemp[nbParcoursTabTemp].source = monJeu.tabParcoursConstruction[index].source;
                tabTemp[nbParcoursTabTemp].indexParcours = monJeu.tabParcoursConstruction[index].indexParcours;
                tabTemp[nbParcoursTabTemp].lgParcours = monJeu.tabParcoursConstruction[index].lgParcours;
                tabTemp[nbParcoursTabTemp].estPlusCourt = monJeu.tabParcoursConstruction[index].estPlusCourt;
                tabTemp[nbParcoursTabTemp].destination = monJeu.tabParcoursConstruction[index].destination;
                nbParcoursTabTemp++;
            }
        }
    }
    // On vérifie que l'on a bien le meme nb d'elts et on recopie le tableau temp dans tabParcoursConstruction
    if (nbParcoursTabTemp == monJeu.nbParcoursConstruction) {
        for (int i=0; i<monJeu.nbParcoursConstruction;i++){
            monJeu.tabParcoursConstruction[i].source = tabTemp[i].source;
            monJeu.tabParcoursConstruction[i].destination = tabTemp[i].destination;
            monJeu.tabParcoursConstruction[i].indexParcours = tabTemp[i].indexParcours;
            monJeu.tabParcoursConstruction[i].lgParcours = tabTemp[i].lgParcours;
            monJeu.tabParcoursConstruction[i].estPlusCourt = tabTemp[i].estPlusCourt;
        }
    }
    else {
        if(TRACE)printf ("CLASSEMENT : ERREUR\n");
    }
}

void classeParcoursCentrale(){
    InfoParcours tabTemp[MAX_PARCOURS_CENTRALE];
    int nbParcoursTabTemp = 0;
    // On va boucler dans que la lg du PARCOURS est inférieure à LG_MAX_PARCOURS et ranger par LG croissantes dans le tableau temporaire
    for (int lg=0;lg<LG_MAX_PARCOURS;lg++){
        for (int index=0; index<monJeu.nbParcoursCentrale;index++){
            if (lg == monJeu.tabParcoursCentrale[index].lgParcours) {
                tabTemp[nbParcoursTabTemp].source = monJeu.tabParcoursCentrale[index].source;
                tabTemp[nbParcoursTabTemp].indexParcours = monJeu.tabParcoursCentrale[index].indexParcours;
                tabTemp[nbParcoursTabTemp].lgParcours = monJeu.tabParcoursCentrale[index].lgParcours;
                tabTemp[nbParcoursTabTemp].estPlusCourt = monJeu.tabParcoursCentrale[index].estPlusCourt;
                tabTemp[nbParcoursTabTemp].destination = monJeu.tabParcoursCentrale[index].destination;
                nbParcoursTabTemp++;
            }
        }
    }
    // On vérifie que l'on a bien le meme nb d'elts et on recopie le tableau temp dans tabParcoursCentrale
    if (nbParcoursTabTemp == monJeu.nbParcoursCentrale) {
        for (int i=0; i<monJeu.nbParcoursCentrale;i++){
            monJeu.tabParcoursCentrale[i].source = tabTemp[i].source;
            monJeu.tabParcoursCentrale[i].destination = tabTemp[i].destination;
            monJeu.tabParcoursCentrale[i].indexParcours = tabTemp[i].indexParcours;
            monJeu.tabParcoursCentrale[i].lgParcours = tabTemp[i].lgParcours;
            monJeu.tabParcoursCentrale[i].estPlusCourt = tabTemp[i].estPlusCourt;
        }
    }
    else {
        if(TRACE)printf ("CLASSEMENT : ERREUR\n");
    }
}

void classeParcoursChateau(){
    InfoParcours tabTemp[MAX_PARCOURS_CHATEAU];
    int nbParcoursTabTemp = 0;
    // On va boucler dans que la lg du PARCOURS est inférieure à LG_MAX_PARCOURS et ranger par LG croissantes dans le tableau temporaire
    for (int lg=0;lg<LG_MAX_PARCOURS;lg++){
        for (int index=0; index<monJeu.nbParcoursChateau;index++){
            if (lg == monJeu.tabParcoursChateau[index].lgParcours) {
                tabTemp[nbParcoursTabTemp].source = monJeu.tabParcoursChateau[index].source;
                tabTemp[nbParcoursTabTemp].indexParcours = monJeu.tabParcoursChateau[index].indexParcours;
                tabTemp[nbParcoursTabTemp].lgParcours = monJeu.tabParcoursChateau[index].lgParcours;
                tabTemp[nbParcoursTabTemp].estPlusCourt = monJeu.tabParcoursChateau[index].estPlusCourt;
                tabTemp[nbParcoursTabTemp].destination = monJeu.tabParcoursChateau[index].destination;
                nbParcoursTabTemp++;
            }
        }
    }
    // On vérifie que l'on a bien le meme nb d'elts et on recopie le tableau temp dans tabParcoursChateau
    if (nbParcoursTabTemp == monJeu.nbParcoursChateau) {
        for (int i=0; i<monJeu.nbParcoursChateau;i++){
            monJeu.tabParcoursChateau[i].source = tabTemp[i].source;
            monJeu.tabParcoursChateau[i].destination = tabTemp[i].destination;
            monJeu.tabParcoursChateau[i].indexParcours = tabTemp[i].indexParcours;
            monJeu.tabParcoursChateau[i].lgParcours = tabTemp[i].lgParcours;
            monJeu.tabParcoursChateau[i].estPlusCourt = tabTemp[i].estPlusCourt;
        }
    }
    else {
        if(TRACE)printf ("CLASSEMENT : ERREUR\n");
    }
}

void jeu(){
    if(TRACE)printf("Mode jeu : 1 - communiste 2 - capitaliste\n");
    scanf("%d", monJeu.modeJeu);
    //position premier élement
    //faire tourner tout le code à chaque fois qu'on rajoute un nouvel élement

}



///////////////////////// FIN JEU.C ////////////////////

///////////////////////// MAIN ////////////////////

int main() {
    initialisationJeu();
    if(TRACE)printf("DEBUT\n");

    test();

    //ChangerNiveauConstruction(0, 1);
    for(int i = 0; i<monJeu.nbElements;i++){
        if(monJeu.element[i].actif == ACTIF){
            detectionElementsConnectes(i, monJeu.element[i].affichageElement.largeurX,monJeu.element[i].affichageElement.largeurY);
        }
        //afficherEltConnectes(i);
    }
    int distance = 0;
    int *tabCheminParcouru = calloc (MAX_CONSTRUCTION, sizeof(int));
    int *route = calloc(MAX_CONSTRUCTION, sizeof(int));

    // BOUCLE PRINCIPALE : ON PARCOURT TOUS LES ELT DU JEU, SI CE NE SONT PAS DES ROUTES, ON REGARDE TOUS LES PARCOURS VERS LES AUTRES ELTS
    for(int i = 0; i<monJeu.nbElements;i++){
        if(monJeu.element[i].actif == ACTIF && monJeu.element[i].type != ROUTE){
            // On initialise le tabCheminParcouru pour éviter de boucler et route pour mémoriser les routes empruntées
            for (int j=0; j<MAX_CONSTRUCTION;j++){
                tabCheminParcouru[j]=-1; // on le met à zéro quand on passe dessus
                route[j]=-1;
            }
            tabCheminParcouru[i]=0;

            // On initialise les tabCheminDeConnexionsAuxInfra
            for (int p=0; p<MAX_CONSTRUCTION; p++){
                for (int q=0; q<MAX_CONSTRUCTION;q++){
                    //monJeu.element[i].tabCheminDeConnexionsAuxInfra[p][q]=-1;
                }
            }

            // Lors du premier appel, la route courante est la source
            //route[distance]=i;
            calculeDistanceAvecLesInfraConnectees(i, i, &distance, tabCheminParcouru, route);
        }
        afficherTabDistanceInfraConnectees(i);
    }
    // Affichage des PARCOURS
    afficheTabParcoursConstruction();
    afficheTabParcoursChateau();
    afficheTabParcoursCentrale();
    // Détection des CONSTRUCTIONS alimentées par CENTRALE
    ChangerNiveauConstruction(0, 1);
    ChangerNiveauConstruction(0, 1);
    ChangerNiveauConstruction(0, 1);
    ChangerNiveauConstruction(0, 1);
    ChangerNiveauConstruction(0, 1);
    ChangerNiveauConstruction(38, 1);
    ChangerNiveauConstruction(38, 1);
    ChangerNiveauConstruction(38, 1);
    ChangerNiveauConstruction(38, 1);
    ChangerNiveauConstruction(38, 1);
    ChangerNiveauConstruction(23, 1);
    ChangerNiveauConstruction(23, 1);
    ChangerNiveauConstruction(23, 1);
    ChangerNiveauConstruction(23, 1);
    ChangerNiveauConstruction(23, 1);
    //ChangerNiveauConstructioute[distance]=i;
    //calculeDistanceAvecLesInfraConnectees(i, i, &distance, tabCheminParcouru, route);


/*
// Affichage des PARCOURS
afficheTabParcoursConstruction();
afficheTabParcoursChateau();
afficheTabParcoursCentrale();
// Détection des CONSTRUCTIONS alimentées par CENTRALE
ChangerNiveauConstruction(0, 1);
ChangerNiveauConstruction(0, 1);
ChangerNiveauConstruction(0, 1);
ChangerNiveauConstruction(0, 1);
ChangerNiveauConstruction(0, 1);
ChangerNiveauConstruction(38, 1);
ChangerNiveauConstruction(38, 1);
ChangerNiveauConstruction(38, 1);
ChangerNiveauConstruction(38, 1);
ChangerNiveauConstruction(38, 1);
 */


// On classe le tableau des CENTRALES

    classeParcoursCentrale();
    classeParcoursChateau();
    classeParcoursConstruction();
    afficheTabParcoursConstruction();
    afficheTabParcoursChateau();
    afficheTabParcoursCentrale();


//detecte toutes les constructions alimentees par toutes les centrales et indique les capacités restantes des centrales
//detecteConstructionsAlimenteesParCentrale();
detecteConstructionAlimenteesparChateau();
//    ChangerNiveauConstruction(0, 1);
if(TRACE)printf ("detecte centrale\n");
//detecteConstructionsAlimenteesParCentrale();
// Détection des maisons VIABLES
// Pour l'instant detecte que ceux qui sont connectés mais pas alimentées
detecteConstructionsViables();
// Libération
//ChangerNiveauConstruction(0, 1);
if(TRACE)printf("niveau edu de l'école : %d\n", monJeu.element[0].niveauEduElement);
if(TRACE)printf("niveau global d'édu de la ville : %d\n", monJeu.niveauEducation);
free (tabCheminParcouru);
free (route);
carte();
return 0;
}

///////////////////////// FIN MAIN ////////////////////
