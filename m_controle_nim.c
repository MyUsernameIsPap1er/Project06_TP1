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
		return 0;
	}

	get_ID_unique(&partie.id_partie);

	init_jeu_alea(partie.jetons_original);
	copier_jeu(partie.jetons_original, partie.jetons_actuel);


	return 1;
}

int jouer_la_partie(void) {
	
	init_nouvelle_partie();
	init_partie_joueur(partie);
	init_partie_grundy(partie);

	tour_de = HUMAIN;

	int ligne;
	int nb_jetons;

	while (partie_en_cours)
	{

		if (tour_de == HUMAIN)
		{
			updater_jeu_joueur(partie_joueur);

			declencher_coup_joueur(partie_joueur.id_partie, &ligne, &nb_jetons);
			
			valider_coup_joueur(partie_joueur.id_partie, &ligne, &nb_jetons);

			terminer_partie_joueur(partie_joueur.id_partie);

		}

		if (tour_de == GRUNDY)
		{

			updater_jeu_grundy(partie_grundy);

			declencher_coup_grundy(partie_grundy.id_partie, &ligne, &nb_jetons);

			valider_coup_grundy();

			terminer_partie_grundy(partie_grundy.id_partie);
		}
	}

	

	
}

int valider_coup_joueur(t_partie_infos* partie_joueur, int ligne, int nb_pièce) {

	
}


int valider_coup_grundy(t_partie_infos* partie_grundy, int ligne, int nb_pièce) {

	  // Retire le nombre de jetons à la ligne
}

int updater_jeu_joueur(t_partie_infos* partie_joueur) {


}

int updater_jeu_grundy(t_partie_infos* partie_grundy) {

}

void set_nouvelle_partie(t_partie_infos partie) {

	partie.jetons_actuel = { 0 };
	partie.jetons_actuel = { 0 };
	partie.id_partie = { 0 };
}

int tester_partie_conforme(const t_partie_infos* partie) {

	tester_jeu_conforme(partie);
}