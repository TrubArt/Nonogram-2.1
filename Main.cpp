#include "src/solution.h"
#include "src/picture/picture.h"

#include <iostream>
#define NOMINMAX
#include <Windows.h>

int main()
{
	Solution maintask("Condition", "Additional color condition");

	std::cout << "Picture before:\n";
	std::cout << maintask.getPicture();

	bool earlyCycleOut = maintask.nonogramSolution();

	// обработка причины прекращения цикла
	if (earlyCycleOut)
	{
		std::cout << "\nPicture dont finish:(\n";
	}

	std::cout << "Finaly picture:\n";
	maintask.getPicture().printToConsoleColor(0, 1);
	std::cin.get();

	std::vector<PaintCellInfo> cells = maintask.getQueue();
	std::cout << "Cells queue:\n";

	int index = 1;
	for (const auto& cell : cells)
	{
		std::cout << index++ << ": ";
		std::cout << cell.rowNumber << " ";
		std::cout << cell.indexInRow << " ";
		std::cout << static_cast<int>(cell.color);
		std::cout << "\n";
	}
}
