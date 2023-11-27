#include "constantes.h"

Repertoire *monRepertoire;
FILE* FICHIER;

// Déclaration des constantes
const char* CHEMINFICHIER = "repertoire.csv";
const char MENU_CREER[] = "/*--------------------   Crer Enregistrement  ---------------------*/\n\n";
const char MENU_AFFICHER[] = "/*--------------------   Affiche répertoire  ---------------------*/\n\n";
const char MENU_RECHERCHER[] = "/*--------------------   Recherche  ---------------------*/\n\n";
const char MENU_SUPPRIMER[] = "/*--------------------   Supprimer  ---------------------*/\n\n";
const char Table[] =    "| Nom                  | Prenom               | Ann  | Numéro       | Mail                           |\n";
const char Bordure_Table[] = "+----------------------+----------------------+------+--------------+--------------------------------+\n";
const char ERREUR_ALLOCATION[] = "Erreur d'allocation mémoire pour la matrice";
const char ERREUR_FILE[] = "Erreur lors de l'ouverture du fichier";
const char CHAMPS[5][22] = {"Nom", "Prenom", "Anne de naissance", "Numéro de téléphone", "Mail"};