#include "debug.h"

namespace interpreter {

	std::map<int, std::string> sprWhitelist = {
		//instruction block address translation upper/lower
		{528, "ibat0u"},
		{529, "ibat0l"},
		{530, "ibat1u"},
		{531, "ibat1l"},
		{532, "ibat2u"},
		{533, "ibat2l"},
		{534, "ibat3u"},
		{535, "ibat3l"},
		//data block address translation upper/lower
		{536, "dbat0u"},
		{537, "dbat0l"},
		{538, "dbat1u"},
		{539, "dbat1l"},
		{540, "dbat2u"},
		{541, "dbat2l"},
		{542, "dbat3u"},
		{543, "dbat3l"},
		//Hardware Implementation-Dependent
		{1008, "hid0"},
	};
	char buffer[256];
	void instruction_move(std::string name, std::string spr, u32 reg, std::string pseudo) {
		sprintf(buffer, "%s, r%d", spr.c_str(), reg);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}
	void instruction_move2(std::string name, std::string spr, u32 reg, std::string pseudo) {
		sprintf(buffer, "r%d, %s", reg, spr.c_str());
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}
	void instruction1(std::string name, u32 reg, std::string pseudo) {
		sprintf(buffer, "r%d", reg);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}
	void instruction2(std::string name, u32 r1, u32 val, std::string pseudo) {
		sprintf(buffer, "r%d, 0x%X", r1, val);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}
	void instruction3(std::string name, u32 reg1, u32 reg2, u32 val, std::string pseudo) {
		sprintf(buffer, "r%d, r%d, 0x%X", reg1, reg2, val);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}
	void instruction_store(std::string name, u32 reg1, u32 val, u32 reg2, std::string pseudo) {
		sprintf(buffer, "r%d, 0x%X(r%d)", reg1, val, reg2);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}

	//TODOs: interpret "SIMM" (signed) correctly
	void debug(GekkoInstruction& inst, gekko::GekkoCPU& cpu) {
		switch (inst.opcode) { //base opcode
			case 14:
				addiD(inst);
				break;
			case 15:
				addisD(inst);
				break;
			case 19:
				switch (inst.idx2) {
					case 150: //isync, not implementing
						printf("isync\n");
						break;
					default:
						throw format("unknown opcode %d idx2 %d %08X\n", inst.opcode, inst.idx2, inst.hex);
				}
				break;
			case 24:
				oriD(inst);
				break;
			case 31:
				switch (inst.idx2) {
					case 146:
						mtmsrD(inst);
						break;
					case 210:
						mtsrD(inst);
						break;
					case 339:
						mfsprD(inst);
						break;
					case 467:
						mtsprD(inst, cpu);
						break;
					default:
						throw format("unknown opcode %d idx2 %d %08X\n", inst.opcode, inst.idx2, inst.hex);
				}
				break;
			/*
			case 19:
				switch (inst.idx2) {
				case 150: //isync, not implementing
					if (InterpreterDebugPrint)
						printf("isync\n");
					break;
				default:
					throw format("unknown opcode %d idx2 %d %08X\n", inst.opcode, inst.idx2, inst.hex);
				}
			case 24:
				ori(inst);
				break;
			case 31:
				switch (inst.idx2) {
				case 146:
					mtmsr(inst);
					break;
				case 339:
					mfspr(inst);
					break;
				case 467:
					mtspr(inst);
					break;
				default:
					throw format("unknown opcode %d idx2 %d %08X\n", inst.opcode, inst.idx2, inst.hex);
				}
				break;
			case 44:
				sth(inst);
				break;*/
			case 44:
				sthD(inst);
				break;
			default:
				throw format("unknown debug opcode %d\n", inst.opcode);
		}
	}

	void addiD(GekkoInstruction& inst) { //opcode 14
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

	void oriD(GekkoInstruction& inst) { //opcode 24
		if (inst.rA == 0 && inst.rS == 0 && inst.UIMM == 0)
			printf("nop\n");
		else
			if (inst.rA == inst.rD)
				instruction3("ori", inst.rA, inst.rS, inst.UIMM, format("r%d |= 0x%X", inst.rA, inst.UIMM));
			else
				instruction3("ori", inst.rA, inst.rS, inst.UIMM, format("r%d = (r%d) | 0x%X", inst.rA, inst.rS, inst.UIMM));
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

	void sthD(GekkoInstruction& inst) { //opcode 44
		instruction_store("sth", inst.rS, inst.d, inst.rA, format("(r%d + 0x%X) = (r%d)", inst.rA, inst.d, inst.rS));
		/*
		if rA = 0
			then b ← 0
		else b ←(rA)
			EA ← b + EXTS(d)
			MEM(EA, 2) ← rS[16 - 31]
		*/
	}
}