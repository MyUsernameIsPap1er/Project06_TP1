# Project06_TP1
*Information Indicatif sur le TP*

Ajoutez les updates importants ou les liens utiles au project ici : 
POUR CONST_NIM :

// VIENNENT D'ABORD LES CONSTANTES 
/*==========================================================*/
/*
deux constantes pour identifier les deux protagonistes 
et l'unique gagnant d'une partie 

la constante ERREUR ne servira qu'� indiquer qu'une erreur 
a �t� d�cel�e et la partie interrompue  
.
.
.

   type d'un tableau statique repr�sentant le nombre de jetons 
   sur chaque ligne du jeu

typedef int t_tablo_jeu[NB_LIGNES_NIM];


   string statique donnant l'identifiant unique d'une partie de nim
   construite d'un nombre al�atoire  pour les derniers caract�res  
   et dont les premiers caract�res seront uniques et automatis�s par
   la fonction static qui les �met 
   cette fonction vous est offerte 
   vous ne devez pas la modifier

typedef char t_partieID[TAILLE_ID];


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

    l'�tat actuel du jeu, essentiel au  choix et au controle d'un coup 
	dans les trois modules  

	t_tablo_jeu jetons_actuel;

    essentiel au controle et � la reconnaissance de la partie 
	t_partieID id_partie;

}t_partie_infos;

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

/*==========================================================*/
/* copier les trois membres de la partie source dans la partie destination
	 utilisez la fonction strcpy de string.h pour copier ID
*/ 
void copier_partie(const t_partie_infos* src, t_partie_infos* dest);
/*==========================================================*/

/*==========================================================*/

/*
fonction qui offre un ID unique � une partie
cette fonction vous est donn�e, vous ne devez pas la modifier
elle sera uniquement utilis�e dans nouvelle_partie du module de controle
*/
void get_ID_unique(t_partieID id_partie);

//==============================================================================//
PARTIE_JOUEUR: 
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
retourne 1 si le joueur a une partie en cours et 0 sinon

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

//=======================================================//
PARTIE_GRUNDY:

Ce module est le fr�re jumeau du module m_joueur_nim

la  seule diff�rence notable sera que lors du d�clenchement du coup 
de grundy,  le choix de la ligne et du nombre de jetons sur cette ligne
sera obtenue par algorithmie, celle du noyau de P.M. Grundy (1917-1959)
et non par interface �cran/clavier

Le module contient trois variables priv�es

t_partie_infos  partie_grundy

int partie_grundy_en_cours  valeur logique(0, 1)

et une matrice d'entiers assez facilement construite du tableau actuel
dans la variable partie_grundy

ATTENTION (comme pour partie_joueur)
LA PARTIE_GRUNDY NE DOIT JAMAIS �TRE MODIFI�E DIRECTEMENT APR�S AVOIR
�T� OBTENUE ET COPI�E du param�tre de la fonction init_partie_grundy
c'est alors que la variable partie_grundy_en_cours passe � vrai

lorsque la fonction declencher_coup_grundy est appell�e dans la fonction jouer_la_partie
du module de controle vous devrez

A - ) d�clencher la fonction updater_jeu_grundy du module de controle puisque 
	  � part au premier coup de la partie, un coup de l'autre joueur dont vous ignorez 
	  tout a sans doute eu lieu, le module de controle updatera votre partie_grundy

B - ) plusieurs fonctions priv�es  d�di�es au traitement de la matrice de grundy
		pour d�terminer la ligne et le nombre de jetons	�  enlever sur cette ligne
		pour jeter le prochain joueur dans le noyau de Grundy (dit �tat pair)
		si cette action est impossible (ce qui peut arriver), grundy joue al�atoirement 

C - ) une fois la ligne et nombre de jetons obtenus de l'algorithme du point B 
      d�clencher la fonction valider_coup_grundy  du module de controle 
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
	ne correspond pas � celui de la partie grundy  retour de 0

	sinon l'algorithme de grundy est d�clench�
*/
int declencher_coup_grundy(const t_partieID);

/*==========================================================*/
/*
   si une partie grundy est en cours et que le  param�tre donne bien son ID
   la variable  partie en cours du module grundy est obligatoirement mise � 0

   ne pas r�aliser cet ordre du module de controle amenera ce module de controle
   � lever une exception et � potentiellement arr�ter le programme
*/
void terminer_partie_grundy(const t_partieID);

/*==========================================================*/

PARTIE_CONTROLE:
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


