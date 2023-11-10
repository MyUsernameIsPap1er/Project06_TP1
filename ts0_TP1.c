//=========================================================
// 	hs pour le tp1 A2023
//  vous avez  2 petits exemples
//=========================================================

/*==========================================================*/
/*==========================================================*/

#include "m_types_const_nim.h"
/*==========================================================*/
typedef struct {
	double x;
	double y;
}t_point2D;
/*==========================================================================*/
t_point2D somme2D(t_point2D p0, t_point2D p1);
t_point2D somme2D(t_point2D p0, t_point2D p1) {


}

/*================================================================*/
double norme2D(t_point2D p);


/*=========================================================*/

typedef struct {
	double x;
	double y;
	double z;
}t_point3D;
/*=========================================================*/

#if 1
int main(void) {

	t_point2D p0={ 5.1 , -1.2 };

	t_point2D tabpoints[10];

	double n = norme2D(p0);

	system("pause");
	return EXIT_SUCCESS;
}
#endif
//=========================================================

#if 0
int main(void) {

	t_partieID test;

	mt_srandSys();

	get_ID_unique(test);
	printf("\n premier ID      %s\n\n", test);

	system("pause");	system("cls");
		
	get_ID_unique(test);
	printf("\n second ID      %s\n\n", test);


	system("pause");
	return EXIT_SUCCESS;
}
#endif
//=========================================================


//=========================================================
//=========================================================
#if 0
int main(void) {

	t_partie_infos p00;
	t_partie_infos* pj0;

	mt_srandSys();

	// l'acces direct aux membres de la struct p00
	p00.jetons_actuel[0] = 12;
	get_ID_unique(p00.id_partie);

	// le pointeur aura l'adresse de p00
	// dit autrement *pj0 et p00 sont le meme objet
	pj0 = &p00; 

	printf("\n les tailles	%d , %d  %d \n", sizeof(pj0), sizeof(*pj0), sizeof(*pj0));
	printf("\n les adresses	%p , %p  \n", pj0, &p00);


	// l'acces indirect aux membres de la struct
	pj0->jetons_original[1] = 6;
	pj0->jetons_original[0]= p00.jetons_actuel[0];

	// affiche l'ID avec un %s
	printf("\n ID =	%s \n", p00.id_partie);
	printf("\n ID =	%s \n", pj0->id_partie);

	system("pause");
	return EXIT_SUCCESS;
}
#endif
//=========================================================

double norme2D(t_point2D p) {
	return sqrt(p.x * p.x + p.y * p.y);
}

#if 1


#endif // 1








