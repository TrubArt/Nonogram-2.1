#include <iostream>
#include <Windows.h>
#include "headers/Solution.h"
#include "headers/Picture.h"

bool nonogramSolution(Solution& maintask)
{
	int step = 1;
	bool noChangesAfterCycle = false;

	while (!noChangesAfterCycle && !maintask.isEndOfWork())
	{
		Picture pictureToCompare{ maintask.getPicture() };

		// работа методов
		maintask.callingMethods();

		// если после работы методов нет изменений
		if (pictureToCompare == maintask.getPicture())
			noChangesAfterCycle = true;

		step++;
	}

	return noChangesAfterCycle;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Solution maintask1("Condition", "Additional color condition");

	std::cout << "Изображение до решения:\n";
	std::cout << maintask1.getPicture();

	bool earlyCycleOut = nonogramSolution(maintask1);

	// обработка причины прекращения цикла
	if (earlyCycleOut)
		std::cout << "\nИзображение не закончено после отработки всех методов:(\n";

	std::cout << "Изображение после окончания решения:\n";
	std::cout << maintask1.getPicture();
}
