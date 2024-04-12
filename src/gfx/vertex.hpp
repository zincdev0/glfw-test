#ifndef ZINC_GFX_VERTEX_H_
#define ZINC_GFX_VERTEX_H_
#include <zinc\vec2.hpp>
#include <zinc\vec3.hpp>

namespace gfx {
	struct vertex_pos2_col3 {
		vec2<float> pos;
		vec3<float> col;
	};
}

#endif /* ZINC_GFX_VERTEX_H_ */