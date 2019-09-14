#include "interpreter_loadstore.h"

namespace interpreter {
	void stb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 38

	}

	void stbu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 39

	}

	void stbux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 247

	}

	void stbx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 215

	}

	void sth(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 44
		cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));
		if (cpu->memaddr > (std::byte*)1)
			throw "sth not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write16(cpu->EA, (u16)rGPR[inst.rS]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void sthu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 45
		rGPR[inst.rA] = cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));
		if (cpu->memaddr > (std::byte*)1)
			throw "sthu not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write16(cpu->EA, (u16)rGPR[inst.rS]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void sthux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 439

	}

	void sthx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 407

	}

	void stw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 36

	}

	void stwu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 37

	}

	void stwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 183

	}

	void stwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 151

	}
}