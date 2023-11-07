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
    Le module controle contient six variables privées 

		1- int partie_en_cours  valeur logique (0,1)

		2- t_partie_infos  partie actuelle

		3- int tour_de  indique le prochain joueur (HUMAIN  GRUNDY) 
		
		4- int nb_coups_adate donne le nombre de coups faits à date dans la partie

		les deux entiers suivants sont essentiels à la validation de l'update
		de la  partie d'un joueur APRÈS un coup de l'autre joueur
		5- int ligne_modif garde la ligne du jeu modifiée lors du dernier coup
		6- int nb_jetons_pris  garde le nombre de jetons retirés lors du dernier coup

*/

// les initialisations véritables viendront lors de l'init d'une partie
static int partie_en_cours = 0;

static t_partie_infos partie ;

// par exemple tour_de alternera dans une véritable partie entre HUMAIN et GRUNDY
static int tour_de = -1;
static int nb_coups_adate = -1;
static int ligne_modif = -1;
static int nb_jetons_pris = -1;

/*==========================================================*/
/*==========================================================*/


/*==========================================================*/
/* Les fonctions publiques du module controle
   assurent le declenchement d'actions essentielles 
   autant pour la création d'une nouvelle partie que 
   du controle obligé et de l'update des trois t_partie_infos 
   dans les modules du logiciel lors des coups dans une partie de nim
 */
/*==========================================================*/

   
/*==========================================================*/
/*   
	les deux premières fonctions sont destinées au programme 
	qui de l'extérieur des quatre modules va demander 
	d'initialiser une nouvelle partie  
	ou de jouer une partie précédemment initialisée
	( comme le main en vérité :)
   */

   /*==========================================================*/
 /* 1 - si aucune partie n'est en cours
   declencher l'initialisation d'une nouvelle partie
   le module de controle déclenche les fonctions nécessaires
   puis en fait part aux deux modules joueur et grundy 
   la partie n'est pas jouée, elle est mise en place
   la variable partie_en_cours est mise à 1
   le joueur qui commence  est fixé aléatoirement 
   retour de 1 en cas de succes et de 0 sinon (peu importe l'erreur)
  */
int init_nouvelle_partie(void);

/*==========================================================*/
/* 2- declencher la partie préalablement initialisée
   
   fait jouer alternativement les joueurs et controle chacun de leurs coups
   
   la partie se termine heureusement avec un gagnant et 0 jeton en jeu
   elle retourne alors le gagnant, une des deux constantes  
   retour HUMAIN ou GRUNDY

   elle se termine différemment si une operation de controle obligatoire 
   lors de chaque coup dans la partie amene l'observation d'une incohérence 
   certaine dans le data privé des modules.  La fonction termine alors la partie 
   dans les trois modules et le vérifie(exception possible) 
   retour ERREUR
*/
int jouer_la_partie(void);

/*==========================================================*/
/*
	les quatre fonctions dédiées aux controles et aux variations des variables 
	t_partie_infos dans les modules joueur_nim et grundy_nim 

	elles se servent avant tout des fonctions publiques du premier module 
	que votre équipe a complété et testé m_types_const_nim
*/
int valider_coup_joueur(t_partie_infos* partie_joueur, int ligne, int nb_pièce);

int valider_coup_grundy(t_partie_infos* partie_grundy, int ligne, int nb_pièce);

int updater_jeu_joueur(t_partie_infos* partie_joueur);

int updater_jeu_grundy(t_partie_infos* partie_grundy);

/*==========================================================*/

/* fonctions privées élémentaires nécessaires à la création
   et au double controle d'une partie

   je vous laisse libres d'en définir 
   elles se servent encore avant tout des fonctions publiques du premier module
	que votre équipe a complété et testé m_types_const_nim

   elles devront être données static
*/

 void set_nouvelle_partie();
/*==========================================================*/

/*
*/
int tester_partie_conforme(const t_partie_infos* partie);


/*==========================================================*/
#endif	
/*==========================================================*/

