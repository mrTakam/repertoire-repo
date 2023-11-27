//
// Created by ntope on 12/11/2023.
//
#pragma

// champs.h
#ifndef REPERTOIRE_H
#define REPERTOIRE_H
#include <stdio.h>



/**
 * @brief Affiche un message d'erreur en cas d'échec d'allocation mémoire.
 *
 * Cette fonction est utilisée pour afficher un message d'erreur en cas d'échec d'allocation
 * mémoire pour une structure dynamique.
 *
 * @param structure Un pointeur vers la structure qui n'a pas pu être allouée.
 * @return void
 */
void ErreurAllocation(void* structure);

/**
 * @brief Initialise le répertoire.
 *
 * Cette fonction initialise le répertoire en effectuant toutes les opérations nécessaires
 * pour commencer à travailler avec un répertoire vide.
 *
 * @param void
 * @return void
 */
void InitialiserRepertoire();

/**
 * @brief Libère les ressources utilisées par le répertoire.
 *
 * Cette fonction libère toutes les ressources (mémoire, fichiers, etc.) utilisées par le répertoire.
 *
 * @param void
 * @return void
 */
void LibererRepertoire();

/**
 * @brief Importe les données d'un fichier CSV dans le répertoire.
 *
 * Cette fonction importe les données d'un fichier CSV existant dans le répertoire.
 *
 * @param void
 * @return void
 */
void Import_CSV();

/**
 * @brief Initialise l'affichage du répertoire.
 *
 * Cette fonction initialise l'affichage du répertoire, préparant l'affichage des champs et des données.
 *
 * @param void
 * @return void
 */
void InitialiseAffichage();

/**
 * @brief Affiche les champs de la ligne spécifiée.
 *
 * Cette fonction affiche les champs de la ligne spécifiée du répertoire.
 *
 * @param num_ligne Le numéro de la ligne à afficher.
 * @return void
 */
void AffichagedeChamps(int num_ligne);

/**
 * @brief Saisie le nom de l'utilisateur.
 *
 * Cette fonction permet à l'utilisateur de saisir un nom.
 *
 * @param nomSaisie Le tableau où le nom saisi sera stocké.
 * @return void
 */
void SaisieNom(char nomSaisie[]);

/**
 * @brief Saisie les champs de la ligne.
 *
 * Cette fonction permet à l'utilisateur de saisir les champs d'une ligne du répertoire.
 *
 * @param ChampsSaisie Un tableau 2D pour stocker les champs saisis.
 * @return void
 */
void Saisieligne(char ChampsSaisie[5][30]);

/**
 * @brief Formate la ligne spécifiée.
 *
 * Cette fonction formate la ligne spécifiée pour être stockée dans le fichier CSV.
 *
 * @param ligne La ligne à formater.
 * @return void
 */
void Formaterligne(char ligne[100]);

/**
 * @brief Crée un nouveau fichier CSV à partir de l'ancien.
 *
 * Cette fonction crée un nouveau fichier CSV à partir de l'ancien, en effectuant des opérations spécifiques.
 *
 * @param nouveaufichier Le fichier CSV qui sera créé.
 * @param ancientfichier L'ancien fichier CSV.
 * @return void
 */
void CreationNouveau_CSV(FILE* nouveaufichier, FILE* ancientfichier);

/**
 * @brief Supprime l'ancien fichier CSV.
 *
 * Cette fonction supprime l'ancien fichier CSV après la création du nouveau fichier.
 *
 * @param nouveaufichier Le nouveau fichier CSV.
 * @param ancientfichier L'ancien fichier CSV.
 * @return void
 */
void SuppressionAncient_CSV(FILE* nouveaufichier, FILE* ancientfichier);


// REPERTOIRE_H
#endif