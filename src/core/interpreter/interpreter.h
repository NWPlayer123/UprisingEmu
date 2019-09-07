#pragma once

#include "../../io/file.h"
#include "../gekko.h"
#include "debug.h"
#include "../../types.h"

//if bit 16 is 1, extend it (16 -> 32)
static inline constexpr s32 EXTS(u32 x) { return (x >> 15 ? x | 0xFFFF0000 : x); }

//we have to carry bits so shift (32 - y) other direction and OR
static inline constexpr u32 ROTL(u32 x, u32 y) { return ((x << y) | (x >> (32 - y))); }
static inline constexpr u32 ROTR(u32 x, u32 y) { return ((x << (32 - y)) | (x >> y)); }
static inline constexpr u32 MASK(u32 x, u32 y) { return ((x <= y) ? ((~0u >> x) & (~0u << (31 - y))) : ((~0u >> x) | (~0u << (31 - y)))); }

typedef void (*HandleInput)(u32& value, void* address, bool isWrite);

namespace interpreter {

	void run(std::vector<GekkoInstruction>& code);

	void addi(GekkoInstruction& inst);  //opcode 14
	void addis(GekkoInstruction& inst); //opcode 15
	void rlwinm(GekkoInstruction& inst); //opcode 21
	void ori(GekkoInstruction& inst);   //opcode 24
	void mfmsr(GekkoInstruction& inst); //opcode 31, idx2 83
	void mtmsr(GekkoInstruction& inst); //opcode 31, idx2 146
	void mtsr(GekkoInstruction& inst);  //opcode 31, idx2 210
	void mfspr(GekkoInstruction& inst); //opcode 31, idx2 339
	void mftb(GekkoInstruction& inst); //opcode 31, idx2 371
	void mtspr(GekkoInstruction& inst); //opcode 31, idx2 467
	void lwz(GekkoInstruction& inst);   //opcode 32
	void stw(GekkoInstruction& inst);   //opcode 36
	void sth(GekkoInstruction& inst);   //opcode 44
}