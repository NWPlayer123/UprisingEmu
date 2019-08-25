#include "memory.h"

namespace memory {
	std::vector<std::byte> allocate(size_t size) {
		std::vector<std::byte> array; //create vector
		array.reserve(size); //"reserve"/allocate X bytes
		return array; //return by value
	}
}