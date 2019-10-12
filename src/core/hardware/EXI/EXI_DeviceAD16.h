#pragma once

#include "..//..//..//types.h"
#include "EXI_Device.h"

namespace EXI {
	class EXIDevice_AD16 : public EXIDevice {
		void TransferByte(u8& byte);
	};
}