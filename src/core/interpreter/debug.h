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

	void addiD(GekkoInstruction& inst); //opcode 14
	void addisD(GekkoInstruction& inst); //opcode 15
	void rlwinmD(GekkoInstruction& inst); //opcode 21
	void oriD(GekkoInstruction& inst); //opcode 24
	void mfmsrD(GekkoInstruction& inst); //opcode 31 idx2 83
	void mtmsrD(GekkoInstruction& inst); //opcode 31 idx2 146
	void mtsrD(GekkoInstruction& inst); //opcode 31 idx2 210
	void mfsprD(GekkoInstruction& inst); //opcode 31 idx2 339
	void mftbD(GekkoInstruction& inst); //opcode 31 idx2 371
	void mtsprD(GekkoInstruction& inst, gekko::GekkoCPU& cpu); //opcode 31 idx2 467
	void lwzD(GekkoInstruction& inst); //opcode 32
	void lwzuD(GekkoInstruction& inst); //opcode 33
	void lbzD(GekkoInstruction& inst); //opcode 34
	void lbzuD(GekkoInstruction& inst); //opcode 35
	void stwD(GekkoInstruction& inst); //opcode 36
	void stwuD(GekkoInstruction& inst); //opcode 37
	void stbD(GekkoInstruction& inst); //opcode 38
	void stbuD(GekkoInstruction& inst); //opcode 39
	void lhzD(GekkoInstruction& inst); //opcode 40
	void lhzuD(GekkoInstruction& inst); //opcode 41
	void lhaD(GekkoInstruction& inst); //opcode 42
	void lhauD(GekkoInstruction& inst); //opcode 43
	void sthD(GekkoInstruction& inst); //opcode 44
	void sthuD(GekkoInstruction& inst); //opcode 45
}