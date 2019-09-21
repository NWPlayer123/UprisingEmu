#include "interpreter_system.h"

namespace interpreter {
	// Memory Synchronization Instructions
	void eieio(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 854

	}

	void isync(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 19

	}

	void lwarx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 20

	}

	void stwcx_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 150

	}

	void sync(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 598

	}

	void mcrxr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 512
		cpu->CR.setreg(inst.crfD, cpu->xer.hex >> 28); //set crfD to top 4 bits of xer
		cpu->xer.hex &= 0x0FFFFFFF; //clear xer
	}

	void mfcr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 19

	}

	void mfmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 83
		rGPR[inst.rD] = cpu->msr.hex;
	}

	void mfspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 339
		switch (inst.spr()) {
			default: rGPR[inst.rS] = cpu->spr[inst.spr()];
		}
	}

	void mftb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 371
		switch (inst.spr()) {
			case 268: rGPR[inst.rD] = (u32)(cpu->count); break;
			case 269: rGPR[inst.rD] = (u32)(cpu->count >> 32); break;
			default: throw format("invalid time base reg: %d", inst.spr());
		}
	}

	void mtcrf(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 144

	}

	void mtmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 146
		cpu->msr.hex = rGPR[inst.rS];
	}

	void mtspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 467
		switch (inst.spr()) {
			default: cpu->spr[inst.spr()] = rGPR[inst.rS];
		}
	}

	//Segment Register Manipulation Instructions
	void mfsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 595

	}

	void mfsrin(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 659

	}

	void mtsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 210
		cpu->sr[inst.SR] = rGPR[inst.rS];
	}

	void mtsrin(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 242

	}
}