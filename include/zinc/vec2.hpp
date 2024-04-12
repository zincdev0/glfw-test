#ifndef ZINC_VEC2_H_
#define ZINC_VEC2_H_

template <typename T> class vec2 {
public:
	T x, y;

	vec2(const T &x_, const T &y_):
		x(x_),
		y(y_)
	{}

	bool operator == (const vec2 &rhs) const {
		return (this->x == rhs.x) && (this->y == rhs.y);
	}
	vec2 &operator += (const vec2 &rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
	vec2 &operator -= (const vec2 &rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}
	template <typename U> vec2 &operator *= (const U &rhs) {
		this->x *= rhs;
		this->y *= rhs;
		return *this;
	}
	template <typename U> vec2 &operator /= (const U &rhs) {
		this->x /= rhs;
		this->y /= rhs;
		return *this;
	}
	vec2 operator + (const vec2 &rhs) const {
		return vec2(this->x + rhs.x, this->y + rhs.y);
	}
	vec2 operator - (const vec2 &rhs) const {
		return vec2(this->x - rhs.x, this->y - rhs.y);
	}
	template <typename U> vec2 operator * (const U &rhs) const {
		return vec2(this->x * rhs, this->y * rhs);
	}
	template <typename U> vec2 operator / (const U &rhs) const {
		return vec2(this->x / rhs, this->y / rhs);
	}
};

template <typename To, typename From> vec2<To> vec2_cast(const vec2<From> &val) {
	return vec2<To>((To)(val.x), (To)(val.y));
}

#endif /* ZINC_VEC2_H_ */