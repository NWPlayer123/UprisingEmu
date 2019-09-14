#pragma once

#include "..//..//..//types.h"

namespace debug {
	void instruction_move(std::string name, std::string spr, u32 reg);
	void instruction_move2(std::string name, std::string spr, u32 reg);
	void instruction_offset(std::string name, u32 reg1, u32 val, u32 reg2);
	void instruction1(std::string name, u32 reg);
	void instruction2(std::string name, u32 r1, s32 val);
	void instruction3(std::string name, u32 reg1, u32 reg2, u32 val);
}