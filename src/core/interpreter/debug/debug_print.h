#pragma once

#include "..//..//..//types.h"

namespace debug {
	void instruction_move(std::string name, std::string spr, u32 reg);
	void instruction_move2(std::string name, std::string spr, u32 reg);
	void instruction_offset(std::string name, u32 reg1, u32 val, u32 reg2);
	void instruction1(std::string name, u32 reg);
	void instruction2(std::string name, u32 r1, s32 val);
	void instruction3(std::string name, u32 reg1, u32 reg2, u32 val);
	void instruction_reg3(std::string name, u32 reg1, u32 reg2, u32 reg3);
	void instruction_rlwinm(std::string name, u32 rA, u32 rS, u32 SH, u32 MB, u32 ME);
	void instruction_compare(std::string name, u32 crfD, u32 L, u32 reg, u32 UIMM);
}