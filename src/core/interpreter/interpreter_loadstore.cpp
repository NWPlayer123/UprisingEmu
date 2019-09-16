#include "interpreter_loadstore.h"

namespace interpreter {
	// Integer Load Instructions
	void lbz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 34
		cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "lbz not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read8(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lbzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 35
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "lbzu not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read8(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lbzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 119
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "lbzux not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read8(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lbzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 87
		cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "lbzx not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read8(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lha(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 42
		cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "lha not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read16(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);

		rGPR[inst.rD] = EXTS(rGPR[inst.rD]); //"algebraic" -> extend sign bit
	}

	void lhau(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 43
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "lhau not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read16(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);

		rGPR[inst.rD] = EXTS(rGPR[inst.rD]); //"algebraic" -> extend sign bit
	}

	void lhaux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 375
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "lhaux not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read16(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);

		rGPR[inst.rD] = EXTS(rGPR[inst.rD]); //"algebraic" -> extend sign bit
	}

	void lhax(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 343
		cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "lhax not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read16(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);

		rGPR[inst.rD] = EXTS(rGPR[inst.rD]); //"algebraic" -> extend sign bit
	}

	void lhz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 40
		cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "lhz not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read16(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lhzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 41
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "lhzu not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read16(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lhzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 311
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "lhzux not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read16(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lhzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 279
		cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "lhzx not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read16(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lwz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 32
		cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "lwz not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read32(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lwzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 33
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "lwzu not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read32(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lwzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 55
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "lwzux not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read32(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void lwzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 23
		cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "lwzx not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->read32(cpu->EA, rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	// Integer Store Instructions
	void stb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 38
		cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "stb not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write8(cpu->EA, (u8)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void stbu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 39
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "stbu not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write8(cpu->EA, (u8)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void stbux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 247
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "stbux not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write8(cpu->EA, (u8)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void stbx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 215
		cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "stbx not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write8(cpu->EA, (u8)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void sth(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 44
		cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "sth not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write16(cpu->EA, (u16)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void sthu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 45
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "sthu not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write16(cpu->EA, (u16)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void sthux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 439
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "sthux not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write16(cpu->EA, (u16)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void sthx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 407
		cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "sthx not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write16(cpu->EA, (u16)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void stw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 36
		cpu->loadaddr(inst.rA ? rGPR[inst.rA] : 0, EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "stw not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write32(cpu->EA, (u32)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void stwu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 37
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], EXTS(inst.d));

		if (cpu->memaddr > (std::byte*)1)
			throw "stwu not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write32(cpu->EA, (u32)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void stwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 183
		rGPR[inst.rA] = cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "stwux not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write32(cpu->EA, (u32)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	void stwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 151
		cpu->loadaddr(rGPR[inst.rA], rGPR[inst.rB]);

		if (cpu->memaddr > (std::byte*)1)
			throw "stwx not impl yet";
		else if (cpu->memaddr == (std::byte*)1)
			cpu->write32(cpu->EA, (u32)rGPR[inst.rD]);
		else throw format("Invalid address: %08X", cpu->EA);
	}

	// Integer Load and Store with Byte Reverse Instructions
	void lhbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 790

	}

	void lwbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 534

	}

	void sthbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 918

	}

	void stwbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 662

	}

	// Integer Load and Store Multiple Instructions
	void lmw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 46

	}

	void stmw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 47

	}

	// Integer Load and Store String Instructions
	void lswi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 597

	}

	void lswx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 533

	}

	void stswi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 725

	}

	void stswx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 661

	}
}