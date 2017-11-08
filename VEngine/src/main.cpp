#include<iostream>
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include"graphics\window.h"

using namespace core;
using namespace graphics;
int main(int argc, char* argv[])
{
	Window window("GLFW", 800, 600);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	while (!window.closed())
	{
		window.mainLoop();
	}
	std::cin.get();
	return(0);
}