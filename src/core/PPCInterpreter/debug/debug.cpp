﻿#include "debug.h"

namespace PPCDebug {
	void debug(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) {
		printf("%08X ", cpu->pc);
		if (primary[inst.opcode] != nullptr)
			primary[inst.opcode](inst, cpu);
		else
			throw format("unknown debug opcode %d\n", inst.opcode);
	}

	/*void addiD(GekkoInstruction& inst) { //opcode 14
		if (inst.rA == 0)
			instruction2("li", inst.rD, inst.SIMM, format("r%d = 0x%X", inst.rD, EXTS(inst.SIMM)));
		else
			if (inst.rA == inst.rD)
				instruction3("addi", inst.rD, inst.rA, inst.SIMM, format("r%d += 0x%X", inst.rD, EXTS(inst.SIMM)));
			else
				instruction3("addi", inst.rD, inst.rA, inst.SIMM, format("r%d = (r%d) + 0x%X", inst.rD, inst.rA, EXTS(inst.SIMM)));
	}

	void addisD(GekkoInstruction& inst) { //opcode 15
		if (inst.rA == 0)
			instruction2("lis", inst.rD, inst.SIMM, format("r%d = 0x%X", inst.rD, inst.SIMM << 16));
		else
			if (inst.rA == inst.rD)
				instruction3("addis", inst.rD, inst.rA, inst.SIMM, format("r%d += 0x%X", inst.rD, inst.SIMM << 16));
			else
				instruction3("addis", inst.rD, inst.rA, inst.SIMM, format("r%d = (r%d) + 0x%X", inst.rD, inst.rA, inst.SIMM << 16));
	}

	void rlwinmD(GekkoInstruction& inst) { //opcode 21
		if (inst.Rc)
			instruction_rlwinm("rlwinm.", inst.rA, inst.rS, inst.SH, inst.MB, inst.ME, format("r%d = ROTL(r%d, %d) & 0x%X", inst.rA, inst.rS, inst.SH, MASK(inst.MB, inst.ME)));
		else
			instruction_rlwinm("rlwinm", inst.rA, inst.rS, inst.SH, inst.MB, inst.ME, format("r%d = ROTL(r%d, %d) & 0x%X", inst.rA, inst.rS, inst.SH, MASK(inst.MB, inst.ME)));
	}

	void oriD(GekkoInstruction& inst) { //opcode 24
		if (inst.rA == 0 && inst.rS == 0 && inst.UIMM == 0)
			printf("nop\n");
		else
			if (inst.rA == inst.rD)
				instruction3("ori", inst.rA, inst.rS, inst.UIMM, format("r%d |= 0x%X", inst.rA, inst.UIMM));
			else
				instruction3("ori", inst.rA, inst.rS, inst.UIMM, format("r%d = (r%d) | 0x%X", inst.rA, inst.rS, inst.UIMM));
	}

	void subfD(GekkoInstruction& inst) {
		instruction_reg3("subf", inst.rD, inst.rA, inst.rB, format("r%d = (r%d) - (r%d)", inst.rD, inst.rB, inst.rA));
	}

	//TODO: audit the 4 below
	void mfmsrD(GekkoInstruction& inst) {
		instruction1("mfspr", inst.rD, format("r%d = (%s)", inst.rS, "msr"));
	}

	void mtmsrD(GekkoInstruction& inst) { //opcode 31 idx2 146
		instruction1("mtmsr", inst.rS, format("%s = (r%d)", "msr", inst.rS));
	}

	void mtsrD(GekkoInstruction& inst) { //opcode 31 idx2 210
		instruction_move("mtsr", format("sr%d", inst.SR), inst.rS, format("sr%d = (r%d)", inst.SR, inst.rS));
	}

	void mfsprD(GekkoInstruction& inst) { //opcode 31 idx2 339
		u32 spr = ((inst.spr1 << 5) | inst.spr2); //TODO: remove bottlenecks
		auto search = sprWhitelist.find(spr);
		if (search != sprWhitelist.end())
			instruction_move2("mfspr", search->second.c_str(), inst.rS, format("r%d = (%s)", inst.rS, search->second.c_str()));
		else
			throw format("Unknown spr %d", spr);
	}

	void mftbD(GekkoInstruction& inst) {  //opcode 31 idx2 371
		instruction1("mftb", inst.rD, format("r%d = (%s)", inst.rS, "tb"));
	}

	void mtsprD(GekkoInstruction& inst, gekko::GekkoCPU& cpu) { //opcode 31 idx2 467
		u32 spr = ((inst.spr1 << 5) | inst.spr2); //TODO: remove bottlenecks
		auto search = sprWhitelist.find(spr);
		if (search != sprWhitelist.end())
			instruction_move("mtspr", search->second.c_str(), inst.rS, format("%s = (r%d)", search->second.c_str(), inst.rS));
		else
			throw format("Unknown spr %d", spr);

		UpperBAT ubat;
		LowerBAT lbat;
		u32 size = 0;
		switch (spr) {
		case 528: //upper BATs
		case 530:
		case 532:
		case 534:
		case 536:
		case 538:
		case 540:
		case 542:
			switch (ubat.BL) {
				case 0:
					size = 0x20000 << 0;
					break;
				case 1:
					size = 0x20000 << 1;
					break;
				case 3:
					size = 0x20000 << 2;
					break;
				case 7:
					size = 0x20000 << 3;
					break;
				case 15:
					size = 0x20000 << 4;
					break;
				case 31:
					size = 0x20000 << 5;
					break;
				case 63:
					size = 0x20000 << 6;
					break;
				case 127:
					size = 0x20000 << 7;
					break;
				case 255:
					size = 0x20000 << 8;
					break;
				case 511:
					size = 0x20000 << 9;
					break;
				case 1023:
					size = 0x20000 << 10;
					break;
				case 2047:
					size = 0x20000 << 11;
					break;
			}

			ubat = cpu.ubat[(spr - 528) / 2];
			//printf("\n%08X-%08X S%d U%d\n", ubat.BEPI << 17, (ubat.BEPI << 17) + size, ubat.Vs, ubat.Vp);
			lbat = cpu.lbat[(spr - 528) / 2];
			//printf("%08X-%08X %d %d\n\n", lbat.BRPN << 17, (lbat.BRPN << 17) + size, lbat.WIMG, lbat.PP);
			break;
		case 529: //lower BATs
		case 531:
		case 533:
		case 535:
		case 537:
		case 539:
		case 541:
		case 543:
			break;
		case 1008: //hid0
			break;
		default:
			throw format("Unknown spr %d", spr);
		}
	}

	// rD = MEM(rA + EXTS(d), 4) -> load word
	void lwzD(GekkoInstruction& inst) { //opcode 32
		instruction_offset("lwz", inst.rD, inst.d, inst.rA, format("r%d = (u32)(r%d + 0x%X)", inst.rD, inst.rA, inst.d));
	}

	/* rD = MEM(rA + EXTS(d), 4) -> load word
	 * rA += EXTS(d) -> update address *
	void lwzuD(GekkoInstruction& inst) { //opcode 33
		instruction_offset("lwzu", inst.rD, inst.d, inst.rA, format("r%d = (u32)(r%d + 0x%X); r%d += EA", inst.rD, inst.rA, inst.d, inst.rA));
	}

	// rD = MEM(rA + EXTS(d), 1) -> load byte
	void lbzD(GekkoInstruction& inst) { //opcode 34
		instruction_offset("lbz", inst.rD, inst.d, inst.rA, format("r%d = (u8)(r%d + 0x%X)", inst.rD, inst.rA, inst.d));
	}

	/* rD = MEM(rA + EXTS(d), 1) -> load byte
	 * rA += EXTS(d) -> update address *
	void lbzuD(GekkoInstruction& inst) { //opcode 35
		instruction_offset("lbzu", inst.rD, inst.d, inst.rA, format("r%d = (u8)(r%d + 0x%X); r%d += EA", inst.rD, inst.rA, inst.d, inst.rA));
	}

	// MEM(rA + EXTS(d), 4) = rS -> store word
	void stwD(GekkoInstruction& inst) { //opcode 36
		instruction_offset("stw", inst.rS, inst.d, inst.rA, format("(u32)(r%d + 0x%X) = (r%d)", inst.rA, inst.d, inst.rS));
	}

	/* MEM(rA + EXTS(d), 4) = rS -> store word
	 * rA += EXTS(d) -> update address *
	void stwuD(GekkoInstruction& inst) { //opcode 37
		instruction_offset("stwu", inst.rS, inst.d, inst.rA, format("(u32)(r%d + 0x%X) = (r%d); r%d += EA", inst.rA, inst.d, inst.rS, inst.rA));
	}

	// MEM(rA + EXTS(d), 1) = rS -> store byte
	void stbD(GekkoInstruction& inst) { //opcode 38
		instruction_offset("stb", inst.rS, inst.d, inst.rA, format("(u8)(r%d + 0x%X) = (r%d)", inst.rA, inst.d, inst.rS));
	}

	/* MEM(rA + EXTS(d), 1) = rS -> store byte
	 * rA += EXTS(d) -> update address *
	void stbuD(GekkoInstruction& inst) { //opcode 39
		instruction_offset("stbu", inst.rS, inst.d, inst.rA, format("(u8)(r%d + 0x%X) = (r%d); r%d += EA", inst.rA, inst.d, inst.rS, inst.rA));
	}

	// rD = MEM(rA + EXTS(d), 2) -> load half
	void lhzD(GekkoInstruction& inst) { //opcode 40
		instruction_offset("lhz", inst.rD, inst.d, inst.rA, format("r%d = (u16)(r%d + 0x%X)", inst.rD, inst.rA, inst.d));
	}

	/* rD = MEM(rA + EXTS(d), 2) -> load half
	 * rA += EXTS(d) -> update address *
	void lhzuD(GekkoInstruction& inst) { //opcode 41
		instruction_offset("lhzu", inst.rD, inst.d, inst.rA, format("r%d = (u16)(r%d + 0x%X); r%d += EA", inst.rD, inst.rA, inst.d, inst.rA));
	}

	// rD = EXTS(MEM(rA + EXTS(d), 2)) -> load signed half
	void lhaD(GekkoInstruction& inst) { //opcode 42
		instruction_offset("lha", inst.rD, inst.d, inst.rA, format("r%d = (s16)(r%d + 0x%X)", inst.rD, inst.rA, inst.d));
	}

	/* rD = EXTS(MEM(rA + EXTS(d), 2)) -> load signed half
	 * rA += EXTS(d) -> update address *
	void lhauD(GekkoInstruction& inst) { //opcode 43
		instruction_offset("lhau", inst.rD, inst.d, inst.rA, format("r%d = (s16)(r%d + 0x%X); r%d += EA", inst.rD, inst.rA, inst.d, inst.rA));
	}

	// MEM(rA + EXTS(d), 2) = rS -> store half
	void sthD(GekkoInstruction& inst) { //opcode 44
		instruction_offset("sth", inst.rS, inst.d, inst.rA, format("(u16)(r%d + 0x%X) = (r%d)", inst.rA, inst.d, inst.rS));
	}

	/* MEM(rA + EXTS(d), 2) = rS -> store half
	 * rA += EXTS(d) -> update address *
	void sthuD(GekkoInstruction& inst) { //opcode 45
		instruction_offset("sthu", inst.rS, inst.d, inst.rA, format("(u16)(r%d + 0x%X) = (r%d); r%d += EA", inst.rA, inst.d, inst.rS, inst.rA));
	}*/
}