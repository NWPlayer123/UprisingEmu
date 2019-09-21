#include "interpreter.h"

namespace interpreter {
	void dodebug(std::unique_ptr<gekko::cpu>& cpu) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				printf("r%-2d %08X ", (i * 8) + j, rGPR[(i * 8) + j]);
			}
			printf("\n");
		}
	}

	void run(std::vector<gekko::instruction>& code) {
		std::unique_ptr cpu = std::make_unique<gekko::cpu>();
		gekko::instruction inst;
		cpu->pc = 0xFFF00100; //set IPL entrypoint
		cpu->base = 0xFFF00100; //temp, don't break my code[]
		while (true) {
			inst = code[(cpu->pc - cpu->base) / 4];
			//printf("%08X\n", inst.hex);
			if (primary[inst.opcode] != nullptr) {
				primary[inst.opcode](inst, cpu);
			} else {
				throw format("unknown opcode %d\n", inst.opcode);
			}
			/*debug::debug(inst, cpu); //print instruction to terminal
			if (inst.opcode == 10)
				dodebug(cpu);*/
			if (inst.opcode != 16 && inst.opcode != 18 && !(inst.opcode == 31 && inst.ext == 16) && !(inst.opcode == 31 && inst.ext == 528))
				cpu->pc += 4; //TODO: find less garbage way? probably just duplicate pc++ for every non-branch instruction
			cpu->count++;
		}
	}
}