#ifndef METHOD_LAST_COLOR_SET
#define METHOD_LAST_COLOR_SET

#include "iMethod.h"

// закрашивает все CellType::undefined в цвет param
class LastColorSet : public IMethod
{
public:
	void realization(const Condition& cond, Picture& pict, std::vector<PaintCellInfo>& queue, bool isColumn, size_t rowOrColIndex) const override;
	std::string methodName() const override;
	std::string principleOfMethodWork() const override;
};

#endif // !METHOD_LAST_COLOR_SET
