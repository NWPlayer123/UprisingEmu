#include "debug_branch.h"

namespace debug {
	// Branch Instructions
	void bx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 18
		printf("%-12ssub_%08X\n", "b", inst.AA ? inst.BD << 2 : EXTS(inst.BD << 2) + cpu->oldpc);
	}

	void bcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 16
		std::string opcode = "";
		switch ((inst.BO << 5) | inst.BI) {
			case (12 << 5) | 0: opcode = "blt"; break;
			case (12 << 5) | 1: opcode = "bgt"; break;
			case (12 << 5) | 2: opcode = "beq"; break;
			case (4 << 5) | 10: opcode = "bne"; break;
			case (16 << 5) | 0: opcode = "bdnz"; break;
			default: opcode = "bc"; break;
		}
		opcode += inst.BO & 1 ? "+" : ""; //branch prediction hint
		printf("%-12ssub_%08X\n", opcode.c_str(), inst.AA ? inst.BD << 2 : EXTS(inst.BD << 2) + cpu->oldpc);
	}

	void bcctrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 19 ext 528
	}

	void bclrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 19 ext 16

	}
}