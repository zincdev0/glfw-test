#ifndef ZINC_GFX_ELEMENT_BUFFER_H_
#define ZINC_GFX_ELEMENT_BUFFER_H_
#include "buffer.hpp"

namespace gfx {
	class element_buffer: public buffer {
	public:
		element_buffer():
			buffer()
		{}

		void bind() {
			_bind(GL_ELEMENT_ARRAY_BUFFER);
		}

		void set_data(const GLsizeiptr &size, const void *data, const GLenum &usage) {
			_set_data(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
		}
	};
}

#endif /* ZINC_GFX_ELEMENT_BUFFER_H_ */