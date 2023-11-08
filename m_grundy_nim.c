
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

	partie_grundy_en_cours = 1; //Lance une partie donc partie_grundy_en_cours se met � 1

	return 1;
}
/*==========================================================*//*==========================================================*/
int declencher_coup_grundy(const t_partieID) {
	
	if (partie_grundy_en_cours || tester_partie_conforme(t_partieID)) //Si il y a une partie en cours, retourne 0 ou que le ID ne correspond pas
	{
		return 0;
	}
	/*D�clancher l'algorithme grundy: 
	
	1- Repr�senter le nb de pi�ces sur chacune des lignes du jeu en binaire dans la ligne corresspondantes d'une matrice d'entiers
	cette matrice est d�finie avec une ligne de plus que le nb de lignes du jeu

	2- Maintenant dans chq case de la derni�re  ligne de la matrice  faites la sommes des valeurs qui viennent au-dessus d'elle dans sa colonne

	3- Si tts les val sur la derni�re ligne de la matrice sont paires, in sera dans une structure paire sinon ce sera une structure impaire

	4-Structure paire et d'un coup valide-> joueur am�ne jeu vers structure impaire

	5-Structure impaire-> joueur a tjrs l'opportunit� de ramener le jeu en structure pair d'un coup valide

	6- Z�ro = structure paire (si adversaire est continuellement en structure paire il ne peut pas gagner) 

	*/ 

	//1
	
}
/*==========================================================*//*==========================================================*/
void terminer_partie_grundy(const t_partieID) {

}
/*==========================================================*//*==========================================================*/