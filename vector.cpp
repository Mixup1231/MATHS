#include "vector.h"

Vec3f cross_product(const Vec3f& a, const Vec3f& b) {
	Vec3f r;
	r.v[0] = a.v[1] * b.v[2] - a.v[2] * b.v[1];
	r.v[1] = a.v[2] * b.v[0] - a.v[0] * b.v[2];
	r.v[2] = a.v[0] * b.v[1] - a.v[1] * b.v[0];
	return r;
}

Vec4f cross_product(const Vec4f& a, const Vec4f& b) {
	Vec4f r;
	r.v[0] = a.v[1] * b.v[2] - a.v[2] * b.v[1];
	r.v[1] = a.v[2] * b.v[0] - a.v[0] * b.v[2];
	r.v[2] = a.v[0] * b.v[1] - a.v[1] * b.v[0];
	r.v[3] = 1.f;
	return r;
}