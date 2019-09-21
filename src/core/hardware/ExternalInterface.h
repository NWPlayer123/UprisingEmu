#pragma once

#include "..//..//types.h"

namespace EXI {
	typedef union EXI0CPR {
		u32 hex;
		struct {
			//0-17 (31:14) reserved
			BITSTRUCT(18, 1, ROMIDIS);
			BITSTRUCT(19, 1, EXT);
			BITSTRUCT(20, 1, EXTINT);
			BITSTRUCT(21, 1, EXTINTMSK);
			BITSTRUCT(22, 1, CS2B);
			BITSTRUCT(23, 1, CS1B);
			BITSTRUCT(24, 1, CS0B);
			BITSTRUCT(25, 3, CLK);
			BITSTRUCT(28, 1, TCINT);
			BITSTRUCT(29, 1, TCINTMSK);
			BITSTRUCT(30, 1, EXIINT);
			BITSTRUCT(31, 1, EXIINTMSK);
		};
	} EXI0CPR;

	typedef union EXI0MAR {
		u32 hex;
		struct {
			//0-5 (31:26) reserved
			BITSTRUCT(6, 21, EXIMAR);
			BITSTRUCT(27, 5, ALIGN);
		};
	} EXI0MAR;

	typedef union EXI0LENGTH {
		u32 hex;
		struct {
			//0-5 (31:26) reserved
			BITSTRUCT(6, 21, EXILENGTH);
			BITSTRUCT(27, 5, ALIGN);
		};
	} EXI0LENGTH;

	typedef union EXI0CR {
		u32 hex;
		struct {
			//0-25 (31:6) reserved
			BITSTRUCT(26, 2, TLEN);
			BITSTRUCT(28, 2, RW);
			BITSTRUCT(30, 1, DMA);
			BITSTRUCT(31, 1, TSTART);
		};
	} EXI0CR;

	typedef union EXI0DATA {
		u32 hex;
		struct {
			BITSTRUCT(0, 8, DATA0);
			BITSTRUCT(8, 8, DATA1);
			BITSTRUCT(16, 8, DATA2);
			BITSTRUCT(24, 8, DATA3);
		};
	} EXI0DATA;

	//------------------------------------------

	typedef union EXI1CPR {
		u32 hex;
		struct {
			//0-17 (31:14) reserved
			//BootROM disable mask EXI0 only
			BITSTRUCT(19, 1, EXT);
			BITSTRUCT(20, 1, EXTINT);
			BITSTRUCT(21, 1, EXTINTMSK);
			//CS1B, CS2B are EXI0 only
			BITSTRUCT(24, 1, CS0B);
			BITSTRUCT(25, 3, CLK);
			BITSTRUCT(28, 1, TCINT);
			BITSTRUCT(29, 1, TCINTMSK);
			BITSTRUCT(30, 1, EXIINT);
			BITSTRUCT(31, 1, EXIINTMSK);
		};
	} EXI1CPR;

	typedef union EXI1MAR {
		u32 hex;
		struct {
			//0-5 (31:26) reserved
			BITSTRUCT(6, 21, EXIMAR);
			BITSTRUCT(27, 5, ALIGN);
		};
	} EXI1MAR;

	typedef union EXI1LENGTH {
		u32 hex;
		struct {
			//0-5 (31:26) reserved
			BITSTRUCT(6, 21, EXILENGTH);
			BITSTRUCT(27, 5, ALIGN);
		};
	} EXI1LENGTH;

	typedef union EXI1CR {
		u32 hex;
		struct {
			//0-25 (31:6) reserved
			BITSTRUCT(26, 2, TLEN);
			BITSTRUCT(28, 2, RW);
			BITSTRUCT(30, 1, DMA);
			BITSTRUCT(31, 1, TSTART);
		};
	} EXI1CR;

	typedef union EXI1DATA {
		u32 hex;
		struct {
			BITSTRUCT(0, 8, DATA0);
			BITSTRUCT(8, 8, DATA1);
			BITSTRUCT(16, 8, DATA2);
			BITSTRUCT(24, 8, DATA3);
		};
	} EXI1DATA;

	//------------------------------------------

	typedef union EXI2CPR {
		void info(u32 value);
		u32 hex;
		struct {
			//0-17 (31:14) reserved
			//BootROM disable mask EXI0 only
			//EXT is EXI0/1 only
			//CS1B, CS2B are EXI0 only
			BITSTRUCT(24, 1, CS0B);
			BITSTRUCT(25, 3, CLK);
			BITSTRUCT(28, 1, TCINT);
			BITSTRUCT(29, 1, TCINTMSK);
			BITSTRUCT(30, 1, EXIINT);
			BITSTRUCT(31, 1, EXIINTMSK);
		};
	} EXI2CPR;

	typedef union EXI2MAR {
		u32 hex;
		struct {
			//0-5 (31:26) reserved
			BITSTRUCT(6, 21, EXIMAR);
			BITSTRUCT(27, 5, ALIGN);
		};
	} EXI2MAR;

	typedef union EXI2LENGTH {
		u32 hex;
		struct {
			//0-5 (31:26) reserved
			BITSTRUCT(6, 21, EXILENGTH);
			BITSTRUCT(27, 5, ALIGN);
		};
	} EXI2LENGTH;

	typedef union EXI2CR {
		void info(u32 value);
		u32 hex;
		struct {
			//0-25 (31:6) reserved
			BITSTRUCT(26, 2, TLEN);
			BITSTRUCT(28, 2, RW);
			BITSTRUCT(30, 1, DMA);
			BITSTRUCT(31, 1, TSTART);
		};
	} EXI2CR;

	typedef union EXI2DATA {
		u32 hex;
		struct {
			BITSTRUCT(0, 8, DATA0);
			BITSTRUCT(8, 8, DATA1);
			BITSTRUCT(16, 8, DATA2);
			BITSTRUCT(24, 8, DATA3);
		};
	} EXI2DATA;

	typedef struct EXI {
		void write(u32 address, u32 value);
		EXI0CPR cpr0; //00
		EXI0MAR mar0; //04
		EXI0LENGTH length0; //08
		EXI0CR cr0; //0C
		EXI0DATA data0; //10

		EXI1CPR cpr1; //14
		EXI1MAR mar1; //18
		EXI1LENGTH length1; //1C
		EXI1CR cr1; //20
		EXI1DATA data1; //24

		EXI2CPR cpr2; //28
		EXI2MAR mar2; //2C
		EXI2LENGTH length2; //30
		EXI2CR cr2; //34
		EXI2DATA data2; //38
	} EXI;
}