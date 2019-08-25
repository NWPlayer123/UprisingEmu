#pragma once

#include "../../io/file.h"
#include "../gekko.h"
#include "../../types.h"

//if bit 16 is 1, extend it (16 -> 32)
#define EXTS(x) (x >> 15 ? x | 0xFFFF0000 : x)

namespace interpreter {

	void run(munna::file& f);

	void addi(GekkoInstruction& inst); //opcode 14
	void addis(GekkoInstruction& inst); //opcode 15
	void ori(GekkoInstruction& inst); //opcode 24
	void mtmsr(GekkoInstruction& inst); //opcode 31, idx2 146
	void mfspr(GekkoInstruction& inst); //opcode 31, idx2 339
	void mtspr(GekkoInstruction& inst); //opcode 31, idx2 467
	void sth(GekkoInstruction& inst); //opcode 44
}