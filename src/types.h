#pragma once

#include <array>
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

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

#define BITSTRUCT(bit, len, name) struct { u32 : (32 - bit - len); u32 name : len; }

//if bit 16 is 1, extend it (16 -> 32)
static inline constexpr s32 EXTS(u32 x) { return (x >> 15 ? x | 0xFFFF0000 : x); }

//we have to carry bits so shift (32 - y) other direction and OR
static inline constexpr u32 ROTL(u32 x, u32 y) { return ((x << y) | (x >> (32 - y))); }
static inline constexpr u32 ROTR(u32 x, u32 y) { return ((x << (32 - y)) | (x >> y)); }
static inline constexpr u32 MASK(u32 x, u32 y) { return ((x <= y) ? ((~0u >> x) & (~0u << (31 - y))) : ((~0u >> x) | (~0u << (31 - y)))); }

// https://stackoverflow.com/a/26221725
template<typename ... Args>
std::string format(const std::string& format, Args ... args)
{
	size_t size = (size_t)snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
	std::unique_ptr<char[]> buf(new char[size]);
	snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}