#pragma once

#include "../types.h"

//we can interpret all instructions under one structure
union GekkoInstruction {
	u32 hex;
	//opcode struct
	struct {
		u32 : 26;
		u32 opcode : 6;
	};
	//"index2" struct re: opcode 31
	struct {
		u32 : 1;
		u32 idx2 : 10;
		u32 : 21;
	};
    struct {
		s32 SIMM : 16;
		u32 rA : 5;
		u32 rD : 5;
        u32 : 6;
    };
	//mtspr
	struct {
		u32 : 11;
		u32 spr1 : 5;
		u32 spr2 : 5;
		u32 rS : 5;
		u32 : 6;
	};
	//sth (+more?)
	struct {
		u32 d : 16;
	};
	//unsigned immediate
	struct {
		u32 UIMM : 16;
	};
};

#define VALID_MSR_MASK 0x2000
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