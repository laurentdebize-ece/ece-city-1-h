void ecrireFichierTextePourSauvegarderFichierTexte(char *nomFichier){
    FILE *ifs = fopen(nomFichier, "w+");
    int tailleFichier = 0;
    if (!ifs) {
        printf("Erreur de lecture fichier\n");
    }
    for(int i = 0; i< 45 ; i++){
        for(int j = 0; j< 45;j++){
            if(monJeu.tabTXT[i][j] == ROUTE ){
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
            }
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
