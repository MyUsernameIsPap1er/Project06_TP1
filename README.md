# Project06_TP1
*Information Indicatif sur le TP*

Ajoutez les updates importants ou les liens utiles au project ici : 
POUR CONST_NIM :

// VIENNENT D'ABORD LES CONSTANTES 
/*==========================================================*/
/*
deux constantes pour identifier les deux protagonistes 
et l'unique gagnant d'une partie 

la constante ERREUR ne servira qu'à indiquer qu'une erreur 
a été décelée et la partie interrompue  
.
.
.

   type d'un tableau statique représentant le nombre de jetons 
   sur chaque ligne du jeu

typedef int t_tablo_jeu[NB_LIGNES_NIM];


   string statique donnant l'identifiant unique d'une partie de nim
   construite d'un nombre aléatoire  pour les derniers caractères  
   et dont les premiers caractères seront uniques et automatisés par
   la fonction static qui les émet 
   cette fonction vous est offerte 
   vous ne devez pas la modifier

typedef char t_partieID[TAILLE_ID];


type structuré utilisé  dans les modules  m_controle_nim,
m_joueur_nim et m_grundy_nim pour représenter une partie de nim

dans les modules m_joueur_nim et m_grundy_nim,  cette variable t_partie_infos 
privée permet aux  fonctions du module de connaitre l'état de la partie actuelle
et ainsi de permettre la détermination du prochain coup. Mais ces deux modules ont 
interdiction de les modifier

c'est le module de controle qui doit seul vérifier la cohérence 
des images locales du jeu et lors d'un coup valide de modifier 
la sienne comme celles des deux autres modules à leur demande 

*/

typedef struct {
	// essentiel au controle et à l'affichage du jeu dans m_joueur_nim
	t_tablo_jeu jetons_original; 

    l'état actuel du jeu, essentiel au  choix et au controle d'un coup 
	dans les trois modules  

	t_tablo_jeu jetons_actuel;

    essentiel au controle et à la reconnaissance de la partie 
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

/* tester  si le tableau de jeu  ne présente aucune valeur négative 
	ou supérieure à NB_JETONS_MAX
	retour 0 faux ou 1 vrai 
*/
int tester_jeu_conforme(const t_tablo_jeu jeu);
/*==========================================================*/


//copier toutes les valeurs du tableau source dans le tableau destination 
void copier_jeu(const t_tablo_jeu src, t_tablo_jeu dest);
/*==========================================================*/


//tester  si les deux tableaux de jeu présentent les mêmes valeurs 
// retour 0 faux ou 1 vrai 
int tester_jeux_egaux(const t_tablo_jeu jeu0, const t_tablo_jeu jeu1);
/*==========================================================*/

/*tester  si les deux tableaux de jeu sont conformes et si les valeurs 
  du jeu actuel sont toutes inférieures ou égales à celles du jeu original
  retour 0 faux ou 1 vrai 
*/
int tester_ordre_jeux(const t_tablo_jeu original, const t_tablo_jeu actuel);
/*==========================================================*/

/* tester  si toutes les valeurs du tableau de jeu sont nulles 
	indicateur d'une partie  terminée
	retour 0 faux ou 1 vrai
*/
int tester_fin_jeu(const t_tablo_jeu jeu);
/*==========================================================*/

/* 
   modifier le tableau de jeu en enlevant
   un nb_jetons à la position ligne du tableau de jeu

   précondition : sur cette ligne, le nombre de jetons à retirer 
   est inférieur ou égal au nombre  actuel de jetons

   Retour  1 si l'operation à été faite correctement, 0 sinon 
*/
int modifier_jeu(t_tablo_jeu jeu, int ligne, int nb_jetons);
/*==========================================================*/
// maintenant les fonctions agissant sur une ou des t_partie_infos
/*==========================================================*/

/*==========================================================*/
/*	
	tester si tous les membres de la partie0 sont égaux à ceux de la partie1
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
fonction qui offre un ID unique à une partie
cette fonction vous est donnée, vous ne devez pas la modifier
elle sera uniquement utilisée dans nouvelle_partie du module de controle
*/
void get_ID_unique(t_partieID id_partie);

//==============================================================================//
PARTIE_JOUEUR: 
Le module m_joueur_nim contient deux variables privées

		t_partie_infos  partie_joueur

		int partie_joueur_en_cours  valeur logique (0,1)

		ATTENTION
		cette variable PARTIE_JOUEUR NE DOIT JAMAIS ÊTRE MODIFIÉE DIRECTEMENT 
		APRÈS AVOIR ÉTÉ OBTENUE ET COPIÉE du paramètre de la fonction init_partie_joueur
		c'est alors que la variable partie_joueur_en_cours passe à 1(vrai)

		lorsque la fonction declencher_coup_joueur est appellée dans la fonction 
		jouer_la_partie du module de controle vous devrez

		A -) déclencher la fonction updater_jeu_joueur du module de controle puisque 
		à part au premier coup de la partie, un coup de l'autre joueur dont vous ignorez 
		tout a sans doute eu lieu, le module de controle updatera votre partie_joueur

		B -) donner une interface de choix à l'humain
			avec un minimum de cinq fonctions privées du module partie_joueur qui
			0- celle qui assure la boucle d'obtention d'une ligne du jeu et 
				d'un nombre correct de jetons à prendre à l'aide des 4 suivantes
			1- efface l'écran pour afficher  la page d'aide du jeu  
			   "en résumé choisir une ligne non-vide pour y prendre entre 1
			     et tous les jetons "
			2- efface l'écran pour afficher le jeu 
			   "en résumé sur chaque ligne, les jetons présents et les jetons 
			     absents différenciés " 
			3- qui obtient(un beau scanf) le numéro d'une ligne non-vide (espérons-le)
			4- qui obtient (un beau scanf) le nombre de jetons à prendre sur cette ligne
		
		C -) une fois la ligne et nombre de jetons validés, déclencher la fonction 
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
    ne correspond pas à celui de la partie joueur  retour de 0

	sinon l'algorithme important documenté plus haut est déclenché
*/

int declencher_coup_joueur(const t_partieID sonID);

 /*==========================================================*/
 /*
	si une partie joueur est en cours et que le  paramètre donne bien son ID  
	la variable  partie en cours du module est obligatoirement mise à 0 
	
	ne pas réaliser cet ordre du module de controle amenera ce module de controle
	à lever une exception et à potentiellement arrêter le programme
*/

void terminer_partie_joueur(const t_partieID sonID);

//=======================================================//
PARTIE_GRUNDY:

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

PARTIE_CONTROLE:
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


