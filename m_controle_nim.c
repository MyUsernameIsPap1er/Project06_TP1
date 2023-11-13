/*==========================================================*/
/*  aut2023 tp1
	implémentation du module types et constantes du logiciel

	Equipe : Max, Simon, Zied, Nicholas

*/
/*==========================================================*/
/*==========================================================*/

#include "m_controle_nim.h"
#include "m_grundy_nim.h"
#include "m_joueur_nim.h"

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

	if (!(tester_jeu_conforme(partie.jetons_original)))
	{
		return ERREUR;
	}

	copier_jeu(partie.jetons_original, partie.jetons_actuel);

	return 1;
}



int jouer_la_partie(void) {

	init_nouvelle_partie(); // On initialise la partie

	if (mt_randi(2) > 1) // Choisi pseudo-aléatoirement le premier joueur
	{
		tour_de = GRUNDY;
	}
	else
	{
		tour_de = HUMAIN;
	}

	while (partie_en_cours)
	{

		if (tour_de == HUMAIN)
		{
			if (tester_fin_jeu(partie.jetons_actuel)) //Test la fin du jeu à chaque tour
			{
				partie_en_cours = 0;
				printf("Vous avez perdu!\n\n");
				system("PAUSE");
				break;
			}

			//=============================================================================================//
			//Fonctions qui assure le coup du joueur
			//=============================================================================================//

			init_partie_joueur(&partie);

			declencher_coup_joueur(partie_joueur.id_partie, &ligne_modif, &nb_jetons_pris, &nb_coups_adate);

			terminer_partie_joueur(partie_joueur.id_partie);

			++nb_coups_adate; // Incrémente les tours

			tour_de = GRUNDY; // Change le tour
		}

		if (tour_de == GRUNDY)
		{
			if (tester_fin_jeu(partie.jetons_actuel)) //Test la fin du jeu à chaque tour
			{
				partie_en_cours = 0;
				printf("Vous avez gagner la partie!\n\n");
				system("PAUSE");
				break;
			}

			//=============================================================================================//
			//Fonctions qui assure le coup de grundy
			//=============================================================================================//

			init_partie_grundy(&partie); 

			declencher_coup_grundy(&partie, partie_grundy.id_partie, &ligne_modif, &nb_jetons_pris);

			terminer_partie_grundy(partie_grundy.id_partie);

			++nb_coups_adate; // Incrémente les tours

			tour_de = HUMAIN; // Change le tour
		}
	}

	set_nouvelle_partie(); // Permet la création d'une nouvelle partie après que la partie soit fini

	return 1;
}

int valider_coup_joueur(t_partie_infos* partie_joueur, int ligne, int nb_jetons) {

	//assert(partie_joueur->jetons_actuel[ligne] < nb_jetons);
	//assert(ligne > NB_LIGNES_NIM);
	//assert(ligne <= 0);

	ligne -= 1; // Pour shifter de 0 à 1 pour la selection dans la matrice

	modifier_jeu(partie_joueur->jetons_actuel, ligne, nb_jetons);	  // Retire le nombre de jetons à la ligne
	copier_partie(partie_joueur, &partie);
}


int valider_coup_grundy(t_partie_infos* partie_grundy, int ligne, int nb_jetons) {

	//assert(partie_grundy->jetons_actuel[ligne] > nb_jeton);
	//assert(ligne < NB_LIGNES_NIM);	
	modifier_jeu(partie_grundy->jetons_actuel, ligne, nb_jetons);	  // Retire le nombre de jetons à la ligne
	copier_partie(partie_grundy, &partie);

	ligne_modif = ligne;
	nb_jetons_pris = nb_jetons;

}

int updater_jeu_joueur(t_partie_infos* partie_joueur) {

	copier_partie(&partie, partie_joueur);
}

int updater_jeu_grundy(t_partie_infos* partie_grundy) {

	copier_partie(&partie, partie_grundy);
}

void set_nouvelle_partie(void) {

	cls();

	char non[] = "non";
	char Non[] = "Non";
	char oui[] = "oui";
	char Oui[] = "Oui";
	char reponse[3];
	int demande = 1;
	while (demande)
	{

		printf("\n\n\n Voulez rejouer une nouvelle partie? (Oui/Non) : ");
		scanf("%s", &reponse);

		if (strcmp(oui, reponse) == 0 || strcmp(Oui, reponse) == 0) // Si oui est saisie, création d'une nouvelle partie
		{
			jouer_la_partie();
		}
		if (strcmp(non, reponse) == 0 || strcmp(Non, reponse) == 0)
		{
			demande = 0;
			break;
		}
		else
		{
			printf("ERREUR : saisissez oui ou non");
		}
	}

	return 1;
}

int tester_partie_conforme(const t_partie_infos* partie) {

	tester_jeu_conforme(partie);
}