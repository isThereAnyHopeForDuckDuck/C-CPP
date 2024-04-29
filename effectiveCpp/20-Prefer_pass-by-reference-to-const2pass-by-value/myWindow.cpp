#include "myWindow.h"

#include <iostream>

myWindow::myWindow()
{
	std::cout << "myWindow create" << std::endl;
}

myWindow::myWindow(const myWindow&)
{
	std::cout << "myWindow copy create" << std::endl;
}

