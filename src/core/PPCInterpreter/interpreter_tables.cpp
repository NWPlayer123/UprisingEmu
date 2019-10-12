#include "interpreter_tables.h"

namespace PPCInterpreter {
	void opcode19(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) {
		if (table19[inst.ext] != nullptr) {
			table19[inst.ext](inst, cpu);
		}
		else {
			throw format("unknown debug opcode %d ext %d\n", inst.opcode, inst.ext);
		}
	}

	void opcode31(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) {
		if (table31[inst.ext] != nullptr) {
			table31[inst.ext](inst, cpu);
		}
		else {
			throw format("unknown opcode %d ext %d\n", inst.opcode, inst.ext);
		}
	}
}