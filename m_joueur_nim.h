/*==========================================================*/
/*  aut2023 tp1
	interface du module joueur nim 

	Equipe :

*/
/*==========================================================*/
/*==========================================================*/

#ifndef _M_JOUEUR_NIM_
#define _M_JOUEUR_NIM_
/*==========================================================*/

#include "m_controle_nim.h"

/*==========================================================*/
/*==========================================================*/
/*
	Le module m_joueur_nim contient deux variables priv�es

		t_partie_infos  partie_joueur

		int partie_joueur_en_cours  valeur logique (0,1)

		ATTENTION
		cette variable PARTIE_JOUEUR NE DOIT JAMAIS �TRE MODIFI�E DIRECTEMENT 
		APR�S AVOIR �T� OBTENUE ET COPI�E du param�tre de la fonction init_partie_joueur
		c'est alors que la variable partie_joueur_en_cours passe � 1(vrai)

		lorsque la fonction declencher_coup_joueur est appell�e dans la fonction 
		jouer_la_partie du module de controle vous devrez

		A -) d�clencher la fonction updater_jeu_joueur du module de controle puisque 
		� part au premier coup de la partie, un coup de l'autre joueur dont vous ignorez 
		tout a sans doute eu lieu, le module de controle updatera votre partie_joueur

		B -) donner une interface de choix � l'humain
			avec un minimum de cinq fonctions priv�es du module partie_joueur qui
			0- celle qui assure la boucle d'obtention d'une ligne du jeu et 
				d'un nombre correct de jetons � prendre � l'aide des 4 suivantes
			1- efface l'�cran pour afficher  la page d'aide du jeu  
			   "en r�sum� choisir une ligne non-vide pour y prendre entre 1
			     et tous les jetons "
			2- efface l'�cran pour afficher le jeu 
			   "en r�sum� sur chaque ligne, les jetons pr�sents et les jetons 
			     absents diff�renci�s " 
			3- qui obtient(un beau scanf) le num�ro d'une ligne non-vide (esp�rons-le)
			4- qui obtient (un beau scanf) le nombre de jetons � prendre sur cette ligne
		
		C -) une fois la ligne et nombre de jetons valid�s, d�clencher la fonction 
		     valider_coup_joueur  du module de controle qui valide le coup et modifie 
			 votre partie_joueur    
		   

*/

static t_partie_infos partie_joueur;

static int partie_joueur_en_cours = 0;

/*==========================================================*/
/*==========================================================*/

/*==========================================================*/
/* quatre fonctions publiques du module  m_joueur_nim  */
/*==========================================================*/

// retourne 1 si le joueur a une partie en cours et 0 sinon

int get_partie_joueur_en_cours(void);
/*==========================================================*/

/*  
	 si le joueur a une partie en cours retour automatique de 0
    
	 sinon copier la partie recue dans partie_joueur
     le joueur a une partie en cours, retour de 1
*/

int init_partie_joueur(const t_partie_infos* partie);

/*==========================================================*/

/*  
	si le joueur n'a pas de partie en cours ou si l'ID recu
    ne correspond pas � celui de la partie joueur  retour de 0

	sinon l'algorithme important document� plus haut est d�clench�
*/

int declencher_coup_joueur(const t_partieID sonID);

 /*==========================================================*/
 /*
	si une partie joueur est en cours et que le  param�tre donne bien son ID  
	la variable  partie en cours du module est obligatoirement mise � 0 
	
	ne pas r�aliser cet ordre du module de controle amenera ce module de controle
	� lever une exception et � potentiellement arr�ter le programme
*/

void terminer_partie_joueur(const t_partieID sonID);

/*==========================================================*/

/*Fonction qui efface l'ecran*/

void cls(void);

/*==========================================================*/

/*
0 - celle qui assure la boucle d'obtention d'une ligne du jeu et
d'un nombre correct de jetons � prendre � l'aide des 4 suivantes
*/

/*
1 - efface l'�cran pour afficher  la page d'aide du jeu
"en r�sum� choisir une ligne non-vide pour y prendre entre 1
et tous les jetons "
*/
void guidejeu(void);
/*
2 - efface l'�cran pour afficher le jeu 
"en r�sum� sur chaque ligne, les jetons pr�sents et les jetons 
absents diff�renci�s " 
*/
void aff_jeu_actuel(void);

/*
3 - qui obtient(un beau scanf) le num�ro d'une ligne non-vide (esp�rons-le)
*/
void ligne_jeu(void);
/*
4 - qui obtient(un beau scanf) le nombre de jetons � prendre sur cette ligne
*/
void jetons_jeu(void);

/*==========================================================*/
#endif	
/*==========================================================*/

