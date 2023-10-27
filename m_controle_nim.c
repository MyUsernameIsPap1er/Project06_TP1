/*==========================================================*/
/*  aut2023 tp1
	implémentation du module types et constantes du logiciel

	Equipe : Max, Simon, Zieb

*/
/*==========================================================*/
/*==========================================================*/

#include "m_controle_nim.h"
/*==========================================================*/

int init_nouvelle_partie(void) {
	if (partie_en_cours == 0) {
		
		partie_en_cours = 1;		
	}
}