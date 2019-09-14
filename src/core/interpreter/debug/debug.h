#pragma once

#include "..//..//..//types.h"
#include "..//..//gekko.h"
#include "debug_tables.h"

namespace debug {
	void debug(gekko::instruction& inst, std::unique_ptr<gekko::cpu>& cpu);
}