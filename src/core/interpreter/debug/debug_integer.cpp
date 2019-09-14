#include "debug_integer.h"

namespace debug {
	s32 temp; //faster than in-function

	void addx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 266

	}

	void addcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 10

	}

	void addex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 138

	}

	void addi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 14
		temp = EXTS(inst.SIMM);
		if (inst.rA) //not li
			instruction3(temp < 0 ? "subi" : "addi", inst.rD, inst.rA, temp < 0 ? -temp : temp);
		else
			instruction2("li", inst.rD, temp); //TODO: can it ever be negative?
	}

	void addicx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 12, 13

	}

	void addis(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 15
		temp = EXTS(inst.SIMM); //don't need to shift cuz we're only printing SIMM
		if (inst.rA) //not li
			instruction3(temp < 0 ? "subis" : "addis", inst.rD, inst.rA, temp < 0 ? -temp : temp);
		else
			instruction2("lis", inst.rD, temp); //TODO: can it ever be negative?
	}

	void addmex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 234

	}

	void addzex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 202

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