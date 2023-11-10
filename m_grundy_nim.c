
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

	if (partie_grundy_en_cours || strcmp(*sonID, partie_grundy.id_partie)) //Si il y a une partie en cours, retourne 0 ou que le ID ne correspond pas
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
	int tableau_nim_binaire[8] = { 0 }; // Tableau contenant un bit (0 ou 1) qui représente la parité des colonnes respectives de matice_grundy (opération XOR dans chaque colonne)
	int numero_nim = 0; // Nombre résultant de la conversion binaire-décimale du nombre binaire contenu dans tableau_nim_binaire
	int structure_status; // Status de la structure (pair = 0, impaire = 1)
	int nb_jetons_soustraire = 0; // Nombre de jetons à retirer par le coup de grundy

	for (size_t j = 0; j < NB_REP_BINAIRE; j++) // Loop de colonne en colonne
	{
		for (size_t i = 0; i < NB_LIGNES_NIM; i++) // Loop de ligne en ligne
		{
			if (tableau_nim_binaire[j] == 1 && matice_grundy[i][j] == 1) // Regarde si le bit présent dans tableau_addition[j] est 1, si oui et																	  
			{														     // que le bit lu dans matice_grundy[i][j] est aussi 1, on remet le bit à 0
				tableau_nim_binaire[j] = 0;
			}

			tableau_nim_binaire[j] += matice_grundy[i][j]; //sert simplement à mettre le bit à 1
		}

		if (tableau_nim_binaire[j] == 1) // Ce if sert à convertir directement le numéro de nim binaire en décimal
		{
			numero_nim += (int)(pow(2, j));
		}
	}
	if (numero_nim > 0) // Si numero_nim est plus grand que 0, nous somme dans une structure impaire donc structure_status = 1
		                // Sinon la variable structure_status reste 0 et signifie que la structure est pair
	{
		structure_status = 1;
	}
	
	if (structure_status == 0) // Si la structure est pair, déterminer un nombre random de jetons à enlever dans une ligne random du jeu. S'assure aussi que le nombre de jetons est valide
	{
		nb_jetons_soustraire = mt_randi(partie_grundy.jetons_actuel[mt_randi(NB_LIGNES_NIM + 1) - 1]);
	}
	else // Si structure_status n'est pas 0, elle est impaire, et donc le nombre de jetons à enlever est le numéro de nim
	{
		nb_jetons_soustraire = numero_nim;    
	}


	//3
	
/*==========================================================*//*==========================================================*/
void terminer_partie_grundy(const t_partieID) {
	valider_coup_grundy();
	if (partie_grundy_en_cours || strcmp(*sonID, partie_grundy.id_partie)) {
		partie_grundy_en_cours = 0;
	}
}
/*==========================================================*//*==========================================================*/