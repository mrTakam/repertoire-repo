#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repertoire.h"
#include "constantes.h"


void ErreurAllocation(void* structure){
    if (structure == NULL) {
        perror(ERREUR_ALLOCATION);
        exit(EXIT_FAILURE);
    } 
}


void InitialiserRepertoire() {
    Repertoire *repertoire = (Repertoire *)malloc(sizeof(Repertoire));  
    ErreurAllocation(repertoire);
    monRepertoire = repertoire;
}
void LibererRepertoire() { 
    free(monRepertoire); 
}


void Import_CSV() {

  // Ouvrez le fichier en mode lecture
  FILE *FICHIER = fopen(CHEMINFICHIER, "r");
  ErreurAllocation(FICHIER);

  // importation des données
  char ligne[100];
  int num_ligne = 0;

  while (fgets(ligne, sizeof(ligne), FICHIER) != NULL) {
    // Supprimer le caractère de nouvelle ligne s'il est présent
    ligne[strcspn(ligne, "\n")] = '\0';
    // Copie de la ligne pour préservation l'intégrité du fichier
    char ligneCopie[100];    
    
    strcpy(ligneCopie, ligne);
    char *token = strtok(ligneCopie, ",");

    for (int i = 0; i < 5 && token != NULL; ++i) {
        switch (i) {
            case 0: strcpy((char *)monRepertoire->Nom[num_ligne], token); break;
            case 1: strcpy((char *)monRepertoire->Prenom[num_ligne], token); break;
            case 2: strcpy((char *)monRepertoire->Naissance[num_ligne], token); break;
            case 3: strcpy((char *)monRepertoire->Numero[num_ligne], token); break;
            default: strcpy((char *)monRepertoire->Mail[num_ligne], token); break;
        }
        token = strtok(NULL, ",");
    }
    num_ligne++;
  }

  fclose(FICHIER);
}


void InitialiseAffichage() {
  printf(Bordure_Table);
  printf(Table);
  printf(Bordure_Table);
}
void AffichagedeChamps(int num_ligne) {
    printf("| %-20s | %-20s | %.5s | %.12s | %-30s |\n",
           monRepertoire->Nom[num_ligne], monRepertoire->Prenom[num_ligne],
           monRepertoire->Naissance[num_ligne],
           monRepertoire->Numero[num_ligne], monRepertoire->Mail[num_ligne]);           
    printf(Bordure_Table);
}


void SaisieNom(char nomSaisie[]){
    printf("Veuillez saisir un nom :\n");
    scanf("%s", nomSaisie);
    printf("\n");
}


void Saisieligne(char ChampsSaisie[5][30]){
  for(int i = 0; i < 5; i++){
    printf("%s : ", CHAMPS[i]);
    scanf("%s", ChampsSaisie[i]);
    printf("\n");
  }
}
void Formaterligne(char ligne[100]){
    char ChampsSaisie[5][30];
    char separateur[] = ",";

    Saisieligne(ChampsSaisie);  
    strcpy(ligne, ChampsSaisie[0]);

    for(int i =1; i <5; i++){
        strcat(ligne, separateur);
        strcat(ligne, ChampsSaisie[i]);
    }
}


void CreationNouveau_CSV(FILE* nouveaufichier, FILE* ancientfichier){
    char ligne[100];
    int num_ligne = 0;
    char nomSaisie[20];
    
    ErreurAllocation(nouveaufichier);
    ErreurAllocation(ancientfichier);

    SaisieNom(nomSaisie);
    Import_CSV();

    while (fgets(ligne, sizeof(ligne), ancientfichier) != NULL) {
        if (strcmp((char *)monRepertoire->Nom[num_ligne], nomSaisie) != 0) {
            fputs(ligne, nouveaufichier);
        }
        num_ligne++;
    }
}
void SuppressionAncient_CSV(FILE* nouveaufichier, FILE* ancientfichier){
    if (remove(CHEMINFICHIER) != 0) {
        perror("Erreur lors de la suppression du fichier original");
        exit(EXIT_FAILURE);
    }
    if (rename("nouveau.csv", CHEMINFICHIER) != 0) {
        perror("Erreur lors du renommage du nouveau fichier");
        exit(EXIT_FAILURE);
    }
}