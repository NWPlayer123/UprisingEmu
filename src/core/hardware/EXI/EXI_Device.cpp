#include "EXI_Device.h"

namespace EXI {
	void EXIDevice::ImmWrite(u32 data, u32 size) {
		while (size--) {
			byte = data >> 24; //lowest byte
			TransferByte(byte);
			data <<= 8; //top byte
		}
	}

	u32 EXIDevice::ImmRead(u32 size) {
		while (size--) {
			TransferByte(byte);
			result |= byte << ((size - 1) * 8);
		}
		return result;
	}

	void EXIDevice::ImmReadWrite(u32& data, u32 size) {
		throw std::string("ImmReadWrite not impl. yet\n"); //TODO: find use case
	}

	//TODO: add memory allocation and link it
	//use generic read32/write32 in gekko::cpu?
	//future self: pass memory& something instead of cpu& since we only need memory r/w
	void EXIDevice::DMAWrite(u32 address, u32 size) {
		throw std::string("DMAWrite not impl. yet\n");
	}
	void EXIDevice::DMARead(u32 address, u32 size) {
		throw std::string("DMARead not impl. yet\n");
	}
}