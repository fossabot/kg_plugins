#include "JsonStorage.h"

#include <iomanip>
#include <sstream>

namespace aeflg {

std::string escapeJsString(const std::string& value)
{
	std::string out;
	out.reserve(value.size() + 16);
	for (const char ch : value) {
		switch (ch) {
		case '\\': out += "\\\\"; break;
		case '"': out += "\\\""; break;
		case '\r': out += "\\r"; break;
		case '\n': out += "\\n"; break;
		case '\t': out += "\\t"; break;
		default: out += ch; break;
		}
	}
	return out;
}

std::string settingsToJson(const GridSettings& settings)
{
	std::ostringstream os;
	os << std::fixed << std::setprecision(3);
	os << "{";
	os << "\"plugin\":\"AE_Figma_Layout_Grid_AEX\",";
	os << "\"version\":\"0.1.0\",";
	os << "\"columns\":{";
	os << "\"count\":" << settings.columns.count << ",";
	os << "\"marginLeft\":" << settings.columns.marginLeft << ",";
	os << "\"marginRight\":" << settings.columns.marginRight << ",";
	os << "\"gutter\":" << settings.columns.gutter << "},";
	os << "\"rows\":{";
	os << "\"count\":" << settings.rows.count << ",";
	os << "\"marginTop\":" << settings.rows.marginTop << ",";
	os << "\"marginBottom\":" << settings.rows.marginBottom << ",";
	os << "\"gutter\":" << settings.rows.gutter << "},";
	os << "\"generatedGuides\":[";
	for (size_t i = 0; i < settings.generatedGuides.size(); ++i) {
		const auto& g = settings.generatedGuides[i];
		if (i != 0) {
			os << ",";
		}
		os << "{\"orientation\":" << g.orientation << ",\"position\":" << g.position << "}";
	}
	os << "]}";
	return os.str();
}

} // namespace aeflg
