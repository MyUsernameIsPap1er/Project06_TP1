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

	for (size_t i = 0; i < NB_LIGNES_NIM; ++i)
	{
		dest[i] = mt_randi(NB_JETONS_MAX);
	}
}

/*==========================================================*/
int tester_jeu_conforme(const t_tablo_jeu jeu) {
	int i;
	for (i = 0; i < NB_LIGNES_NIM; i += 1) {
		if (jeu[i] < 0) {
			return 0;
		}
	}
	return 1;
}

/*==========================================================*/
void copier_jeu(const t_tablo_jeu src, t_tablo_jeu dest) {

	for (size_t i = 0; i < NB_LIGNES_NIM; ++i)
	{
		dest[i] = src[i];
	}
}

/*==========================================================*/
int tester_jeux_egaux(const t_tablo_jeu jeu0, const t_tablo_jeu jeu1) {
	int i;
	for (i = 0;i < NB_LIGNES_NIM;i += 1) {
		if (jeu0[i] != jeu1[i]) {
			return 0;
		}
	}
	return 1;
}


/*==========================================================*/
int tester_ordre_jeux(const t_tablo_jeu original, const t_tablo_jeu actuel) {

	if (tester_jeu_conforme(original) || tester_jeu_conforme(actuel))
	{
		return 0;
	}

	for (size_t i = 0; i < NB_LIGNES_NIM; ++i)
	{
		if (actuel[i] > original[i])
		{
			return 0;
		}
	}
	return 1;
}
/*==========================================================*/
int tester_fin_jeu(const t_tablo_jeu jeu) {

	for (size_t i = 0; i < NB_LIGNES_NIM ; i++)
	{
		if (jeu[i] != 0)
		{
			return 0;
		}
	}
	return 1;
}
/*==========================================================*/


	if (partie0->jetons_actuel == partie1->jetons_actuel &&
		partie0->jetons_original == partie1->jetons_original && 
		!(strcmp(partie0->id_partie, partie1->id_partie))) {
		
		return 1;
	}
	return 0;
}
/*==========================================================*/
void copier_partie(const t_partie_infos* src, t_partie_infos* dest) {

	*dest->jetons_actuel = *src->jetons_actuel;
	*dest->jetons_original = *src->jetons_original;
	strcpy(dest, src);
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
	char tampon[4* TAILLE_ID] = { 0 };
	int alea;

	alea = source/100 + mt_randi(source);
	sprintf(tampon, "P%d   %d", ordre, alea);
	tampon[TAILLE_ID-1] = 0;
	strcpy(id_partie, tampon);
	ordre += 1;
}
/*==========================================================*/

// 

/*==========================================================*/


