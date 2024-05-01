#include <iostream>
#include <Windows.h>
#include "headers/Solution.h"
#include "headers/Picture.h"
#include "headers/MethodsVectorShell.h"

bool nonogramSolution(Solution& maintask, const std::vector<IMethod*>& methods)
{
	int step = 1;
	bool noChangesAfterCycle = false;

	while (!noChangesAfterCycle && !maintask.isEndOfWork())
	{
		Picture pictureToCompare{ maintask.getPicture() };

		// работа методов
		maintask.callingMethods(methods);

		// если после работы методов нет изменений
		if (pictureToCompare == maintask.getPicture() && !maintask.isEndOfWork())
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
	
	// для добавления новых методов нужно изменить конструктор по умолчанию MethodsVectorShell
	// считаю такое решение приемлимым. Если нужно будет изменить порядок вызова методов, то
	// всегда можно дописать методы для работы с этим классом
	MethodsVectorShell vect;

	std::cout << "Изображение до решения:\n";
	std::cout << maintask1.getPicture();

	bool earlyCycleOut = nonogramSolution(maintask1, vect.get());

	// обработка причины прекращения цикла
	if (earlyCycleOut)
		std::cout << "\nИзображение не закончено после отработки всех методов:(\n";

	std::cout << "Изображение после окончания решения:\n";
	std::cout << maintask1.getPicture();
}
