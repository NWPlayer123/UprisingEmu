#include "debug_system.h"

namespace debug {

	std::map<int, std::string> whitelist = {
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

	// Memory Synchronization Instructions
	void eieio(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 854

	}

	void isync(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 19 ext 150
		printf("isync\n");
	}

	void lwarx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 20

	}

	void stwcx_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 150

	}

	void sync(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 598

	}


	void mcrxr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 512

	}

	void mfcr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 19

	}

	void mfmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 83
		instruction1("mfmsr", inst.rD);
	}

	void mfspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 339
		auto search = whitelist.find(inst.spr());
		if (search != whitelist.end())
			instruction_move2("mfspr", search->second.c_str(), inst.rS);
		else
			throw format("Unknown spr %d", inst.spr());
	}

	void mftb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 371
		instruction1(inst.spr() == 268 ? "mftb" : "mftbu", inst.rD);
	}

	void mtcrf(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 144

	}

	void mtmsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 146
		instruction1("mtmsr", inst.rS);
	}

	void mtspr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 467
		auto search = whitelist.find(inst.spr());
		if (search != whitelist.end())
			instruction_move("mtspr", search->second.c_str(), inst.rS);
		else
			throw format("Unknown spr %d", inst.spr());
	}

	//Segment Register Manipulation Instructions
	void mfsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 595
	}

	void mfsrin(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 659

	}

	void mtsr(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 210
		instruction_move("mtsr", format("sr%d", inst.SR), inst.rS);
	}

	void mtsrin(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu) { //opcode 31 ext 242

	}
}