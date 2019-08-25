#include "interpreter.h"

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
	gekko::GekkoCPU cpu; //define and initialize struct
#define rGPR cpu.gpr
	bool InterpreterDebugPrint = true;
	char buffer[256];
	void instruction_move(std::string name, std::string reg, u32 r1, std::string pseudo) {
		sprintf(buffer, "%s, r%d", reg.c_str(), r1);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}
	void instruction_move2(std::string name, u32 reg, std::string spr, std::string pseudo) {
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
	void instruction3(std::string name, u32 r1, u32 r2, u32 val, std::string pseudo) {
		sprintf(buffer, "r%d, r%d, 0x%X", r1, r2, val);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}

	void dodebug(void) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				printf("r%-2d %08X ", (i * 8) + j, rGPR[(i * 8) + j]);
			}
			printf("\n");
		}
	}

	void run(munna::file& f) {
		GekkoInstruction inst;
		for (int i = 0; i < 0x100; i++) {
			inst.hex = f.read32();
			//printf("%08X\n", inst.hex);
			//dodebug();
			switch (inst.opcode) { //base opcode
			case 14:
				addi(inst);
				break;
			case 15:
				addis(inst);
				break;
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
				break;
			default:
				throw format("unknown opcode %d\n", inst.opcode);
			}
		}
	}
	void addi(GekkoInstruction& inst) { //opcode 14
		if (inst.rA == 0) {
			rGPR[inst.rD] = EXTS(inst.SIMM);
			if (InterpreterDebugPrint)
				instruction2("li", inst.rD, inst.SIMM, format("r%d = 0x%X", inst.rD, EXTS(inst.SIMM)));
		}
		else {
			rGPR[inst.rD] = rGPR[inst.rA] + EXTS(inst.SIMM);
			if (InterpreterDebugPrint)
				instruction3("addi", inst.rD, inst.rA, inst.SIMM, format("r%d = *r%d + 0x%X", inst.rD, inst.rA, EXTS(inst.SIMM)));
		}
	}

	void addis(GekkoInstruction& inst) { //opcode 15
		if (inst.rA == 0) {
			rGPR[inst.rD] = (inst.SIMM << 16);
			if (InterpreterDebugPrint)
				instruction2("lis", inst.rD, inst.SIMM, format("r%d = 0x%X", inst.rD, inst.SIMM << 16));
		}
		else {
			rGPR[inst.rD] = rGPR[inst.rA] + (inst.SIMM << 16);
			if (InterpreterDebugPrint)
				instruction3("addis", inst.rD, inst.rA, inst.SIMM, format("r%d = *r%d + 0x%X", inst.rD, inst.rA, inst.SIMM << 16));
		}
	}

	void ori(GekkoInstruction& inst) {
		if (inst.rA == 0 && inst.rS == 0 && inst.UIMM == 0) {
			if (InterpreterDebugPrint)
				printf("nop\n");
		}
		else {
			rGPR[inst.rA] = rGPR[inst.rS] | inst.UIMM;
			instruction3("ori", inst.rA, inst.rS, inst.UIMM, format("r%d = *r%d | 0x%X", inst.rA, inst.rS, inst.UIMM << 16));
		}
	}

	void mtmsr(GekkoInstruction& inst) { //opcode 31 idx2 146
		if (rGPR[inst.rS] & ~VALID_MSR_MASK)
			throw format("unknown MSR mask: %08X", rGPR[inst.rS]);
		else
			cpu.msr.hex = rGPR[inst.rS];
			if (InterpreterDebugPrint)
				instruction1("mtmsr", inst.rS, format("%s = *r%d", "msr", inst.rS));
	}

	void mfspr(GekkoInstruction& inst) { //opcode 31 idx2 339
		u32 spr = ((inst.spr1 << 5) | inst.spr2); //TODO: remove bottlenecks
		switch (spr) {
			case 1008: //hid0
				if (cpu.spr[spr] & ~VALID_HID0_MASK)
					throw format("invalid HID0 mask: 0x%08X", cpu.spr[spr]);
				else
					rGPR[inst.rS] = cpu.spr[spr];
				break;
			default:
				throw format("Unknown spr %d", spr);
		}

		if (InterpreterDebugPrint) {
			auto search = sprWhitelist.find(spr);
			if (search != sprWhitelist.end())
				instruction_move2("mfspr", inst.rS, search->second.c_str(), format("r%d = %s", inst.rS, search->second.c_str()));
			else
				throw format("Unknown spr %d", spr);
		}
	}

	void mtspr(GekkoInstruction& inst) { //opcode 31 idx2 467
		u32 spr = ((inst.spr1 << 5) | inst.spr2); //TODO: remove bottlenecks
		switch (spr) {
			case 528:
			case 529:
			case 530:
			case 531:
			case 532:
			case 533:
			case 534:
			case 535:
			case 536:
			case 537:
			case 538:
			case 539:
			case 540:
			case 541:
			case 542:
			case 543:
				//TODO: implement allocation
				break;
			case 1008: //hid0
				if (rGPR[inst.rS] & ~VALID_HID0_MASK)
					throw format("invalid HID0 mask: 0x%08X", rGPR[inst.rS]);
				else
					cpu.spr[spr] = rGPR[inst.rS];
				break;
			default:
				throw format("Unknown spr %d", spr);
		}

		if (InterpreterDebugPrint) {
			auto search = sprWhitelist.find(spr);
			if (search != sprWhitelist.end())
				instruction_move("mtspr", search->second.c_str(), inst.rS, format("%s = *r%d", search->second.c_str(), inst.rS));
			else
				throw format("Unknown spr %d", spr);
		}
	}

	void sth(GekkoInstruction& inst) { //opcode 44
		u32 EA = (inst.rA ? rGPR[inst.rA] : 0) + EXTS(inst.d);
		printf("%08X\n", EA);
		/*if rA = 0
			then b ← 0
		else b ←(rA)
			EA ← b + EXTS(d)
			MEM(EA, 2) ← rS[16 - 31]*/
	}
}