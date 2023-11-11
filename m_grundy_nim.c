
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

	partie_grundy_en_cours = 1; //Lance une partie donc partie_grundy_en_cours se met � 1

	return 1;
}
/*==========================================================*//*==========================================================*/
int declencher_coup_grundy(const t_partieID* sonID, int* ligne, int* nb_jetons) {

	if (partie_grundy_en_cours || strcmp(*sonID, partie_grundy.id_partie)) //Si il y a une partie en cours, retourne 0 ou que le ID ne correspond pas
	{
		return 0;
	}



	//1
	for (size_t i = 0; i < NB_LIGNES_NIM; ++i) // Loop � travers les lignes de l'array de jetons
	{
		int quotient = partie_grundy.jetons_actuel[i]; // Initialisation de "quotient" contenant le nombre de jetons � la position "i" de la partie_grundy

		for (size_t j = 0; j < NB_REP_BINAIRE; ++j) // Loop pour convertir le nombre de jetons en binaire
		{
			noyau_grundy[i][j] = quotient % 2; // Rempli la case avec le modulo de "quotient" (le bit)

			quotient /= 2; // Divise par deux et loop pour continuer la conversion
		}
	}

	//2
	int tableau_nim_binaire[8] = { 0 }; // Tableau contenant un bit (0 ou 1) qui repr�sente la parit� des colonnes respectives de matice_grundy (op�ration XOR dans chaque colonne)
	int numero_nim = 0; // Nombre r�sultant de la conversion binaire-d�cimale du nombre binaire contenu dans tableau_nim_binaire
	int structure_status; // Status de la structure (pair = 0, impaire = 1)
	int ligne_coup; // Ligne sur laquelle grundy va jouer
	int nb_jetons_soustraire; // Nombre de jetons � retirer par le coup de grundy

	for (size_t j = 0; j < NB_REP_BINAIRE; j++) // Loop de colonne en colonne
	{
		for (size_t i = 0; i < NB_LIGNES_NIM; i++) // Loop de ligne en ligne
		{
			if (tableau_nim_binaire[j] == 1 && noyau_grundy[i][j] == 1) // Regarde si le bit pr�sent dans tableau_addition[j] est 1, si oui et																	  
			{														     // que le bit lu dans matice_grundy[i][j] est aussi 1, on remet le bit � 0
				tableau_nim_binaire[j] = 0;
			}

			tableau_nim_binaire[j] += noyau_grundy[i][j]; //sert simplement � mettre le bit � 1
		}

		if (tableau_nim_binaire[j] == 1) // Ce if sert � convertir directement le num�ro de nim binaire en d�cimal
		{
			numero_nim += (int)(pow(2, j));
		}
	}
	if (numero_nim > 0) // Si numero_nim est plus grand que 0, nous somme dans une structure impaire donc structure_status = 1
		// Sinon la variable structure_status reste 0 et signifie que la structure est pair
	{
		structure_status = 1;
	}

	if (structure_status == 0) // Si la structure est pair, retire un nombre random de jetons dans une ligne random du jeu. S'assure aussi que le nombre de jetons � retirer est valide
	{

		ligne_coup = mt_randi(NB_LIGNES_NIM + 1) - 1; // Choisi une ligne entre 0 et 20
		nb_jetons_soustraire = mt_randi(partie_grundy.jetons_actuel[ligne_coup]); // Choisi un nombre de jetons entre 1 et la valeur de jetons pr�sent � la ligne d�terminer juste avant


	}
	else
	{
		for (size_t i = 0; i < NB_LIGNES_NIM; i++) // Loop entre les lignes pour trouver la bonne ligne qui supporte la soustraction
		{
			int jetons_post_soustraction = 0;

			for (size_t j = 0; j < NB_REP_BINAIRE; ++j) // Loop entre les colonnes et calcul le nombre de jetons en binaire (en convertissant au fur et a mesure en decimal) qui devrait �tre
				// sur la ligne pour que la structure soit pair. Ce nombre (jetons_post_soustraction) sera soustrais (SI POSSIBLE, sinon on reloop) au
				// nombre de jetons pr�sent sur la ligne (jeu actuel) ce qui determinera la valeur de nb_jetons_soustraire
			{
				if (noyau_grundy[i][j] != tableau_nim_binaire[j])
				{
					jetons_post_soustraction += (int)(pow(2, j)); // conversion en d�cimal
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

	*nb_jetons = nb_jetons_soustraire;
	*ligne = ligne_coup;

	//modifier_jeu(partie_grundy.jetons_actuel, ligne_coup, nb_jetons_soustraire); // Retire le nombre de jetons � la ligne d�termin�e
}


/*==========================================================*//*==========================================================*/
void terminer_partie_grundy(const t_partieID* sonID) {
	if (partie_grundy_en_cours || strcmp(*sonID, partie_grundy.id_partie)) {
		partie_grundy_en_cours = 0;
	}
}
/*==========================================================*//*==========================================================*/
	/*D�clancher l'algorithme grundy:

	1- Repr�senter le nb de pi�ces sur chacune des lignes du jeu en binaire dans la ligne corresspondantes d'une matrice d'entiers
	cette matrice est d�finie avec une ligne de plus que le nb de lignes du jeu

	2- Maintenant dans chq case de la derni�re  ligne de la matrice  faites la sommes des valeurs qui viennent au-dessus d'elle dans sa colonne

	3- Si tts les val sur la derni�re ligne de la matrice sont paires, in sera dans une structure paire sinon ce sera une structure impaire

	4-Structure paire et d'un coup valide-> joueur am�ne jeu vers structure impaire

	5-Structure impaire-> joueur a tjrs l'opportunit� de ramener le jeu en structure pair d'un coup valide

	6- Z�ro = structure paire (si adversaire est continuellement en structure paire il ne peut pas gagner)

	*/