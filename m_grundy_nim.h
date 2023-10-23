/*==========================================================*/
/*  aut2023 tp1
	interface du module grundy nim

	Equipe : Zied, Maxime & Simon

*/
/*==========================================================*/
/*==========================================================*/

#ifndef _M_GRUNDY_NIM_
#define _M_GRUNDY_NIM_
/*==========================================================*/

#include "m_controle_nim.h"
/*==========================================================*/
/*
Ce module est le frère jumeau du module m_joueur_nim

la  seule différence notable sera que lors du déclenchement du coup 
de grundy,  le choix de la ligne et du nombre de jetons sur cette ligne
sera obtenue par algorithmie, celle du noyau de P.M. Grundy (1917-1959)
et non par interface écran/clavier

Le module contient trois variables privées

t_partie_infos  partie_grundy

int partie_grundy_en_cours  valeur logique(0, 1)

et une matrice d'entiers assez facilement construite du tableau actuel
dans la variable partie_grundy

ATTENTION (comme pour partie_joueur)
LA PARTIE_GRUNDY NE DOIT JAMAIS ÊTRE MODIFIÉE DIRECTEMENT APRÈS AVOIR
ÉTÉ OBTENUE ET COPIÉE du paramètre de la fonction init_partie_grundy
c'est alors que la variable partie_grundy_en_cours passe à vrai

lorsque la fonction declencher_coup_grundy est appellée dans la fonction jouer_la_partie
du module de controle vous devrez

A - ) déclencher la fonction updater_jeu_grundy du module de controle puisque 
	  à part au premier coup de la partie, un coup de l'autre joueur dont vous ignorez 
	  tout a sans doute eu lieu, le module de controle updatera votre partie_grundy

B - ) plusieurs fonctions privées  dédiées au traitement de la matrice de grundy
		pour déterminer la ligne et le nombre de jetons	à  enlever sur cette ligne
		pour jeter le prochain joueur dans le noyau de Grundy (dit état pair)
		si cette action est impossible (ce qui peut arriver), grundy joue aléatoirement 

C - ) une fois la ligne et nombre de jetons obtenus de l'algorithme du point B 
      déclencher la fonction valider_coup_grundy  du module de controle 
	  qui valide le coup et modifie la partie_grundy

* /
/*==========================================================*/

#define NB_REP_BINAIRE 8
typedef int matice_grundy[NB_LIGNES_NIM][NB_REP_BINAIRE];

/*==========================================================*/
/*voici les trois statiques */

static t_partie_infos partie_grundy;

static int partie_grundy_en_cours = 0;

static matice_grundy noyau_grundy = { 0 };

/*==========================================================*/
/*==========================================================*/
/*==========================================================*/
/* quatre fonctions publiques du module  m_grundy_nim  */
/*==========================================================*/

// retourne 1 si grundy a une partie en cours et 0 sinon

int get_partie_grundy_en_cours(void);
/*==========================================================*/

/*
	 si grundy a une partie en cours retour automatique de 0

	 sinon copier la partie recue dans partie_grundy
	 grundy a une partie en cours, retour de 1
*/

int init_partie_grundy(const t_partie_infos* partie);

/*==========================================================*/

/*
	si grundy n'a pas de partie en cours ou si l'ID recu
	ne correspond pas à celui de la partie grundy  retour de 0

	sinon l'algorithme de grundy est déclenché
*/

int declencher_coup_grundy(const t_partieID);

/*==========================================================*/
/*
   si une partie grundy est en cours et que le  paramètre donne bien son ID
   la variable  partie en cours du module grundy est obligatoirement mise à 0

   ne pas réaliser cet ordre du module de controle amenera ce module de controle
   à lever une exception et à potentiellement arrêter le programme
*/

void terminer_partie_grundy(const t_partieID);

/*==========================================================*/
#endif	
/*==========================================================*/


