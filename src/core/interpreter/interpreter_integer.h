#pragma once

#include "..//..//types.h"
#include "..//gekko.h"

namespace interpreter {
	#define	rGPR cpu->gpr

	void addx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 266
	void addcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 10
	void addex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 138
	void addi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 14
	void addicx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 12, 13 ("." is 13)
	void addis(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 15
	void addmex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 234
	void addzex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 202
	void divwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 491
	void divwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 459
	void mulhwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 75
	void mulhwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);  //opcode 31 ext 11
	void mulli(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 7
	void mullwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 235
	void negx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 104
	void subfx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 40
	void subfcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 8
	void subfex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 31 ext 136
	void subficx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);  //opcode 8
	void subfmex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);  //opcode 31 ext 232
	void subfzex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);  //opcode 31 ext 200
}