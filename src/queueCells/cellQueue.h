#ifndef CELLQUEUE_NONOGRAM
#define CELLQUEUE_NONOGRAM

#include "paintCellInfo.h"

#include <vector>

class CellQueue
{
	std::vector<PaintCellInfo> data;

public:
	CellQueue() = default;
	std::vector<PaintCellInfo>& get();
	const std::vector<PaintCellInfo>& get() const;

	// �� ���� ������ � ������� ������� ������
	// �������� �� ������� � ����� � ����������� :)
	void customPush(const PaintCellInfo& el);
};

#endif // !CELLQUEUE_NONOGRAM
