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
			++start;		// �� ������ ������ ����� ��� ���������
			for (int count = 0; count <= (*startIter).getNum() - 1; ++count)		// ����������� ���������� ������, ������ �����
			{
				if (count < (*startIter).getNum() - 1)
				{
					this->setColorWithInformation(pict, posit, start++, CellType::black);	// ����������� Number-1 ������
				}
				else		// ���� count == (*startIter).getNum() - 1
				{
					if (start >= end)	// ������� ������������� ����, ��� ������ ��������� ���������
						return;
					this->setColorWithInformation(pict, posit, start++, CellType::white);	// � ��������� � ����� 0
				}
			}
			++startIter;	// ��������� � ���������� �����
		}
		if (start >= end)	// ������� ������������� ����, ��� ������ ��������� ���������
			return;
	}

	std::list<NumberAndBorders>::const_reverse_iterator endIter = cond->getNumInfo().crbegin();
	while (analyzedLine->getCellType(end - 1) != CellType::undefined)
	{
		if (analyzedLine->getCellType(end - 1) == CellType::white) --end;
		else
		{
			--end;		// �� ������ ������ ����� ��� ���������
			for (int count = 0; count <= (*endIter).getNum() - 1; ++count)
			{
				if (count < (*endIter).getNum() - 1)
				{
					this->setColorWithInformation(pict, posit, --end, CellType::black);	// ����������� Number-1 ������
				}
				else		// ���� count == (*startIter).getNum() - 1
				{
					if (start >= end)	// ������� ������������� ����, ��� ������ ��������� ���������
						return;
					this->setColorWithInformation(pict, posit, --end, CellType::white);	// � ��������� � ����� 0
				}
			}
			++endIter;	// ��������� � ���������� �����
		}
		if (start >= end)	// ������� ������������� ����, ��� ������ ��������� ���������
			return;
	}
}