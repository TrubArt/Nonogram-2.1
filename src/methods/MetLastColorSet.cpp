#include "metLastColorSet.h"

void LastColorSet::realization(const Condition& cond, Picture& pict, std::vector<PaintCellInfo>& queue, bool isColumn, size_t rowOrColIndex) const
{
	std::cout << "\n\n\n\n Dont use this function, use anotherrealization! \n\n\n\n";
}

std::string LastColorSet::methodName() const
{
	return "LastColorSet";
}

std::string LastColorSet::principleOfMethodWork() const
{
	std::string answ;
	answ.append("Метод принимает на вход UpdCondReturnParam param, который сообщает классу о том, что\n");
	answ.append("необходимо все оставшиеся в линии CellType::undefined закрасить в цвет param");
	return answ;
}

void LastColorSet::anotrealization(const Condition& cond, Picture& pict, std::vector<PaintCellInfo>& queue
									, bool isColumn, size_t rowOrColIndex, UpdCondReturnParam param) const
{
	if (param == UpdCondReturnParam::lineNotCompleted)
	{
		return;
	}

	const Line* analyzedLine = cond.getLinePtr();
	for (size_t index = cond.getStart(); index < cond.getEnd(); ++index)
	{
		if (analyzedLine->getCellType(index) != CellType::undefined)
		{
			continue;
		}

		setColorAndAddInQueue(pict, queue, isColumn, rowOrColIndex, index, static_cast<CellType>(param));
	}
}
