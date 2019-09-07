#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <cstddef>
#include <cstdint>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
extern u16 __builtin_bswap16(u16);
extern u32 __builtin_bswap32(u32);
extern u64 __builtin_bswap64(u64);

// https://stackoverflow.com/a/26221725
template<typename ... Args>
std::string format(const std::string& format, Args ... args)
{
	size_t size = (size_t)snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
	std::unique_ptr<char[]> buf(new char[size]);
	snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}