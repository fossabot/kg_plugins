#pragma once

#include "GridModel.h"

namespace aeflg {

std::vector<ColumnRect> calculateColumns(double compWidth, double compHeight, const GridSettings& settings);
std::vector<RowRect> calculateRows(double compWidth, double compHeight, const GridSettings& settings);
std::vector<GridGuide> calculateColumnGuides(double compWidth, const GridSettings& settings);
std::vector<GridGuide> calculateRowGuides(double compHeight, const GridSettings& settings);
std::vector<GridGuide> calculateAllGuides(double compWidth, double compHeight, const GridSettings& settings);

} // namespace aeflg
