#include "GridMath.h"

#include <cmath>

namespace aeflg {

std::vector<ColumnRect> calculateColumns(double compWidth, double compHeight, const GridSettings& settings)
{
	std::vector<ColumnRect> rects;
	const int count = settings.columns.count;
	if (count < 1) {
		return rects;
	}

	const double availableWidth = compWidth - settings.columns.marginLeft - settings.columns.marginRight;
	const double columnWidth = (availableWidth - settings.columns.gutter * (count - 1)) / count;
	if (columnWidth <= 0.0) {
		return rects;
	}

	rects.reserve(static_cast<size_t>(count));
	for (int i = 0; i < count; ++i) {
		const double left = settings.columns.marginLeft + i * (columnWidth + settings.columns.gutter);
		rects.push_back({ left, left + columnWidth, 0.0, compHeight });
	}
	return rects;
}

std::vector<RowRect> calculateRows(double compWidth, double compHeight, const GridSettings& settings)
{
	std::vector<RowRect> rects;
	const int count = settings.rows.count;
	if (count < 1) {
		return rects;
	}

	const double availableHeight = compHeight - settings.rows.marginTop - settings.rows.marginBottom;
	const double rowHeight = (availableHeight - settings.rows.gutter * (count - 1)) / count;
	if (rowHeight <= 0.0) {
		return rects;
	}

	rects.reserve(static_cast<size_t>(count));
	for (int i = 0; i < count; ++i) {
		const double top = settings.rows.marginTop + i * (rowHeight + settings.rows.gutter);
		rects.push_back({ 0.0, compWidth, top, top + rowHeight });
	}
	return rects;
}

std::vector<GridGuide> calculateColumnGuides(double compWidth, const GridSettings& settings)
{
	std::vector<GridGuide> guides;
	const auto rects = calculateColumns(compWidth, 1.0, settings);
	guides.reserve(rects.size() * 2);
	for (const auto& r : rects) {
		guides.push_back({ 1, static_cast<int>(std::llround(r.left)) });
		guides.push_back({ 1, static_cast<int>(std::llround(r.right)) });
	}
	return guides;
}

std::vector<GridGuide> calculateRowGuides(double compHeight, const GridSettings& settings)
{
	std::vector<GridGuide> guides;
	const auto rects = calculateRows(1.0, compHeight, settings);
	guides.reserve(rects.size() * 2);
	for (const auto& r : rects) {
		guides.push_back({ 0, static_cast<int>(std::llround(r.top)) });
		guides.push_back({ 0, static_cast<int>(std::llround(r.bottom)) });
	}
	return guides;
}

std::vector<GridGuide> calculateAllGuides(double compWidth, double compHeight, const GridSettings& settings)
{
	auto guides = calculateColumnGuides(compWidth, settings);
	auto rows = calculateRowGuides(compHeight, settings);
	guides.insert(guides.end(), rows.begin(), rows.end());
	return guides;
}

} // namespace aeflg
