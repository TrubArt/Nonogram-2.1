#include "Imethod.h"
#include "../headers/Picture.h"

void Imethod::setColorWithInformation(Picture* pict, const std::pair<int, int>& posit, int index, CellType Ctype) const
{
	if (posit.first == 0)
		pict->setColor(posit.second, index, Ctype);
	else
		pict->setColor(index, posit.second, Ctype);
}