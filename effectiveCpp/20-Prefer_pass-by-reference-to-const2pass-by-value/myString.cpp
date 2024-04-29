#include "myString.h"

#include <iostream>

myString::myString()
{
	std::cout << "mystring create" << std::endl;
}

myString::myString(const myString&)
{
	std::cout << "mystring copy create" << std::endl;
}

myString::myString(const myString&&)
{
	std::cout << "mystring move create" << std::endl;
}
