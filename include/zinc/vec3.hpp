#ifndef ZINC_VEC3_H_
#define ZINC_VEC3_H_

template <typename T> class vec3 {
public:
	T x, y, z;

	vec3(const T &x_, const T &y_, const T &z_):
		x(x_),
		y(y_),
		z(z_)
	{}

	bool operator == (const vec3 &rhs) const {
		return (this->x == rhs.x) && (this->y == rhs.y) && (this->z == rhs.z);
	}
	vec3 &operator += (const vec3 &rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}
	vec3 &operator -= (const vec3 &rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}
	template <typename U> vec3 &operator *= (const U &rhs) {
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
		return *this;
	}
	template <typename U> vec3 &operator /= (const U &rhs) {
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
		return *this;
	}
	vec3 operator + (const vec3 &rhs) const {
		return vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	}
	vec3 operator - (const vec3 &rhs) const {
		return vec3(this->x - rhs.x, this->y - rhs.y, this->z + rhs.z);
	}
	template <typename U> vec3 operator * (const U &rhs) const {
		return vec3(this->x * rhs, this->y * rhs, this->z * rhs);
	}
	template <typename U> vec3 operator / (const U &rhs) const {
		return vec3(this->x / rhs, this->y / rhs, this->z / rhs);
	}
};

template <typename To, typename From> vec3<To> vec3_cast(const vec3<From> &val) {
	return vec3<To>((To)(val.x), (To)(val.y), (To)(val.z));
}

#endif /* ZINC_VEC3_H_ */