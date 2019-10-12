#pragma once

#include "..//..//..//types.h"

namespace EXI {
	// This file is for the base class that all other devices inherit
	// See EXI.h for transfer write-up
	class EXIDevice {
		// Immediate mode transfer
		virtual void ImmWrite(u32 data, u32 size);
		virtual u32  ImmRead(u32 size);
		virtual void ImmReadWrite(u32& data, u32 size);

		// DMA mode transfer (R/W is invalid for DMA, per Control Register)
		// Uses EXI_MAR and EXI_LENGTH
		virtual void DMAWrite(u32 address, u32 size);
		virtual void DMARead(u32 address, u32 size);

		//both r/w in one function, data = device dependent (Modem, IPL, ...)
		//subclasses only need to worry about this, r/w above will call
		virtual void TransferByte(u8& byte) = 0;
		u8 byte;
		u32 result;
	};
}