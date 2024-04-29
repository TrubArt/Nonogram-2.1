#include "../headers/Cell.h"

Cell::Cell()
{ 
	cellType = CellType::undefined; 
}

Cell::Cell(CellType Ctype) 
{ 
	cellType = Ctype; 
}

void Cell::set(CellType Ctype)
{
	cellType = Ctype;
}

CellType Cell::get() const
{
	return cellType;
}

std::string Cell::toString() const
{
	std::string answer;
	if (cellType == CellType::undefined)
		answer.append("*");
	else
		answer.append(std::to_string(static_cast<int>(cellType)));

	return answer;
}

std::ostream& operator<<(std::ostream& out, const Cell& cell)
{
	out << cell.toString();
	return out;
}
