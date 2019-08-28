#pragma once

#include "../../io/file.h"
#include "../gekko.h"
#include "debug.h"
#include "../../types.h"

//if bit 16 is 1, extend it (16 -> 32)
#define EXTS(x) (x >> 15 ? x | 0xFFFF0000 : x)

typedef void (*HandleInput)(u32& value, void* address, bool isWrite);

namespace interpreter {

	void run(munna::file& f);

	void addi(GekkoInstruction& inst); //opcode 14
	void addis(GekkoInstruction& inst); //opcode 15
	void ori(GekkoInstruction& inst); //opcode 24
	void mtmsr(GekkoInstruction& inst); //opcode 31, idx2 146
	void mtsr(GekkoInstruction& inst); //opcode 31 idx2 210
	void mfspr(GekkoInstruction& inst); //opcode 31, idx2 339
	void mtspr(GekkoInstruction& inst); //opcode 31, idx2 467
	void sth(GekkoInstruction& inst); //opcode 44
}