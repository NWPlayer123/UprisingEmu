#include "gekko.h"

namespace gekko {
	GekkoCPU::GekkoCPU(void) {
		this->msr.hex = 0;
		hwreg(PI::REGISTER_BASE);
		hwreg(PI::REGISTER_BASE | 0xC0000000);
		hwreg(MI::REGISTER_BASE);
		hwreg(MI::REGISTER_BASE | 0xC0000000);
		hwreg(DSP::REGISTER_BASE);
		hwreg(DSP::REGISTER_BASE | 0xC0000000);
	}

	void GekkoCPU::hwreg(u32 address) {
		this->memory[address >> 12] = (std::byte*)1;
	}

	void GekkoCPU::write16(u32 address, u16 value) {
		//printf("\nwrite16\n");
	}

	void GekkoCPU::write32(u32 address, u32 value) {
		//printf("\nwrite32\n");
	}

	void GekkoCPU::read16(u32 address, u32& reg) {
		//printf("\nwrite16\n");
	}

	void GekkoCPU::read32(u32 address, u32& reg) {
		//printf("\nwrite32\n");
	}
}