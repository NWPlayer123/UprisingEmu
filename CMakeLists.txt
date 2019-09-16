cmake_minimum_required (VERSION 3.8)
project(UprisingEmu)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread -O2 -fdiagnostics-color=always")

set(SOURCES
		src/core/hardware/DSP.cpp
		src/core/interpreter/debug/debug.cpp
		src/core/interpreter/debug/debug_branch.cpp
		src/core/interpreter/debug/debug_integer.cpp
		src/core/interpreter/debug/debug_loadstore.cpp
		src/core/interpreter/debug/debug_print.cpp
		src/core/interpreter/debug/debug_system.cpp
		src/core/interpreter/debug/debug_tables.cpp
		src/core/interpreter/interpreter.cpp
		src/core/interpreter/interpreter_branch.cpp
		src/core/interpreter/interpreter_integer.cpp
		src/core/interpreter/interpreter_loadstore.cpp
		src/core/interpreter/interpreter_system.cpp
		src/core/interpreter/interpreter_tables.cpp
		src/core/gekko.cpp
		src/core/memory.cpp
		src/io/file.cpp
		src/main.cpp
		)

set(HEADERS
		src/core/hardware/DSP.h
		src/core/interpreter/debug/debug.h
		src/core/interpreter/debug/debug_branch.h
		src/core/interpreter/debug/debug_integer.h
		src/core/interpreter/debug/debug_loadstore.h
		src/core/interpreter/debug/debug_print.h
		src/core/interpreter/debug/debug_system.h
		src/core/interpreter/debug/debug_tables.h
		src/core/interpreter/interpreter.h
		src/core/interpreter/interpreter_branch.h
		src/core/interpreter/interpreter_integer.h
		src/core/interpreter/interpreter_loadstore.h
		src/core/interpreter/interpreter_system.h
		src/core/interpreter/interpreter_tables.h
		src/core/gekko.h
		src/core/memory.h
		src/io/file.h
		src/types.h
		src/main.h
		)

add_executable (UprisingEmu ${SOURCES} ${HEADERS})
