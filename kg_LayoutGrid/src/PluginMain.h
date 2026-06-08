#pragma once

#include "AEConfig.h"
#ifdef AE_OS_WIN
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#include <windows.h>
#endif

#include "AE_GeneralPlug.h"
#include "AE_Macros.h"
#include "AEGP_SuiteHandler.h"
#include "entry.h"

extern "C" {
DllExport A_Err EntryPointFunc(
	struct SPBasicSuite* pica_basicP,
	A_long major_versionL,
	A_long minor_versionL,
	const A_char* file_pathZ,
	const A_char* res_pathZ,
	AEGP_PluginID aegp_plugin_id,
	void* global_refconPV);
}
