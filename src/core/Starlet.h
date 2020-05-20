#pragma once

#include "..//types.h"

/*
"Starlet" is the name of the security processor on the Wii.
It's a NEC ARM926EJ-S SoC (ARMv5TEJ), clocked at 243MHz.
AKA 1/3 of the Broadway. It's part of the Hollywood chip.
Supports ARM and THUMB.

Boot process:
 - Power On, start on-dye rom (boot0)
 - 0xFFFF0000 (ARM Reset Vector) -> boot0 start
     (all other exception vectors hardloop rn)
 - boot0 decrypts and hashes boot1 at 0x0D400000 (mirrored to 0xFFF00000)
 - boot1 ???
*/

#define ARM_Exception_Reset			0xFFFF0000
#define ARM_Exception_Syscall		0xFFFF0004
#define ARM_Exception_PrefetchAbort	0xFFFF0008
#define ARM_Exception_DataAbort		0xFFFF0010
#define ARM_Exception_Reserved		0xFFFF0014
#define ARM_Exception_IRQ			0xFFFF0018
#define ARM_Exception_FIQ			0xFFFF001C

namespace Starlet {

}