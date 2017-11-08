#pragma once
#include<iostream>
#include<GL\glew.h>
#include<GLFW\glfw3.h>

#define internel static
#define local_resist static
#define global_variable static

namespace core {
	namespace graphics {
		class Window
		{
		private:
			const char* title;
			int width;
			int height;
			GLFWwindow* window;
		public:
			Window(const char* title, int width, int height);
			~Window();

			bool closed();
			void mainLoop();
		private:
			bool init();
			void clear();
			void update();
			void render();

		};
	}
}