#include "gekko.h"

namespace gekko {
	cpu::cpu(void) {
		this->xer.hex = 0;
		this->msr.hex = 0;
		//one page is too wide, so we need to map the whole range

		// Command Processor (CP)
		this->hwreg(0x0C000000);
		// Pixel Engine (PE)
		this->hwreg(0x0C001000);
		// Video Interface (VI)
		this->hwreg(0x0C002000);
		// Processor Interface (PI)
		this->hwreg(0x0C003000);
		// Memory Interface (MI)
		this->hwreg(0x0C004000);
		// Audio Interface (AI)
		this->hwreg(0x0C005000);
		// DVD Interface (DI) 6000
		// Serial Interface (SI) 6400
		// External Interface (EXI) 6800
		// Streaming Interface 6C00
		this->hwreg(0x0C006000);
		// GX FIFO
		this->hwreg(0x0C008000);

		// Command Processor (CP)
		this->hwreg(0xCC000000);
		// Pixel Engine (PE)
		this->hwreg(0xCC001000);
		// Video Interface (VI)
		this->hwreg(0xCC002000);
		// Processor Interface (PI)
		this->hwreg(0xCC003000);
		// Memory Interface (MI)
		this->hwreg(0xCC004000);
		// Audio Interface (AI)
		this->hwreg(0xCC005000);
		// DVD Interface (DI) 6000
		// Serial Interface (SI) 6400
		// External Interface (EXI) 6800
		// Streaming Interface 6C00
		this->hwreg(0xCC006000);
		// GX FIFO
		this->hwreg(0xCC008000);
	}

	void cpu::hwreg(u32 address) {
		this->memory[address >> 12] = (std::byte*)1;
	}

	void cpu::write8(u32 address, u8 value) {
		//printf("\nwrite8\n");
	}

	void cpu::write16(u32 address, u16 value) {
		//printf("\nwrite16\n");
	}

	void cpu::write32(u32 address, u32 value) {
		//printf("\nwrite32\n%08X %08X\n", address, value);
		switch (address & 0xFFFFFF00) {
			case 0x0C006800:
			case 0xCC006800:
				this->exi.write(address, value);
				break;
		}
	}

	void cpu::read8(u32 address, u32& reg) {
		//printf("\nread8\n");
	}

	void cpu::read16(u32 address, u32& reg) {
		//printf("\nread16\n");
	}

	void cpu::read32(u32 address, u32& reg) {
		//printf("\nread32\n");
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
				CR0 |= result & 0x8000 ? CR_LT : CR_GT;
			this->CR.setreg(0, CR0);
		}
	}

	bool CR::getbit(u8 index) {
		return (this->hex >> (31 - index)) & 1;
	}

	u8 CR::getreg(u8 index) {
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

	void CR::setreg(u8 index, u8 value) {
		switch (index) {
			case 0: this->CR0 = value & 15; break;
			case 1: this->CR1 = value & 15; break;
			case 2: this->CR2 = value & 15; break;
			case 3: this->CR3 = value & 15; break;
			case 4: this->CR4 = value & 15; break;
			case 5: this->CR5 = value & 15; break;
			case 6: this->CR6 = value & 15; break;
			case 7: this->CR7 = value & 15; break;
			default: throw format("unknown CR index: %d", index);
		}
	}

	void CR::write(u8 index, bool bit) {
		this->hex = ((this->hex & ~(1 << index)) | (bit << index));
	}
}