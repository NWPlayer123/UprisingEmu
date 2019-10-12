#include "debug_print.h"

namespace PPCDebug {
	char buffer[256];
	void instruction_move(std::string name, std::string spr, u32 reg) {
		sprintf(buffer, "%s, r%d", spr.c_str(), reg);
		printf("%-12s%s\n", name.c_str(), &buffer);
	}
	void instruction_move2(std::string name, std::string spr, u32 reg) {
		sprintf(buffer, "r%d, %s", reg, spr.c_str());
		printf("%-12s%s\n", name.c_str(), &buffer);
	}
	void instruction1(std::string name, u32 reg) {
		sprintf(buffer, "r%d", reg);
		printf("%-12s%s\n", name.c_str(), &buffer);
	}
	void instruction2(std::string name, u32 r1, s32 val) {
		sprintf(buffer, "r%d, 0x%X", r1, val);
		printf("%-12s%s\n", name.c_str(), &buffer);
	}
	void instruction3(std::string name, u32 reg1, u32 reg2, u32 val) {
		sprintf(buffer, "r%d, r%d, 0x%X", reg1, reg2, val);
		printf("%-12s%s\n", name.c_str(), &buffer);
	}

	void instruction_offset(std::string name, u32 reg1, u32 val, u32 reg2) {
		sprintf(buffer, "r%d, 0x%X(r%d)", reg1, val, reg2);
		printf("%-12s%s\n", name.c_str(), &buffer);
	}

	void instruction_rlwinm(std::string name, u32 rA, u32 rS, u32 SH, u32 MB, u32 ME) {
		sprintf(buffer, "r%d, r%d, %d,%d,%d", rA, rS, SH, MB, ME);
		printf("%-12s%s\n", name.c_str(), &buffer);
	}

	void instruction_reg3(std::string name, u32 reg1, u32 reg2, u32 reg3) {
		sprintf(buffer, "r%d, r%d, r%d", reg1, reg2, reg3);
		printf("%-12s%s\n", name.c_str(), &buffer);
	}

	void instruction_compare(std::string name, u32 crfD, u32 L, u32 reg, u32 UIMM) {
		sprintf(buffer, "cr%d, %d, r%d, 0x%X", crfD, L, reg, UIMM);
		printf("%-12s%s\n", name.c_str(), &buffer);
	}

	/*void instruction_move(std::string name, std::string spr, u32 reg, std::string pseudo) {
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
	void instruction2(std::string name, u32 r1, s32 val, std::string pseudo) {
		sprintf(buffer, "r%d, %d", r1, val);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}
	void instruction3(std::string name, u32 reg1, u32 reg2, u32 val, std::string pseudo) {
		sprintf(buffer, "r%d, r%d, 0x%X", reg1, reg2, val);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}

	void instruction_offset(std::string name, u32 reg1, u32 val, u32 reg2, std::string pseudo) {
		sprintf(buffer, "r%d, 0x%X(r%d)", reg1, val, reg2);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}

	void instruction_rlwinm(std::string name, u32 rA, u32 rS, u32 SH, u32 MB, u32 ME, std::string pseudo) {
		sprintf(buffer, "r%d, r%d, %d, %d, %d", rA, rS, SH, MB, ME);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}

	void instruction_reg3(std::string name, u32 reg1, u32 reg2, u32 reg3, std::string pseudo) {
		sprintf(buffer, "r%d, r%d, r%d", reg1, reg2, reg3);
		printf("%-12s%-20s# %s\n", name.c_str(), &buffer, pseudo.c_str());
	}*/
}