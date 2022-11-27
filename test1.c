#include <stdio.h>
#include "stdlib.h"
#include "jeu.h"
#include <allegro5/allegro_acodec.h>
#include "time.h"
#define TRACE 0
#define LARGEUR 2880
#define HAUTEUR 1694
#define ECRAN_LONGUEUR 2880
#define ECRAN_LARGEUR 1694
#define OR2 al_map_rgb(255,235,20)
//#define JAUNE al_map_rgba(218,223,56, 2)
#define JAUNE al_map_rgba(156,148,73, 2)
#define BLANC al_map_rgb(255,255,255)
#define BLEU al_map_rgba(0, 123, 255, 2)
//#define BLEU al_map_rgba(56, 196, 223, 2)
#define ROUGE al_map_rgba(248, 96, 96, 2)

#define NOIR al_map_rgb(0,0,0)

///////////////////////// AFFICHAGE.C ////////////////////
void initSonConstruction(Son son){
    al_init_acodec_addon();
    al_reserve_samples(4);
    son.sonConstructionRoute = al_load_sample("../Son_sonConstructionRoute.ogg");
    son.sonConstructionCentrale = al_load_sample("../Son_sonConstructionCentrale.ogg");
    son.sonConstructionChateauEau = al_load_sample("../Son_sonConstructionChateau.ogg");
    son.sonConstructionMaison = al_load_sample("../Son_sonConstructionMaison.ogg");
    //if (!son.sonConstructionRoute )
}
void sonConstruction(Son son, int typeSon){
    if(typeSon == 1){
        al_play_sample(son.sonConstructionRoute, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
    if(typeSon == 2){
        al_play_sample(son.sonConstructionChateauEau, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
    if(typeSon == 3){
        al_play_sample(son.sonConstructionMaison, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
    if(typeSon == 4){
        al_play_sample(son.sonConstructionCentrale, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
}

void ecrireFichierTextePourSauvegarderFichierTexte(char *nomFichier){
    FILE *ifs = fopen(nomFichier, "w+");
    int tailleFichier = 0;
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
    }
    for(int i = 0; i< 45 ; i++){
        for(int j = 0; j< 45;j++){
            if(monJeu.tabTXT[i][j] != 0){
                fprintf(ifs, "%d",monJeu.tabTXT[i][j]);
            }
                /*if(monJeu.tabTXT[i][j] == ROUTE ){
                    fprintf(ifs, "%d",ROUTE);
                }
                else if(monJeu.tabTXT[i][j] == CONSTRUCTION ){
                    fprintf(ifs, "%d",CONSTRUCTION);
                }
                else if(monJeu.tabTXT[i][j] == CENTRALE ){
                    fprintf(ifs, "%d",CENTRALE);
                }
                else if(monJeu.tabTXT[i][j] == ECOLE ){
                    fprintf(ifs, "%d",ECOLE);
                }
                else if(monJeu.tabTXT[i][j] == MUSEE ){
                    fprintf(ifs, "%d",MUSEE);
                }
                else if(monJeu.tabTXT[i][j] == CHATEAU ){
                    fprintf(ifs, "%d",CHATEAU);
                }*/
            else{
                fprintf(ifs, "%d",0);
            }
            if(j == 44){
                fprintf(ifs, "\n");
            }
        }
    }
    fclose(ifs);
    //pour ajouter un seul nouvel element à la fois dans le fichier texte
}

void musiqueFond(){
    al_install_audio();

    al_init_acodec_addon();
    al_reserve_samples(1);
    ALLEGRO_SAMPLE *son1 = al_load_sample("../son1.ogg");
    al_play_sample(son1, 0.2, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void surpassageCase (int xSouris, int ySouris){
    //centrale passage souris
    int x1 = 2505;
    int y1 = 276;
    int x2 = x1+130;
    int y2 = y1 + 135;
    int x1Chateau = 2669;
    int y1Chateau = 276;
    int x2Chateau = x1Chateau+130;
    int y2Chateau = y1Chateau + 135;
    int x1Route = 2669;
    int y1Route = 437;
    int x2Route = x1Route+130;
    int y2Route = y1Route + 135;

    int x1Constru= 2508;
    int y1Constru = 437;
    int x2Constru = x1Constru+130;
    int y2Constru= y1Constru + 135;


    if(xSouris >= x1 && xSouris <= x2){
        if(ySouris >= y1 && ySouris <= y2){
            al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgba(20,20, 20,150));
            al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(247, 206, 23), 3);
        }

    }
    if(xSouris >= x1 && xSouris <= x2){
        if(ySouris >= y1Constru && ySouris <= y2Constru){
            al_draw_filled_rectangle(x1Constru, y1Constru, x2Constru, y2Constru, al_map_rgba(20,20, 20,150));
            al_draw_rectangle(x1Constru, y1Constru, x2Constru, y2Constru, al_map_rgb(247, 206, 23), 3);
        }

    }
    if(xSouris >= x1Chateau && xSouris <= x2Chateau){
        if(ySouris >= y1Chateau && ySouris <= y2Chateau){
            al_draw_filled_rectangle(x1Chateau, y1Chateau, x2Chateau, y2Chateau, al_map_rgba(20,20,20,150));
            al_draw_rectangle(x1Chateau, y1Chateau, x2Chateau, y2Chateau, al_map_rgb(247, 206, 23), 3);
        }

    }
    if(xSouris >= x1Route && xSouris <= x2Route){
        if(ySouris >= y1Route && ySouris <= y2Route){
            al_draw_filled_rectangle(x1Route, y1Route, x2Route, y2Route, al_map_rgba(20,20,20,150));
            al_draw_rectangle(x1Route, y1Route, x2Route, y2Route, al_map_rgb(247, 206, 23), 3);
        }

    }
    if(xSouris >= 2510 && xSouris <= 2632){
        if(ySouris >= 961 && ySouris <= 1083){
            al_draw_filled_rectangle(2508, 956, 2633, 1081, al_map_rgba(20,20,20,150));
            al_draw_rectangle(2508, 956, 2633, 1081, al_map_rgb(247, 206, 23), 3);
        }

    }
    /*
    if(xSouris >= 2510 && xSouris <= 2632){
        if(ySouris >= 961 && ySouris <= 1083){
            return ECOLE;
        }

    }
    if(xSouris >= 2673 && xSouris <= 2795){
        if(ySouris >= 957 && ySouris <= 1084){
            return MUSEE;
        }

    }
    if(xSouris >= 2510 && xSouris <= 2633){
        if(ySouris >= 1118 && ySouris <= 1240){
            return CASERNE;
        }

    }
     */

}

void affichageMenuGraphique(Image image, int xSouris, int ySouris){


    //al_draw_bitmap(image.fond, 0, 0, 0);
    al_draw_filled_rectangle(0, 0, 100, 100, al_map_rgba(20, 20, 20, 130));
    //al_clear_to_color(al_map_rgba(20, 20, 20, 200));
    al_draw_bitmap(image.menu, 800, 300, 0);
    //al_draw_filled_rectangle(0, 400, 0, 400, BLANC);
    al_flip_display();
}

// Renvoie le type de CASE dans lequel on a cliqué (CENTRALE, CHATEAU, ... PAUSE)
int clicDansCase (int xSouris, int ySouris, Image image, ALLEGRO_EVENT event, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE* queue){//ça ça marche
    //centrale passage souris
    int x1 = 2505;
    int y1 = 276;
    int x2 = x1+130;
    int y2 = y1 + 135;
    int x1Route = 2669;
    int y1Route = 437;
    int x2Route = x1Route+130;
    int y2Route = y1Route + 135;
    int x1Constru= 2508;
    int y1Constru = 437;
    int x2Constru = x1Constru+130;
    int y2Constru= y1Constru + 135;
    int x1Chateau = 2669;
    int y1Chateau = 276;
    int x2Chateau = x1Chateau+130;
    int y2Chateau = y1Chateau + 135;
    bool endMenu = false;

    // On vérifie si on se trouve sur une des FONCTIONS d'AJOUT d'ELT
    if(xSouris >= x1 && xSouris<= x2){
        if(ySouris >= y1 && ySouris <= y2){ //si souris dedans on return
            return CENTRALE;
            //printf("centrale");
        }
    }
    if(xSouris >= x1 && xSouris <= x2){
        if(ySouris >= y1Constru && ySouris <= y2Constru){
            return CONSTRUCTION;
        }
    }
    if(xSouris >= x1Chateau && xSouris <= x2Chateau){
        if(ySouris >= y1Chateau && ySouris <= y2Chateau){
            return CHATEAU;

        }
    }
    if(xSouris >= x1Route && xSouris <= x2Route){
        if(ySouris >= y1Route && ySouris <= y2Route){
            return ROUTE;
        }

    }
    if(xSouris >= 2510 && xSouris <= 2632){
        if(ySouris >= 961 && ySouris <= 1083){
            return ECOLE;
        }

    }
    if(xSouris >= 2673 && xSouris <= 2795){
        if(ySouris >= 957 && ySouris <= 1084){
            return MUSEE;
        }

    }
    if(xSouris >= 2510 && xSouris <= 2633){
        if(ySouris >= 1118 && ySouris <= 1240){
            return CASERNE;
        }

    }
    // On vérifie si on est sur le MENU PAUSE
    if((xSouris >= x1Route-75 && xSouris <= x2Route-85) || (xSouris >= 42 && xSouris <= 168) ){
        if((ySouris >= y1Route+165 && ySouris <= y2Route+155) || (ySouris >= 32 && ySouris <= 172)){
            return 999;
            //al_draw_filled_rectangle(x1Route-75, y1Route+165, x2Route-85, y2Route+155, al_map_rgba(20,20,20,150));
            while(!endMenu){
                al_wait_for_event(queue,&event);
                al_draw_bitmap(image.menu, 800, 300, 0);
                switch (event.type) {
                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        endMenu = true;
                        break;

                    case ALLEGRO_EVENT_MOUSE_AXES:
                        xSouris = event.mouse.x;
                        ySouris = event.mouse.y;
                        break;

                    case ALLEGRO_EVENT_TIMER:
                        abort();
                        affichageMenuGraphique(image, xSouris, ySouris);
                        break;

                    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                        if(xSouris >= 300 && xSouris <= 400){
                            if(ySouris >= 300 && ySouris <= 400){
                                endMenu = true;
                            }
                        }
                        //centrale passage souris
                        if(TRACE)printf("centrale\n");
                        break;
                }
                al_flip_display();
            }
        }
    }

    // On verifie si on est sur la fonction AFFICHAGE RESEAU EAU
    if(xSouris >= 2495 && xSouris <= 2817) {
        if (ySouris >= 780 && ySouris <= 825) {
            if (AFFICHAGE_RESEAU_EAU == monJeu.modeBoucle) {
                monJeu.modeBoucle = STANDARD;
                return -1;
            }
            monJeu.modeBoucle = AFFICHAGE_RESEAU_EAU;
            //actualiseReseauxEaux();
            //afficheStatutDesRessourcesParConstruction ();
            /*
            for(int i = 0; i<monJeu.nbElements ; i++){
                if(monJeu.element[i].type == ROUTE){
                    al_draw_filled_rectangle(monJeu.element[i].affichageElement.positionX, monJeu.element[i].affichageElement.positionY, monJeu.element[i].affichageElement.positionX + monJeu.element[i].affichageElement.largeurX, monJeu.element[i].affichageElement.positionY + monJeu.element[i].affichageElement.largeurY, BLANC);
                }
            }*/
        }
    }
    // On verifie si on est sur la fonction AFFICHAGE RESEAU ELEC
    if(xSouris >= 2521 && xSouris <= 2807) {
        if (ySouris >= 867 && ySouris <= 906) {
            if (AFFICHAGE_RESEAU_ELEC == monJeu.modeBoucle) {
                monJeu.modeBoucle = STANDARD;
                return -1;
            }
            monJeu.modeBoucle = AFFICHAGE_RESEAU_ELEC;
        }
    }
    return (-1);
}

//imaginons on return centrale avec clicDansCase
//on lui passe clicDansCase (int clicDansCase, xSouris, y Souris), en ligneSouris, colonnes souris, calculées juste avant
int ajouterElementGraphique(int typeconstruction, int ligneSouris, int coloneSouris){
    ajouterElement(typeconstruction, ligneSouris, coloneSouris);
}


//#include "affichage.h"
//#define ECE_CITY_1_H_AFFICHAGE_H

void dessinerFilledRectangle2(float x, float y, float largeur, float hauteur, ALLEGRO_COLOR color){
    al_draw_filled_rectangle(x, y, x+largeur, y+hauteur, color);
}


void affichageInterfaceJeu(){
    ALLEGRO_BITMAP *interfaceModeJeu = al_load_bitmap("../images/interfaceJeu.png");
    al_draw_bitmap(interfaceModeJeu, 0, 0, 0);
    al_flip_display();


}

void affichageChargementCapitaliste(){
    ALLEGRO_BITMAP *ecranChargementCapitaliste = al_load_bitmap("../images/modeCapitaliste.png");

    al_draw_bitmap(ecranChargementCapitaliste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 50, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargementCapitaliste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 400, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargementCapitaliste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 1000, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargementCapitaliste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 2300, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargementCapitaliste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, LARGEUR-160, 60, OR2);
    al_flip_display();
    sleep(1);
}


void affichageChargementCommuniste(){
    ALLEGRO_BITMAP *ecranChargementCommuniste = al_load_bitmap("../images/modeCommuniste.png");

    al_draw_bitmap(ecranChargementCommuniste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 50, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargementCommuniste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 400, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargementCommuniste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 1000, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargementCommuniste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, 2300, 60, OR2);
    al_flip_display();
    sleep(1);
    al_draw_bitmap(ecranChargementCommuniste, 0, 0, 0);
    dessinerFilledRectangle2(70, HAUTEUR-150, LARGEUR-160, 60, OR2);
    al_flip_display();
    sleep(1);
}

int displaycount = 0;

void affichage(Case tabCase[LIGNES_TAB][COLONNES_TAB],int tabTXT[LIGNES_TAB][COLONNES_TAB + 1],Image image,int ligneSouris,int colonneSouris, int xSouris, int ySouris, ALLEGRO_FONT* argent, int construction, int centrale, int route, int chateau, int returnClic, ALLEGRO_FONT* reseauEau, int conteur) {
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
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,tabCase[i][j].x+TAILLE_CASE,tabCase[i][j].y+TAILLE_CASE,
                                         al_map_rgb(0,0,0));
                //al_draw_scaled_bitmap(image.routegd,0,0,118,118,tabCase[i][j].x,tabCase[i][j].y,TAILLE_CASE,TAILLE_CASE,0);
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

            //CHATEAU D'EAU :
            if (tabTXT[i][j] == 7) {
                /*
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,

                                         tabCase[i][j].x+4*TAILLE_CASE,tabCase[i][j].y+6*TAILLE_CASE,
                                         al_map_rgba(0,70,255,200));*/
                al_draw_scaled_bitmap(image.chateaudeau,0,0,237,354,tabCase[i][j].x,tabCase[i][j].y,4*TAILLE_CASE,6*TAILLE_CASE,0);

            }

            //CENTRALE ELECTRIQUE :
            if (tabTXT[i][j] == 8) {
                /*
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+4*TAILLE_CASE,tabCase[i][j].y+6*TAILLE_CASE,
                                         al_map_rgba(189,255,0,200));*/
                al_draw_scaled_bitmap(image.centraleelec,0,0,237,354,tabCase[i][j].x,tabCase[i][j].y,4*TAILLE_CASE,6*TAILLE_CASE,0);
            }
            //TERRAIN VAGUE :
            if (tabTXT[i][j] == 9) {
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));
                al_draw_scaled_bitmap(image.terrainVague,0,0,177,177,tabCase[i][j].x,tabCase[i][j].y,3*TAILLE_CASE,3*TAILLE_CASE,0);

            }

            //CABANE :
            if (tabTXT[i][j] == 10) {
                /*
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));*/
                al_draw_scaled_bitmap(image.cabane,0,0,168,177,tabCase[i][j].x,tabCase[i][j].y,3*TAILLE_CASE,3*TAILLE_CASE,0);

            }

            //MAISON :
            if (tabTXT[i][j] == 11) {
                /*
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));*/
                al_draw_scaled_bitmap(image.maison1,0,0,177,181,tabCase[i][j].x,tabCase[i][j].y,3*TAILLE_CASE,3*TAILLE_CASE,0);

            }

            //IMMEUBLE :
            if (tabTXT[i][j] == 12) {
                /*
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));*/
                al_draw_scaled_bitmap(image.immeuble,0,0,133,195,tabCase[i][j].x,tabCase[i][j].y - TAILLE_CASE,3*TAILLE_CASE,4*TAILLE_CASE,0);

            }

            //GRATTE_CIEL :
            if (tabTXT[i][j] == 13) {
                /*
                    al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));*/
                    al_draw_scaled_bitmap(image.gc1,0,0,118,237,tabCase[i][j].x,tabCase[i][j].y - 3 * TAILLE_CASE,3*TAILLE_CASE,6*TAILLE_CASE,0);
            }

        }
    }
    // Maintenant que l'on a parcouru toute la grille pour refaire l'affichage graphique
    // Nous allons parcourir les ELEMENTS pour afficher le LABEL correspondant au mode d'affichage en cours
    if (AFFICHAGE_RESEAU_EAU == monJeu.modeBoucle) {
        al_draw_filled_rectangle(0, 0, 2880, 1694, al_map_rgba(20, 20, 20, 200));
        // Maintenant on va parcourir tous les PARCOURS ACTIFS issus des CHATEAUX d'EAU pour les afficher en bleu
        for (int i = 0; i < MAX_PARCOURS_CHATEAU; i++) {
            if (monJeu.tabParcoursChateau[i].actif) {
                if (TRACE) printf("Parcours %d ACTIF : ", i);
                //al_draw_filled_rectangle(monJeu.element[i].affichageElement.positionX, monJeu.element[i].affichageElement.positionY, monJeu.element[i].affichageElement.positionX+monJeu.element[i].affichageElement.largeurX, monJeu.element[i].affichageElement.positionY + monJeu.element[i].affichageElement.largeurY, BLANC);
                //afficheParcours(monJeu.tabParcoursChateau[i].indexParcours, monJeu.tabParcoursChateau[i].lgParcours);
                int lg = monJeu.tabParcoursChateau[i].lgParcours;
                int indexParcours = monJeu.tabParcoursChateau[i].indexParcours;
                int indexEltJeu;
                int ligneSouris, colonneSouris;
                for(int j=1; j<lg-1; j++){
                    indexEltJeu = monJeu.tabParcours[indexParcours][j];
                    if (ROUTE != monJeu.element[indexEltJeu].type) {
                        printf ("ERREUR dans affichage : %dème ELT  %d pas une ROUTE mais %d (PARCOUR %d)\n", j,
                                indexEltJeu, monJeu.element[indexEltJeu].type, indexParcours);
                        afficheParcours(indexParcours, -1);
                        afficheStatutDesRessourcesParConstruction();
                        afficheTousParcours();
                        afficheTabParcoursChateau();
                        afficheTabParcoursCentrale();
                        abort();
                        return;
                    }/*
                    printf("affichage case bleu %d , %d , %d , %d", monJeu.element[indexEltJeu].affichageElement.positionX, monJeu.element[indexEltJeu].affichageElement.positionY,
                         monJeu.element[indexEltJeu].affichageElement.positionX+monJeu.element[indexEltJeu].affichageElement.largeurX*TAILLE_CASE,
                         monJeu.element[indexEltJeu].affichageElement.positionY+monJeu.element[indexEltJeu].affichageElement.largeurY*TAILLE_CASE);
                    */
                    ligneSouris = monJeu.element[indexEltJeu].affichageElement.positionY;
                    colonneSouris = monJeu.element[indexEltJeu].affichageElement.positionX;
                    al_draw_filled_rectangle(tabCase[ligneSouris][colonneSouris].x, tabCase[ligneSouris][colonneSouris].y,
                                             tabCase[ligneSouris][colonneSouris].x + monJeu.element[indexEltJeu].affichageElement.largeurX*TAILLE_CASE,
                                             tabCase[ligneSouris][colonneSouris].y + monJeu.element[indexEltJeu].affichageElement.largeurY*TAILLE_CASE, BLEU);
                }

            }
        }
        int i,j;
        char ptr[LG_LABEL];
        ALLEGRO_COLOR couleur = BLANC;
        for (int k=0; k<monJeu.nbElements; k++) {
            i = monJeu.element[k].affichageElement.positionY;
            j = monJeu.element[k].affichageElement.positionX;
            if (monJeu.element[k].type == CONSTRUCTION){
                // On est dans la BOUCLE ALLEGRO
                // On est dans le MODEBOUCLE = AFFICHAGE_RESEAU_EAU
                // On ne veut pas afficher le bitmpa mais le label d'état d'alimentation de la CONSTRUCTION en eau
                if (!monJeu.element[k].isWatered) couleur = ROUGE;
                else couleur = BLANC;
                if (monJeu.element[k].labelAlimentationEau) al_draw_text(reseauEau, couleur, tabCase[i][j].x, tabCase[i][j].y, 0, monJeu.element[k].labelAlimentationEau);
            }
            else if (monJeu.element[k].type == CHATEAU){
                if (!monJeu.element[k].capacite) couleur = ROUGE;
                else couleur = BLANC;
                sprintf(ptr, "CHATEAU#%02d (reste %03d/%03d)", k, monJeu.element[k].capacite, CAPA_CHATEAU);
                al_draw_text(reseauEau, couleur, tabCase[i][j].x, tabCase[i][j].y, 0, ptr);
            }
        }
    }
    if (AFFICHAGE_RESEAU_ELEC == monJeu.modeBoucle) {
        al_draw_filled_rectangle(0, 0, 2880, 1694, al_map_rgba(20, 20, 20, 200));
        // Maintenant on va parcourir tous les PARCOURS ACTIFS issus des CENTRALE pour les afficher en jaune
        for (int i = 0; i < MAX_PARCOURS_CENTRALE; i++) {
            if (monJeu.tabParcoursCentrale[i].actif) {
                if (TRACE) printf("Parcours %d ACTIF : ", i);
                //al_draw_filled_rectangle(monJeu.element[i].affichageElement.positionX, monJeu.element[i].affichageElement.positionY, monJeu.element[i].affichageElement.positionX+monJeu.element[i].affichageElement.largeurX, monJeu.element[i].affichageElement.positionY + monJeu.element[i].affichageElement.largeurY, BLANC);
                //afficheParcours(monJeu.tabParcoursChateau[i].indexParcours, monJeu.tabParcoursChateau[i].lgParcours);
                int lg = monJeu.tabParcoursCentrale[i].lgParcours;
                int indexParcours = monJeu.tabParcoursCentrale[i].indexParcours;
                int indexEltJeu;
                int ligneSouris, colonneSouris;
                for(int j=1; j<lg-1; j++){
                    indexEltJeu = monJeu.tabParcours[indexParcours][j];
                    if (ROUTE != monJeu.element[indexEltJeu].type) {
                        printf ("ERREUR dans affichage 2\n");
                        return;
                    }/*
                    printf("affichage case bleu %d , %d , %d , %d", monJeu.element[indexEltJeu].affichageElement.positionX, monJeu.element[indexEltJeu].affichageElement.positionY,
                         monJeu.element[indexEltJeu].affichageElement.positionX+monJeu.element[indexEltJeu].affichageElement.largeurX*TAILLE_CASE,
                         monJeu.element[indexEltJeu].affichageElement.positionY+monJeu.element[indexEltJeu].affichageElement.largeurY*TAILLE_CASE);
                    */
                    ligneSouris = monJeu.element[indexEltJeu].affichageElement.positionY;
                    colonneSouris = monJeu.element[indexEltJeu].affichageElement.positionX;
                    al_draw_filled_rectangle(tabCase[ligneSouris][colonneSouris].x, tabCase[ligneSouris][colonneSouris].y,
                                             tabCase[ligneSouris][colonneSouris].x + monJeu.element[indexEltJeu].affichageElement.largeurX*TAILLE_CASE,
                                             tabCase[ligneSouris][colonneSouris].y + monJeu.element[indexEltJeu].affichageElement.largeurY*TAILLE_CASE, JAUNE);
                }

            }
        }
        int i,j;
        char ptr[LG_LABEL];
        ALLEGRO_COLOR couleur = BLANC;
        for (int k=0; k<monJeu.nbElements; k++) {
            i = monJeu.element[k].affichageElement.positionY;
            j = monJeu.element[k].affichageElement.positionX;
            if (monJeu.element[k].type == CONSTRUCTION){
                // On est dans la BOUCLE ALLEGRO
                // On est dans le MODEBOUCLE = AFFICHAGE_RESEAU_ELEC
                // On ne veut pas afficher le bitmpa mais le label d'état d'alimentation de la CONSTRUCTION en eau
                if (!monJeu.element[k].isPowered) couleur = ROUGE;
                else couleur = BLANC;
                if (monJeu.element[k].labelAlimentationElec) al_draw_text(reseauEau, couleur, tabCase[i][j].x, tabCase[i][j].y, 0, monJeu.element[k].labelAlimentationElec);
            }
            else if (monJeu.element[k].type == CENTRALE){
                if (!monJeu.element[k].capacite) couleur = ROUGE;
                else couleur = BLANC;
                sprintf(ptr, "CENTRALE#%02d (reste %04d/%04d)", k, monJeu.element[k].capacite, CAPA_CENTRALE);
                al_draw_text(reseauEau, couleur, tabCase[i][j].x, tabCase[i][j].y, 0, ptr);
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

    //mode affichage secondaire
    if(monJeu.modeJeu == MODE_CAPITALISTE){
        al_draw_bitmap(image.cap, 370, 154, 0);
        //al_draw_text(argent, al_map_rgb(239, 194, 0), 400, 150, 0, "mode capitaliste");
    }
    if(monJeu.modeJeu == MODE_COMMUNISTE){
        al_draw_bitmap(image.commu, 370, 155, 0);
        //al_draw_text(argent, al_map_rgb(239, 194, 0), 400, 150, 0, "mode capitaliste");
    }

    //argent
   // monJeu.argent = 500000;
    char argentTxt[50];
    sprintf(argentTxt, "%d", monJeu.argent);
    char nbHabTxt[50];
    sprintf(nbHabTxt, "%d", monJeu.nbhabitants);
    char compteurTxt[50];
    sprintf(compteurTxt, "%d", conteur);

    al_draw_text(argent, BLANC, 2600, 75, 0, argentTxt);
    al_draw_text(argent, BLANC, 2210, 81, 0, nbHabTxt);
    al_draw_text(argent, BLANC, 1809, 81, 0, compteurTxt);

    if(construction == true && centrale == false && route == false && chateau == false){
        bool result =  detecteSiOnPeutPoserConstruction(2, LARGEUR_CONSTRUCTION, LONGUEUR_CONSTRUCTION, ligneSouris, colonneSouris);
        if(result == false){
            al_draw_bitmap(image.maison1, xSouris, ySouris, 0);
            if (0) printf("ligne souris : %d", ligneSouris);
            if (0) printf("colone souris : %d", colonneSouris);
            //abort();
        }
        al_draw_bitmap(image.terrainVague, xSouris, ySouris, 0);
    }

    if(route == true && construction == false && chateau == false && centrale == false){
        al_draw_bitmap(image.routehb, xSouris, ySouris, 0);
    }
    if(chateau == true && construction == false && centrale == false && route == false){
        al_draw_bitmap(image.chateaudeau, xSouris, ySouris, 0);
    }
    if(centrale == true && route == false && chateau == false && construction == false){
        al_draw_bitmap(image.centraleelec, xSouris, ySouris, 0);
    }
    if(xSouris >= 0 && xSouris <= 35*TAILLE_CASE){
        if(ySouris >= 0 && ySouris <= 50*TAILLE_CASE){
            centrale = false;
            route = false;
            chateau = false;
            construction = false;
            returnClic = -10;
            //printf("%d", returnClic);
            //printf("(%d, %d)", xSouris, ySouris);
        }
    }
   // printf("(%d, %d)", xSouris, ySouris);

    al_flip_display();
}
void affichageMenu(Case tabCase[LIGNES_TAB][COLONNES_TAB],int tabTXT[LIGNES_TAB][COLONNES_TAB + 1],Image image,int ligneSouris,int colonneSouris, int xSouris, int ySouris, ALLEGRO_FONT* argent) {
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
                al_draw_filled_rectangle(tabCase[i][j].x+2,tabCase[i][j].y+2,tabCase[i][j].x+TAILLE_CASE-2,tabCase[i][j].y+TAILLE_CASE-2,
                                         al_map_rgb(0,0,0));
                //al_draw_scaled_bitmap(image.routegd,0,0,118,118,tabCase[i][j].x,tabCase[i][j].y,TAILLE_CASE,TAILLE_CASE,0);
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
               // al_draw_scaled_bitmap(image.gc2,0,0,118,354,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,6*TAILLE_CASE,0);
                al_draw_filled_rectangle(tabCase[i][j].x,tabCase[i][j].y,
                                         tabCase[i][j].x+3*TAILLE_CASE,tabCase[i][j].y+3*TAILLE_CASE,
                                         al_map_rgba(20,20,0,200));
            }
            if (tabTXT[i][j] == 14) {
                //al_draw_scaled_bitmap(image.gc3,0,0,118,354,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,6*TAILLE_CASE,0);
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

    //affichageMenuGraphique(image, xSouris, ySouris);
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

    //surpassageCase(xSouris, ySouris);

    //mode affichage secondaire
    if(monJeu.modeJeu == MODE_CAPITALISTE){
        al_draw_bitmap(image.cap, 370, 154, 0);
        //al_draw_text(argent, al_map_rgb(239, 194, 0), 400, 150, 0, "mode capitaliste");
    }
    if(monJeu.modeJeu == MODE_COMMUNISTE){
        al_draw_bitmap(image.commu, 370, 155, 0);
        //al_draw_text(argent, al_map_rgb(239, 194, 0), 400, 150, 0, "mode capitaliste");
    }

    //argent
    //monJeu.argent = 500000;
    char monTxt[50];
    sprintf(monTxt, "%d", monJeu.argent);

    al_draw_text(argent, BLANC, 2600, 75, 0, monTxt);


// COMPLEMENT POUR LE MENU

    //al_draw_bitmap(image.fond, 0, 0, 0);
    //al_clear_to_color(al_map_rgba(20, 20, 20, 130));
    al_draw_filled_rectangle(0, 0, 2880, 1694, al_map_rgba(20, 20, 20, 190));
    //al_clear_to_color(al_map_rgba(20, 20, 20, 200));
    al_draw_bitmap(image.menu, 800, 300, 0);

    //sauvegarder
    if(xSouris >= 1210 && xSouris <= 1720){
        if(ySouris >= 525 && ySouris <= 625){
            al_draw_rectangle(1210, 525, 1720, 625, BLANC, 6);
            //ecrireFichierTextePourSauvegarderFichierTexte("../file1.txt");
        }
    }
    if(xSouris >= 1210 && xSouris <= 1720){
        if(ySouris >= 643 && ySouris <= 743){
            al_draw_rectangle(1210, 643, 1720, 743, BLANC, 6);        }
    }
    if(xSouris >= 1210 && xSouris <= 1720){
        if(ySouris >= 762 && ySouris <= 862){
            al_draw_rectangle(1210, 762, 1720, 862, BLANC, 6);
        }
    }


    al_flip_display();
}

//ALLEGRO_BITMAP *ecranChargement = al_load_bitmap("../images/modeJeu.jpg");


bool clicDansCase2(int xSouris, int ySouris){
    //mode capitaliste
    if(xSouris >= 1210 && xSouris <=1683){
        if(ySouris >= 416 && ySouris <= 500){
            monJeu.modeJeu = MODE_CAPITALISTE;
            return true;
        }
    }
    if(xSouris >= 1210 && xSouris <= 1683){
        if(ySouris >= 513 && ySouris <= 597){
            monJeu.modeJeu = MODE_COMMUNISTE;
            return true;

        }
    }
    if(xSouris >= 1210 && xSouris <= 1683){
        if(ySouris >= 613 && ySouris <= 697){
            return true;
        }
    }

}

void affichageModeJeu2(Case tabCase[LIGNES_TAB][COLONNES_TAB],int tabTXT[LIGNES_TAB][COLONNES_TAB + 1],Image image,int ligneSouris,int colonneSouris, int xSouris, int ySouris) {
    //FOND :
    al_draw_bitmap(image.fond, 0, 0, 0);

    //al_draw_bitmap(ecranChargement, 0, 0, 0);
    //al_draw_rectangle(1210, 416, 1683, 500, BLANC, 3);
    //al_draw_rectangle(1210, 513, 1683, 597, BLANC, 3);
    //al_draw_rectangle(1210, 613, 1683, 697, BLANC, 3);
    //al_draw_filled_rectangle(1200, 400, 1300, 500, al_map_rgba(20, 20, 20, 200));

    //capitaliste
    if(xSouris >= 1210 && xSouris <= 1683){
        if(ySouris >= 416 && ySouris <= 500){
            al_draw_rectangle(1210, 416, 1683, 500, BLANC, 3);
        }
    }
    //communiste
    if(xSouris >= 1210 && xSouris <= 1683){
        if(ySouris >= 513 && ySouris <= 597){
            al_draw_rectangle(1210, 513, 1683, 597, BLANC, 3);
        }
    }
    //quitter
    if(xSouris >= 1210 && xSouris <= 1683){
        if(ySouris >= 613 && ySouris <= 697){
            al_draw_rectangle(1210, 613, 1683, 697, BLANC, 3);
        }
    }

    surpassageCase(xSouris, ySouris);
    al_flip_display();
}
// cette fonction renvoie 1 si l'utilisateur décide de SAUVEGARDER
// 2 s'il souhaite CHARGER la dernière  partie
// et 0 s'il veut QUITTER
// 3 pour charger le USE CASE
int issueMenuPause(int xSouris, int ySouris, int entreeMenuPause, Image image, ALLEGRO_EVENT_QUEUE* queue){
    if(xSouris >= 1210 && xSouris <= 1720){
        if(ySouris >= 525 && ySouris <= 625){
            // option SAUVEGARDER
            //sauvegarder();
            ecrireFichierTexte(NOM_FICHIER);
            //al_draw_bitmap(image.sauvegarde, 190, 0, 0);
            //al_pause_event_queue(queue, true);
            //al_flip_display();
            //sleep(1);
            return SAUVEGARDER;
            //puts("CAS 1");
        }
    }
    if(xSouris >= 1210 && xSouris <= 1720){
        if(ySouris >= 643 && ySouris <= 743){
            // option CHARGER
            lireFichierTexte(NOM_FICHIER);
            //puts("CAS 2");
            return CHARGER;
        }
    }
    if(xSouris >= 1210 && xSouris <= 1720){
        if(ySouris >= 750 && ySouris <= 760){
            // option cachée permet de CHARGER le USE CASE
            ajouterElement(1,10,8);
            ajouterElement(0,16,8);
            ajouterElement(3,14,8);
            ajouterElement(3,15,8);
            ajouterElement(2,14,4);
            ajouterElement(3,14,7);
            ajouterElement(3,13,14);
            ajouterElement(3,14,14);
            ajouterElement(3,15,14);
            ajouterElement(3,16,14);
            ajouterElement(3,17,14);
            ajouterElement(3,18,14);
            ajouterElement(3,19,14);
            ajouterElement(3,20,14);
            ajouterElement(3,21,14);
            ajouterElement(3,22,14);
            ajouterElement(2,23,14);
            ajouterElement(2,15,15);
            return CHARGER;
        }
    }
    if(xSouris >= 1210 && xSouris <= 1720){
        if(ySouris >= 762 && ySouris <= 862){
            // Nous sommes dans l'option QUITTER
            //puts("CAS 3");
            return QUITTER;
        }
    }
    if(xSouris >= 1210 && xSouris <= 1720){
        if(ySouris >= 863 && ySouris <= 900){
            // option cachée -- DEBUG CACHE

/*            // Dans un premier temps on réinitialise le statut de l'alimentation en eau et électricité
            reinitEtatRessourcesDesConstructions();
            // Puis on rescanne le réseau electrique
            detecteConstructionsAlimenteesParCentrale();
            // Puis on rescanne le réseau d'eau
            detecteConstructionAlimenteesparChateau();
            // Puis on vérifie la viabilité
            detecteConstructionsViables();
            actualiseReseauxEaux();
            actualiseReseauxElec();
*/
            initElementsConnectes();
            for (int i = 0; i < MAX_CONSTRUCTION; i++) {
                detectionElementsConnectes(i);
            }
            // Initialisation des PARCOURS
            monJeu.nbParcours = 0;
            monJeu.nbParcoursCentrale = 0;
            monJeu.nbParcoursChateau = 0;
            monJeu.nbParcoursConstruction = 0;
            initTabParcours();
            initTabParcoursCentrale();
            initTabParcoursChateau();
            recenseParcours();

            afficheTabParcoursChateau();
            afficheTabParcoursCentrale();

            classeParcoursCentrale();
            classeParcoursChateau();
            reinitEtatRessourcesDesConstructions();
            initCapaciteChateauxEtCentrales();
            detecteConstructionsAlimenteesParCentrale();
            detecteConstructionAlimenteesparChateau();
            actualiseReseauxEaux();
            actualiseReseauxElec();

            afficheStatutDesRessourcesParConstruction();
            afficheTousParcours();
            afficheTabParcoursChateau();
            afficheTabParcoursCentrale();
        }
    }
}



int carte() {
    musiqueFond();
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
    Son son;
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
    ALLEGRO_FONT *argent = al_load_font("../Polices/madetommy.ttf", 40, 0);
    ALLEGRO_FONT *reseauEau = al_load_font ("../Polices/madetommy.ttf", 25, 0);
    image.cap = al_load_bitmap("../images/cap.png");
    image.commu = al_load_bitmap("../images/commu.png");
    image.chateaudeau = al_load_bitmap("../images/piscine.png");
    image.centraleelec = al_load_bitmap("../images/centrale 3.png");
    image.caserne = al_load_bitmap("../images/caserne.png");
    image.routehb = al_load_bitmap("../images/route hb.png");
    image.routegd = al_load_bitmap("../images/route gd.png");
    image.routehd = al_load_bitmap("../images/route dh.png");
    image.routehg = al_load_bitmap("../images/route gh.png");
    image.routebd = al_load_bitmap("../images/route db.png");
    image.routebg = al_load_bitmap("../images/route gb.png");
    image.menu = al_load_bitmap("../images/menu.png");
    image.sauvegarde = al_load_bitmap("../images/sauvegarde.png");
    //image.fond = al_load_bitmap("../images/fond.png");
    image.fond = al_load_bitmap("../images/fond.png");
    image.terrainVague = al_load_bitmap("../images/t-v 2.png");
    image.cabane = al_load_bitmap("../images/cabane.png");
    image.immeuble = al_load_bitmap("../images/immeuble.png");
    image.maison1 = al_load_bitmap("../images/maison 1.png");
    image.gc1 = al_load_bitmap("../images/g-c 1.png");
    //initSonConstruction(son);
    al_init_acodec_addon();
    al_reserve_samples(4);
    son.sonConstructionRoute = al_load_sample("../Son_sonConstructionRoute.ogg");
    son.sonConstructionCentrale = al_load_sample("../Son_sonConstructionCentrale.ogg");
    son.sonConstructionChateauEau = al_load_sample("../Son_sonConstructionChateau.ogg");
    son.sonConstructionMaison = al_load_sample("../Son_sonConstructionMaison.ogg");

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

    int counterAttentePause = 0;
    int returnClic = -10;
    int entrerMenuPause = 0;
    int retourMenuPause = JOUER;
    int conteur = 0;
    bool route = false;
    bool centrale = false;
    bool chateau = false;
    bool construction = false;
    int impots = 0;
    while (!end3) {
        //Dans le cas ou l'utilisateur fait rien, il est inactif, spectateur du jeu
        //va permettre de payer les impots

        al_wait_for_event(queue,&event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                if (entrerMenuPause) break;
                end3 = true;
                break;

            case ALLEGRO_EVENT_MOUSE_AXES:
                xSouris = event.mouse.x;
                ySouris = event.mouse.y;

                if (entrerMenuPause) break;
                for (int i = 0; i < LIGNES_TAB; ++i) {
                    for (int j = 0; j < COLONNES_TAB; ++j) {
                        if ((float)tabCase[i][j].y < (float)ySouris && (float)ySouris < (float)tabCase[i][j].y+TAILLE_CASE &&
                            (float)tabCase[i][j].x < (float)xSouris && (float) xSouris < (float)tabCase[i][j].x+TAILLE_CASE) {
                            ligneSouris = i;
                            colonneSouris = j;
                        }
                    }
                }
                if(TRACE) {
                    printf("%d,%d\n",ligneSouris,colonneSouris);
                    printf("%d,%d\n",xSouris,ySouris);
                }
                break;

            case ALLEGRO_EVENT_TIMER:
                if ((counter++)%rapportReduction == 0) {
                    //conteur++;
                    if (!entrerMenuPause) monJeu.cycle++;
                    //toutes les 15 secondes
                    //if(conteur%3 == 0){
                    if(monJeu.cycle%NB_SEC_PAR_CYCLE == 0){
                        impots = evolutionConstruction();
                        monJeu.argent += impots;
                    }
                    //printf("compteur : %d ", conteur);
                    // Dans cette partie on va faire évoluer la ville
                    // Améliorer toutes les constructions actives
                    // payer les impots
                    // mettre a jour le flouzz
                    currentTime = al_get_time();
                    if(TRACE) printf("%2f ", currentTime);
                }
                if (entrerMenuPause) {
                    affichageMenu(tabCase,monJeu.tabTXT,image,ligneSouris,colonneSouris,xSouris,ySouris,argent);
                    break;
                }
                if (SAUVEGARDER == retourMenuPause) {
                    // NOUS ALLONS AFFICHER L'INFORMATION "SAUVEGARDER" PDT QQ SECONDES
                    al_draw_bitmap(image.sauvegarde, 190, 0, 0);
                    //al_pause_event_queue(queue, true);
                    al_flip_display();
                    if (NB_TIC_TIMER_SAUVEGARDE < (counterAttentePause++)) {
                        // On a terminé d'afficher le panneau de SAUVEGARDE
                        retourMenuPause = JOUER;
                        counterAttentePause = 0;
                    }
                    break;
                }
                //affichage(tabCase,monJeu.tabTXT,image,ligneSouris,colonneSouris,xSouris,ySouris,argent, construction, centrale, route, chateau, returnClic, reseauEau, conteur);
                affichage(tabCase,monJeu.tabTXT,image,ligneSouris,colonneSouris,xSouris,ySouris,argent, construction, centrale, route, chateau, returnClic, reseauEau, monJeu.cycle);
                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                //abort();
                //fonction poser element
                if (construction || centrale || route || chateau) {
                    // Dans ce cas, l'un des 4 ELT est en train d'être ajouté, il faut vérifier si on peut l'ajouter à notre grille
                    if (construction){
                        ajouterElement(CONSTRUCTION,colonneSouris,ligneSouris);
                        sonConstruction(son, 3);
                    }
                    else if (centrale){
                        ajouterElement(CENTRALE,colonneSouris,ligneSouris);
                        sonConstruction(son, 4);
                    }
                    else if (route){
                        ajouterElement(ROUTE,colonneSouris,ligneSouris);
                        sonConstruction(son, 1);
                    }
                    else if (chateau){
                        ajouterElement(CHATEAU,colonneSouris,ligneSouris);
                        sonConstruction(son, 2);
                    }
                }

                construction = false;
                centrale = false;
                //route = false;
                chateau = false;
                if (entrerMenuPause){
                    retourMenuPause = issueMenuPause(xSouris, ySouris,entrerMenuPause, image, queue);
                    if (retourMenuPause == QUITTER) return 0;
                    if (retourMenuPause == SAUVEGARDER) {
                    }
                    else if (retourMenuPause == CHARGER) {
                        retourMenuPause = JOUER;
                    }
                    entrerMenuPause = false;
                    break;
                }
                //centrale passage souris
                returnClic = clicDansCase(xSouris, ySouris, image, event, timer, queue);
                //printf("returnClic %d\n", returnClic);
                if (-1 == returnClic) break;
                if (999 == returnClic) {
                    // Nous sommes dans le menu PAUSE
                    entrerMenuPause = 1;
                    break;
                }
                if(CENTRALE == returnClic){
                    if(route)route=false;
                    centrale = true;
                }
                if(ROUTE == returnClic){
                    route = !route;
                }
                if(CHATEAU == returnClic){
                    if(route)route=false;
                    chateau = true;
                }
                if(CONSTRUCTION == returnClic){
                    if(route)route=false;
                    construction = true;
                }
                break;
        }
        //printf("nombre hab : %d\n", monJeu.nbhabitants);

    }
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    //abort();
    return returnClic;
}

void carteDepart() {
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


    //déclaration bitmap
    image.fond = al_load_bitmap("../images/modeJeu.jpg");

    al_flip_display();

    al_start_timer(timer);
    while (!end3) {
        al_wait_for_event(queue,&event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                end3 = true;
                break;

            case ALLEGRO_EVENT_MOUSE_AXES:
                xSouris = event.mouse.x;
                ySouris = event.mouse.y;
                break;

            case ALLEGRO_EVENT_TIMER:

                //abort ();
                affichageModeJeu2(tabCase,monJeu.tabTXT,image,ligneSouris,colonneSouris,xSouris,ySouris);
                break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                //centrale passage souris
                //clicDansCase(xSouris, ySouris);
                end3 = clicDansCase2(xSouris, ySouris);
                break;
        }
    }

    /*
    if(monJeu.modeJeu == MODE_COMMUNISTE){
        affichageChargementCommuniste();
    }
    if(monJeu.modeJeu == MODE_CAPITALISTE){
        affichageChargementCapitaliste();
    }
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
     */
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

void initElementsConnectes(){
    for (int j = 0; j < MAX_CONSTRUCTION; j++) {
        monJeu.element[j].nbElementConnects = 0;
        //Initialise les tableaux de connexité des constructions à -1
        for (int i = 0; i < MAX_CONSTRUCTION ; i++) {
            monJeu.element[j].listeIndexElementsConnectes[i] = -1;
            monJeu.element[j].tabDistanceAvecInfraConnectees[i] = -1;
        }
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
    monJeu.modeBoucle = STANDARD;



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
    if (lgParcours > LG_MAX_PARCOURS) {
        printf ("ERREUR AFFICHAGE PARCOURS\n");
        abort();
    }
    if (-1 == lgParcours) lgParcours = LG_MAX_PARCOURS;
    printf ("PRC%03d:", indexParcours);
    for(int i=0; i<lgParcours; i++){
        if (-1 == monJeu.tabParcours[indexParcours][i]) break;
        printf("%d",monJeu.tabParcours[indexParcours][i]);
        if (i!=(lgParcours-1)) printf("-->");
    }
    puts("");
}

void afficheTousParcours(){
    if (!monJeu.nbParcours) return;
    printf("%2d PARCOURS DANS JEU\n", monJeu.nbParcours);
    for (int i=0;i<monJeu.nbParcours;i++){
        afficheParcours(i, LG_MAX_PARCOURS);
    }
}
void afficheTabParcoursConstruction(){
    // Si aucun parcours on sort
    if (!monJeu.nbParcoursConstruction) return;
    printf("%2d PARCOURS DEPUIS CONSTRUCTION\n", monJeu.nbParcoursConstruction);
    for (int i=0;i<monJeu.nbParcoursConstruction;i++){
        if (monJeu.tabParcoursConstruction[i].source == -1) continue;
        printf ("SOURCE:%d / DEST:%d / LG:%d / +COURT:%d / ",
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
    printf("%2d PARCOURS DEPUIS CHATEAU\n", monJeu.nbParcoursChateau);
    for (int i=0;i<monJeu.nbParcoursChateau;i++){
        if (monJeu.tabParcoursChateau[i].source == -1) continue;
        printf ("SOURCE:%d / DEST:%d / LG:%d / +COURT:%d / ",
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
    printf("%2d PARCOURS DEPUIS CENTRALE\n", monJeu.nbParcoursCentrale);
    for (int i=0;i<monJeu.nbParcoursCentrale;i++){
        if (monJeu.tabParcoursCentrale[i].source == -1) continue;
        printf ("SOURCE:%d / DEST:%d / LG:%d / +COURT:%d / ",
                monJeu.tabParcoursCentrale[i].source,
                monJeu.tabParcoursCentrale[i].destination,
                monJeu.tabParcoursCentrale[i].lgParcours,
                monJeu.tabParcoursCentrale[i].estPlusCourt);
        afficheParcours(monJeu.tabParcoursCentrale[i].indexParcours, monJeu.tabParcoursCentrale[i].lgParcours);
    }
}

int ajouteParcours (int *ptrParcours, int lgParcours){
    // On vérifie que l'on peut encore ajouter un PARCOURS
    if (monJeu.nbParcours >= MAX_PARCOURS) {
        puts("ERREUR AJOUTER PARCOURS");
        abort();
    }
    // Si le Parcours est <= à 2 cases, on ne l'ajoute pas
    if (lgParcours <= 2) return -1;
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
        if (i >= LG_MAX_PARCOURS) {
            puts("ERREUR LG_MAX_PARCOURS");
            abort ();
        }
        monJeu.tabParcours[monJeu.nbParcours][i] = ptrParcours[i];
    }
    monJeu.nbParcours ++;
    // Affichage des parcours pour DEBUGGAGE
    //afficheTabParcoursConstruction();
    //afficheTabParcoursChateau();
    //afficheTabParcoursCentrale();
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

int renvoietailleX(int typeElement){
    if(typeElement == ROUTE) return LARGEUR_ROUTE;
    if(typeElement == CENTRALE) return LARGEUR_CENTRALE;
    if(typeElement == CHATEAU) return LARGEUR_CHATEAU;
    if(typeElement == CONSTRUCTION) return LARGEUR_CONSTRUCTION;
}
int renvoietailleY(int typeElement){
    if(typeElement == ROUTE) return LONGUEUR_ROUTE;
    if(typeElement == CENTRALE) return LONGUEUR_CENTRALE;
    if(typeElement == CHATEAU) return LONGUEUR_CHATEAU;
    if(typeElement == CONSTRUCTION) return LONGUEUR_CONSTRUCTION;
}

void ajouterElement(int typeElement, int positionX, int positionY){
    // On commence par verifier la capacité d'ajout
    if (monJeu.nbElements >= MAX_CONSTRUCTION) {
        puts("ERREUR AJOUTER ELEMENT MAX_CONSTRUCTION");
        abort ();
    }

    // Vérification de l'intégrité des variables X, Y
    int tailleX = renvoietailleX(typeElement);
    int tailleY = renvoietailleY(typeElement);
    if(!detecteSiOnPeutPoserConstruction(typeElement, tailleX, tailleY, positionX, positionY)) return;
    if (positionX+tailleX >= MAX_COLONNES+1 || positionY+tailleY >= MAX_LIGNES+1) {
        // IL FAUDRA PRENDRE EN COMPTE LA LARGEUR ET LA HAUTEUR DE L'ELT !!!!!!!!!!
        printf("Erreur position dans AJOUTERELEMENT (%d/%d,%d/%d)\n", positionX, MAX_COLONNES, positionY, MAX_LIGNES);
        return;
    }

    //Faire qu'on ne peut pas placer un element sur un autre

    if (TRACE) printf("AJOUTER ELT : %d à %d,%d\n", typeElement, positionX, positionY);
    switch (typeElement) {
        case ROUTE :
            if(monJeu.argent - PRIX_ROUTE < 0){
                printf("plus assez d'argent\n");
               //abort();

            }
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
            monJeu.tabTXT[positionY][positionX] = 1;
            break;

        case CHATEAU:
            if(monJeu.argent -PRIX_CHATEAU < 0){
                printf("plus assez d'argent pour\n");
                //abort();

            }
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
            if(monJeu.argent - PRIX_CENTRALE< 0){
                 printf("plus assez d'argent\n");
                //abort();

            }
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
            if(monJeu.argent - PRIX_CONSTRUCTION < 0){
                printf("plus assez d'argent\n");
                //abort();

            }
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
            monJeu.tabTXT[positionY][positionX]=9;
            monJeu.nbElements++;
            break;

        case ECOLE:// On fera spawn une bibliothèque qui pourra s'améliorer en école d'ingé (3x3 cases)
            if(monJeu.argent - PRIX_ECOLE < 0){
                // printf("plus assez d'argent pour ro\n");
                //abort();

            }
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
            if(monJeu.argent - PRIX_MUSEE < 0){
                 printf("plus assez d'argent pour ro\n");
                //abort();

            }
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
    majApresAjoutElement(monJeu.nbElements-1);
    //majApresEvolutionNiveauConstruction();

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
    if (monJeu.element[numeroElement].niveau>0) monJeu.element[numeroElement].niveau = monJeu.element[numeroElement].niveau-1;

}

void ameliorerConstruction(int numeroElement){
    if (monJeu.element[numeroElement].niveau<5) monJeu.element[numeroElement].niveau = monJeu.element[numeroElement].niveau+1;
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
                monJeu.tabTXT[monJeu.element[numeroElement].affichageElement.positionY][monJeu.element[numeroElement].affichageElement.positionX]=9;
                //printf("position element %d : (%d, %d) \n", numeroElement,monJeu.element[numeroElement].affichageElement.positionX, monJeu.element[numeroElement].affichageElement.positionY);
                break;
            case CABANE:
                monJeu.element[numeroElement].nbHabitantElement = 10;
                monJeu.tabTXT[monJeu.element[numeroElement].affichageElement.positionY][monJeu.element[numeroElement].affichageElement.positionX]=10;
               // printf("position element %d : (%d, %d) \n", numeroElement,monJeu.element[numeroElement].affichageElement.positionX, monJeu.element[numeroElement].affichageElement.positionY);

                break;
            case MAISON:
                monJeu.element[numeroElement].nbHabitantElement = 50;
                monJeu.tabTXT[monJeu.element[numeroElement].affichageElement.positionY][monJeu.element[numeroElement].affichageElement.positionX]=11;
                //printf("position element %d : (%d, %d) \n", numeroElement,monJeu.element[numeroElement].affichageElement.positionX, monJeu.element[numeroElement].affichageElement.positionY);
                break;
            case IMMEUBLE:
                monJeu.element[numeroElement].nbHabitantElement = 100;
                monJeu.tabTXT[monJeu.element[numeroElement].affichageElement.positionY][monJeu.element[numeroElement].affichageElement.positionX]=12;
                break;
            case GRATTE_CIEL:
                monJeu.element[numeroElement].nbHabitantElement = 1000;
                monJeu.tabTXT[monJeu.element[numeroElement].affichageElement.positionY][monJeu.element[numeroElement].affichageElement.positionX]=13;

                break;
        }
        if(monJeu.element[numeroElement].niveau > 5){
            return;
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
    //puts("Fonction changer niveau : ");
    if(TRACE)printf("bâtiment position [%d][%d] est passé niveau : %d\n", monJeu.element[numeroElement].affichageElement.positionX, monJeu.element[numeroElement].affichageElement.positionX, monJeu.element[numeroElement].niveau);
    //puts("");
}


// En MODE_COMMUNISTE :
// Si la CONSTRUCTION n'est pas viable, elle REGRESSE au lieu d'évoluer
// En MODE_CAPITALISTE : on evolue quoi qu'il arrive

//renvoie le total des impots a percevoir après évolution
int evolutionConstruction(){
    detecteConstructionsViables();
    int impots = 0;
    // Pour chaque CONSTRUCTION, on evolue en fonction du MODE
    if (MODE_NON_CHOISI== monJeu.modeJeu) {
        if(TRACE)printf("ERREUR : Mode JEU NON CHOISI\n");
        return 0;
    }
    for (int i=0;i<monJeu.nbElements;i++){
        if(monJeu.element[i].actif != ACTIF) continue;
        //on veut quand mm qu'il soit connecté à la route
        else if(monJeu.element[i].viable && monJeu.modeJeu == MODE_COMMUNISTE){//ça veut dire qu'on est en mode communiste
            ChangerNiveauConstruction(i,1);
        }
        else if(!monJeu.element[i].viable && monJeu.modeJeu == MODE_COMMUNISTE){//ça veut dire qu'on est en mode communiste
            ChangerNiveauConstruction(i,-1);
        }
        else{
            ChangerNiveauConstruction(i, 1);
        }

        impots += monJeu.element[i].nbHabitantElement;
    }
    majApresEvolutionNiveauConstruction();
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
// Vérifie si les coordonnées x, y sont comprises dans la zone occupée par l'element K
bool estDansZone (int k, int x, int y){
    if (x >= monJeu.element[k].affichageElement.positionX && x < monJeu.element[k].affichageElement.positionX + monJeu.element[k].affichageElement.largeurX){
        if(y >= monJeu.element[k].affichageElement.positionY && y < monJeu.element[k].affichageElement.positionY + monJeu.element[k].affichageElement.largeurY){
            return true;
        }
    }
    return false;
}

// Rnevoie true si on peut poser, false sinon
bool detecteSiOnPeutPoserConstruction(int numeroElement, int tailleX, int tailleY, int positioncurseurX, int positioncurseurY){
    for (int x = positioncurseurX; x < positioncurseurX+tailleX;x++) {
        for(int y = positioncurseurY; y<positioncurseurY+tailleY;y++){
            for(int k = 0; k<monJeu.nbElements; k++){
                //if(numeroElement != k && monJeu.element[k].actif == ACTIF){//if(1)printf("Test interco : %d en (%d,%d) avec %d en %d,%d)\n", numeroElement,x,y,k,monJeu.element[k].affichageElement.positionX,monJeu.element[k].affichageElement.positionY);
                    if(estDansZone (k, x, y)){// == monJeu.element[k].affichageElement.positionX && y == monJeu.element[k].affichageElement.positionY){
                        if (0) printf("position X : %d", positioncurseurX);
                        if (0) printf("position Y = %d", positioncurseurY);
                        return false;
                    }
                //}
            }
        }
    }
    return true;
}


void detectionElementsConnectes(int numeroElement){
    int tailleX = monJeu.element[numeroElement].affichageElement.largeurX;
    int tailleY = monJeu.element[numeroElement].affichageElement.largeurY;
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
void lireFichierTexte(char *nomFichier) {
    FILE *ifs = fopen(nomFichier, "r");
    int typeElement, positionX, positionY , taille, numeroPartie, niveau, argent, cycle;

    if (!ifs) {
        if(TRACE)printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    fscanf(ifs, "%d\n", &argent);
    fscanf(ifs, "%d\n", &cycle);

    // creer les aretes du graphe
    while (1) {//for (int i = 0; i < taille; ++i) {
        if (0 < fscanf(ifs, "TYPE=%03d NIVEAU=%03d X=%03d Y=%03d\n", &typeElement, &niveau, &positionX, &positionY)) {
            //printf("TYPE=%03d X=%03d Y=%03d\n", typeElement, positionX, positionY);
            ajouterElement(typeElement, positionX, positionY);
            monJeu.element[monJeu.nbElements-1].niveau = niveau;
            initConstruction(monJeu.nbElements-1, 0);

        }
        else break;
    }
    monJeu.argent = argent;
    monJeu.cycle = cycle;
    fclose(ifs);
}

void ecrireFichierTexte(char *nomFichier) {
    FILE *ifs = fopen(nomFichier, "w");

    if (!ifs) {
        printf("Erreur d'ouverture de fichier\n");
        exit(-1);
    }
    fprintf(ifs, "%d\n", monJeu.argent);
    fprintf(ifs, "%d\n", monJeu.cycle);

    // creer les aretes du graphe
    for (int i = 0; i < monJeu.nbElements; ++i) {
        fprintf(ifs, "TYPE=%03d NIVEAU=%03d X=%03d Y=%03d\n", monJeu.element[i].type, monJeu.element[i].niveau, monJeu.element[i].affichageElement.positionX,  monJeu.element[i].affichageElement.positionY);
        //printf("TYPE=%03d NIVEAU=%03d X=%03d Y=%03d\n", monJeu.element[i].type, monJeu.element[i].affichageElement.positionX,  monJeu.element[i].affichageElement.positionY);
    }
    fclose(ifs);
}



void test(){

    /////////////// TEST //////////////
    ajouterElement(CONSTRUCTION, 1, 1);//0
    ChangerNiveauConstruction(0, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(0, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(0, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(0, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(0, 1);
    majApresEvolutionNiveauConstruction ();

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
    ChangerNiveauConstruction(23, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(23, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(23, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(23, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(23, 1);
    majApresEvolutionNiveauConstruction ();

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
    ChangerNiveauConstruction(38, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(38, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(38, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(38, 1);
    majApresEvolutionNiveauConstruction ();
    ChangerNiveauConstruction(38, 1);
    majApresEvolutionNiveauConstruction ();

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
    return;

    /////////////FIN TEST////////////



    //lireFichierTextePourAjouterElement("../fichierMathis.txt");


    printf("%d", monJeu.argent);
    //ajouterElement(CONSTRUCTION, 1, 1);//0
    printf("%d", monJeu.argent);
    /*
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
     */
}


void afficherEltConnectes(int numeroElement){
    printf("Element %d connecté à elements : ", numeroElement);
    for(int i = 0; i < MAX_CONSTRUCTION ; i++){
        if(monJeu.element[numeroElement].listeIndexElementsConnectes[i] != -1){
            printf("%d, ", monJeu.element[numeroElement].listeIndexElementsConnectes[i]);
        }
    }
    //puts("");
}
int cpt = 0;


void afficheRoute(int *ptrRoute, int distance){
    //return;
    for(int i=0; i<distance+1; i++){
        if (-1 != ptrRoute[i]) printf("%d_",ptrRoute[i]);
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
            //afficheRoute(ptrRoute,*ptrDistanceCouranteDepuisSource);
            ajouteParcours(ptrRoute, *ptrDistanceCouranteDepuisSource+1);
            if (-1 == monJeu.element[source].tabDistanceAvecInfraConnectees[indexEltConnecte] ||
                (*ptrDistanceCouranteDepuisSource-1) < monJeu.element[source].tabDistanceAvecInfraConnectees[indexEltConnecte]) {
                monJeu.element[source].tabDistanceAvecInfraConnectees[indexEltConnecte] = *ptrDistanceCouranteDepuisSource-1;
                //if(TRACE)printf("INFRA trouvée %d via %d (ROUTE) à distance %d\n", indexEltConnecte, routeCourante, *ptrDistanceCouranteDepuisSource);
                //if(TRACE)printf("ROUTE GAGNANTE EN %d coups (SOURCE=%d DEST=%d): ", *ptrDistanceCouranteDepuisSource, source, indexEltConnecte);
                //afficheRoute(ptrRoute,*ptrDistanceCouranteDepuisSource);
                setParcoursCourantPlusCourt(source, indexEltConnecte);
                if (TRACE) puts("SET ROUTE PLUS COURTE");
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
    if(1)printf("Distance des INFRA connectées à %d : ", numeroElement);
    for(int i = 0; i < MAX_CONSTRUCTION ; i++){
        if(monJeu.element[numeroElement].tabDistanceAvecInfraConnectees[i] != -1){
            if(1)printf("INFRA %d à %d cases, ", i, monJeu.element[numeroElement].tabDistanceAvecInfraConnectees[i]);
        }
    }
    //puts("");
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
    bool dejaVu[MAX_CONSTRUCTION];

    // On initialise le tableau des ELT deja vus pour tracer les CHATEAUX deja vus
    for (int i=0;i<MAX_CONSTRUCTION;i++) {
        dejaVu[i]=false;
    }
    for (int i=0; i<monJeu.nbParcoursChateau; i++){
        // Est ce que c'est toujours le mm chateau
        indexChateauCourant = monJeu.tabParcoursChateau[i].source;
        if (!dejaVu[indexChateauCourant]) {
            monJeu.element[indexChateauCourant].capacite = CAPA_CHATEAU;
            dejaVu[indexChateauCourant] = true;
        }
        /*
        if(indexChateauCourant != monJeu.tabParcoursChateau[i].source){
            monJeu.element[i].capacite = CAPA_CHATEAU;
            indexChateauCourant = monJeu.tabParcoursChateau[i].source;
        }
         */
        // Si pour cette CHATEAU la capacite restante est NULLE on passe le tour
        //if(TRACE)printf ("monJeu.element[%d].capacite =%d\n",i,monJeu.element[i].capacite);
        if (monJeu.element[indexChateauCourant].capacite == 0) continue;

        //Est ce que c'est une construction ?
        indexDestination = monJeu.tabParcoursChateau[i].destination;
        if(monJeu.element[indexDestination].type == CONSTRUCTION) {
            if (!monJeu.element[indexDestination].isWatered){
                if (0) printf ("ELT %d NOT WATERED\n", indexDestination);
                // Dans ce cas, le CHATEAU va fournir TOUT ou PARTIE de sa capacité en eau restante à cette construction
                if(monJeu.element[indexChateauCourant].capacite >= (monJeu.element[indexDestination].nbHabitantElement-monJeu.element[indexDestination].waterLevel)){// est ce que la capacité le permet
                    // Le CHATEAU fournit la CAPACITE nécessaire pour alimenter completement la CONSTRUCTION
                    // La CAPACITE du CHATEAU est réduite d'autant
                    monJeu.element[indexChateauCourant].capacite -= (monJeu.element[indexDestination].nbHabitantElement-monJeu.element[indexDestination].waterLevel);
                    if (0) printf (" CHATEAU %d CAPACITE RESTANTE %d/%d\n", indexChateauCourant, monJeu.element[indexChateauCourant].capacite, CAPA_CHATEAU);
                    // La CONSTRUCTION devient completement ALIMENTEE en EAU
                    monJeu.element[indexDestination].isWatered = true;
                    if (0) printf ("ELT %d NOT WATERED==>WATERED\n", indexDestination);
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
    bool dejaVu[MAX_CONSTRUCTION];

    // On initialise le tableau des ELT deja vus pour tracer les CHATEAUX deja vus
    for (int i=0;i<MAX_CONSTRUCTION;i++) {
        dejaVu[i]=false;
    }
    for (int i=0; i<monJeu.nbParcoursCentrale; i++){
        // Est ce que c'est toujours le mm centrale
        indexCentraleCourante = monJeu.tabParcoursCentrale[i].source;
        if (!dejaVu[indexCentraleCourante]) {
            monJeu.element[indexCentraleCourante].capacite = CAPA_CENTRALE;
            dejaVu[indexCentraleCourante] = true;
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
                monJeu.element[indexDestination].tabFournitureRessources[indexCentraleCourante] = monJeu.element[indexDestination].nbHabitantElement;
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


void reinitEtatRessourcesDesConstructions(){
    // On parcours toutes les CONSTRUCTIONS et on réinitialise tous les éléments liés à l'alimentation en eau ou électrique
    for (int j = 0; j < MAX_CONSTRUCTION; j++) {
        monJeu.element[j].viable = false;
        monJeu.element[j].isPowered = false;
        monJeu.element[j].isWatered = false;
        monJeu.element[j].waterLevel = 0;
        for (int i = 0; i < MAX_CONSTRUCTION ; i++) {
            monJeu.element[j].tabFournitureRessources[i] = -1;
        }
    }
}
void majApresEvolutionNiveauConstruction() {
// Apres avoir modifié le niveau d'une construction, la connexion des CONSTRUCTIONS aux CHATEAUX et aux CENTRALES ne changent pas
// Il faut juste :
// Scanner tous les réseaux electriques pour vérifier qui est toujours alimenté par les centrales
// Scanner tous les réseaux d'eau pour vérifier qui est alimenté par quel réseau d'eau et à quelle hauteur

    // Dans un premier temps on réinitialise le statut de l'alimentation en eau et électricité
    reinitEtatRessourcesDesConstructions();
    // Puis on rescanne le réseau electrique
    detecteConstructionsAlimenteesParCentrale();
    // Puis on rescanne le réseau d'eau
    detecteConstructionAlimenteesparChateau();
    // Puis on vérifie la viabilité
    detecteConstructionsViables();
    actualiseReseauxEaux();
    actualiseReseauxElec();
    // DEBUG
    //afficheStatutDesRessourcesParConstruction();
}

void recenseParcours(){

    int distance = 0;
    int *tabCheminParcouru = calloc (MAX_CONSTRUCTION, sizeof(int));
    int *route = calloc(MAX_CONSTRUCTION, sizeof(int));


        // BOUCLE PRINCIPALE
    //
    // ON PARCOURT TOUS LES ELT DU JEU, SI CE NE SONT PAS DES ROUTES, ON REGARDE TOUS LES PARCOURS VERS LES AUTRES ELTS
    // EN EMPRUNTANT QUE DES ROUTES !!!!!
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
        //afficherTabDistanceInfraConnectees(i);
    }
    free (tabCheminParcouru);
    free(route);
}

void afficheStatutDesRessourcesParConstruction(){
    // Affiche le statut des alimentations electriques et en eau pour chaque CONSTRUCTION
    for(int i = 0; i<monJeu.nbElements;i++) {
        if (monJeu.element[i].type == CONSTRUCTION) {
            printf("ELT %02d : WaterLevel %04d/%04d / Powered %s (", i, monJeu.element[i].waterLevel, monJeu.element[i].nbHabitantElement, monJeu.element[i].isPowered?"Yes":"No");
            for (int j = 0; j < monJeu.nbElements; j++) {
                if (monJeu.element[i].tabFournitureRessources[j] != -1) {
                    if (monJeu.element[j].type == CENTRALE) printf(" CENTRALE#%02d %04d", j, monJeu.element[i].tabFournitureRessources[j]);
                    if (monJeu.element[j].type == CHATEAU) printf(" CHATEAU #%02d %04d", j, monJeu.element[i].tabFournitureRessources[j]);
                }
            }
            printf (" )\n");
        }
    }
}

void majApresAjoutConstruction(int numElt){
    // Après avoir ajouter la construction d'index numElt dans le tabElement du jeu
    // Si cette construction n'est pas reliée à une route alors on ne met rien à jour
/*
    detectionElementsConnectes(numElt);
    int hasRouteConnected = 0;
    int index = -1;
    for(int i=0;i<monJeu.element[numElt].nbElementConnects;i++){
        index = monJeu.element[numElt].listeIndexElementsConnectes[i];
        if (ROUTE == monJeu.element[index]) hasRouteConnected = 1;
    }
    if (!hasRouteConnected) return;

    // Si la construction est reliée à une route, il faut mett :
    recenseParcours();
    classeParcoursCentrale();
    classeParcoursChateau();
    detecteConstructionsAlimenteesParCentrale();
    detecteConstructionAlimenteesparChateau();
    detecteConstructionsViables();
    */
}

void initCapaciteChateauxEtCentrales(){
    for(int i=0;i<monJeu.nbElements;i++){
        if (monJeu.element[i].type == CHATEAU) monJeu.element[i].capacite = CAPA_CHATEAU;
        else if (monJeu.element[i].type == CENTRALE) monJeu.element[i].capacite = CAPA_CENTRALE;
    }
}
void majApresAjoutElement(int numElt) {
    // Après avoir ajouter l'ELT d'index numElt dans le tabElement du jeu
    // Si cet ELT n'est reliée à RIEN alors on sort
    detectionElementsConnectes(numElt);
    if (!monJeu.element[numElt].nbElementConnects) return;

    // Sinon on met à jour les listeIndexElementsConnected des ELT auquels il est relié
    // Puis on recenseParcours
    // Puis on refait les statutRessources
    int index = -1;
    /*
    // La on ne regarde que les ELT qui sont connectés
    for (int i = 0; i < monJeu.element[numElt].nbElementConnects; i++) {
        index = monJeu.element[numElt].listeIndexElementsConnectes[i];
        detectionElementsConnectes(index);
    }
     */

    initElementsConnectes();
    for (int i = 0; i < MAX_CONSTRUCTION; i++) {
        detectionElementsConnectes(i);
    }
    // Initialisation des PARCOURS
    monJeu.nbParcours = 0;
    monJeu.nbParcoursCentrale = 0;
    monJeu.nbParcoursChateau = 0;
    monJeu.nbParcoursConstruction = 0;
    initTabParcours();
    initTabParcoursCentrale();
    initTabParcoursChateau();
    recenseParcours();
    classeParcoursCentrale();
    classeParcoursChateau();
    reinitEtatRessourcesDesConstructions();

    initCapaciteChateauxEtCentrales();
    detecteConstructionsAlimenteesParCentrale();
    detecteConstructionAlimenteesparChateau();
    actualiseReseauxEaux();
    actualiseReseauxElec();

    // DEBUG
    int debug = 0;
    if (debug) {
        printf ("AJOUT DE L'ELT %02d\n", numElt);
        afficheTabParcoursChateau();
        afficheTabParcoursCentrale();
        afficheStatutDesRessourcesParConstruction();
        // FIN DEBUG
    }
}

// Recherche les reseaux d'eau qui alimentent une CONSTRUCTION
// Si INDEXELT ne pointe pas sur UNE CONSTRUCTION : Renvoyer -1
// Si INDEXELT pointe sur une CONSTRUCTION renvoyer 0
// Et écrit dans PTR l'origine des approvisionnement en eau
int rechercheReseauxEaux(int indexElt, char *ptr){
    if (monJeu.element[indexElt].type != CONSTRUCTION) return -1;
    if (!ptr) return -1;
    int lg = 0;
    if (monJeu.element[indexElt].isWatered) sprintf(ptr, "%02d FULLY WATERED AT %04d/%04d BY", indexElt, monJeu.element[indexElt].waterLevel, monJeu.element[indexElt].nbHabitantElement);
    else if (0 != monJeu.element[indexElt].waterLevel) sprintf(ptr, "%02d NOT FULLY WATERED BY", indexElt);
    else sprintf(ptr, "%02d NOT WATERED AT ALL", indexElt);
        for (int j = 0; j < monJeu.nbElements; j++) {
        // On crée un INDEX J qui va parcourir le TABFOURNITURERESSOURCES de la CONSTRUCTION INDEXELT
        // On parcours le TABFOURNITURERESSOURCES de la CONSTRUCTION INDEXELT
        if (monJeu.element[indexElt].tabFournitureRessources[j] >= 0) {
            lg = strlen (ptr);
            if (monJeu.element[j].type == CHATEAU) sprintf(&(ptr[lg]), " CHATEAU#%02d AT %04d", j, monJeu.element[indexElt].tabFournitureRessources[j]);
        }
    }
    return 0;
}

// Recherche les reseaux ELEC qui alimentent une CONSTRUCTION
// Si INDEXELT ne pointe pas sur UNE CONSTRUCTION : Renvoyer -1
// Si INDEXELT pointe sur une CONSTRUCTION renvoyer 0
// Et écrit dans PTR l'origine des approvisionnement ELEC
int rechercheReseauxElec(int indexElt, char *ptr){
    if (monJeu.element[indexElt].type != CONSTRUCTION) return -1;
    if (!ptr) return -1;
    int lg = 0;
    if (monJeu.element[indexElt].isPowered) sprintf(ptr, "%02d POWERED BY", indexElt);
    else sprintf(ptr, "#%02d NOT POWERED", indexElt);
    for (int j = 0; j < monJeu.nbElements; j++) {
        // On crée un INDEX J qui va parcourir le TABFOURNITURERESSOURCES de la CONSTRUCTION INDEXELT
        // On parcours le TABFOURNITURERESSOURCES de la CONSTRUCTION INDEXELT
        if (monJeu.element[indexElt].tabFournitureRessources[j] >= 0) {
            lg = strlen (ptr);
            if (monJeu.element[j].type == CENTRALE) sprintf(&(ptr[lg]), " CENTRALE#%02d AT %04d/%04d", j, monJeu.element[indexElt].tabFournitureRessources[j],monJeu.element[indexElt].nbHabitantElement);
        }
    }
    return 0;
}

void actualiseReseauxElec(){
    // Affiche le statut des alimentations elec pour chaque CONSTRUCTION
    // Renseigne les tabParcoursCentraleActif avec 1 si ACTIF et 0 sinon
    char ptr[LG_LABEL_ALIMENTATION_ELEC];
    for (int i=0;i<LG_LABEL_ALIMENTATION_ELEC;i++) ptr[i]=0;
    int retour = -1;
    for(int i = 0; i<monJeu.nbElements;i++) {
        // Pour tous les ELT du JEU on écrit dans PTR la QU d'eau reçue de chaque CHATEAU (s'il s'agit d'une CONSTRUCTION
        retour = rechercheReseauxElec(i, ptr);
        if (-1 != retour) {
            // Nous sommes dans le cas ou le ième ELT du JEU est une CONSTRUCTION
            // PTR contient les informations liées au RESEAU D'EAU
            // On va afficher le contenu de PTR sur la CONSTRUCTION
            sprintf(monJeu.element[i].labelAlimentationElec, "%s\n", ptr);
            if (0) printf("%s\n", ptr);
        }
        // Maintenant on recherche l'index du chemin le plus court entre le
    }
    // Maintenant on met à jour les PARCOURS d'eaux qui sont ACTIFS en renseignant tabParcoursChateauActif[numParcours] = 1 si ACTIF
    int source, destination, dejaVu;
    for(int i = 0; i<MAX_PARCOURS_CENTRALE;i++) {
        // On vérifie si la CONSTRUCTION est bien ALIMENTEE par ce reseau d'eau
        // Pour cela on recupere l'index de la destination du tabParcoursChateau et on regarde si son tabRessource est > 0
        source = monJeu.tabParcoursCentrale[i].source;
        destination = monJeu.tabParcoursCentrale[i].destination;
        if ((-1 == source) || (-1 == destination)) continue;
        dejaVu = 0;
        // On initialise tabParcoursChateauActif[i] = 0;
        //monJeu.tabParcoursChateauActif[i] = 0;
        monJeu.tabParcoursCentrale[i].actif = false;
        if (monJeu.element[destination].tabFournitureRessources[source] >= 0) {
            // On vérifie si un Parcours n'est pas déjà actif pour cette même SOURCE et même DESTINATION
            for(int j = 0; j<i;j++) {
                if (source == monJeu.tabParcoursCentrale[j].source && destination == monJeu.tabParcoursCentrale[j].destination) {
                    // Dans ce cas on a déjà trouvé un PARCOURS pour cette source et destination
                    dejaVu = 1;
                    break;
                }
            }
            if (dejaVu) continue;
            //monJeu.tabParcoursChateauActif[i] = 1;
            monJeu.tabParcoursCentrale[i].actif = true;

        }
    }
}

void actualiseReseauxEaux(){
    // Affiche le statut des alimentations en eau pour chaque CONSTRUCTION
    // Renseigne les tabParcoursChateauActif avec 1 si ACTIF et 0 sinon
    char ptr[LG_LABEL_ALIMENTATION_EAU];
    for (int i=0;i<LG_LABEL_ALIMENTATION_EAU;i++) ptr[i]=0;
    int retour = -1;
    for(int i = 0; i<monJeu.nbElements;i++) {
        // Pour tous les ELT du JEU on écrit dans PTR la QU d'eau reçue de chaque CHATEAU (s'il s'agit d'une CONSTRUCTION
        retour = rechercheReseauxEaux(i, ptr);
        if (-1 != retour) {
            // Nous sommes dans le cas ou le ième ELT du JEU est une CONSTRUCTION
            // PTR contient les informations liées au RESEAU D'EAU
            // On va afficher le contenu de PTR sur la CONSTRUCTION
            sprintf(monJeu.element[i].labelAlimentationEau, "%s\n", ptr);
            if (0) printf("%s\n", ptr);
        }
        // Maintenant on recherche l'index du chemin le plus court entre le
    }
    // Maintenant on met à jour les PARCOURS d'eaux qui sont ACTIFS en renseignant tabParcoursChateauActif[numParcours] = 1 si ACTIF
    int source, destination, dejaVu;
    for(int i = 0; i<MAX_PARCOURS_CHATEAU;i++) {
        // On vérifie si la CONSTRUCTION est bien ALIMENTEE par ce reseau d'eau
        // Pour cela on recupere l'index de la destination du tabParcoursChateau et on regarde si son tabRessource est > 0
        source = monJeu.tabParcoursChateau[i].source;
        destination = monJeu.tabParcoursChateau[i].destination;
        if ((-1 == source) || (-1 == destination)) continue;
        dejaVu = 0;
        // On initialise tabParcoursChateauActif[i] = 0;
        //monJeu.tabParcoursChateauActif[i] = 0;
        monJeu.tabParcoursChateau[i].actif = false;
        if (monJeu.element[destination].tabFournitureRessources[source] >= 0) {
            // On vérifie si un Parcours n'est pas déjà actif pour cette même SOURCE et même DESTINATION
            for(int j = 0; j<i;j++) {
                if (source == monJeu.tabParcoursChateau[j].source && destination == monJeu.tabParcoursChateau[j].destination) {
                    // Dans ce cas on a déjà trouvé un PARCOURS pour cette source et destination
                    dejaVu = 1;
                    break;
                }
            }
            if (dejaVu) continue;
            //monJeu.tabParcoursChateauActif[i] = 1;
            monJeu.tabParcoursChateau[i].actif = true;

        }
    }
    // DEBUG
    int debug = 1;
    if (debug) {
        for (int i = 0; i < MAX_PARCOURS_CHATEAU; i++) {
//            if (monJeu.tabParcoursChateauActif[i]) {
            if (monJeu.tabParcoursChateau[i].actif) {
                if (0) printf("********* Parcours %d ACTIF : ", i);
                //graphique
                //al_draw_filled_rectangle(monJeu.element[i].affichageElement.positionX, monJeu.element[i].affichageElement.positionY, monJeu.element[i].affichageElement.positionX+monJeu.element[i].affichageElement.largeurX, monJeu.element[i].affichageElement.positionY + monJeu.element[i].affichageElement.largeurY, BLANC);
                if (0) afficheParcours(monJeu.tabParcoursChateau[i].indexParcours, monJeu.tabParcoursChateau[i].lgParcours);
            }
        }
    }
}

///////////////////////// FIN JEU.C ////////////////////

///////////////////////// MAIN ////////////////////

int main() {

    /////////////// TEST ///////////////

    initialisationJeu();
/*
    ajouterElement(1,10,8);
    ajouterElement(0,16,8);
    ajouterElement(3,14,8);
    ajouterElement(3,15,8);
    ajouterElement(2,14,4);
    ajouterElement(3,14,7);
    ajouterElement(3,13,14);
    ajouterElement(3,14,14);
    ajouterElement(3,15,14);
    ajouterElement(3,16,14);
    ajouterElement(3,17,14);
    ajouterElement(3,18,14);
    ajouterElement(3,19,14);
    ajouterElement(3,20,14);
    ajouterElement(3,21,14);
    ajouterElement(3,22,14);
    ajouterElement(2,23,14);
    ajouterElement(2,15,15);
*/
    carteDepart();
    carte();

//    majApresEvolutionNiveauConstruction();
//    afficheStatutDesRessourcesParConstruction();

    return 0;


    /////////// FIN TEST //////////////


    initialisationJeu();
    if(TRACE)printf("DEBUT\n");

    test();
    carteDepart();
    carte();
    return 0;


    //ChangerNiveauConstruction(0, 1);
    for(int i = 0; i<monJeu.nbElements;i++){
        if(monJeu.element[i].actif == ACTIF){
            detectionElementsConnectes(i);
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
    actualiseReseauxEaux();
// Libération
//ChangerNiveauConstruction(0, 1);
    if(TRACE)printf("niveau edu de l'école : %d\n", monJeu.element[0].niveauEduElement);
    if(TRACE)printf("niveau global d'édu de la ville : %d\n", monJeu.niveauEducation);
    free (tabCheminParcouru);
    free (route);
    carteDepart();
    carte();
    return 0;
}

///////////////////////// FIN MAIN ////////////////////


