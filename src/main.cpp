﻿#include "main.h"

int main() {
	std::cout << "Hello CMake." << std::endl;
	auto f = munna::file("../gc-ntsc-10.bin.decrypted");
	u64 size = f.size();
	std::vector<gekko::instruction> code = memory::alloc_code(f);
	try {
		PPCInterpreter::run(code);
	}
	catch (std::string s) {
		std::cout << s;
		return -1;
	}
	catch (const char* s) {
		std::cout << s;
		return -1;
	}
	catch (const std::exception& e) {
		printf(e.what());
	}
	return 0;
}
