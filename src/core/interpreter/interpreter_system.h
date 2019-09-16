#pragma once

#include "..//..//types.h"
#include "..//gekko.h"

namespace interpreter {
	#define	rGPR cpu->gpr

	// Memory Synchronization Instructions
	void eieio(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 854
	void isync(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 19 ext 150
	void lwarx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 20
	void stwcx_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 150
	void sync(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 598

	void mcrxr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 512
	void mfcr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 19
	void mfmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 83
	void mfspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 339
	void mftb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 371
	void mtcrf(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 144
	void mtmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 146
	void mtspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 467

	void mfsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 595
	void mfsrin(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 659
	void mtsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 210
	void mtsrin(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 242
}