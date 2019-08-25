cmake_minimum_required (VERSION 3.8)
project(UprisingEmu)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread -O2")

set(SOURCES
		src/core/hardware/DSP.cpp
		src/core/interpreter/interpreter.cpp
		src/core/gekko.cpp
		src/core/memory.cpp
		src/io/file.cpp
		src/main.cpp
		)

set(HEADERS
		src/core/hardware/DSP.h
		src/core/interpreter/interpreter.h
		src/core/gekko.h
		src/core/memory.h
		src/io/file.h
		src/types.h
		src/main.h
		)

add_executable (UprisingEmu ${SOURCES} ${HEADERS})
