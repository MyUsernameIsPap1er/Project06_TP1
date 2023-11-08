
#include "m_grundy_nim.h"

/*==========================================================*//*==========================================================*/
int get_partie_grundy_en_cours(void) {

	if (partie_grundy_en_cours) //Regarde si partie_grundy_en_cours vaut 1
	{
		return 1; //si oui
	}
	return 0; //si non
}
/*==========================================================*//*==========================================================*/
int init_partie_grundy(const t_partie_infos* partie) {

	if (partie_grundy_en_cours) //Si il y a une partie en cours, retourne 0
	{
		return 0;
	}

	copier_partie(partie, partie_grundy); //Sinon copie la partie recue dans partie_grundy

	partie_grundy_en_cours = 1; //Lance une partie donc partie_grundy_en_cours se met à 1

	return 1;
}
/*==========================================================*//*==========================================================*/
int declencher_coup_grundy(const t_partieID) {
	
	if (partie_grundy_en_cours || tester_partie_conforme(t_partieID)) //Si il y a une partie en cours, retourne 0 ou que le ID ne correspond pas
	{
		return 0;
	}

	/*Déclancher l'algorithme grundy: 
	
	1- Représenter le nb de pièces sur chacune des lignes du jeu en binaire dans la ligne corresspondantes d'une matrice d'entiers
	cette matrice est définie avec une ligne de plus que le nb de lignes du jeu

	2- Maintenant dans chq case de la dernière  ligne de la matrice  faites la sommes des valeurs qui viennent au-dessus d'elle dans sa colonne

	3- Si tts les val sur la dernière ligne de la matrice sont paires, in sera dans une structure paire sinon ce sera une structure impaire

	4-Structure paire et d'un coup valide-> joueur amène jeu vers structure impaire

	5-Structure impaire-> joueur a tjrs l'opportunité de ramener le jeu en structure pair d'un coup valide

	6- Zéro = structure paire (si adversaire est continuellement en structure paire il ne peut pas gagner) 

	*/ 

	//1
	for (size_t i = 0; i < NB_LIGNES_NIM; ++i) // Loop à travers les lignes de l'array de jetons
	{
		int quotient = partie_grundy.jetons_actuel[i]; // Initialisation de "quotient" contenant le nombre de jetons à la position "i" de la partie_grundy

		for (size_t j = 0; j < NB_REP_BINAIRE; ++j) // Loop pour convertir le nombre de jetons en binaire
		{
			matice_grundy[i][j] = quotient % 2; // Rempli la case avec le modulo de "quotient" (le bit)

			quotient /= 2; // Divise par deux et loop pour continuer la conversion
		}
	}

	//2
	int tableau_addition[8] = { 0 }; // Tableau contenant les additions des bits, rempli avec des 0

	for (size_t j = 0; j < NB_REP_BINAIRE; j++) // Loop dans les colonnes
	{
		for (size_t i = 0; i < NB_LIGNES_NIM; i++) //Loop dans les lignes
		{
			tableau_addition[j] += matice_grundy[i][j]; //enregistre l'addition de tous les bits d'une colonne
		}
	}

	//3
	int addition_tablo_add = 0;
	for (size_t j = 0; j < NB_REP_BINAIRE; j++) //loop dans les colonnes pour permettre la lecture de ceux-ci
	{
		addition_tablo_add += tableau_addition[j]; // additionne les valeurs du tableau d'addition
	}
	if (addition_tablo_add % 2 == 0) {  //si résultat de l'addition est pair->structure pair sinon impair
		... 
	}
}
/*==========================================================*//*==========================================================*/
void terminer_partie_grundy(const t_partieID) {

}
/*==========================================================*//*==========================================================*/