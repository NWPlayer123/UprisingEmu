#pragma once

#include "..//..//..//types.h"
#include "..//..//gekko.h"
#include "debug_print.h"

namespace debug {
	void mcrxr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 512
	void mfcr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 19
	void mfmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 83
	void mfspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 339
	void mftb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 371
	void mtcrf(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 144
	void mtmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 146
	void mtspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 467
}