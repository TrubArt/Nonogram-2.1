#pragma once
#ifndef METHOD_STARTENDNUM_NONOGRAM
#define METHOD_STARTENDNUM_NONOGRAM
#include "../Imethod.h"

// ���� start || end == CellType::black, �� ���������� ����������� ������ ������������� �������/���������� �����
class StartEndNum : public Imethod
{
public:
	void realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const override;
};

#endif // !METHOD_STARTENDNUM_NONOGRAM
