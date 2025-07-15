#include <winteryufox.core/library.h>
#include <iostream>

extern "C" {
	void sayHello() {
		std::cout << "Hello from DLL!" << std::endl;
	}
}