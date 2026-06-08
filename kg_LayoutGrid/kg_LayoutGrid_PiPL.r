#include "AEConfig.h"
#include "AE_EffectVers.h"

#ifndef AE_OS_WIN
	#include "AE_General.r"
#endif

#define KG_LAYOUTGRID_EFFECT_VERSION 524289
#define KG_LAYOUTGRID_EFFECT_FLAGS 33555460
#define KG_LAYOUTGRID_EFFECT_FLAGS2 134217728

resource 'PiPL' (16000) {
	{
		Kind {
			AEGP
		},
		Name {
			"kg_LayoutGrid"
		},
		Category {
			"KG_plugins"
		},
		Version {
			196608
		},
#ifdef AE_OS_WIN
		CodeWin64X86 {"EntryPointFunc"},
#else
	#ifdef AE_OS_MAC
		CodeMacIntel64 {"EntryPointFunc"},
		CodeMacARM64 {"EntryPointFunc"},
	#endif
#endif
	}
};

resource 'PiPL' (16001) {
	{
		Kind {
			AEEffect
		},
		Name {
			"kg_LayoutGrid"
		},
		Category {
			"KG_plugins"
		},
#ifdef AE_OS_WIN
	#ifdef AE_PROC_INTELx64
		CodeWin64X86 {"EffectMain"},
	#endif
#else
	#ifdef AE_OS_MAC
		CodeMacIntel64 {"EffectMain"},
		CodeMacARM64 {"EffectMain"},
	#endif
#endif
		AE_PiPL_Version {
			2,
			0
		},
		AE_Effect_Spec_Version {
			PF_PLUG_IN_VERSION,
			PF_PLUG_IN_SUBVERS
		},
		AE_Effect_Version {
			KG_LAYOUTGRID_EFFECT_VERSION
		},
		AE_Effect_Info_Flags {
			0
		},
		AE_Effect_Global_OutFlags {
			KG_LAYOUTGRID_EFFECT_FLAGS
		},
		AE_Effect_Global_OutFlags_2 {
			KG_LAYOUTGRID_EFFECT_FLAGS2
		},
		AE_Effect_Match_Name {
			"kg_LayoutGrid"
		},
		AE_Reserved_Info {
			0
		}
	}
};
