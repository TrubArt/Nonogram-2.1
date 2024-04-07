#include "../headers/Picture.h"

namespace
{
	// функция нужна для проверки синхронизации строк и столбцов
	bool checkSynchronization(const std::vector<Line*>& rows, const std::vector<Line*>& columns)
	{
		for (int i = 0; i < rows.size(); i++)
			for (int j = 0; j < columns.size(); j++)
				if (rows.at(i)->getCellType(j) != columns.at(j)->getCellType(i))
					return false;

		return true;
	} // на релизе убрать
}

Picture::Picture(int N, int M)
{
	rows.resize(N);
	columns.resize(M);

	for (auto& i : rows)
		i = new Line(M);
	for (auto& i : columns)
		i = new Line(N);
}

Picture::Picture(const Picture& x)
{
	rows.resize(x.rows.size());
	columns.resize(x.columns.size());

	for (int i = 0; i < rows.size(); i++)
		rows.at(i) = new Line(*x.rows.at(i));
	for (int i = 0; i < columns.size(); i++)
		columns.at(i) = new Line(*x.columns.at(i));
}

Picture::~Picture()
{
	for (auto& i : rows)
		delete i;
	for (auto& i : columns)
		delete i;
}

Picture& Picture::operator=(const Picture& x)
{
	if (&x != this)
	{
		// предварительная очистка памяти
		for (auto& i : rows)
			if (i)
				delete i;
		for (auto& i : columns)
			if (i)
				delete i;

		rows.resize(x.rows.size());
		columns.resize(x.columns.size());

		for (int i = 0; i < rows.size(); i++)
			rows.at(i) = new Line(*x.rows.at(i));
		for (int i = 0; i < columns.size(); i++)
			columns.at(i) = new Line(*x.columns.at(i));
	}

	return *this;
}

void Picture::colorSet(int i, int j, CellType type)
{
	// необходимо 2 вызова, чтобы была однозначная картинка
	// и с точки зрения строк и с точки зрения столбцов
	rows.at(i)->setCellType(j, type);
	columns.at(j)->setCellType(i, type);
}

std::string Picture::toString() const
{
	std::string answer;
	for (const auto& i : rows)
		answer.append(i->toString() + "\n");
	return answer;
}

std::ostream& operator<<(std::ostream& out, const Picture& pict)
{
	if (!checkSynchronization(pict.rows, pict.columns))
	{
		std::cerr << "Нарушена синхронизация таблицы!!!\n";
		std::exit(1);
	}

	out << pict.toString();
	return out;
}
