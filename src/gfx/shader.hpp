#ifndef ZINC_GFX_SHADER_H_
#define ZINC_GFX_SHADER_H_
#include "include.hpp"

namespace gfx {
	class shader {
	public:
		enum type: GLenum {
			VERTEX = GL_VERTEX_SHADER,
			FRAGMENT = GL_FRAGMENT_SHADER,
			GEOMETRY = GL_GEOMETRY_SHADER,
		};

		GLuint id;

		shader(const type &type_, const char *source):
			id(glCreateShader(type_))
		{
			glShaderSource(id, 1, &source, nullptr);
			glCompileShader(id);
			GLint status;
			glGetShaderiv(id, GL_COMPILE_STATUS, &status);
			if(status != GL_TRUE) {
				GLint len;
				GLchar info[1024];
				glGetShaderInfoLog(id, 1024, &len, info);
				std::cerr << "Failed to compile shader: " << info << '\n';
			}
		}

		~shader() {
			dispose();
		}

		void dispose() {
			if(id != 0) {
				glDeleteShader(id);
				id = 0;
			}
		}
	};
}

#endif /* ZINC_GFX_SHADER_H_ */