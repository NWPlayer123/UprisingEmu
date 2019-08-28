#pragma once

#include "../gekko.h"
#include "interpreter.h"
#include "../../types.h"

namespace interpreter {

	void instruction_move(std::string name, std::string spr, u32 reg, std::string pseudo);
	void instruction_move2(std::string name, std::string spr, u32 reg, std::string pseudo);
	void instruction1(std::string name, u32 reg, std::string pseudo);
	void instruction2(std::string name, u32 r1, u32 val, std::string pseudo);
	void instruction3(std::string name, u32 reg1, u32 reg2, u32 val, std::string pseudo);

	void debug(GekkoInstruction& inst, gekko::GekkoCPU& cpu);

	void addiD(GekkoInstruction& inst); //opcode 15
	void addisD(GekkoInstruction& inst); //opcode 15
	void oriD(GekkoInstruction& inst); //opcode 24
	void mtmsrD(GekkoInstruction& inst); //opcode 31 idx2 146
	void mtsrD(GekkoInstruction& inst); //opcode 31 idx2 210
	void mfsprD(GekkoInstruction& inst); //opcode 31 idx2 339
	void mtsprD(GekkoInstruction& inst, gekko::GekkoCPU& cpu); //opcode 31 idx2 467
	void sthD(GekkoInstruction& inst); //opcode 44
}