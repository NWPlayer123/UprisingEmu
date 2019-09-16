#pragma once

#include "..//..//types.h"
#include "..//gekko.h"

namespace interpreter {
	#define	rGPR cpu->gpr

	/* Plan is, our memory pages will be either 0 (nullptr), 1 (hardware register), or
	 * some actual address (std::array*). Each function here, if > 1, write to page,
	 * if 1, call cpu->read/write, which will pipe to each hwreg, and/or throw an error.
	 */

	// Integer Load Instructions
	void lbz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 34
	void lbzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 35
	void lbzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 119
	void lbzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 87
	void lha(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 42
	void lhau(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 43
	void lhaux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 375
	void lhax(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 343
	void lhz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 40
	void lhzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 41
	void lhzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 311
	void lhzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 279
	void lwz(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 32
	void lwzu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 33
	void lwzux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 55
	void lwzx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 23

	// Integer Store Instructions
	void stb(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 38
	void stbu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 39
	void stbux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 247
	void stbx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 215
	void sth(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 44
	void sthu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 45
	void sthux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 439
	void sthx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 407
	void stw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 36
	void stwu(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 37
	void stwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 183
	void stwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 151

	// Integer Load and Store with Byte Reverse Instructions
	void lhbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 790
	void lwbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 534
	void sthbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 918
	void stwbrx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 662

	// Integer Load and Store Multiple Instructions
	void lmw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 46
	void stmw(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 47

	// Integer Load and Store String Instructions
	void lswi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 597
	void lswx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 533
	void stswi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 725
	void stswx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 661
}