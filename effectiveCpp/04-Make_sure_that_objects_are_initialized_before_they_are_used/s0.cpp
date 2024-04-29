#include "s0.h"

#include "s4.h"
#include "s3.h"

#include <iostream>

s0 g_s0;

s0::s0()
{
	std::cout << "s0 struct" << std::endl;
	g_s4.run();
	s3::get();
}

void s0::run()
{
}
