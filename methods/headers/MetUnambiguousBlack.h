#pragma once
#ifndef METHOD_UNAMBIGUOUSBLACK_NONOGRAM
#define METHOD_UNAMBIGUOUSBLACK_NONOGRAM
#include "../IMethod.h"

// определяет 100% CellType::black в центре диапазона каждого числа
class UnambiguousBlack : public IMethod
{
public:
	void realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const override;
};

#endif // !METHOD_UNAMBIGUOUSBLACK_NONOGRAM
