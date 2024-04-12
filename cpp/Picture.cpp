#include "../headers/Picture.h"

namespace
{
	// ������� ����� ��� �������� ������������� ����� � ��������
	bool checkSynchronization(const std::vector<Line*>& rows, const std::vector<Line*>& columns)
	{
		for (int i = 0; i < rows.size(); i++)
			for (int j = 0; j < columns.size(); j++)
				if (rows[i]->getCellType(j) != columns[j]->getCellType(i))
					return false;

		return true;
	} // �� ������ ������
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
		rows[i] = new Line(*x.rows[i]);
	for (int i = 0; i < columns.size(); i++)
		columns[i] = new Line(*x.columns[i]);
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
		// ��������������� ������� ������
		for (auto& i : rows)
			if (i)
				delete i;
		for (auto& i : columns)
			if (i)
				delete i;

		rows.resize(x.rows.size());
		columns.resize(x.columns.size());

		for (int i = 0; i < rows.size(); i++)
			rows[i] = new Line(*x.rows[i]);
		for (int i = 0; i < columns.size(); i++)
			columns[i] = new Line(*x.columns[i]);
	}

	return *this;
}

bool Picture::operator==(const Picture& x) const
{
	for (int i = 0; i < rows.size(); i++)
		if (*rows[i] != *x.rows[i])
			return false;

	return true;
}

bool Picture::operator!=(const Picture& x) const
{
	return !(*this == x);
}

const Line* Picture::getPtr(std::pair<int, int> x) const
{
	if (x.first == 0)
		return rows[x.second];
	else return columns[x.second];
}

void Picture::setColor(int rowNumber, int index, CellType type)
{
	if (!checkSynchronization(rows, columns))
	{
		std::cerr << "�������� ������������� �������!!!\n";
		std::exit(1);
	}

	// ���������� 2 ������, ����� ���� ����������� ��������
	// � � ����� ������ ����� � � ����� ������ ��������
	rows[rowNumber]->setCellType(index, type);
	columns[index]->setCellType(rowNumber, type);
}

CellType Picture::getColor(int rowNumber, int index)
{
	return rows[rowNumber]->getCellType(index);
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
	out << pict.toString();
	return out;
}
