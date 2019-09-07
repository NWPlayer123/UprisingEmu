#include "memory.h"

namespace memory {
	std::vector<std::byte> alloc_data(size_t size) {
		std::vector<std::byte> array; //create vector
		array.reserve(size); //"reserve"/allocate X bytes
		return array; //return by value
	}

	std::vector<GekkoInstruction> alloc_code(size_t size) {
		std::vector<GekkoInstruction> array; //create vector
		array.reserve(size); //"reserve"/allocate X instructions
		return array; //return by value
	}

	std::vector<GekkoInstruction> alloc_code(munna::file& f) {
		std::vector<GekkoInstruction> array; //create vector
		if (f.filesize == UINT64_MAX) f.size();
		array.reserve(f.filesize >> 2); //divide to get 4-byte instructions
		f.handle.read((char*)&array[0], f.filesize >> 2);
		if (f.do_swap) {
			for (int i = 0; i < (f.filesize >> 2); i++) {
				array[i].hex = __builtin_bswap32(array[i].hex);
			}
		}
		return array; //return by value
	}
}