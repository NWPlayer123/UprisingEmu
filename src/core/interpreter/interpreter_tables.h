#pragma once

/* do not look in here, you've been warned */

#include "interpreter_branch.h"
#include "interpreter_integer.h"
#include "interpreter_loadstore.h"
#include "interpreter_system.h"
#include "..//..//types.h"
#include "..//gekko.h"

namespace interpreter {
	#define	rGPR cpu->gpr

	void opcode19(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);
	void opcode31(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);

	static std::array<std::function<void(gekko::instruction&, std::unique_ptr<gekko::cpu>&)>, 64> primary = {
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 0-7
		nullptr, nullptr, cmpli,   nullptr, addic,   addic_rc,addi,   addis,    //opcode 8-15
		bcx,     nullptr, bx,      opcode19,nullptr, rlwinmx, nullptr, nullptr, //opcode 16-23
		ori,     oris,    nullptr, nullptr, nullptr, nullptr, nullptr, opcode31,//opcode 24-31
		lwz,     lwzu,    lbz,     lbzu,    stw,     stwu,    stb,     stbu,    //opcode 32-39
		lhz,     lhzu,    lha,     lhau,    sth,     sthu,    nullptr, nullptr, //opcode 40-47
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 48-55
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr  //opcode 56-63
	};

	static std::array<std::function<void(gekko::instruction&, std::unique_ptr<gekko::cpu>&)>, 536> table19 = {
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 0-7
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 8-15
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 16-23
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 24-31
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 32-39
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 40-47
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 48-55
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 56-63
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 64-71
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 72-79
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 80-87
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 88-95
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 96-103
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 104-111
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 112-119
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 120-127
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 128-135
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 136-143
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, isync,   nullptr, //opcode 144-151
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 152-159
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 160-167
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 168-175
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 176-183
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 184-191
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 192-199
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 200-207
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 208-215
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 216-223
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 224-231
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 232-239
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 240-247
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 248-255
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 256-263
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 264-271
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 272-279
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 280-287
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 288-295
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 296-303
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 304-311
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 312-319
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 320-327
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 328-335
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 336-343
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 344-351
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 352-359
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 360-367
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 368-375
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 376-383
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 384-391
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 392-399
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 400-407
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 408-415
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 416-423
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 424-431
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 432-439
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 440-447
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 448-455
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 456-463
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 464-471
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 472-479
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 480-487
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 488-495
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 496-503
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 504-511
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 512-519
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 520-527
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //opcode 528-535
	};

	static std::array<std::function<void(gekko::instruction&, std::unique_ptr<gekko::cpu>&)>, 1024> table31 = {
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 0-7
		nullptr, nullptr, addcx,   nullptr, nullptr, nullptr, nullptr, nullptr, //ext 8-15
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 16-23
		nullptr, nullptr, nullptr, nullptr, andx,    nullptr, nullptr, nullptr, //ext 24-31
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 32-39
		subfx,   nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 40-47
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 48-55
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 56-63
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 64-71
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 72-79
		nullptr, nullptr, nullptr, mfmsr,   nullptr, nullptr, nullptr, nullptr, //ext 80-87
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 88-95
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 96-103
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 104-111
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 112-119
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 120-127
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 128-135
		nullptr, nullptr, addex,   nullptr, nullptr, nullptr, nullptr, nullptr, //ext 136-143
		nullptr, nullptr, mtmsr,   nullptr, nullptr, nullptr, nullptr, nullptr, //ext 144-151
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 152-159
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 160-167
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 168-175
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 176-183
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 184-191
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 192-199
		nullptr, nullptr, addzex,  nullptr, nullptr, nullptr, nullptr, nullptr, //ext 200-207
		nullptr, nullptr, mtsr,    nullptr, nullptr, nullptr, nullptr, nullptr, //ext 208-215
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 216-223
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 224-231
		nullptr, nullptr, addmex,  nullptr, nullptr, nullptr, nullptr, nullptr, //ext 232-239
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 240-247
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 248-255
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 256-263
		nullptr, nullptr, addx,    nullptr, nullptr, nullptr, nullptr, nullptr, //ext 264-271
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 272-279
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 280-287
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 288-295
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 296-303
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 304-311
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 312-319
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 320-327
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 328-335
		nullptr, nullptr, nullptr, mfspr,   nullptr, nullptr, nullptr, nullptr, //ext 336-343
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 344-351
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 352-359
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 360-367
		nullptr, nullptr, nullptr, mftb,    nullptr, nullptr, nullptr, nullptr, //ext 368-375
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 376-383
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 384-391
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 392-399
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 400-407
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 408-415
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 416-423
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 424-431
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 432-439
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 440-447
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 448-455
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 456-463
		nullptr, nullptr, nullptr, mtspr,   nullptr, nullptr, nullptr, nullptr, //ext 464-471
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 472-479
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 480-487
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 488-495
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 496-503
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 504-511
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 512-519
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 520-527
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 528-535
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 536-543
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 544-551
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 552-559
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 560-567
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 568-575
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 576-583
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 584-591
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 592-599
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 600-607
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 608-615
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 616-623
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 624-631
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 632-639
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 640-647
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 648-655
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 656-663
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 664-671
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 672-679
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 680-687
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 688-695
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 696-703
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 704-711
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 712-719
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 720-727
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 728-735
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 736-743
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 744-751
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 752-759
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 760-767
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 768-775
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 776-783
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 784-791
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 792-799
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 800-807
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 808-815
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 816-823
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 824-831
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 832-839
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 840-847
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 848-855
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 856-863
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 864-871
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 872-879
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 880-887
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 888-895
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 896-903
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 904-911
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 912-919
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 920-927
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 928-935
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 936-943
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 944-951
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 952-959
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 960-967
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 968-975
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 976-983
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 984-991
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 992-999
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 1000-1007
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 1008-1015
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, //ext 1016-1023
	};
}