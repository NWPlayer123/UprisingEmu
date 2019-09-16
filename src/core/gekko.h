#pragma once
#include "hardware/DSP.h"
#include "hardware/MI.h"
#include "hardware/PI.h"
#include "../types.h"

#define BITSTRUCT(bit, len, name) struct { u32 : (32 - bit - len); u32 name : len; }

namespace gekko {
	typedef union XER {
		u32 hex;
		BITSTRUCT(0, 1, SO); //Summary Overflow
		BITSTRUCT(1, 1, OV); //Overflow
		BITSTRUCT(2, 1, CA); //Carry (used in 64-bit math)
		//bits 3-24 unused
		BITSTRUCT(25, 7, count); //byte count for lswx/stswx
	} XER;

	#define VALID_MSR_MASK 0x2030
	//full function bits are saved in SRR1 when exception occurs
	typedef union MSR {
		u32 hex;
		struct {
			u32 LE : 1; //31, little-endian
			u32 RI : 1; //30, recoverable interrupt
			u32 PM : 1; //29, performance monitor marked
			u32 : 1; //28, reserved, full function
			u32 DR : 1; //27, data address translation
			u32 IR : 1; //26, instruction address translation
			u32 IP : 1; //25, exception prefix
			u32 : 1; //24, reserved, ???
			u32 FE1 : 1; //23, floating-point exception mode 1
			u32 BE : 1; //22, branch trace enable
			u32 SE : 1; //21, single-step trace enable
			u32 FE0 : 1; //20, floating-point exception mode 0
			u32 ME : 1; //19, machine check enable
			u32 FP : 1; //18, floating-point available
			u32 PR : 1; //17, privilege level
			u32 EE : 1; //16, external interrupt enable
			u32 ILE : 1; //15, exception little-endian mode
			u32 : 1; //14, reserved, ???
			u32 POW : 1; //13, power management enable
			u32 : 3; //10-12, reserved, partial function
			u32 : 5; //5-9, reserved, full function
			u32 : 4; //1-4, reserved, partial function
			u32 : 1; //0, reserved, full function
		};
	} MSR;

	//we can interpret all instructions under one structure
	union instruction {
		u32 hex;
		BITSTRUCT(0, 6, opcode);

		BITSTRUCT(6, 3, crfD);
		BITSTRUCT(6, 5, rD);
		BITSTRUCT(6, 5, rS);

		BITSTRUCT(10, 1, L);

		BITSTRUCT(11, 5, rA);
		BITSTRUCT(11, 5, spr2);

		BITSTRUCT(12, 4, SR);

		BITSTRUCT(16, 5, rB);
		BITSTRUCT(16, 5, NB); //num_bytes for lswi/stswi
		BITSTRUCT(16, 5, SH);
		BITSTRUCT(16, 5, spr1);

		BITSTRUCT(16, 16, SIMM); //interpret signed manually, convenience
		BITSTRUCT(16, 16, UIMM);
		BITSTRUCT(16, 16, d); //for load/store

		BITSTRUCT(21, 1, OE); //OE makes a different opcode w/extended
		BITSTRUCT(21, 5, MB);
		BITSTRUCT(21, 10, ext); //"extended" opcode

		BITSTRUCT(26, 5, ME);
		BITSTRUCT(31, 1, Rc); //"compare" bit
		inline constexpr u32 spr(void) { return ((this->spr1 << 5) | this->spr2); }
	};

	#define VALID_HID0_MASK 0x11CC64
	typedef union HID0 {
		u32 hex;
		struct {
			u32 NOOPTI : 1; //31, No-op touch instructions
			u32 : 1; //bit 30
			u32 BHT : 1; //29, branch history table
			u32 ABE : 1; //28, address broadcast enable
			u32 : 1; //bit 27
			u32 BTIC : 1; //26, branch target instruction cache
			u32 DCFA : 1; //25, data cache flush assist
			u32 SGE : 1; //24, store gathering enable
			u32 IFEM : 1; //23, instruction fetch enable M (bit)
			u32 SPD : 1; //22, speculative cache access disable
			u32 DCFI : 1; //21, data cache flash invalidate
			u32 ICFI : 1; //20, instruction cache flash invalidate
			u32 DLOCK : 1; //19, data cache lock
			u32 ILOCK : 1; //18, instruction cache lock
			u32 DCE : 1; //17, data cache enable
			u32 ICE : 1; //16, instruction cache enable
			u32 NHR : 1; //15, Not Hard Reset
			u32 : 3; //12-14
			u32 DPM : 1; //11, dynamic power management
			u32 SLEEP : 1; //10, sleep mode enable
			u32 NAP : 1; //9, nap mode enable
			u32 DOZE : 1; //8, doze mode enable
			u32 PAR : 1; //7, disable precharge of ARTRY
			u32 ECLK : 1; //6, reserved???
			u32 : 1; //bit 5
			u32 BCLK : 1; //4, reserved???
			u32 EBD : 1; //enable 60x *bus data* parity checking
			u32 EBA : 1; //enable 60x *bus address* parity checking
			u32 DBP : 1; //disable 60x *bus* address and data *parity* generation
			u32 EMCP : 1; //enable MCP
		};
	} HID0;

	typedef union UpperBAT {
		u32 hex = 0;
		struct {
			u32 Vp : 1; //bit 31, User mode valid
			u32 Vs : 1; //bit 30, Supervisor mode valid
			u32 BL : 11; //bit 19-29, block length
			u32 : 4;
			u32 BEPI : 15;
		};
	} UpperBAT;

	typedef union LowerBAT {
		u32 hex = 0;
		struct {
			u32 PP : 2; //bit 30-31, protection bits
			u32 : 1; //bit 29
			u32 WIMG : 4; //bit 25-28, write-through, caching-inhibited, memory coherence guarded
			u32 : 10;
			u32 BRPN : 15;
		};
	} LowerBAT;

	#define CR_LT 1 << 3
	#define CR_EQ 1 << 2
	#define CR_GT 1 << 1
	#define CR_SO 1 << 0
	typedef union CR {
		u64 hex;
		struct {
			u8 CR0;
			u8 CR1;
			u8 CR2;
			u8 CR3;
			u8 CR4;
			u8 CR5;
			u8 CR6;
			u8 CR7;
		};
		u8& operator[](u8 index);
	} CR;

	typedef struct cpu {
		cpu(void);
		inline void hwreg(u32 address);
		void write8(u32 address, u8 value);
		void write16(u32 address, u16 value);
		void write32(u32 address, u32 value);
		void read8(u32 address, u32& reg);
		void read16(u32 address, u32& reg);
		void read32(u32 address, u32& reg);

		u32 loadaddr(u32 base_addr, s32 offset);

		//Special Purpose Registers
		XER xer;
		void xer_carry(u32 a, u32 b);
		void xer_carry2(u32 a, u32 b, u32 carry);
		void xer_overflow(u32 a, u32 b, u32 result);
		void update_info_regs(u32 a, u32 b, u32 result, u32 record, u32 overflow);
		CR CR;

		u64 count = 0;
		u32 pc = 0;
		u32 gpr[32] = { 0 };
		u32 spr[1024] = { 0 }; //need to gateway
		MSR msr; //machine state register
		std::byte* memory[0x100000] = { nullptr }; //0x100000000 (4GB) / 0x1000 (4KB)
		u32 sr[16] = { 0 };
		UpperBAT ubat[8];
		LowerBAT lbat[8];

		//temp variables
		u32 EA;
		std::byte* memaddr = nullptr;
	} cpu;
}