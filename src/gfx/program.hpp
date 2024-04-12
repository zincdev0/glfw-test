#ifndef ZINC_GFX_PROGRAM_H_
#define ZINC_GFX_PROGRAM_H_
#include "include.hpp"
#include "shader.hpp"

namespace gfx {
	class program {
	public:
		using loc = GLint;

		GLuint id;

		program():
			id(glCreateProgram())
		{}

		~program() {
			dispose();
		}

		void attach(gfx::shader shd) {
			glAttachShader(id, shd.id);
		}

		void link() {
			glLinkProgram(id);
			GLint status;
			glGetProgramiv(id, GL_LINK_STATUS, &status);
			if(status != GL_TRUE) {
				GLint len;
				GLchar info[1024];
				glGetProgramInfoLog(id, 1024, &len, info);
				std::cerr << "Failed to link program: " << info << '\n';
			}
		}

		loc get_attrib_location(const char *name) {
			return glGetAttribLocation(id, name);
		}

		loc get_uniform_location(const char *name) {
			return glGetUniformLocation(id, name);
		}

		void use() {
			glUseProgram(id);
		}

		void dispose() {
			if(id != 0) {
				glDeleteProgram(id);
				id = 0;
			}
		}
	};
}

#endif /* ZINC_GFX_PROGRAM_H_ */