#include "interpreter_integer.h"

namespace interpreter {
	void addx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 266
		rGPR[inst.rD] = rGPR[inst.rA] + rGPR[inst.rB]; //do operation
		if (inst.Rc | inst.OE) //handle o. instructions
			cpu->update_info_regs(rGPR[inst.rA], rGPR[inst.rB], rGPR[inst.rD], inst.Rc, inst.OE);
	}

	void addcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 10
		rGPR[inst.rD] = rGPR[inst.rA] + rGPR[inst.rB]; //do operation
		cpu->xer_carry(rGPR[inst.rA], rGPR[inst.rB]); //set carry bit
		if (inst.Rc | inst.OE) //handle o. instructions
			cpu->update_info_regs(rGPR[inst.rA], rGPR[inst.rB], rGPR[inst.rD], inst.Rc, inst.OE);
	}

	void addex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 138
		rGPR[inst.rD] = rGPR[inst.rA] + rGPR[inst.rB] + cpu->xer.CA; //do operation
		cpu->xer_carry2(rGPR[inst.rA], rGPR[inst.rB], cpu->xer.CA); //set carry bit
		if (inst.Rc | inst.OE) //handle o. instructions
			cpu->update_info_regs(rGPR[inst.rA], rGPR[inst.rB], rGPR[inst.rD], inst.Rc, inst.OE);
	}

	void addi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 14
		if (inst.rA)
			rGPR[inst.rD] = rGPR[inst.rA] + EXTS(inst.SIMM);
		else
			rGPR[inst.rD] = EXTS(inst.SIMM);
	}

	void addicx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 12, 13
		rGPR[inst.rD] = rGPR[inst.rA] + EXTS(inst.SIMM);
		cpu->xer_carry(rGPR[inst.rA], EXTS(inst.SIMM)); //set carry bit
		if (inst.opcode == 13) //addic.
			cpu->update_info_regs(rGPR[inst.rA], EXTS(inst.SIMM), rGPR[inst.rD], true, false);
	}

	void addis(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 15
		if (inst.rA) //addis
			rGPR[inst.rD] = rGPR[inst.rA] + (inst.SIMM << 16);
		else //lis
			rGPR[inst.rD] = inst.SIMM << 16;
	}

	//"b" is -1 instead of inst.rB re: addex
	void addmex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 234
		rGPR[inst.rD] = rGPR[inst.rA] + 0xFFFFFFFF + cpu->xer.CA; //do operation
		cpu->xer_carry2(rGPR[inst.rA], 0xFFFFFFFF, cpu->xer.CA); //set carry bit
		if (inst.Rc | inst.OE) //handle o. instructions
			cpu->update_info_regs(rGPR[inst.rA], 0xFFFFFFFF, rGPR[inst.rD], inst.Rc, inst.OE);
	}

	//"b" is 0 instead of inst.rB re: addex
	void addzex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 202
		rGPR[inst.rD] = rGPR[inst.rA] + cpu->xer.CA; //do operation
		cpu->xer_carry2(rGPR[inst.rA], 0, cpu->xer.CA); //set carry bit
		if (inst.Rc | inst.OE) //handle o. instructions
			cpu->update_info_regs(rGPR[inst.rA], 0, rGPR[inst.rD], inst.Rc, inst.OE);
	}

	void divwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 491

	}

	void divwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 459

	}

	void mulhwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 75

	}

	void mulhwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 11

	}

	void mulli(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 7

	}

	void mullwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 235

	}

	void negx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 104

	}

	void subfx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 40

	}

	void subfcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 8

	}

	void subfex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 136

	}

	void subficx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 8

	}

	void subfmex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 232

	}

	void subfzex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 200

	}
}