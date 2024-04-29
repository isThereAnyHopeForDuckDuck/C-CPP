#include "s4.h"

#include <iostream>

s4 g_s4;

s4::s4()
{
	std::cout << "s4 struct" << std::endl;
}

void s4::run()
{
	std::cout << "s4 id" << m_id << std::endl;
}
