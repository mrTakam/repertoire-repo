#include <string.h>
#include "repertoire.h"
#include "procedures.h"
#include "constantes.h"


void Affiche_Repertoire() {
    char ligne[100];
    int num_ligne = 0;
      

    Import_CSV();
    InitialiseAffichage();
    FICHIER = fopen(CHEMINFICHIER, "r");
    while (fgets(ligne, sizeof(ligne), FICHIER) != NULL) {
        AffichagedeChamps(num_ligne);
        num_ligne++;
    }

    fclose(FICHIER);
}

void Recherche() {    
    char ligne[100];
    int num_ligne = 0;
    char nomSaisie[20];

    SaisieNom(nomSaisie);
    InitialiseAffichage();

    Import_CSV();
    FICHIER = fopen(CHEMINFICHIER, "r");
    while (fgets(ligne, sizeof(ligne), FICHIER) != NULL) {
        if (strcmp((char*) monRepertoire->Nom[num_ligne], nomSaisie) == 0) {
            AffichagedeChamps(num_ligne);
        }   
        num_ligne++;     
    }

    fclose(FICHIER);
}

void Creer_Enregistrement(){
    char ligne[100];
    FICHIER = fopen(CHEMINFICHIER, "a"); 
    ErreurAllocation(FICHIER); 
    Formaterligne(ligne);
    fprintf(FICHIER, "%s", ligne);
    fclose(FICHIER);
}


void Supprimer(){
    FILE* nouveaufichier = fopen("nouveau.csv", "w");
    FILE* ancientfichier = fopen(CHEMINFICHIER, "r");
    CreationNouveau_CSV(nouveaufichier, ancientfichier);    
    fclose(ancientfichier);
    fclose(nouveaufichier);
    SuppressionAncient_CSV(nouveaufichier, ancientfichier);
}