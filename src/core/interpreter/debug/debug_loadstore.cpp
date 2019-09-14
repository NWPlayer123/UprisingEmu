#include "debug_loadstore.h"

namespace debug {
	void stb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 38

	}

	void stbu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 39

	}

	void stbux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 247

	}

	void stbx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 215

	}

	void sth(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 44
		instruction_offset("sth", inst.rS, inst.d, inst.rA);
	}

	void sthu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 45

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