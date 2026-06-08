#include "GridValidation.h"

namespace aeflg {

static ValidationResult fail(const char* message)
{
	return { false, message };
}

ValidationResult validateSettings(double compWidth, double compHeight, const GridSettings& settings)
{
	if (compWidth <= 0.0 || compHeight <= 0.0) {
		return fail("Active comp size is invalid.");
	}
	if (settings.columns.count < 1 || settings.rows.count < 1) {
		return fail("Count must be 1 or greater.");
	}
	if (settings.columns.marginLeft < 0.0 || settings.columns.marginRight < 0.0 ||
		settings.columns.gutter < 0.0 || settings.rows.marginTop < 0.0 ||
		settings.rows.marginBottom < 0.0 || settings.rows.gutter < 0.0) {
		return fail("Margins and gutters must be 0 or greater.");
	}

	const double availableWidth = compWidth - settings.columns.marginLeft - settings.columns.marginRight;
	const double columnWidth = (availableWidth - settings.columns.gutter * (settings.columns.count - 1)) / settings.columns.count;
	if (columnWidth <= 0.0) {
		return fail("Column width is 0 or negative.");
	}

	const double availableHeight = compHeight - settings.rows.marginTop - settings.rows.marginBottom;
	const double rowHeight = (availableHeight - settings.rows.gutter * (settings.rows.count - 1)) / settings.rows.count;
	if (rowHeight <= 0.0) {
		return fail("Row height is 0 or negative.");
	}

	return {};
}

} // namespace aeflg
