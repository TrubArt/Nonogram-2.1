#include "../headers/NumberAndBorder.h"
#include "../headers/Line.h"

NumberAndBorders::NumberAndBorders(int number, const myP& dia, const myP& realdia) : dia(dia), realDia(realdia)
{
	this->number = number;
	isExistRD = false;
}

int NumberAndBorders::getNum() const
{
	return number;
}

const NumberAndBorders::myP& NumberAndBorders::getD() const
{
	return dia;
}

const NumberAndBorders::myP& NumberAndBorders::getRD() const
{
	return realDia;
}

bool NumberAndBorders::getFlagExistRd() const
{
	return isExistRD;
}

void NumberAndBorders::setD(const myP& x)
{
	dia = x;
}

void NumberAndBorders::setFlagExistRd(bool flag)
{
	isExistRD = flag;
}

void NumberAndBorders::setRD(const myP& x)
{
	realDia = x;
}

void NumberAndBorders::updateNumberAndBorders(const Line* const data)
{
	this->updateDIf0InEdges(data);
	this->updateRDviaD();
	this->updateDviaRD(data);
}

std::string NumberAndBorders::toString() const
{
	std::string answer;
	answer.append(std::to_string(number) +
		"{D[" + std::to_string(dia.first) + "," + std::to_string(dia.second) + "), RD[");

	if (isExistRD)
		answer.append(std::to_string(realDia.first) + "," + std::to_string(realDia.second));
	else
		answer.append("NaN");

	answer.append(")}");
	return answer;
}

void NumberAndBorders::updateRDviaD()
{
	if (isExistRD)
	{
		if (realDia.first < dia.first)
			realDia.first = dia.first;
		if (realDia.second > dia.second)
			realDia.second = dia.second;
	}
}

void NumberAndBorders::updateDIf0InEdges(const Line* const data)
{
	int leftBlack = data->getLeftIndexTypeCell(dia.first, dia.second, CellType::white);		// первый левый CellType::white в D
	while (leftBlack != -1 && leftBlack - dia.first < number) {	// если leftBlack находится и расстояние от него до dia.first меньше самого number,
		dia.first = leftBlack + 1;								// то number туда не поместится, соответственно сдвигаем границу
		leftBlack = data->getLeftIndexTypeCell(dia.first, dia.second, CellType::white);
	}

	int rightBlack = data->getRightIndexTypeCell(dia.first, dia.second, CellType::white);	// первый правый CellType::white в D
	while (rightBlack != -1 && (dia.second - 1) - rightBlack < number) {	// если leftBlack находится и расстояние от него до dia.first меньше самого number,
		dia.second = rightBlack;										// то number туда не поместится, соответственно сдвигаем границу
		rightBlack = data->getRightIndexTypeCell(dia.first, dia.second, CellType::white);
	}
}

void NumberAndBorders::updateDviaRD(const Line* const data)
{
	int numberOfBlack = data->getCountTypeCell(realDia.first, realDia.second, CellType::black);
	if (numberOfBlack != 0)
	{
		int leftBlack = data->getLeftIndexTypeCell(realDia.first, realDia.second, CellType::black);
		int rightBlack = data->getRightIndexTypeCell(realDia.first, realDia.second, CellType::black);
		if (dia.first < leftBlack - (number - numberOfBlack))
			dia.first = leftBlack - (number - numberOfBlack);
		if (dia.second > rightBlack + (number - numberOfBlack) + 1)
			dia.second = rightBlack + (number - numberOfBlack) + 1;

		this->updateRDviaD();
	}
}
