#ifndef ZINC_RECT_H_
#define ZINC_RECT_H_
#include "math.hpp"
#include "vec2.hpp"

template <typename T> class rect {
public:
	vec2<T> pos, size;

	rect(const vec2<T> &pos_, const vec2<T> &size_):
		pos(pos_),
		size(size_)
	{}

	bool intersects(const rect<T> &other) const {
		return
			this->size.x + other.size.x >= math::abs<T>((other.pos.x * 2 + other.size.x) - (this->pos.x * 2 + this->size.x)) &&
			this->size.y + other.size.y >= math::abs<T>((other.pos.y * 2 + other.size.y) - (this->pos.y * 2 + this->size.y))
		;
	}
};

#endif /* ZINC_RECT_H_ */