#pragma once
#include "hardware/DSP.h"
#include "hardware/MI.h"
#include "gekkoreg.h"
#include "memory.h"
#include "../types.h"

namespace gekko {
	typedef struct GekkoCPU {
		GekkoCPU(void);
		inline void hwreg(u32 address);
		void write16(u32& address);

		u32 gpr[32] = { 0 };
		u32 spr[1024] = { 0 }; //need to gateway
		MSR msr; //machine state register
		std::byte* memory[0x100000] = { nullptr }; //0x100000000 (4GB) / 0x1000 (4KB)
		u32 sr[16] = { 0 };
		UpperBAT ubat[8];
		LowerBAT lbat[8];
	} GekkoCPU;
}