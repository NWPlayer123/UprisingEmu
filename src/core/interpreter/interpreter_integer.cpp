#include "interpreter_integer.h"

namespace interpreter {
	// Integer Arithmetic Instructions
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

	void addic(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 12
		rGPR[inst.rD] = rGPR[inst.rA] + EXTS(inst.SIMM);
		cpu->xer_carry(rGPR[inst.rA], EXTS(inst.SIMM)); //set carry bit
	}

	void addic_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 13
		rGPR[inst.rD] = rGPR[inst.rA] + EXTS(inst.SIMM);
		cpu->xer_carry(rGPR[inst.rA], EXTS(inst.SIMM)); //set carry bit
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
		rGPR[inst.rD] = ~rGPR[inst.rA] + rGPR[inst.rB] + 1; //do operation
		if (inst.Rc | inst.OE) //handle o. instructions
			cpu->update_info_regs(rGPR[inst.rA], rGPR[inst.rB], rGPR[inst.rD], inst.Rc, inst.OE);
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

	// Integer Compare Instructions
	void cmp(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 0

	}

	void cmpi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 11

	}

	void cmpl(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 32

	}

	void cmpli(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 10
		u8 temp = cpu->xer.SO ? CR_SO : 0;
		if (inst.UIMM == 0)
			temp |= CR_EQ;
		else //get MSB, which handles sign
			temp |= inst.UIMM & 0x80000000 ? CR_LT : CR_GT;
		cpu->CR[inst.crfD] = temp;
	}

	// Integer Logical Instructions
	void andx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 28

	}

	void andcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 60

	}

	void andi_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 28

	}

	void andis_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 29

	}

	void cntlzwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 26

	}

	void eqvx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 284

	}

	void extsbx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 954

	}

	void extshx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 922

	}

	void nandx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 476

	}

	void norx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 124

	}

	void orx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 444

	}

	void orcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 412

	}

	void ori(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 24
		rGPR[inst.rA] = rGPR[inst.rS] | inst.UIMM;
	}

	void oris(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 25
		rGPR[inst.rA] = rGPR[inst.rS] | (inst.UIMM << 16);
	}

	void xorx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 316

	}

	void xori(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 26

	}

	void xoris(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 27

	}

	// Integer Rotate Instructions
	void rlwimix(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 20

	}

	void rlwinmx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 21
		rGPR[inst.rA] = (ROTL(inst.rS, inst.SH)) & (MASK(inst.MB, inst.ME));
	}

	void rlwnmx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 23

	}

	// Integer Shift Instructions
	void slwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 24

	}

	void srawx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 792

	}

	void srawix(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 824

	}

	void srwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 536

	}
}