﻿#include "iMethod.h"

void IMethod::setColorAndAddInQueue(Picture& pict, std::vector<PaintCellInfo>& queue, bool isColumn, size_t rowOrColIndex
									, size_t lineIndex, CellType cType) const
{
	bool isPaint = false;
	if (!isColumn)
	{
		isPaint = setColorWithInformation(pict, rowOrColIndex, lineIndex, cType);

		if (isPaint)
		{
			addInfoInQueue(queue, rowOrColIndex, lineIndex, cType);
		}

		return;
	}

	isPaint = setColorWithInformation(pict, lineIndex, rowOrColIndex, cType);

	if (isPaint)
	{
		addInfoInQueue(queue, lineIndex, rowOrColIndex, cType);
	}
}

bool IMethod::setColorWithInformation(Picture& pict, size_t rowIndex, size_t lineIndex, CellType cType) const
{
	return pict.setColor(rowIndex, lineIndex, cType);
}

void IMethod::addInfoInQueue(std::vector<PaintCellInfo>& queue, size_t rowIndex, size_t lineIndex, CellType cType) const
{
	queue.push_back(PaintCellInfo(rowIndex, lineIndex, cType));
}
