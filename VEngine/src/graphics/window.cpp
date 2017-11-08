#include "window.h"
namespace core {
	namespace graphics {
		Window::Window(const char * title, int width, int height)
		{
			this->title = title;
			this->width = width;
			this->height = height;
			if (!init())
				glfwTerminate();
		}
		Window::~Window()
		{
			glfwTerminate();
		}
		bool Window::init() 
		{
			if (!glfwInit()) {
				std::cout << "GLFW not OK" << std::endl;
				glfwTerminate();
				return false;
			}
			window = glfwCreateWindow(width, height, title, NULL, NULL);
			glfwMakeContextCurrent(window);
			if (glewInit() != GLEW_OK)
			{
				std::cout << "GLEW not OK" << std::endl;
				return false;
			}
			return true;
		}
		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
		void Window::clear()
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}
		void Window::render()
		{
			glBegin(GL_QUADS);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(0.5f, -0.5f); 
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(-0.5f, 0.5f);
			glEnd();
		}
		void Window::mainLoop()
		{
			update();
			clear();
			render();
		}
		bool Window::closed()
		{
			return (glfwWindowShouldClose(window)==1);
		}
	}
}
