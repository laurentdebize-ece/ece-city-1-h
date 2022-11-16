#include "affichage.h"
#define ECE_CITY_1_H_AFFICHAGE_H
void affichage(Case tabCase[LIGNES_TAB][COLONNES_TAB],int tabTXT[LIGNES_TAB][COLONNES_TAB + 1],Image image,int ligneSouris,int colonneSouris) {

    //al_clear_to_color(al_map_rgb(159,232,85));
    al_clear_to_color(al_map_rgb(255,255,255));

    //FOND :
    //al_draw_scaled_bitmap(image.fond,0,0,356,304,0,0,ECRAN_LONGUEUR,ECRAN_LARGEUR,0);

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
                al_draw_scaled_bitmap(image.chateaudeau,0,0,512,512,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,2*TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 8) {
                al_draw_scaled_bitmap(image.centraleelec,0,0,512,512,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,2*TAILLE_CASE,0);
            }
            if (tabTXT[i][j] == 9) {
                al_draw_scaled_bitmap(image.caserne,0,0,512,512,tabCase[i][j].x,tabCase[i][j].y,2*TAILLE_CASE,2*TAILLE_CASE,0);
            }
        }
    }
    //SOURIS :
    al_draw_filled_rectangle(tabCase[ligneSouris][colonneSouris].x+3,tabCase[ligneSouris][colonneSouris].y+3,
                             tabCase[ligneSouris][colonneSouris].x+TAILLE_CASE-4,tabCase[ligneSouris][colonneSouris].y+TAILLE_CASE-4,
                             al_map_rgba(20,20,20,200));

    al_flip_display();
}


void cartetest(){

}

void toto() {
    bool end = false;
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

    image.chateaudeau = al_load_bitmap("../images/chateau d'eau.png");
    image.centraleelec = al_load_bitmap("../images/centrale électrique.png");
    image.caserne = al_load_bitmap("../images/caserne.png");
    image.routehb = al_load_bitmap("../images/route hb.png");
    image.routegd = al_load_bitmap("../images/route gd.png");
    image.routehd = al_load_bitmap("../images/route dh.png");
    image.routehg = al_load_bitmap("../images/route gh.png");
    image.routebd = al_load_bitmap("../images/route db.png");
    image.routebg = al_load_bitmap("../images/route gb.png");
    image.fond = al_load_bitmap("../images/fond 3.png");

    file = fopen("../test.txt","r");
    for (int i = 0; i < LIGNES_TAB; ++i) {
        for (int j = 0; j < COLONNES_TAB + 1; ++j) {
            tabTXT[i][j] = fgetc(file) - '0';
        }
    }
    fclose(file);
    for (int i = 0; i < LIGNES_TAB; ++i) {
        for (int j = 0; j < COLONNES_TAB + 1; ++j) {
            printf("%d ",tabTXT[i][j]);
        }
        printf("\n");
    }

    al_clear_to_color(al_map_rgb(255,255,255));
    al_flip_display();

    al_start_timer(timer);

    while (!end) {
        al_wait_for_event(queue,&event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                end = true;
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
                printf("%d,%d\n",ligneSouris,colonneSouris);
                break;

            case ALLEGRO_EVENT_TIMER:
                affichage(tabCase,tabTXT,image,ligneSouris,colonneSouris);
                break;
        }
    }
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
}