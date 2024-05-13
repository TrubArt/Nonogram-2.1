#include "../headers/MetLastColorSet.h"
#include "../../headers/Solution.h"

void LastColorSet::realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const {}

std::string LastColorSet::methodName() const
{
	return "LastColorSet";
}

std::string LastColorSet::principleOfMethodWork() const
{
	return "";
}

void LastColorSet::anotrealization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit, UpdCondReturnParam param) const
{
	if (param != UpdCondReturnParam::lineNotCompleted)
	{
		const Line* analyzedLine = cond->getLinePtr();
		for (int i = cond->getStart(); i < cond->getEnd(); ++i)
		{
			if (analyzedLine->getCellType(i) == CellType::undefined)
				this->setColorWithInformation(pict, posit, i, static_cast<CellType>(param));
		}
	}
}
