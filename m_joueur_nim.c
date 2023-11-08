#include "m_joueur_nim.h"

int get_partie_joueur_en_cours(void) { 
	if (partie_joueur_en_cours) { //si partie_joueur_en_cours == 1 retourne 1
		return 1;
	}
	return 0; //sinon retourne 0;
}

int init_partie_joueur(const t_partie_infos* partie) { //recoie info de la partie initialise

	if (partie_joueur_en_cours) { //observe si il y a partie en cour
		return 0; // si oui retourne 0
	}
	partie_joueur.jetons_orignial = *partie.jetons_original;
	partie_joueur.jetons_actuel = *partie.jetons_actuel;
	strcpy(partie_joueur.id_partie,*partie.id_partie); // si non copie info dans partie_joueur et set partie_en_cours a 1
	
	partie_joueur_en_cours = 1;

	return 1; // success de init retourne 1///
}

int declencher_coup_joueur(const t_partieID* sonID) {

	

	if (get_partie_joueur_en_cours || strcmp(*sonID,partie_joueur.id_partie)) {

		updater_jeu_joueur();

		guidejeu(void);

		aff_jeu_actuel(void);

		int ligne_choisi;

		ligne_jeu(void);

		int jetons_choisi;

		jetons_jeu(void);



		

		
	}

	return 0;
}

void terminer_partie_joueur(const t_partieID sonID) {

}

void cls(void) {
	system("cls"); //fait la meme chose que cls sur cmd
}

void guidejeu(void) {
	cls(); //clear lecran
	printf("\nC'est votre tour!");
	printf("\n\nChoisi une ligne avec un\des jetons");
	printf("\net prends le nombre de jetons de ton choix...");
	system("PAUSE");
}

void aff_jeu_actuel(void) {

	int jetons_absent[NB_LIGNES_NIM]; 

	prinf("Jetons sur le tableau : "); 
	
	for (int i = 0;i <= NB_LIGNES_NIM;i++) { //affiche horizontalement le tableau de NIM avec les jetons encore dans la partie

		printf("  %d  ", &partie_joueur.jetons_actuel[i]);

	}

	printf("\n"); // nouvelle affichage en dessous
	printf("Jetons absents :       ");

	for (int i = 0;i <= NB_LIGNES_NIM;i++) { //affiche horizontalement les jetons retire dans chaques lignes
	
		jetons_absent[i] = partie_joueur.jetons_original[i] - partie_joueur.jetons_actuel[i];

		printf("  %d  ", jetons_absent[i]);
	}
	system("PAUSE");
}

void ligne_jeu(void) {
	
	printf("Choisi une ligne : ");
	scanf(" ", &ligne_choisi); 
	while (ligne_choisi > NB_LIGNES_NIM || partie_joueur.jetons_actuel[(ligne_choisi - 1)] == 0 || ligne_choisi <= 0) { //si la ligne est plus grande que le tableau ou qu'il n'y a plus de jetons dans la ligne choisi ou que le input est 0 
		
		printf("\nERREUR : ligne invalide");
		printf("\nChoisi une autre ligne : ");
		scanf(" ", &ligne_choisi);

	}//repeter jusqua avoir un choix valide

}

void jetons_jeu(void) {

	
	printf("Choisi le nombre de jetons a retirer : ");
	scanf(" ", &jetons_choisi);
	while (jetons_choisi > partie_joueur.jetons_actuel[(ligne_choisi)] || jetons_choisi <= 0) { //si le nombre est plus grand que le nb disponible de jetons ou 0

		printf("\nERREUR : nombre de jetons invalide");
		printf("\nChoisi un autre nombre : ");
		scanf(" ", &ligne_choisi);

	} // repeter jusqua avoir un nb valide

}
