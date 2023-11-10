3/*==========================================================*/
/*  aut2023 tp1
	implémentation du module types et constantes du logiciel

	Equipe : Max, Simon, Zied, Nicholas

*/
/*==========================================================*/
/*==========================================================*/

#include "m_controle_nim.h"
/*==========================================================*/

int init_nouvelle_partie(void) {

	if (partie_en_cours == 0) {

		partie_en_cours = 1;
	}
	else {
		return ERREUR;
	}

	get_ID_unique(&partie.id_partie);

	init_jeu_alea(partie.jetons_original);

	if (tester_jeu_conforme(partie.jetons_original))
	{
		return ERREUR;
	}

	copier_jeu(partie.jetons_original, partie.jetons_actuel);

		return 1;
}
	


int jouer_la_partie(void) {
	
	init_nouvelle_partie();


	tour_de = HUMAIN;

	

	while (partie_en_cours)
	{
		

		if (tour_de == HUMAIN)
		{
			if (tester_fin_jeu(partie.jetons_actuel) == 0)
			{
				return GRUNDY;
			}

			init_partie_joueur(partie);

			declencher_coup_joueur(partie_joueur.id_partie, &ligne, &nb_jetons);
			
			valider_coup_joueur(partie_joueur, &ligne, &nb_jetons);

			updater_jeu_joueur(partie_joueur);

			terminer_partie_joueur(partie_joueur.id_partie);

			tour_de = GRUNDY
		}

		if (tour_de == GRUNDY)
		{
			if (tester_fin_jeu(partie.jetons_actuel) == 0)
			{
				return HUMAIN;
			}

			init_partie_grundy(partie);

			declencher_coup_grundy(partie_grundy.id_partie, &ligne, &nb_jetons);

			valider_coup_grundy();

			updater_jeu_grundy(partie_grundy);

			terminer_partie_grundy(partie_grundy.id_partie);

			tour_de = HUMAIN
		}
	}

	

	
}

int valider_coup_joueur(t_partie_infos* partie_joueur, int ligne, int nb_pièce) {
	
	assert(partie_joueur->jetons_actuel[ligne] > nb_pièce);
	assert(ligne < NB_LIGNES_NIM);
	
	modifier_jeu(partie_joueur.jetons_actuel, ligne, nb_jetons);
	
}


int valider_coup_grundy(t_partie_infos* partie_grundy, int ligne, int nb_pièce) {
	assert(partie_grundy->jetons_actuel[ligne] > nb_pièce);
	assert(ligne < NB_LIGNES_NIM);

	
	modifier_jeu(partie_grundy.jetons_actuel, ligne, nb_jetons);	  // Retire le nombre de jetons à la ligne
}

int updater_jeu_joueur(t_partie_infos* partie_joueur) {

	partie.id_partie = partie_joueur->id_partie;
	partie.jetons_actuel= partie_joueur->jetons_actuel;
	partie.jetons_original= partie_joueur->jetons_original
}

int updater_jeu_grundy(t_partie_infos* partie_grundy) {

	partie.id_partie = partie_grundy->id_partie;
	partie.jetons_actuel = partie_grundy->jetons_actuel;
	partie.jetons_original = partie_grundy->jetons_original;
}

void set_nouvelle_partie(t_partie_infos partie) {

	partie.jetons_actuel = { 0 };
	partie.jetons_actuel = { 0 };
	partie.id_partie = { 0 };
}

int tester_partie_conforme(const t_partie_infos* partie) {

	tester_jeu_conforme(partie);
}