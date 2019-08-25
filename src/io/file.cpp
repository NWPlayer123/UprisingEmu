#include "file.h"

namespace munna {
    file::file(std::string filename, std::string mode, int endian) {
		//I like my aliases, so 
		if (mode == "r" || mode == "rb")
			this->handle = std::fstream(filename, std::ios::binary | std::ios::in);
		else if (mode == "w" || mode == "wb")
			this->handle = std::fstream(filename, std::ios::binary | std::ios::out);
		//big endian default != little endian system (usually)
		if (endian != IS_BIG_ENDIAN)
			this->parse = std::make_unique<parse_swap>();
		else
			this->parse = std::make_unique<parse_norm>();

    }

	/************* Parsing Data, Pipe to Endian *************/
	u8 file::readbyte(void) {
		this->handle.read((char*)&this->temp, 1);
		return this->temp;
	}

	u16 file::read16(void) {
		this->parse->read16(this->handle, this->temp);
		return this->temp;
	}

	u32 file::read32(void) {
		this->parse->read32(this->handle, this->temp);
		return this->temp;
	}

	u64 file::read64(void) {
		this->parse->read64(this->handle, this->temp);
		return this->temp;
	}

	/************* Parsing Data, Swap Endian *************/
	void parse_swap::read16(std::fstream& f, u64& value) {
		f.read((char*)&value, 2);
		value = __builtin_bswap16((u16)value);
	}

	void parse_swap::read32(std::fstream& f, u64& value) {
		f.read((char*)&value, 4);
		value = __builtin_bswap32((u32)value);
	}

	void parse_swap::read64(std::fstream& f, u64& value) {
		f.read((char*)&value, 8);
		value = __builtin_bswap64((u64)value);
	}

	/************* Parsing Data, Keep Endian *************/
	void parse_norm::read16(std::fstream& f, u64& value) {
		f.read((char*)& value, 2);
	}

	void parse_norm::read32(std::fstream& f, u64& value) {
		f.read((char*)& value, 4);
	}

	void parse_norm::read64(std::fstream& f, u64& value) {
		f.read((char*)& value, 8);
	}
}