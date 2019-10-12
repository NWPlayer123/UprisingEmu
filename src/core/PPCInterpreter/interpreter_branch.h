#pragma once

#include "..//..//types.h"
#include "..//gekko.h"

namespace PPCInterpreter {
	#define rGPR cpu->gpr

	// Branch Instructions
	void bx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);         //opcode 18
	void bcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 16
	void bcctrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 19 ext 528
	void bclrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 19 ext 16
}