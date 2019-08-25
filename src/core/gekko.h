#pragma once
#include "hardware/DSP.h"
#include "gekkoreg.h"
#include "memory.h"
#include "../types.h"

namespace gekko {
	typedef struct GekkoCPU {
		GekkoCPU(void);

		u32 gpr[32] = { 0 };
		u32 spr[1024] = { 0 }; //need to gateway
		MSR msr; //machine state register
		memory::page memory[0x100000] = { memory::TYPE_INVALID, nullptr }; //0x100000000 (4GB) / 0x1000 (4KB)
	} GekkoCPU;

	inline void hwreg(GekkoCPU& cpu, const u32& address, void* HandleInput);
}