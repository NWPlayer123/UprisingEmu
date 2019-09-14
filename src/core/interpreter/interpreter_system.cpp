#include "interpreter_system.h"

namespace interpreter {
	void mcrxr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 512
		cpu->CR[inst.crfD] = cpu->xer.hex >> 28; //set crfD to top 4 bits of xer
		cpu->xer.hex &= 0x0FFFFFFF; //clear xer
	}

	void mfcr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 19

	}

	void mfmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 83

	}

	void mfspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 339

	}

	void mftb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 371

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
}