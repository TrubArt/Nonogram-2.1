#include "src/solution.h"
#include "src/filesWork/loadManagerCpp.h"

#include <iostream>

int main()
{
	// .txt к названию добавляется в FileLoaderCpp
	std::vector<std::string> files = { "additional color condition", "condition", "size" };
	std::string directory = "C:\\Users\\user\\source\\repos\\Nonogram 2.1\\level";
	LoadManagerCpp loadManager(directory, files);

	Solution maintask(loadManager);

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
