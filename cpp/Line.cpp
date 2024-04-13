#include "../headers/Line.h"
#include <algorithm>

Line::Line(int size)
{
	data.resize(size);
	for (auto& i : data)
		i = new Cell();
}

Line::Line(const Line& x)
{
	data.resize(x.data.size());

	for (int i = 0; i < data.size(); i++)
		data[i] = new Cell(x.data[i]->get());
}

Line::~Line()
{
	for (const auto& i : data)
		delete i;
}

Line& Line::operator=(const Line& x)
{
	if (&x != this)
	{
		for (const auto& i : data) // �������������� ������������� ������
			if (i)
				delete i;

		data.resize(x.data.size());

		for (int i = 0; i < data.size(); i++)
			data[i] = new Cell(x.data[i]->get());
	}

	return *this;
}

bool Line::operator==(const Line& x) const
{
	if (data.size() != x.data.size())
		return false;
	else
	{
		for (int i = 0; i < data.size(); i++)
			if (data[i]->get() != x.data[i]->get())
				return false;
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
	return std::count_if(data.begin(), data.end(), [Ctype](Cell* x) { return x->get() == Ctype ? true : false; });
}

std::string Line::toString() const
{
	std::string answer;
	for (const auto& i : data)
		if (&i == data.data())
			answer.append(i->toString());
		else
			answer.append(" " + i->toString());

	return answer;
}

std::ostream& operator<<(std::ostream& out, const Line& line)
{
	out << line.toString();
	return out;
}
