#pragma once

#include "core/interpreter/interpreter.h"
#include "core/memory.h"
#include "core/gekko.h"
#include "io/file.h"
#include "types.h"

/*
TODO: eventual JIT - test uint_fast32_t ?
TODO: add step before interpreter::run/JIT::run for initializing e.g. timing, memory?
TODO: inspect what IPL actually sets before hitting the apploader so we can skip it (expecting just globals)
TODO: add decryption logic to EXI/::run 
TODO: figure out how it actually loads the apploader, all I've looked at is the apploader itself getting
 called multiple times to load the dol, which then gets called.
TODO: eventual separate Wii folder aside from core (interpreter, JIT, hardware(?), rendering)
TODO: so much refactoring my brain melts out my ears, re: nice-to-haves

Design Philosophy (tentative/just for me):
* Pass in smallest element possible (e.g. EXI only needs r/w for DMA, so pass in &memory.
* Each moving part should be its own "container" e.g. a struct with a constructor if needed.
* If a file gets too large, of course you should split it up, ya dingus.
 */