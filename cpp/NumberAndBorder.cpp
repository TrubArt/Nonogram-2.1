#include "../headers/NumberAndBorder.h"

NumberAndBorders::NumberAndBorders(int number)
{
	this->number = number;
	startDia = -1;
	endDia = -1;
	startRealDia = -1;
	endRealDia = -1;
}

int NumberAndBorders::getNumber() const
{
	return number;
}

void NumberAndBorders::updateNumberAndBorders()
{

}

std::string NumberAndBorders::toString() const
{
	std::string answer;
	answer.append(std::to_string(number) +
		"(D[" + std::to_string(startDia) + "," + std::to_string(endDia) +
		"], RD[" + std::to_string(startRealDia) + "," + std::to_string(endRealDia) + "])");
	return answer;
}
