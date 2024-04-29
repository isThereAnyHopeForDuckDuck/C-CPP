#pragma once

#include "myString.h"

class window
{
public:
	window();
	window(const window&);

private:
	myString m_name;
};

