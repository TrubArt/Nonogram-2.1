#include "../headers/MetUnambiguousBlack.h"
#include "../../headers/Solution.h"

void UnambiguousBlack::realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const
{
	auto list = cond->getNumInfo();	
	for(const auto& element : list)
	{ 
		for (int index = element.getD().second - element.getNum(); index < element.getD().first + element.getNum(); ++index)
		{
			this->setColorWithInformation(pict, posit, index, CellType::black);
		}
	}
}

std::string UnambiguousBlack::methodName() const
{
	return "UnambiguousBlack";
}

std::string UnambiguousBlack::principleOfMethodWork() const
{
	return "";
}
