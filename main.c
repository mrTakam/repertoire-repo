#include <stdio.h>
#include "procedures.h"
#include "repertoire.h"

int main(void) {
  int fonctionnalite;

    while (1) {
        InitialiserRepertoire();
        printf("Quevoulezvousfaire:\n");
        printf("*Ajouterunepersonne(1)\n");
        printf("*Afficherlerepertoire(2)\n");
        printf("*Realiserune rechercheparnom(3)\n");
        printf("*Supprimerunepersonneparnom(4)\n");
        printf("*Quitter(5)\n");

        scanf("%d", &fonctionnalite);

        if(fonctionnalite== 1) Creer_Enregistrement();    
        if (fonctionnalite == 2) Affiche_Repertoire();
        if (fonctionnalite == 3) Recherche();
        if(fonctionnalite==4) Supprimer();
        if (fonctionnalite == 5) break;

        LibererRepertoire();
        printf("\n");
        printf("\n");
    }
}


