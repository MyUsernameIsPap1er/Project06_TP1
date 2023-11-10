//=========================================================
// 	hs pour le tp1 A2023
//  les deux fonctions simulacres de coup du joueur et de grundy

// j'ai différé les traitements vous verrez 
// suffit de lire les courts commentaires
//=========================================================

/*==========================================================*/
/*==========================================================*/

#include "m_types_const_nim.h"
/*==========================================================*/

/*=========================================================*/
/* chercher la premiere case non vide a partir d'une position 
  aleatoire dans le jeu actuel de la partie pour y prendre un jeton */

int determiner_coup_grundy(const t_partie_infos* partie, int* lig, int* nb);


int determiner_coup_grundy(const t_partie_infos* partie, int* lig, int* nb) {
	int i, ligne;
	//le decalage alea
	int decal = mt_randi(NB_LIGNES_NIM);

	for (i = 0; i < NB_LIGNES_NIM; ++i) {

		ligne = (i + decal) % NB_LIGNES_NIM;
		if (partie->jetons_actuel[ligne] > 0) {
			*lig = ligne;
			*nb = 1;
			return 1;
		}
	}
	// si y'a plus de jetons dans le jeu
	return 0;
}
/*=========================================================*/
/*=========================================================*/
/* chercher la premiere case non vide a partir de la fin du jeu
  actuel de la partie pour y prendre tous les jetons  */
int determiner_coup_joueur(const t_partie_infos* partie, int* lig, int* nb);


int determiner_coup_joueur(const t_partie_infos* partie, int* lig, int* nb) {
	int i;

	for (i = NB_LIGNES_NIM - 1; i > -1; --i) {
		if (partie->jetons_actuel[i] > 0) {
			*lig = i;
			*nb = partie->jetons_actuel[i];
			return 1;
		}
	}
	// si y'a plus de jetons dans le jeu
	return 0;
}
/*=========================================================*/

/*=========================================================*/
// j'ajoute une fonction simple d'affichage d'un tablo de jeu
void afficher_tablo_jeu(const t_tablo_jeu jeu);

void afficher_tablo_jeu( const t_tablo_jeu jeu) {
	int i;
	printf("\n un tableau jeu  \n");
	for (i = 0; i < NB_LIGNES_NIM; ++i) {
		printf("%3d", jeu[i]);
	}
	printf("\n");
}
/*=========================================================*/

/*=========================================================*/
#if 1
int main(void) {
	int i;
	int ligne, nombre;

	t_partie_infos partie_test;

	mt_srandSys();

	// inutile ici mais je le donne un ID
	get_ID_unique(partie_test.id_partie);

	// je remplis le jeu actuel et je l'affiche
	for (i = 0; i < NB_LIGNES_NIM; ++i) {
		partie_test.jetons_actuel[i] = NB_JETONS_MIN + mt_randi(6);

	}
	afficher_tablo_jeu(partie_test.jetons_actuel);


	// determiner un coup de grundy et si oui :)
	if (determiner_coup_grundy(&partie_test, &ligne, &nombre)) {
		// je le joue... dans le logiciel, c'est interdit je le sais 
		partie_test.jetons_actuel[ligne] -= nombre;
		// j'affiche, on verra le changement 
		afficher_tablo_jeu(partie_test.jetons_actuel);
	}
	// determiner un coup du joueur et si oui :)
	if (determiner_coup_joueur(&partie_test, &ligne, &nombre)) {
		// je le joue... dans le logiciel, c'est interdit je le sais 
		partie_test.jetons_actuel[ligne] -= nombre;
		// j'affiche, on verra le changement 
		afficher_tablo_jeu(partie_test.jetons_actuel);
	}

	system("pause");
	return EXIT_SUCCESS;
}
#endif
//=========================================================











