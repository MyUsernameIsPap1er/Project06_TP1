#include "m_joueur_nim.h"
int get_partie_joueur_en_cours(void) {

}

int init_partie_joueur(const t_partie_infos* partie) { //recoie info de la partie initialise

	if (partie_joueur_en_cours) { //observe si il y a partie en cour
		return 0; // si oui retourne 0
	}
	partie_joueur = partie; // si non copie info dans partie_joueur et set partie_en_cours a 1
	partie_joueur_en_cours = 1;

	return 1; // success de init retourne 1///
}

int declencher_coup_joueur(const t_partieID) {

}

void terminer_partie_joueur(const t_partieID) {

}