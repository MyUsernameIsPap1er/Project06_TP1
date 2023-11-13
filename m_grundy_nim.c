
#include "m_grundy_nim.h"
#include "m_controle_nim.h"

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

	copier_partie(partie, &partie_grundy); //Sinon copie la partie recue dans partie_grundy

	partie_grundy_en_cours = 1; //Lance une partie donc partie_grundy_en_cours se met à 1

	return 1;
}
/*==========================================================*//*==========================================================*/
int declencher_coup_grundy(const t_partieID* sonID, int* ligne, int* nb_jetons) {

	if (partie_grundy_en_cours == 0 || !(strcmp(*sonID, partie_grundy.id_partie))) //Si il y a une partie en cours, retourne 0 ou que le ID ne correspond pas
	{
		return 0;
	}

	updater_jeu_grundy(&partie_grundy);

	//1
	for (size_t i = 0; i < NB_LIGNES_NIM; ++i) // Loop à travers les lignes de l'array de jetons
	{
		int quotient = partie_grundy.jetons_actuel[i]; // Initialisation de "quotient" contenant le nombre de jetons à la position "i" de la partie_grundy

		for (size_t j = 0; j < NB_REP_BINAIRE; ++j) // Loop pour convertir le nombre de jetons en binaire
		{
			noyau_grundy[i][j] = quotient % 2; // Rempli la case avec le modulo de "quotient" (le bit)

			quotient /= 2; // Divise par deux et loop pour continuer la conversion
		}
	}



	//2
	int tableau_nim_binaire[8] = { 0 }; // Tableau contenant un bit (0 ou 1) qui représente la parité des colonnes respectives de matice_grundy (opération XOR dans chaque colonne)
	int numero_nim = 0; // Nombre résultant de la conversion binaire-décimale du nombre binaire contenu dans tableau_nim_binaire

	int structure_status = 0; // Status de la structure (pair = 0, impaire = 1)
	int ligne_coup; // Ligne sur laquelle grundy va jouer
	int nb_jetons_soustraire; // Nombre de jetons à retirer par le coup de grundy

	for (size_t j = 0; j < NB_REP_BINAIRE; j++) // Loop de colonne en colonne
	{
		int compteur = 0; // Pour déterminer la parité de la colonne avec %2 en comptant les bits

		for (size_t i = 0; i < NB_LIGNES_NIM; i++) // Loop de ligne en ligne
		{
			if (noyau_grundy[i][j] == 1) // Regarde si le bit présent dans tableau_addition[j] est 1, si oui et																	  
			{														     // que le bit lu dans matice_grundy[i][j] est aussi 1, on remet le bit à 0
				++compteur;
			}
		}
		if (compteur % 2 == 0)
		{
			tableau_nim_binaire[j] = 0;
		}
		if (compteur % 2 == 1)
		{
			tableau_nim_binaire[j] = 1;
		}
		if (tableau_nim_binaire[j] == 1) // Ce if sert à convertir directement le numéro de nim binaire en décimal
		{
			numero_nim += (int)(pow(2, j));
		}
	}
	if (numero_nim > 0) // Si numero_nim est plus grand que 0, nous somme dans une structure impaire donc structure_status = 1
		// Sinon la variable structure_status reste 0 et signifie que la structure est pair
	{
		structure_status = 1;
	}

	if (structure_status == 0) // Si la structure est pair, retire un nombre random de jetons dans une ligne random du jeu. S'assure aussi que le nombre de jetons à retirer est valide
	{

		ligne_coup = mt_randi(NB_LIGNES_NIM + 1) - 1; // Choisi une ligne entre 0 et 20
		nb_jetons_soustraire = mt_randi(partie_grundy.jetons_actuel[ligne_coup]); // Choisi un nombre de jetons entre 1 et la valeur de jetons présent à la ligne déterminer juste avant


	}
	else
	{
		for (size_t i = 0; i < NB_LIGNES_NIM; i++) // Loop entre les lignes pour trouver la bonne ligne qui supporte la soustraction
		{
			int jetons_post_soustraction = 0;

			for (size_t j = 0; j < NB_REP_BINAIRE; ++j) // Loop entre les colonnes et calcul le nombre de jetons en binaire (en convertissant au fur et a mesure en decimal) qui devrait être
				// sur la ligne pour que la structure soit pair. Ce nombre (jetons_post_soustraction) sera soustrais (SI POSSIBLE, sinon on reloop) au
				// nombre de jetons présent sur la ligne (jeu actuel) ce qui determinera la valeur de nb_jetons_soustraire
			{
				if (noyau_grundy[i][j] != tableau_nim_binaire[j])
				{
					jetons_post_soustraction += (int)(pow(2, j)); // conversion en décimal
				}
			}

			if (partie_grundy.jetons_actuel[i] >= jetons_post_soustraction)
			{
				nb_jetons_soustraire = partie_grundy.jetons_actuel[i] - jetons_post_soustraction;
				ligne_coup = i;
				break;
			}

			nb_jetons_soustraire = 0;
		}
	}



	valider_coup_grundy(&partie_grundy, ligne_coup, nb_jetons_soustraire); // Retire le nombre de jetons à la ligne déterminée


	return 1;
}


/*==========================================================*//*==========================================================*/
void terminer_partie_grundy(const t_partieID* sonID) {
	if (partie_grundy_en_cours || strcmp(*sonID, partie_grundy.id_partie)) {
		partie_grundy_en_cours = 0;
	}
}
/*==========================================================*//*==========================================================*/
