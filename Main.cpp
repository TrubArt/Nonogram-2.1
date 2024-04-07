#include <iostream>
#include <Windows.h>
#include "headers/Solution.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Picture m(5, 6);

	std::cout << m << "\n";
	m.colorSet(1, 2, CellType::black);
	std::cout << m << "\n";

	Picture copy(m);
	copy.colorSet(2, 3, CellType::white);
	m.colorSet(2, 3, CellType::black);

	std::cout << m << "\n";
	std::cout << copy << "\n";

}
