﻿#include "src/solution.h"
#include "src/picture/picture.h"

#include <iostream>

int main()
{
	Solution maintask("condition", "additional color condition");

	std::cout << "Picture before:\n";
	std::cout << maintask.getPicture();

	bool earlyCycleOut = maintask.nonogramSolution();

	// обработка причины прекращения цикла
	if (earlyCycleOut)
	{
		std::cout << "\nPicture dont finish:(\n";
	}

	std::cout << "Finaly picture:\n";
	maintask.getPicture().printToConsoleColor(Color::black, Color::darkBlue);
	std::cin.get();

	std::vector<PaintCellInfo> cells = maintask.getQueue().get();
	std::cout << "Cells queue:\n";

	size_t index = 0;
	for (const auto& cell : cells)
	{
		std::cout << ++index << ": ";
		std::cout << cell.rowNumber << " ";
		std::cout << cell.indexInRow << " ";
		std::cout << static_cast<int>(cell.color);
		std::cout << "\n";
	}
}
