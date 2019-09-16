#pragma once

#include "..//..//..//types.h"
#include "..//..//gekko.h"
#include "debug_print.h"

namespace debug {
	// Integer Arithmetic Instructions
	void addx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 266
	void addcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 10
	void addex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 138
	void addi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 14
	void addic(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 12
	void addic_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 13
	void addis(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 15
	void addmex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 234
	void addzex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 202
	void divwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 491
	void divwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 459
	void mulhwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 75
	void mulhwux(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 11
	void mulli(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 7
	void mullwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 235
	void negx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 104
	void subfx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 40
	void subfcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 8
	void subfex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 136
	void subficx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 8
	void subfmex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 232
	void subfzex(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 200

	// Integer Compare Instructions
	void cmp(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 31 ext 0
	void cmpi(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 11
	void cmpl(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 32
	void cmpli(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 10

	// Integer Logical Instructions
	void andx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 28
	void andcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 60
	void andi_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 28
	void andis_rc(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);   //opcode 29
	void cntlzwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 31 ext 26
	void eqvx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 284
	void extsbx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 954
	void extshx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 922
	void nandx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 476
	void norx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 124
	void orx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 31 ext 444
	void orcx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 412
	void ori(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);        //opcode 24
	void oris(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 25
	void xorx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 316
	void xori(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 26
	void xoris(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 27

	// Integer Rotate Instructions
	void rlwimix(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 20
	void rlwinmx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);    //opcode 21
	void rlwnmx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 23

	// Integer Shift Instructions
	void slwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 24
	void srawx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);      //opcode 31 ext 792
	void srawix(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);     //opcode 31 ext 824
	void srwx(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);       //opcode 31 ext 536
}