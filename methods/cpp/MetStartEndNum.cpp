#include "../headers/MetStartEndNum.h"
#include "../../headers/Solution.h"

void StartEndNum::realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const
{
	const Line* analyzedLine = cond->getLinePtr();
	int start = cond->getStart();
	int end = cond->getEnd();

	std::list<NumberAndBorders>::const_iterator startIter = cond->getNumInfo().cbegin();
	while (analyzedLine->getCellType(start) != CellType::undefined)
	{
		if (analyzedLine->getCellType(start) == CellType::white) ++start;
		else
		{
			++start;		// тк первая клетка числа уже закрашена
			for (int count = 0; count <= (*startIter).getNum() - 1; ++count)		// закрашиваем количество клеток, равное числу
			{
				if (count < (*startIter).getNum() - 1)
				{
					this->setColorWithInformation(pict, posit, start++, CellType::black);	// закрашиваем Number-1 клетку
				}
				else		// если count == (*startIter).getNum() - 1
				{
					if (start >= end)	// условие эквивалентное тому, что строка полностью закрашена
						return;
					this->setColorWithInformation(pict, posit, start++, CellType::white);	// и добавляем в конце 0
				}
			}
			++startIter;	// переходим к следующему числу
		}
		if (start >= end)	// условие эквивалентное тому, что строка полностью закрашена
			return;
	}

	std::list<NumberAndBorders>::const_reverse_iterator endIter = cond->getNumInfo().crbegin();
	while (analyzedLine->getCellType(end - 1) != CellType::undefined)
	{
		if (analyzedLine->getCellType(end - 1) == CellType::white) --end;
		else
		{
			--end;		// тк первая клетка числа уже закрашена
			for (int count = 0; count <= (*endIter).getNum() - 1; ++count)
			{
				if (count < (*endIter).getNum() - 1)
				{
					this->setColorWithInformation(pict, posit, --end, CellType::black);	// закрашиваем Number-1 клетку
				}
				else		// если count == (*startIter).getNum() - 1
				{
					if (start >= end)	// условие эквивалентное тому, что строка полностью закрашена
						return;
					this->setColorWithInformation(pict, posit, --end, CellType::white);	// и добавляем в конце 0
				}
			}
			++endIter;	// переходим к следующему числу
		}
		if (start >= end)	// условие эквивалентное тому, что строка полностью закрашена
			return;
	}
}

std::string StartEndNum::methodName() const
{
	return "StartEndNum";
}

std::string StartEndNum::principleOfMethodWork() const
{
	return "";
}
