#include "window.h"

#include <iostream>

window::window()
{
	std::cout << "window create" << std::endl;
}

window::window(const window&)
{
	std::cout << "window copy create" << std::endl;
}

