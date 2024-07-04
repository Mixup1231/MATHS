#ifndef VECTOR_H
#define VECTOR_H

#include "math.h"

#include <array>
#include <iostream>

template <typename T, size_t Size>
struct Vector {
	std::array<T, Size> v;
};

template <typename T, size_t Size>
std::ostream& operator<<(std::ostream& out, const Vector<T, Size>& v) {
	out << '{';
	for (int i = 0; i < Size - 1; i++) {
		out << v.v[i] << ", ";
	}
	out << v.v[Size - 1] << '}';
	return out;
}

template <typename T, size_t Size>
Vector<T, Size> operator+(const Vector<T, Size>& a, const Vector<T, Size>& b) {
	Vector<T, Size> r;
	for (int i = 0; i < Size; i++) {
		r.v[i] = a.v[i] + b.v[i];
	}
	return r;
}

template <typename T, size_t Size>
Vector<T, Size> operator-(const Vector<T, Size>& a, const Vector<T, Size>& b) {
	Vector<T, Size> r;
	for (int i = 0; i < Size; i++) {
		r.v[i] = a.v[i] - b.v[i];
	}
	return r;
}

template <typename T, size_t Size>
Vector<T, Size> operator*(const Vector<T, Size>& v, float s) {
	Vector<T, Size> r;
	for (int i = 0; i < Size; i++) {
		r.v[i] = v.v[i] * s;
	}
	return r;
}

template <typename T, size_t Size>
float dot_product(const Vector<T, Size>& a, const Vector<T, Size>& b) {
	float p = 0;
	for (int i = 0; i < Size; i++) {
		p += a.v[i] * b.v[i];
	}
	return p;
}

template <typename T, size_t Size>
float magnitude(const Vector<T, Size>& v) {
	return sqrtf(dot_product(v, v));
}

template <typename T, size_t Size>
void normalize_in_place(Vector<T, Size>& v) {
	float k = 1.f / magnitude(v);
	v = v * k;
}

template <typename T, size_t Size>
Vector<T, Size> normalize(const Vector<T, Size>& v) {
	Vector<T, Size> r;
	float k = 1.f / magnitude(v);
	r = v * k;
	return r;
}

template <typename T, size_t Size>
Vector<T, Size> reflect(const Vector<T, Size>& v, const Vector<T, Size>& n) {
	Vector<T, Size> r = v;
	reflect(r, n);
	return r;
}

template <typename T, size_t Size>
void reflect(Vector<T, Size>& v, const Vector<T, Size>& n) {
	float p = 2.f * dot_product(v, n);
	for (int i = 0; i < Size; i++) {
		v[i] = v[i] - p * n[i];
	}
}

using Vec2f = Vector<float, 2>;
using Vec3f = Vector<float, 3>;
using Vec4f = Vector<float, 4>;

Vec3f cross_product(const Vec3f& a, const Vec3f& b);
Vec4f cross_product(const Vec4f& a, const Vec4f& b);

#endif //VECTOR_H