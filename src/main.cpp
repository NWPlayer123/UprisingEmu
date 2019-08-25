#include "core/gekko.h"
#include "io/file.h"
#include "core/interpreter/interpreter.h"
#include "main.h"

int main() {
	std::cout << "Hello CMake." << std::endl;
	auto f = munna::file("../gc-ntsc-10.bin.decrypted");
	try {
		interpreter::run(f);
	}
	catch (std::string s) {
		std::cout << s;
		return -1;
	}
	catch (const std::exception& e) {
		printf(e.what());
	}
	return 0;
}
