#include "../headers/Line.h"
#include <algorithm>
#include <Windows.h>
//#include <iostream>
//#include <conio.h>
//#include <stdio.h>

Line::Line(int size)
{
	data.resize(size);
	for (auto& i : data)
	{
		i = new Cell();
	}
}

Line::Line(const Line& x)
{
	data.resize(x.data.size());

	for (int i = 0; i < static_cast<int>(data.size()); ++i)
	{
		data[i] = new Cell(x.data[i]->get());
	}
}

Line::~Line()
{
	for (const auto& i : data)
	{
		delete i;
	}
}

Line& Line::operator=(const Line& x)
{
	if (&x != this)
	{
		for (const auto& i : data) // предварительно освобождается память
		{
			if (i)
				delete i;
		}

		data.resize(x.data.size());

		for (int i = 0; i < static_cast<int>(data.size()); ++i)
		{
			data[i] = new Cell(x.data[i]->get());
		}
	}

	return *this;
}

bool Line::operator==(const Line& x) const
{
	if (data.size() != x.data.size())
		return false;
	else
	{
		for (int i = 0; i < static_cast<int>(data.size()); ++i)
		{
			if (data[i]->get() != x.data[i]->get())
				return false;
		}
		return true;
	}
}

bool Line::operator!=(const Line& x) const
{
	return !(*this == x);
}

void Line::setCellType(int index, CellType Ctype)
{
	data[index]->set(Ctype);
}

CellType Line::getCellType(int index) const
{
	return data[index]->get();
}

size_t Line::getSize() const
{
	return data.size();
}

int Line::getCountTypeCell(CellType Ctype) const
{
	//return std::count_if(data.begin(), data.end(), [Ctype](Cell* x) { return x->get() == Ctype ? true : false; });
	return this->getCountTypeCell(0, static_cast<int>(data.size()), Ctype);
}

int Line::getCountTypeCell(int startIndex, int endIndex, CellType Ctype) const
{
	int answer = 0;
	if (startIndex < 0 || endIndex > static_cast<int>(data.size()))
	{
		std::cout << "Выход за границы Line\n";
		return answer;
	}

	for (int i = startIndex; i < endIndex; ++i)
	{
		if (data[i]->get() == Ctype)
			++answer;
	}

	return answer;
}

int Line::getLeftIndexTypeCell(int startIndex, int endIndex, CellType Ctype) const
{
	int answer = -1;
	if (startIndex < 0 || endIndex > static_cast<int>(data.size()))
	{
		std::cout << "Выход за границы Line\n";
		return answer;
	}

	for (int i = startIndex; i < endIndex; ++i)
	{
		if (data[i]->get() == Ctype)
			return i;
	}

	return answer;
}

int Line::getRightIndexTypeCell(int startIndex, int endIndex, CellType Ctype) const
{
	int answer = -1;
	if (startIndex < 0 || endIndex > static_cast<int>(data.size()))
	{
		std::cout << "Выход за границы Line\n";
		return answer;
	}

	for (int i = endIndex - 1; i >= startIndex; --i)
	{
		if (data[i]->get() == Ctype)
			return i;
	}

	return answer;
}

void Line::printToConsoleDifferences(const Line& line) const
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int index = 0; index < static_cast<int>(data.size()); ++index)
	{
		if (data[index]->get() != line.data[index]->get())
		{
			SetConsoleTextAttribute(console, 4);
		}

		if (index == 0)
			std::cout << data[index]->toString();
		else
			std::cout << " " << data[index]->toString();

		SetConsoleTextAttribute(console, 7);
	}
}

std::string Line::toString() const
{
	std::string answer;
	for (const auto& i : data)
	{
		if (&i == data.data())
			answer.append(i->toString());
		else
			answer.append(" " + i->toString());
	}

	return answer;
}

std::ostream& operator<<(std::ostream& out, const Line& line)
{
	out << line.toString();
	return out;
}
