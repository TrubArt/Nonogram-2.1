#pragma once
#ifndef METHOD_UNAMBIGUOUSWHITE_NONOGRAM
#define METHOD_UNAMBIGUOUSWHITE_NONOGRAM
#include "../IMethod.h"

// определяет 100% CellType::white
class UnambiguousWhite : public IMethod
{
public:
	void realization(const Condition* const cond, Picture* pict, const std::pair<int, int>& posit) const override;
	std::string methodName() const override;
	std::string principleOfMethodWork() const override;
};

#endif // !METHOD_UNAMBIGUOUSWHITE_NONOGRAM
