#ifndef ZINC_MATH_H_
#define ZINC_MATH_H_

namespace math {
	// Est. ~11 cycles
	template <typename T> constexpr T min(const T &a, const T &b) {
		return a * (a < b) + b * (a > b);
	}

	// Est. ~11 cycles
	template <typename T> constexpr T max(const T &a, const T &b) {
		return a * (a > b) + b * (a < b);
	}

	// Est. ~22 cycles
	template <typename T> constexpr T clamp(const T &a, const T &min, const T &max) {
		return math::min<T>(math::max<T>(a, min), max);
	}

	template <typename T> consteval unsigned long long _abs_helper_getoffset() {
		return sizeof(T) * 8 - 1;
	}

	// Est. ~6 cycles
	template <typename T> requires std::is_signed<T>::value constexpr T abs(const T &a) {
		return ((a >> _abs_helper_getoffset<T>()) | 1) * a;
	}

	template <typename T> requires std::is_unsigned<T>::value constexpr T abs(const T &a) {
		return a;
	}
}

#endif /* ZINC_MATH_H_ */