#pragma once

#include <iostream>

class Debug {

public:
	template <typename t>
	static void Log(t value) {
		std::cout << value << std::endl;
	}
};