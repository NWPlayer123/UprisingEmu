#include "debug_tables.h"

namespace debug {
	void opcode31(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) {
		if (table31[inst.ext] != nullptr) {
			table31[inst.ext](inst, cpu);
		}
		else {
			throw format("unknown debug opcode %d ext %d\n", inst.opcode, inst.ext);
		}
	}
}