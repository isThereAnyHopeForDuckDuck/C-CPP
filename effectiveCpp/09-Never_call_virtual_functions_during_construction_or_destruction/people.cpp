#include "people.h"

#include <iostream>

people::people()
{
	init();
}

void people::genName()
{
	std::cout << "gen people name" << std::endl;
}

void people::init()
{
	genName();
}
