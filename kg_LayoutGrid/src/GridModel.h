#pragma once

#include <string>
#include <vector>

namespace aeflg {

struct GridColumns {
	int count = 12;
	double marginLeft = 80.0;
	double marginRight = 80.0;
	double gutter = 24.0;
};

struct GridRows {
	int count = 12;
	double marginTop = 80.0;
	double marginBottom = 80.0;
	double gutter = 24.0;
};

struct GridGuide {
	int orientation = 0; // 0 horizontal, 1 vertical
	int position = 0;
};

struct GridSettings {
	GridColumns columns;
	GridRows rows;
	std::vector<GridGuide> generatedGuides;
};

struct ColumnRect {
	double left = 0.0;
	double right = 0.0;
	double top = 0.0;
	double bottom = 0.0;
};

struct RowRect {
	double left = 0.0;
	double right = 0.0;
	double top = 0.0;
	double bottom = 0.0;
};

struct ValidationResult {
	bool ok = true;
	std::string message;
};

} // namespace aeflg
