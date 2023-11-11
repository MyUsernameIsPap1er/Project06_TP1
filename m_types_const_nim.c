/*==========================================================*/
/*  aut2023 tp1
	implémentation du module types et constantes du logiciel

	Equipe :

*/
/*==========================================================*/
/*==========================================================*/

#include "m_types_const_nim.h"
/*==========================================================*/

/* VOUS AVEZ 10 FONCTIONS PUBLIQUES À DÉFINIR ET À TESTER */
/* VASTE PROGRAMME   */




/*==========================================================*/
void init_jeu_alea(t_tablo_jeu dest) {

	for (size_t i = 0; i < NB_LIGNES_NIM; ++i) //Traverse le tableau
	{
		dest[i] = (int)mt_randf(NB_JETONS_MIN, NB_JETONS_MAX); // Remplie chaque case avec un nombre aléatoire
	}
}

/*==========================================================*/
int tester_jeu_conforme(const t_tablo_jeu jeu) {

	for (int i = 0; i < NB_LIGNES_NIM; ++i) {

		if (jeu[i] < 0 || jeu[i] > NB_JETONS_MAX) { // regarde si chaque valeur vaut plus que 0

			return 0; // retourne 0 si non
		}
	}


	return 1; // retourne 1 si oui
}

/*==========================================================*/
void copier_jeu(const t_tablo_jeu src, t_tablo_jeu dest) {

	for (size_t i = 0; i < NB_LIGNES_NIM; ++i) //Traverse le tableau
	{
		dest[i] = src[i]; //copie chaque valeur de src dans dest
	}
}

/*==========================================================*/
int tester_jeux_egaux(const t_tablo_jeu jeu0, const t_tablo_jeu jeu1) {

	for (int i = 0; i < NB_LIGNES_NIM; i += 1) { //Traverse le tableau

		if (jeu0[i] != jeu1[i]) { //Regarde si les valeurs entre jeu0 et jeu1 sont les mêmes

			return 0; //Retourne 0 si non
		}
	}

	return 1; //Retourne 1 si oui
}


/*==========================================================*/
int tester_ordre_jeux(const t_tablo_jeu original, const t_tablo_jeu actuel) {

	if (tester_jeu_conforme(original) || tester_jeu_conforme(actuel)) //Teste si chacun des jeux sont conformes
	{
		return 0; //Retourne 0 si ils ne le sont pas
	}

	for (size_t i = 0; i < NB_LIGNES_NIM; ++i) //Traverse les tableaux
	{
		if (actuel[i] > original[i]) //Regarde si chaques valeurs du jeu actuel sont plus grandes que celles du jeu originale
		{
			return 0; //Retourne 0 dès qu'une des valeurs est plus grande
		}
	}
	return 1; //Retourne 1 si elles sont toutes plus petites
}
/*==========================================================*/
int tester_fin_jeu(const t_tablo_jeu jeu) {

	for (size_t i = 0; i < NB_LIGNES_NIM; i++) //Traverse le tableau
	{
		if (jeu[i] != 0) //Regarde si toutes les valeurs du jeu sont 0 (fin du jeu)
		{
			return 0; //Retourne 0 si l'une d'elle ne l'est pas
		}
	}
	return 1; //Retourne 1 si tous est 0
}
/*==========================================================*/
int modifier_jeu(t_tablo_jeu jeu, int ligne, int nb_jetons) {

	if (nb_jetons <= jeu[ligne]) //S'assure que le nombre de jetons à retirer est plus petit que le nombre de jeton disponible
	{
		jeu[ligne] -= nb_jetons; //Soustrais les jetons
		return 1; //Retourne 1 si la soustraction est survenu
	}
	return 0; //Retourne 0 si la soustraction n'est pas possible
}
/*==========================================================*/
int parties_egales(const t_partie_infos* partie0, const t_partie_infos* partie1) {

	if (partie0->jetons_actuel == partie1->jetons_actuel &&
		partie0->jetons_original == partie1->jetons_original &&
		!(strcmp(partie0->id_partie, partie1->id_partie))) { //S'assure que toute les variables de chaque tableau sont les mêmes.

		return 1; //Retourne 1 si elles le sont
	}
	return 0; //Retourne 0 si elles ne le sont pas
}
/*==========================================================*/
void copier_partie(const t_partie_infos* src, t_partie_infos* dest) {

	//Copie des valeurs de src dans dest

	for (size_t i = 0; i < NB_LIGNES_NIM; ++i)
	{
		dest->jetons_actuel[i] = src->jetons_actuel[i];
		dest->jetons_original[i] = src->jetons_original[i];
	}
	strcpy(dest->id_partie, src->id_partie);
}
/*==========================================================*/
/*==========================================================*/
/*==========================================================*/
/*==========================================================*/
/*==========================================================*/
/*==========================================================*/
/*==========================================================*/
/*==========================================================*/
/*
  la fonction emettrice des id de partie vous est offerte
  VOUS NE DEVEZ PAS LA MODIFIER

  meme pleine de "magic numbers"
  ce qui est pas beau
  vous ne devez pas la modifier
*/

void get_ID_unique(t_partieID id_partie) {
	const int source = 981 * 8377;
	static ordre = 1;
	char tampon[4 * TAILLE_ID] = { 0 };
	int alea;

	alea = source / 100 + mt_randi(source);
	sprintf(tampon, "P%d   %d", ordre, alea);
	tampon[TAILLE_ID - 1] = 0;
	strcpy(id_partie, tampon);
	ordre += 1;
}
/*==========================================================*/

// 

/*==========================================================*/


