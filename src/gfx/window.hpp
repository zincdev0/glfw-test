#ifndef ZINC_GFX_WINDOW_H_
#define ZINC_GFX_WINDOW_H_
#include "include.hpp"

namespace gfx {
	class window {
	public:
		GLFWwindow *id;

		window(const char *title, const int &width, const int &height, GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr):
			id(glfwCreateWindow(width, height, title, monitor, share))
		{}

		void select() {
			glfwMakeContextCurrent(id);
		}

		bool should_close() {
			return glfwWindowShouldClose(id);
		}

		void set_key_callback(GLFWkeyfun callback) {
			glfwSetKeyCallback(id, callback);
		}

		void set_framebuffer_size_callback(GLFWframebuffersizefun callback) {
			glfwSetFramebufferSizeCallback(id, callback);
		}

		void swap_buffers() {
			glfwSwapBuffers(id);
		}

		void destroy() {
			glfwDestroyWindow(id);
		}

		void poll_events() {
			glfwPollEvents();
		}
	};
}

#endif /* ZINC_GFX_WINDOW_H_ */