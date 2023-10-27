
#include "m_grundy_nim.h"

int get_partie_grundy_en_cours(void) {

	if (partie_grundy_en_cours)
	{
		return 1;
	}
	return 0;
}

int init_partie_grundy(const t_partie_infos* partie) {

	if (partie_grundy_en_cours)
	{
		return 0;
	}

	copier_partie(partie, partie_grundy);

	partie_en_cours = 1;

	return 1;
}