#include "maths_utility.h"

Vec3f to_direction(const Vec3f& euler) {
	Vec3f r;
	r.v[0] = cosf(euler.v[0]) * cosf(euler.v[1]);
	r.v[1] = sinf(euler.v[0]) * cosf(euler.v[1]);
	r.v[2] = sinf(euler.v[0]);
	return r;
}

Vec3f to_euler(const Vec3f& direction) {
	float r = sqrtf(
		direction.v[0] * direction.v[0] +
		direction.v[1] * direction.v[1] +
		direction.v[2] * direction.v[2]
	);

	Vec3f euler;
	euler.v[0] = acosf(direction.v[2] / r);
	euler.v[1] = atan2f(direction.v[1], direction.v[0]);
	euler.v[2] = 0.f;
	return euler;
}