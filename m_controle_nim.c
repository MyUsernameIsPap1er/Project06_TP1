/*==========================================================*/
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

	init_jeu_alea(partie.jetons_original);

	
}

int jouer_la_partie(void) {


}

int valider_coup_joueur(t_partie_infos* partie_joueur, int ligne, int nb_pièce) {

	}
}


int valider_coup_grundy(t_partie_infos* partie_grundy, int ligne, int nb_pièce) {

}

int updater_jeu_joueur(t_partie_infos* partie_joueur) {

}

int updater_jeu_grundy(t_partie_infos* partie_grundy) {

}

void set_nouvelle_partie() {

}