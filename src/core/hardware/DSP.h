#pragma once

#include "../../types.h"

namespace DSP {
	const u32 REGISTER_BASE = 0x0C005000;
	void HandleWrite(u32& value, void* address);
	typedef struct DSPRegisterMap {
		u16 temp1[9]; //idk
		u16 AR_INFO;
	} DSPRegisterMap;
}