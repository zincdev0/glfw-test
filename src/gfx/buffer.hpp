#ifndef ZINC_GFX_BUFFER_H_
#define ZINC_GFX_BUFFER_H_
#include "include.hpp"

namespace gfx {
	class buffer {
	public:
		GLuint id;

		buffer() {
			glGenBuffers(1, &id);
		}

	protected:
		void _bind(const GLenum &target) {
			glBindBuffer(target, id);
		}

		void _set_data(const GLenum &target, const GLsizeiptr &size, const void *data, const GLenum &usage) {
			glBufferData(target, size, data, usage);
		}
	};
}

#endif /* ZINC_GFX_BUFFER_H_ */