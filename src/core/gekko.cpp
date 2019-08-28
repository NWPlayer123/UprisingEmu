#include "gekko.h"

namespace gekko {
	GekkoCPU::GekkoCPU(void) {
		this->msr.hex = 0;
		hwreg(MI::REGISTER_BASE);
		hwreg(MI::REGISTER_BASE | 0xC0000000);
		hwreg(DSP::REGISTER_BASE);
		hwreg(DSP::REGISTER_BASE | 0xC0000000);
	}

	void GekkoCPU::hwreg(u32 address) {
		this->memory[address >> 12] = (std::byte*)1;
	}

	void GekkoCPU::write16(u32& address) {
		//switch (address&);
	}
}