#pragma once

#include "..//types.h"

namespace memory {
	std::vector<std::byte> allocate(size_t size);
	typedef enum PageType {
		TYPE_INVALID = -1,
		TYPE_MEMORY = 0,
		TYPE_HWREG = 1,
		//TODO?
	};

	typedef struct page {
		PageType type;
		void* data;
	} page;
}