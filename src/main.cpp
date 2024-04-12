#include <iostream>
#include <fstream>

#include <zinc\math.hpp>
#include <zinc\vec2.hpp>
#include <zinc\vec3.hpp>
#include <zinc\rect.hpp>

#include "gfx\include.hpp"
#include "gfx\window.hpp"
#include "gfx\shader.hpp"
#include "gfx\program.hpp"
#include "gfx\vertex.hpp"
#include "gfx\buffer.hpp"
#include "gfx\vertex_buffer.hpp"
#include "gfx\element_buffer.hpp"

using vertex = gfx::vertex_pos2_col3;
using index = unsigned int;
static const vertex vertices[4] = {
    { {  0.5f,  0.5f }, { 1.f, 0.f, 0.f }, },
    { {  0.5f, -0.5f }, { 0.f, 1.f, 0.f }, },
    { { -0.5f, -0.5f }, { 0.f, 0.f, 1.f }, },
    { { -0.5f,  0.5f }, { 1.f, 0.f, 1.f }, },
};
static const index indices[6] = {
	0, 1, 3,
	1, 2, 3,
};

static const char *vsh_path = "res\\blit.vsh";
static const char *fsh_path = "res\\blit.fsh";

void key_callback(GLFWwindow *window, int key, __attribute__((unused)) int scancode, int action, __attribute__((unused)) int mods) {
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	
	std::cout << "Pressed key " << std::to_string(key) << '\n';
}

void framebuffer_size_callback(__attribute__((unused)) GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

int main(__attribute__((unused)) const int argc, __attribute__((unused)) const char *argv[]) {
	// GLFW init
	if(!glfwInit()) {
		std::cerr << "GLFW initialization failed\n";
	}
	glfwSetErrorCallback([](int error, const char *description) {
		std::cerr << "Error " << error << ": " << description << '\n';
	});

	// Window settings
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Window init
	gfx::window window("Hello GL", 768, 512);
	if(!window.id) {
		glfwTerminate();
		return 1;
	}
	window.select();
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);

	// Window callbacks
	window.set_key_callback(key_callback);
	window.set_framebuffer_size_callback(framebuffer_size_callback);


	gfx::program prog;
	{
		std::ifstream stream;
		stream.open(vsh_path);
		prog.attach(gfx::shader(gfx::shader::type::VERTEX, std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()).c_str()));
		stream.close();
		stream.open(fsh_path);
		prog.attach(gfx::shader(gfx::shader::type::FRAGMENT, std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()).c_str()));
		stream.close();
		prog.link();
	}

    const gfx::program::loc vpos_location = prog.get_attrib_location("vPos");
    const gfx::program::loc vcol_location = prog.get_attrib_location("vCol");

	gfx::vertex_buffer vb;
	vb.bind();
	vb.set_data(sizeof(vertices), vertices, GL_STATIC_DRAW);

	gfx::element_buffer eb;
	eb.bind();
	eb.set_data(sizeof(indices), indices, GL_STATIC_DRAW);

    GLuint va;
    glGenVertexArrays(1, &va);
    glBindVertexArray(va);
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pos));
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, col));


	glClearColor(.5f, 0.f, .5f, 1.f);

	// Window lifecycle
	while(!window.should_close()) {
		glClear(GL_COLOR_BUFFER_BIT);

		prog.use();
		eb.bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		window.swap_buffers();
		window.poll_events();
	}
	window.destroy();
	prog.dispose();

	// GLFW exit
	glfwTerminate();
	return 0;
}
