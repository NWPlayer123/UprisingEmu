#pragma once

#include "../../io/file.h"
#include "../gekko.h"
#include "debug/debug.h"
#include "../../types.h"
#include "interpreter_integer.h"
#include "interpreter_system.h"
#include "interpreter_tables.h"

typedef void (*HandleInput)(u32& value, void* address, bool isWrite);

namespace interpreter {
	void run(std::vector<gekko::instruction>& code);
	#define rGPR cpu->gpr
	//#define rSPR cpu.spr

	//static std::array<std::function<void(gekko::instruction&, std::unique_ptr<gekko::cpu>&)>, 64> primary = { nullptr };
	//static std::array<std::function<void(gekko::instruction&, std::unique_ptr<gekko::cpu>&)>, 1024> table31 = { nullptr };
}