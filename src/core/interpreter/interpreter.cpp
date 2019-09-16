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
		for (int i = 0; i < 0x100; i++) {
			printf("%08X ", 0xFFF00100 + (i * 4));
			inst = code[cpu->pc];
			cpu->pc++; //update after reading, so we can update with branching
			//printf("%08X\n", inst.hex);
			if (primary[inst.opcode] != nullptr) {
				primary[inst.opcode](inst, cpu);
			} else {
				throw format("unknown opcode %d\n", inst.opcode);
			}
			debug::debug(inst, cpu); //print instruction to terminal
			//dodebug(cpu);
			cpu->count++;
		}
	}
}