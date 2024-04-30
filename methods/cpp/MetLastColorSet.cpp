#include "../headers/MetLastColorSet.h"
#include "../../headers/Solution.h"

void LastColorSet::realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const {}

void  LastColorSet::anotrealization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit, updCondReturnParam param) const
{
	if (param != updCondReturnParam::LineNotCompleted)
	{
		const Line* analyzedLine = cond->getLinePtr();
		for (int i = cond->getStart(); i < cond->getEnd(); ++i)
		{
			if (analyzedLine->getCellType(i) == CellType::undefined)
				this->setColorWithInformation(pict, posit, i, static_cast<CellType>(param));
		}
	}
}