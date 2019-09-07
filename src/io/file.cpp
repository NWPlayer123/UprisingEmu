#include "file.h"

namespace munna {
    file::file(std::string filename, std::string mode, int endian) {
		//I like my aliases, so 
		if (mode == "r" || mode == "rb")
			this->handle = std::fstream(filename, std::ios::binary | std::ios::in);
		else if (mode == "w" || mode == "wb")
			this->handle = std::fstream(filename, std::ios::binary | std::ios::out);
		this->do_swap = endian != IS_BIG_ENDIAN;
		//big endian default != little endian system (usually)
		if (this->do_swap)
			this->parse = std::make_unique<parse_swap>();
		else
			this->parse = std::make_unique<parse_norm>();

    }

	/************* File Position Handling *************/
	u64 file::tell(void) {
		return this->handle.tellg();
	}

	// Seeking overhead shouldn't be terrible, hopefully
	u64 file::size(void) {
		u64 initialpos = this->tell(); //restore initial pos at end
		this->seek(0, 0); //start of file
		this->filesize = this->tell(); // !!! NOT ALWAYS 0 !!!
		this->seek(0, 2); //end of file
		this->filesize = this->tell() - this->filesize;
		this->seek(initialpos);
		return this->filesize; //end streampos - start streampos
	}

	void file::seek(u64 pos) {
		this->handle.seekg(pos);
	}

	void file::seek(s64 off, int pos) {
		if (pos == 0) //I like my python aliases
			this->handle.seekg(off, std::ios::beg);
		else if (pos == 1)
			this->handle.seekg(off, std::ios::cur);
		else if (pos == 2)
			this->handle.seekg(off, std::ios::end);
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