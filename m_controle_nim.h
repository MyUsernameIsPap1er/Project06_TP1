/*==========================================================*/
/*  aut2023 tp1
	interface du module de controle d'une partie de nim
	
	Equipe : Nicolas Zied Simon Maxime

*/

#ifndef _M_CONTROLE_NIM_
#define _M_CONTROLE_NIM_

//=========================================================
#include "m_types_const_nim.h"
/*==========================================================*/
/*
    Le module controle contient six variables priv�es 

		1- int partie_en_cours  valeur logique (0,1)

		2- t_partie_infos  partie actuelle

		3- int tour_de  indique le prochain joueur (HUMAIN  GRUNDY) 
		
		4- int nb_coups_adate donne le nombre de coups faits � date dans la partie

		les deux entiers suivants sont essentiels � la validation de l'update
		de la  partie d'un joueur APR�S un coup de l'autre joueur
		5- int ligne_modif garde la ligne du jeu modifi�e lors du dernier coup
		6- int nb_jetons_pris  garde le nombre de jetons retir�s lors du dernier coup

*/

// les initialisations v�ritables viendront lors de l'init d'une partie
static int partie_en_cours = 0;

static t_partie_infos partie ;

// par exemple tour_de alternera dans une v�ritable partie entre HUMAIN et GRUNDY
static int tour_de = -1;
static int nb_coups_adate = -1;
static int ligne_modif = -1;
static int nb_jetons_pris = -1;

/*==========================================================*/
/*==========================================================*/


/*==========================================================*/
/* Les fonctions publiques du module controle
   assurent le declenchement d'actions essentielles 
   autant pour la cr�ation d'une nouvelle partie que 
   du controle oblig� et de l'update des trois t_partie_infos 
   dans les modules du logiciel lors des coups dans une partie de nim
 */
/*==========================================================*/

   
/*==========================================================*/
/*   
	les deux premi�res fonctions sont destin�es au programme 
	qui de l'ext�rieur des quatre modules va demander 
	d'initialiser une nouvelle partie  
	ou de jouer une partie pr�c�demment initialis�e
	( comme le main en v�rit� :)
   */

   /*==========================================================*/
 /* 1 - si aucune partie n'est en cours
   declencher l'initialisation d'une nouvelle partie
   le module de controle d�clenche les fonctions n�cessaires
   puis en fait part aux deux modules joueur et grundy 
   la partie n'est pas jou�e, elle est mise en place
   la variable partie_en_cours est mise � 1
   le joueur qui commence  est fix� al�atoirement 
   retour de 1 en cas de succes et de 0 sinon (peu importe l'erreur)
  */
int init_nouvelle_partie(void);

/*==========================================================*/
/* 2- declencher la partie pr�alablement initialis�e
   
   fait jouer alternativement les joueurs et controle chacun de leurs coups
   
   la partie se termine heureusement avec un gagnant et 0 jeton en jeu
   elle retourne alors le gagnant, une des deux constantes  
   retour HUMAIN ou GRUNDY

   elle se termine diff�remment si une operation de controle obligatoire 
   lors de chaque coup dans la partie amene l'observation d'une incoh�rence 
   certaine dans le data priv� des modules.  La fonction termine alors la partie 
   dans les trois modules et le v�rifie(exception possible) 
   retour ERREUR
*/
int jouer_la_partie(void);

/*==========================================================*/
/*
	les quatre fonctions d�di�es aux controles et aux variations des variables 
	t_partie_infos dans les modules joueur_nim et grundy_nim 

	elles se servent avant tout des fonctions publiques du premier module 
	que votre �quipe a compl�t� et test� m_types_const_nim
*/
int valider_coup_joueur(t_partie_infos* partie_joueur, int ligne, int nb_pi�ce);

int valider_coup_grundy(t_partie_infos* partie_grundy, int ligne, int nb_pi�ce);

int updater_jeu_joueur(t_partie_infos* partie_joueur);

int updater_jeu_grundy(t_partie_infos* partie_grundy);

/*==========================================================*/

/* fonctions priv�es �l�mentaires n�cessaires � la cr�ation
   et au double controle d'une partie

   je vous laisse libres d'en d�finir 
   elles se servent encore avant tout des fonctions publiques du premier module
	que votre �quipe a compl�t� et test� m_types_const_nim

   elles devront �tre donn�es static
*/

 void set_nouvelle_partie();
/*==========================================================*/

/*
*/
int tester_partie_conforme(const t_partie_infos* partie);


/*==========================================================*/
#endif	
/*==========================================================*/

