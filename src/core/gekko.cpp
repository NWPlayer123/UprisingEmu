#include "gekko.h"

namespace gekko {
	GekkoCPU::GekkoCPU(void) {
		this->msr.hex = 0;

	}

	void hwreg(GekkoCPU& cpu, const u32& address, void* HandleInput) {
		cpu.memory[address >> 12].type = memory::TYPE_HWREG;
		cpu.memory[address >> 12].data = HandleInput;
	}
}