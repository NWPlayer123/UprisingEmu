#pragma once

#include "..//io//file.h"
#include "..//types.h"
#include "gekko.h"

namespace memory {
	std::vector<std::byte> alloc_data(size_t size);
	std::vector<gekko::instruction> alloc_code(size_t size);
	std::vector<gekko::instruction> alloc_code(munna::file& f); //overload
}