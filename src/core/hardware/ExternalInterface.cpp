#include "ExternalInterface.h"

namespace EXI {
	std::string tobin(u32 value) {
		std::string ret = "0b";
		for (int i = 0; i < 32; i++)
			ret += (value & 1 << (31 - i)) ? "1" : "0";
		return ret;
	}

	void EXI::write(u32 address, u32 value) {
		switch (address & 0xFF) {
			case 0x28:
				this->cpr2.hex = value;
				this->cpr2.info(value);
				//printf("%s -> cpr2\n", tobin(value).c_str());
				break;
			case 0x2C:
				printf("%s -> mar2\n", tobin(value).c_str()); break;
			case 0x20:
				printf("%s -> length2\n", tobin(value).c_str()); break;
			case 0x34:
				this->cr2.hex = value;
				this->cr2.info(value);
				//printf("%s -> cr2\n", tobin(value).c_str());
				break;
			case 0x38:
				this->data2.hex = value; //bytes to write to bus
				printf("EXI2 data = 0x%08X\n", value);
				break;
		}
	}
	void EXI2CPR::info(u32 value) {
		if (value & 0xFFFFFF00)
			printf("ERROR: reserved bits set in EXI2CPR\n");
		printf("EXI2 params: ");
		printf("chip 0 %s", (value >> 7) & 1 ? "selected, " : "disabled, ");
		switch ((value >> 4) & 7) {
			case 0b000: printf("%dMHz, ", 1); break;
			case 0b001: printf("%dMHz, ", 2); break;
			case 0b010: printf("%dMHz, ", 4); break;
			case 0b011: printf("%dMHz, ", 8); break;
			case 0b100: printf("%dMHz, ", 16); break;
			case 0b101: printf("%dMHz, ", 32); break;
			default: printf("RESERVED2 MHz, "); break;
		}
		printf((value >> 3) & 1 ? "TCINT cleared, " : "");
		printf((value >> 2) & 1 ? "TCINTMSK enabled, " : "");
		printf((value >> 1) & 1 ? "EXIINT cleared, " : "");
		printf((value >> 0) & 1 ? "EXIINTMSK enabled, " : "");
		printf("\n");
		/*
		if ((value >> 7) & 1)
			printf("selected chip 0 device 2\n");
		switch ((value >> 4) & 7) {
			case 0b000:
				printf("EXI2: %dMHz\n", 1); break;
			case 0b001:
				printf("EXI2: %dMHz\n", 2); break;
			case 0b010:
				printf("EXI2: %dMHz\n", 4); break;
			case 0b011:
				printf("EXI2: %dMHz\n", 8); break;
			case 0b100:
				printf("EXI2: %dMHz\n", 16); break;
			case 0b101:
				printf("EXI2: %dMHz\n", 32); break;
			default:
				printf("RESERVED2 MHz\n"); break;
		}

		if ((value >> 3) & 1) printf("TC2 Interrupt Cleared\n");
		printf((value >> 2) & 1 ? "TC2 enabled\n" : "");

		if ((value >> 1) & 1) printf("EXI2 Interrupt Cleared\n");
		printf((value >> 0) & 1 ? "EXI2 enabled\n" : "");*/
	}

	void EXI2CR::info(u32 value) {
		if (value & 0xFFFFFFC0)
			printf("ERROR: reserved bits set in EXI2CR\n");
		if (value & 1) {
			printf("EXI2 %s transfer, ", (value >> 1) & 1 ? "DMA" : "immediate");
			printf("%d bytes, ", ((value >> 4) & 3) + 1);
			switch ((value >> 2) & 3) {
				case 0b00: printf("read\n"); break;
				case 0b01: printf("write\n"); break;
				case 0b10: printf("r/w\n"); break;
			}
		}
	}
}