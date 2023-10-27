/*==========================================================*/
/*  aut2023 tp1
	interface du module types et constantes du logiciel

	Equipe : Simon, Zied, Max

*/
/*==========================================================*/
/*==========================================================*/

#ifndef _M_TYPES_CONST_NIM_
#define _M_TYPES_CONST_NIM_

/*==========================================================*/
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<assert.h>

// le generateur sert � diff�rents endroits dans le logiciel
#include "mtwister.h"
/*==========================================================*/

// VIENNENT D'ABORD LES CONSTANTES 
/*==========================================================*/
/*
deux constantes pour identifier les deux protagonistes 
et l'unique gagnant d'une partie 

la constante ERREUR ne servira qu'� indiquer qu'une erreur 
a �t� d�cel�e et la partie interrompue  
*/

#define HUMAIN 1
#define GRUNDY 2
#define ERREUR 0

/*==========================================================*/

/* 
   voici le nombre de lignes consid�r� minimal
   dans une partie de nim 
   vous pouvez augmenter mais attention en cas 
   d'augmentation � ne PAS d�truire l'affichage  
   du jeu dont vous �tes responsable dans le module joueur nim 
*/
#define NB_LIGNES_NIM 20

/*==========================================================*/

/*
   voici le nombre de jetons maximal que la fonction 
   de cr�ation al�atoire d'un tableau de jeu
   accordera � une ligne du jeu

   vous pouvez augmenter mais attention en cas
   d'augmentation � ne PAS d�truire l'affichage du jeu 
   dont vous �tes responsable dans le module joueur nim
   
   De toutes fa�ons et sans autre raison 
   il vous est INTERDIT de d�passer 63 
*/
#define NB_JETONS_MAX 25

/*   
   voici le nombre de jetons MINIMAL que la fonction 
   de cr�ation al�atoire d'un tableau de jeu
   accordera � une ligne du jeu
   vous pouvez r�duire mais elle ne sera jamais nulle
*/
#define NB_JETONS_MIN 4


/*
   voici la taille maximale de la string servant 
   comme ID d'une partie de nim dans le logiciel 
*/
#define TAILLE_ID 20


/*==========================================================*/
/*==========================================================*/


// VIENNENT  TROIS TYPES
/*==========================================================*/

/* 
   type d'un tableau statique repr�sentant le nombre de jetons 
   sur chaque ligne du jeu
*/
typedef int t_tablo_jeu[NB_LIGNES_NIM];

/*==========================================================*/

/* string statique donnant l'identifiant unique d'une partie de nim
   construite d'un nombre al�atoire  pour les derniers caract�res  
   et dont les premiers caract�res seront uniques et automatis�s par
   la fonction static qui les �met 
   cette fonction vous est offerte 
   vous ne devez pas la modifier
*/

typedef char t_partieID[TAILLE_ID];

//=========================================================
/*
type structur� utilis�  dans les modules  m_controle_nim,
m_joueur_nim et m_grundy_nim pour repr�senter une partie de nim

dans les modules m_joueur_nim et m_grundy_nim,  cette variable t_partie_infos 
priv�e permet aux  fonctions du module de connaitre l'�tat de la partie actuelle
et ainsi de permettre la d�termination du prochain coup. Mais ces deux modules ont 
interdiction de les modifier

c'est le module de controle qui doit seul v�rifier la coh�rence 
des images locales du jeu et lors d'un coup valide de modifier 
la sienne comme celles des deux autres modules � leur demande 

*/

typedef struct {
	// essentiel au controle et � l'affichage du jeu dans m_joueur_nim
	t_tablo_jeu jetons_original; 

	/* l'�tat actuel du jeu, essentiel au  choix et au controle d'un coup 
	dans les trois modules  
	*/ 
	t_tablo_jeu jetons_actuel;

	// essentiel au controle et � la reconnaissance de la partie 
	t_partieID id_partie;

}t_partie_infos;

/*==========================================================*/

/*==========================================================*/
/* VIENNENT LES FONCTIONS PUBLIQUES �L�MENTAIRES
	de test, d'usage ou de maintien 
	des variables de ces types

    fonctions que vous devrez d�finir en tout premier
	dans l'impl�mentation du module 

	chacune de ces fonctions doit �tre test�e
	ce serait bien d'avoir au moins 2 assert 
	vous pouvez alors tr�s bien r�duire NB_LIGNES_NIM 
	pour faciliter grandement l'observation des tableaux test�s
*/
/*==========================================================*/
/*==========================================================*/


/*==========================================================*/
// d'abord les fonctions agissant sur un ou deux t_tablo_jeu
/*==========================================================*/

/* initialisation 
	utilise le twister pour donner des jetons dans chaque case 
	d'un tableau de jeu 
	SPECIFICATION le nombre de jetons varie obligatoirement 
	 entre NB_JETONS_MIN et NB_JETONS_MAX
*/
void init_jeu_alea(t_tablo_jeu dest);
/*==========================================================*/

/* tester  si le tableau de jeu  ne pr�sente aucune valeur n�gative 
	ou sup�rieure � NB_JETONS_MAX
	retour 0 faux ou 1 vrai 
*/
int tester_jeu_conforme(const t_tablo_jeu jeu);
/*==========================================================*/


//copier toutes les valeurs du tableau source dans le tableau destination 
void copier_jeu(const t_tablo_jeu src, t_tablo_jeu dest);
/*==========================================================*/


//tester  si les deux tableaux de jeu pr�sentent les m�mes valeurs 
// retour 0 faux ou 1 vrai 
int tester_jeux_egaux(const t_tablo_jeu jeu0, const t_tablo_jeu jeu1);
/*==========================================================*/

/*tester  si les deux tableaux de jeu sont conformes et si les valeurs 
  du jeu actuel sont toutes inf�rieures ou �gales � celles du jeu original
  retour 0 faux ou 1 vrai 
*/
int tester_ordre_jeux(const t_tablo_jeu original, const t_tablo_jeu actuel);
/*==========================================================*/

/* tester  si toutes les valeurs du tableau de jeu sont nulles 
	indicateur d'une partie  termin�e
	retour 0 faux ou 1 vrai
*/
int tester_fin_jeu(const t_tablo_jeu jeu);
/*==========================================================*/

/* 
   modifier le tableau de jeu en enlevant
   un nb_jetons � la position ligne du tableau de jeu

   pr�condition : sur cette ligne, le nombre de jetons � retirer 
   est inf�rieur ou �gal au nombre  actuel de jetons

   Retour  1 si l'operation � �t� faite correctement, 0 sinon 
*/
int modifier_jeu(t_tablo_jeu jeu, int ligne, int nb_jetons);
/*==========================================================*/
/*==========================================================*/

/*==========================================================*/
// maintenant les fonctions agissant sur une ou des t_partie_infos
/*==========================================================*/

/*==========================================================*/
/*	
	tester si tous les membres de la partie0 sont �gaux � ceux de la partie1
	utilisez la fonction strcmp de string.h pour comparer les ID
	retour 1 si vrai, 0 sinon
*/
int parties_egales(const t_partie_infos* partie0, const t_partie_infos* partie1);

/*==========================================================*/
/* copier les trois membres de la partie source dans la partie destination
	 utilisez la fonction strcpy de string.h pour copier ID
*/ 
void copier_partie(const t_partie_infos* src, t_partie_infos* dest);
/*==========================================================*/

/*
fonction qui offre un ID unique � une partie
cette fonction vous est donn�e, vous ne devez pas la modifier
elle sera uniquement utilis�e dans nouvelle_partie du module de controle
*/
void get_ID_unique(t_partieID id_partie);
/*==========================================================*/
#endif	
/*==========================================================*/

