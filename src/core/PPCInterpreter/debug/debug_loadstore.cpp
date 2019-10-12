#include "debug_loadstore.h"

namespace PPCDebug {
	// Integer Load Instructions
	void lbz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 34
		instruction_offset("lbz", inst.rD, inst.d, inst.rA);
	}

	void lbzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 35
		instruction_offset("lbzu", inst.rD, inst.d, inst.rA);
	}

	void lbzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 119
		instruction_reg3("lbzux", inst.rD, inst.rA, inst.rB);
	}

	void lbzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 87
		instruction_reg3("lbzx", inst.rD, inst.rA, inst.rB);
	}

	void lha(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 42
		instruction_offset("lha", inst.rD, inst.d, inst.rA);
	}

	void lhau(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 43
		instruction_offset("lhau", inst.rD, inst.d, inst.rA);
	}

	void lhaux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 375
		instruction_reg3("lhaux", inst.rD, inst.rA, inst.rB);
	}

	void lhax(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 343
		instruction_reg3("lhax", inst.rD, inst.rA, inst.rB);
	}

	void lhz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 40
		instruction_offset("lhz", inst.rD, inst.d, inst.rA);
	}

	void lhzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 41
		instruction_offset("lhzu", inst.rD, inst.d, inst.rA);
	}

	void lhzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 311
		instruction_reg3("lhzux", inst.rD, inst.rA, inst.rB);
	}

	void lhzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 279
		instruction_reg3("lhzx", inst.rD, inst.rA, inst.rB);
	}

	void lwz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 32
		instruction_offset("lwz", inst.rD, inst.d, inst.rA);
	}

	void lwzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 33
		instruction_offset("lwzu", inst.rD, inst.d, inst.rA);
	}

	void lwzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 55
		instruction_reg3("lwzux", inst.rD, inst.rA, inst.rB);
	}

	void lwzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 23
		instruction_reg3("lwzx", inst.rD, inst.rA, inst.rB);
	}

	// Integer Store Instructions
	void stb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 38
		instruction_offset("stb", inst.rS, inst.d, inst.rA);
	}

	void stbu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 39
		instruction_offset("stbu", inst.rS, inst.d, inst.rA);
	}

	void stbux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 247
		instruction_reg3("stbux", inst.rS, inst.rA, inst.rB);
	}

	void stbx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 215
		instruction_reg3("stbx", inst.rS, inst.rA, inst.rB);
	}

	void sth(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 44
		instruction_offset("sth", inst.rS, inst.d, inst.rA);
	}

	void sthu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 45
		instruction_offset("sthu", inst.rS, inst.d, inst.rA);
	}

	void sthux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 439
		instruction_reg3("sthux", inst.rS, inst.rA, inst.rB);
	}

	void sthx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 407
		instruction_reg3("sthx", inst.rS, inst.rA, inst.rB);
	}

	void stw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 36
		instruction_offset("stw", inst.rS, inst.d, inst.rA);
	}

	void stwu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 37
		instruction_offset("stwu", inst.rS, inst.d, inst.rA);
	}

	void stwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 183
		instruction_reg3("stwux", inst.rS, inst.rA, inst.rB);
	}

	void stwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 151
		instruction_reg3("stwx", inst.rS, inst.rA, inst.rB);
	}

	// Integer Load and Store with Byte Reverse Instructions
	void lhbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 790
		instruction_reg3("lhbrx", inst.rD, inst.rA, inst.rB);
	}

	void lwbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 534
		instruction_reg3("lwbrx", inst.rD, inst.rA, inst.rB);
	}

	void sthbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 918
		instruction_reg3("sthbrx", inst.rS, inst.rA, inst.rB);
	}

	void stwbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 662
		instruction_reg3("stwbrx", inst.rS, inst.rA, inst.rB);
	}

	// Integer Load and Store Multiple Instructions
	void lmw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 46
		instruction_offset("lmw", inst.rD, inst.d, inst.rA);
	}

	void stmw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 47
		instruction_offset("stmw", inst.rS, inst.d, inst.rA);
	}

	// Integer Load and Store String Instructions
	void lswi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 597
		instruction3("lswi", inst.rD, inst.rA, inst.NB);
	}

	void lswx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 533
		instruction_reg3("lswx", inst.rD, inst.rA, inst.rB);
	}

	void stswi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 725
		instruction3("lswi", inst.rS, inst.rA, inst.NB);
	}

	void stswx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 661
		instruction_reg3("stswx", inst.rS, inst.rA, inst.rB);
	}
}