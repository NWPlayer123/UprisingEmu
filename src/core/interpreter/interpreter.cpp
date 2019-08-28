#include "interpreter.h"

namespace interpreter {
	gekko::GekkoCPU cpu; //define and initialize struct
	#define rGPR cpu.gpr
	#define rSPR cpu.spr

	bool InterpreterDebugPrint = true;

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
			printf("%08X ", 0xFFF0100 + (i * 4));
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
						break;
					default:
						throw format("unknown opcode %d idx2 %d %08X\n", inst.opcode, inst.idx2, inst.hex);
				}
				break;
			case 24:
				ori(inst);
				break;
			case 31:
				switch (inst.idx2) {
					case 146:
						mtmsr(inst);
						break;
					case 210:
						mtsr(inst);
						break;
					case 339:
						mfspr(inst);
						break;
					case 467:
						mtspr(inst);
						//debug(inst, cpu);
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
			debug(inst, cpu);
		}
	}
	void addi(GekkoInstruction& inst) { //opcode 14
		if (inst.rA == 0)
			rGPR[inst.rD] = EXTS(inst.SIMM);
		else
			rGPR[inst.rD] = rGPR[inst.rA] + EXTS(inst.SIMM);
	}

	void addis(GekkoInstruction& inst) { //opcode 15
		if (inst.rA == 0)
			rGPR[inst.rD] = (inst.SIMM << 16);
		else
			rGPR[inst.rD] = rGPR[inst.rA] + (inst.SIMM << 16);
	}

	void ori(GekkoInstruction& inst) { //opcode 24
		rGPR[inst.rA] = rGPR[inst.rS] | inst.UIMM;
	}

	void mtmsr(GekkoInstruction& inst) { //opcode 31 idx2 146
		if (rGPR[inst.rS] & ~VALID_MSR_MASK)
			throw format("unknown MSR mask: %08X", rGPR[inst.rS]);
		else
			cpu.msr.hex = rGPR[inst.rS];
	}

	void mtsr(GekkoInstruction& inst) { //opcode 31 idx2 210
		/*if (rGPR[inst.rS] & ~VALID_MSR_MASK)
			throw format("unknown MSR mask: %08X", rGPR[inst.rS]);
		else*/
		cpu.sr[inst.SR] = rGPR[inst.rS];
	}

	void mfspr(GekkoInstruction& inst) { //opcode 31 idx2 339
		u32 spr = ((inst.spr1 << 5) | inst.spr2); //TODO: remove bottlenecks
		switch (spr) {
			case 1008: //hid0
				if (rSPR[spr] & ~VALID_HID0_MASK)
					throw format("invalid HID0 mask: 0x%08X", rSPR[spr]);
				else
					rGPR[inst.rS] = rSPR[spr];
				break;
			default:
				throw format("Unknown spr %d", spr);
		}
	}

	void mtspr(GekkoInstruction& inst) { //opcode 31 idx2 467
		u32 spr = ((inst.spr1 << 5) | inst.spr2); //TODO: remove bottlenecks
		switch (spr) {
			case 528: //upper
			case 530:
			case 532:
			case 534:
			case 536:
			case 538:
			case 540:
			case 542:
				cpu.ubat[(spr - 528) / 2].hex = rGPR[inst.rS];
				break;
			case 529: //lower
			case 531:
			case 533:
			case 535:
			case 537:
			case 539:
			case 541:
			case 543:
				cpu.lbat[(spr - 529) / 2].hex = rGPR[inst.rS];
				break;
			case 1008: //hid0
				if (rGPR[inst.rS] & ~VALID_HID0_MASK)
					throw format("invalid HID0 mask: 0x%08X", rGPR[inst.rS]);
				else
					rSPR[spr] = rGPR[inst.rS];
				break;
			default:
				throw format("Unknown spr %d", spr);
		}
	}

	void sth(GekkoInstruction& inst) { //opcode 44
		u32 address = (inst.rA ? rGPR[inst.rA] : 0) + EXTS(inst.d);
		//printf("%08X\n", address);
		std::byte* mem = cpu.memory[address >> 12];
		if (mem > (std::byte*)1)
			throw "sth not impl yet";// *(u16*)mem[address & 0xFFF] = (u16)rGPR[inst.rS];
		else if (mem == (std::byte*)1)
			cpu.write16(address);
		else
			throw format("Invalid address: %08X", address);
	}
}