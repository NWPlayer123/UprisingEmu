#pragma once

#include "..//..//types.h"

/*
Dolphin isn't much help in this regard, with regards to timings.
Basically, tie everything to the CPU (since that's what does processing anyways).
Note: everything below is GameCube specific.

CPU Clock Speed = 486000000 Hz (486MHz)
Bus Clock Speed = 162000000 Hz (162MHz, CPU/3)
OS Timer Clock  =  40500000 Hz (40.5MHz, CPU/12 or Bus/4)

Time Base (tb/tbu SPRs) and Decrementer (dec SPR) run at the Timer Clock speed

*/
namespace CoreTiming {
	
}