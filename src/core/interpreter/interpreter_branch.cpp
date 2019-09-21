#include "interpreter_branch.h"

namespace interpreter {
	u32 ctr_ok, cond_ok;

	// Branch Instructions
	void bx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 18
		if (inst.LK) //linking, update link register
			cpu->lr = cpu->pc + 4;

		cpu->oldpc = cpu->pc;
		if (inst.AA) //absolute address
			cpu->pc = EXTS(inst.LI << 2);
		else //relative, add (will go backwards if negative)
			cpu->pc += EXTS(inst.LI << 2);
	}

	void bcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 16
		if (false) {
			printf("%04X\n", inst.BD << 2);
			printf("%d\n", EXTS(inst.BD << 2));
			printf("%08X\n", cpu->pc);
			printf("%08X\n", cpu->pc + EXTS(inst.BD << 2));
			printf("%d\n", inst.BO);
			printf("%d\n", inst.BI);
			printf("%08X\n", cpu->CR.hex);
		}
		if (!inst_BO_2) cpu->ctr--; //not ignoring ctr, decrement
		ctr_ok = inst_BO_2 || ((cpu->ctr != 0) ^ inst_BO_3);
		cond_ok = inst_BO_0 || (cpu->CR.getbit(inst.BI) ^ !inst_BO_1);
		if (ctr_ok && cond_ok) {
			if (inst.LK) //linking, update link register
				cpu->lr = cpu->pc + 4;

			cpu->oldpc = cpu->pc;
			if (inst.AA) //absolute address
				cpu->pc = EXTS(inst.BD << 2);
			else //relative, add (will go backwards if negative)
				cpu->pc += EXTS(inst.BD << 2);
		}
		else {
			cpu->oldpc = cpu->pc;
			cpu->pc += 4;
		}
	}

	void bcctrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 19 ext 528

	}

	void bclrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 19 ext 16

	}
}