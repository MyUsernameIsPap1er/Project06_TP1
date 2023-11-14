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
				printf("\033[7;31m\n\nVous avez perdu!\n\n\033[0m");
				system("PAUSE");
				break;
			}

			//=============================================================================================//
			//  Fonctions qui assure le coup du joueur
			//=============================================================================================//

			init_partie_joueur(&partie); // Initialise la partie du joueur, copie les infos de la partie dans partie_joueur

			declencher_coup_joueur(partie_joueur.id_partie, &ligne_modif, &nb_jetons_pris, &nb_coups_adate); // Permet au joueur d'effectuer son coup (Interface, validation et update de la partie)

			terminer_partie_joueur(partie_joueur.id_partie); // Termine le coup du joueur

			++nb_coups_adate; // Compte le tour

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
			//  Fonctions qui assure le coup de grundy
			//=============================================================================================//

			init_partie_grundy(&partie); // Initialise la partie de grundi, copie les infos de la partie dans partie_grundy

			declencher_coup_grundy(&partie, partie_grundy.id_partie, &ligne_modif, &nb_jetons_pris); // Effectue le coup (valide et update la partie)

			tester_partie_conforme(&partie); // Tester si la partie est conforme

			terminer_partie_grundy(partie_grundy.id_partie); // Termine le coup de grundy

			++nb_coups_adate; // Compte le tour

			tour_de = HUMAIN; // Change le tour
		}
	}

	set_nouvelle_partie(); // Permet la création d'une nouvelle partie après que la partie soit fini

	return 1;
}

int valider_coup_joueur(t_partie_infos* partie_joueur, int ligne, int nb_jetons) {

	

	ligne -= 1; // Pour shifter de 0 à 1 pour la selection dans la matrice

	modifier_jeu(partie_joueur->jetons_actuel, ligne, nb_jetons);	  // Retire le nombre de jetons à la ligne
	copier_partie(partie_joueur, &partie);
}


int valider_coup_grundy(t_partie_infos* partie_grundy, int ligne, int nb_jetons) {


	modifier_jeu(partie_grundy->jetons_actuel, ligne, nb_jetons);	  // Retire le nombre de jetons à la ligne
	

	ligne_modif = ligne;
	nb_jetons_pris = nb_jetons;

}

int updater_jeu_joueur(t_partie_infos* partie_joueur) {

	copier_partie(partie_joueur, &partie);
}

int updater_jeu_grundy(t_partie_infos* partie_grundy) {

	copier_partie(partie_grundy, &partie);
}

void set_nouvelle_partie(void) {

	cls();

	int reponse;
	int demande = 1;
	while (demande)
	{

		printf("\n\n\n Voulez rejouer une nouvelle partie? \n1 pour Oui\n2 pour Non ");
		scanf("%d", &reponse);

		if (reponse == 1) // Si oui est saisie, création d'une nouvelle partie
		{
			jouer_la_partie();
		}
		if (reponse == 2)
		{
			demande = 0;
			printf("Fermeture du programme...");
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
// Des petits asserts au besoin :)
void test_assert_ctrl(void){
assert(0 >= ligne_modif <= NB_LIGNES_NIM);
assert(NB_JETONS_MIN >= nb_jetons_pris <= NB_JETONS_MAX);
assert(ligne_jeu >= 0);
}
