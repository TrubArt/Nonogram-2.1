#pragma once
#ifndef METHOD_UNAMBIGUOUSBLACK_NONOGRAM
#define METHOD_UNAMBIGUOUSBLACK_NONOGRAM
#include "../Imethod.h"

// ���������� 100% CellType::black � ������ ��������� ������� �����
class UnambiguousBlack : public Imethod
{
public:
	void realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const override;
};

#endif // !METHOD_UNAMBIGUOUSBLACK_NONOGRAM