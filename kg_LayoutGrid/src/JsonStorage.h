#pragma once

#include "GridModel.h"

#include <string>

namespace aeflg {

std::string settingsToJson(const GridSettings& settings);
std::string escapeJsString(const std::string& value);

} // namespace aeflg
