#include "gekko.h"

namespace gekko {
	cpu::cpu(void) {
		this->xer.hex = 0;
		this->msr.hex = 0;
		hwreg(PI::REGISTER_BASE);
		hwreg(PI::REGISTER_BASE | 0xC0000000);
		hwreg(MI::REGISTER_BASE);
		hwreg(MI::REGISTER_BASE | 0xC0000000);
		hwreg(DSP::REGISTER_BASE);
		hwreg(DSP::REGISTER_BASE | 0xC0000000);
	}

	void cpu::hwreg(u32 address) {
		this->memory[address >> 12] = (std::byte*)1;
	}

	void cpu::write16(u32 address, u16 value) {
		//printf("\nwrite16\n");
	}

	void cpu::write32(u32 address, u32 value) {
		//printf("\nwrite32\n");
	}

	void cpu::read16(u32 address, u32& reg) {
		//printf("\nwrite16\n");
	}

	void cpu::read32(u32 address, u32& reg) {
		//printf("\nwrite32\n");
	}

	u32 cpu::loadaddr(u32 base_addr, s32 offset) {
		this->EA = base_addr + offset;
		this->memaddr = this->memory[this->EA >> 12];
		return this->EA;
	}

	void cpu::xer_carry(u32 a, u32 b) {
		this->xer.CA = (bool)(b > (~a));
	}

	void cpu::xer_carry2(u32 a, u32 b, u32 carry) {
		this->xer.CA = (bool)((b > (~a)) || (carry != 0 && (carry > (~(a + b)))));
	}

	void cpu::xer_overflow(u32 a, u32 b, u32 result) {
		this->xer.OV = (bool)(((a ^ result) & (b ^ result)) >> 31);
	}

	//"overflow" is e.g. -1 (0xFFFFFFFF) -> 16 (0x1 00000010)
	//OV is cleared or set per-instruction, SO is only set (need to clear with mtspr/mcrxr)
	void cpu::update_info_regs(u32 a, u32 b, u32 result, u32 record, u32 overflow) {
		if (overflow) {
			this->xer_overflow(a, b, result);
			if (this->xer.OV)
				this->xer.SO = 1;
		}

		//convert result to signed, set CR0 bit, and copy SO (possibly updated above)
		if (record) {
			u8 CR0 = this->xer.SO ? CR_SO : 0;
			if (result == 0)
				CR0 |= CR_EQ;
			else //get MSB, which handles sign
				CR0 |= result & 0x80000000 ? CR_LT : CR_GT;
			this->CR[0] = CR0;
		}
	}

	u8& CR::operator[](u8 index) {
		switch (index) {
			case 0: return this->CR0;
			case 1: return this->CR1;
			case 2: return this->CR2;
			case 3: return this->CR3;
			case 4: return this->CR4;
			case 5: return this->CR5;
			case 6: return this->CR6;
			case 7: return this->CR7;
			default: throw format("unknown CR index: %d", index);
		}
	}
}