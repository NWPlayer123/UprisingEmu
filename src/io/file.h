#pragma once

#include <fstream>
#include <memory>
#include "../types.h"

/*extern u16 __builtin_bswap16(u16 x);
extern u32 __builtin_bswap32(u32 x);
extern u64 __builtin_bswap64(u64 x);
#define byteswap16 __builtin_bswap16
#define byteswap32 __builtin_bswap32
#define byteswap64 __builtin_bswap64*/

#define IS_BIG_ENDIAN (*(uint16_t *)"\x00\xFF" < 0x100)

namespace munna {
	//TODO: support mixed fuckery?
	enum endian {
		little = 0,
		big = 1
	};

	class parse_base {
	public:
		virtual void read16(std::fstream& f, u64& value) = 0;
		virtual void read32(std::fstream& f, u64& value) = 0;
		virtual void read64(std::fstream& f, u64& value) = 0;
	};

	class parse_swap : public parse_base {
	public:
		void read16(std::fstream& f, u64& value);
		void read32(std::fstream& f, u64& value);
		void read64(std::fstream& f, u64& value);
	};

	class parse_norm : public parse_base {
	public:
		void read16(std::fstream& f, u64& value);
		void read32(std::fstream& f, u64& value);
		void read64(std::fstream& f, u64& value);
	};

    class file {
        public:
            file(std::string filename, std::string mode="rb", int endian=1);
			u64 tell(void);
			u64 size(void);
			void seek(u64 pos);
			void seek(s64 off, int pos);
			u8 readbyte(void);
			u16 read16(void);
			u32 read32(void);
			u64 read64(void);
			//not sensitive, devs can access it
			//"UINT64_MAX" for error checking
			u64 temp = UINT64_MAX;
			u64 filesize = UINT64_MAX;
			bool do_swap;
			//TODO: private
			std::fstream handle; //internal file handle
		private:
			std::unique_ptr<parse_base> parse; //subclass for reading data
    };
}