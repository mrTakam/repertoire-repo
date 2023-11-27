//
// Created by ntope on 12/11/2023.
//

// constantes.h
#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <stdio.h>

#define MAX_LIGNES 40
// Déclaration de la structure de matrice
typedef struct {
    char* Nom[MAX_LIGNES][20];
    char* Prenom[MAX_LIGNES][20];
    char* Naissance[MAX_LIGNES][4];
    char* Numero[MAX_LIGNES][12];
    char* Mail[MAX_LIGNES][30];
} Repertoire;

// Déclaration des constantes
extern Repertoire *monRepertoire;
extern FILE *FICHIER;
extern const char* CHEMINFICHIER;
extern const char MENU_CREER[];
extern const char MENU_AFFICHER[];
extern const char MENU_RECHERCHER[];
extern const char MENU_SUPPRIMER[];
extern const char Table[];
extern const char Bordure_Table[];
extern const char ERREUR_ALLOCATION[];
extern const char ERREUR_FILE[];
extern const char CHAMPS[5][22];

// CONSTANTES_H
#endif