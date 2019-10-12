#pragma once

#include "..//..//..//types.h"

/* External Interface (EXI) transfer write-up:
 * 1. Write u32 to EXI_DATA (will specify num_bytes later)
 * 2. Write transfer params to EXI_CPR (chip, clock freq, interrupts)
 * 3. Write to EXI_CR (Imm/DMA mode, r/w, 1/2/3/4 bytes, T(ransfer)START)
 * 4. Device does its thing, processes command
 * 5. Unset EXI_CPR so chip isn't mapped and nothing weird can happen
 */

namespace EXI {
	typedef union EXI_CPR {
		u32 hex;
		struct {
			//0-17 (31:14) reserved
			BITSTRUCT(18, 1, ROMIDIS);   //EXI 0 only
			BITSTRUCT(19, 1, EXT);       //EXI 0/1 only
			BITSTRUCT(20, 1, EXTINT);    //EXI 0/1 only
			BITSTRUCT(21, 1, EXTINTMSK); //EXI 0/1 only
			BITSTRUCT(22, 1, CS2B);      //EXI 0 only
			BITSTRUCT(23, 1, CS1B);      //EXI 0 only
			BITSTRUCT(24, 1, CS0B);
			BITSTRUCT(25, 3, CLK);
			BITSTRUCT(28, 1, TCINT);
			BITSTRUCT(29, 1, TCINTMSK);
			BITSTRUCT(30, 1, EXIINT);
			BITSTRUCT(31, 1, EXIINTMSK);
		};
	} EXI_CPR;

	typedef union EXI_MAR {
		u32 hex;
		struct {
			//TODO: remove align?
			//0-5 (31:26) reserved
			BITSTRUCT(6, 21, EXIMAR);
			BITSTRUCT(27, 5, ALIGN);
		};
	} EXI_MAR;

	typedef union EXI_LENGTH {
		u32 hex;
		struct {
			//TODO: remove align?
			//0-5 (31:26) reserved
			BITSTRUCT(6, 21, EXILENGTH);
			BITSTRUCT(27, 5, ALIGN);
		};
	} EXI_LENGTH;

	typedef union EXI_CR {
		u32 hex;
		struct {
			//0-25 (31:6) reserved
			BITSTRUCT(26, 2, TLEN);
			BITSTRUCT(28, 2, RW);
			BITSTRUCT(30, 1, DMA);
			BITSTRUCT(31, 1, TSTART);
		};
	} EXI_CR;

	typedef union EXI_DATA {
		u32 hex;
		struct {
			BITSTRUCT(0, 8, DATA0);
			BITSTRUCT(8, 8, DATA1);
			BITSTRUCT(16, 8, DATA2);
			BITSTRUCT(24, 8, DATA3);
		};
	} EXI_DATA;

	/*typedef struct EXI_HW {
		void write(u32 address, u32 value);
		EXI_CPR cpr; //00
		EXI_MAR mar; //04
		EXI_LENGTH length; //08
		EXI_CR cr; //0C
		EXI_DATA data; //10
	} EXI_HW;
	EXI_HW EXI[3];*/

	// "Container" object that stores all the stuff we need
	typedef struct EXI {
		void write(u32 address, u32 value);
		//static std::array<std::unique_ptr<CEXIChannel>, MAX_EXI_CHANNELS> g_Channels;
		
	} EXI;
}