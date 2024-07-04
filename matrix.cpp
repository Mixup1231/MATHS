#include "matrix.h"

void matrix_rotate(Mat4x4f& m, Vec3f axis, float angle) {
	auto get_matrix = [](const Vec3f& a, const Vec3f& b) -> Mat4x4f {
		Mat4x4f r;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				r.m[i].v[j] = (i < 3 && j < 3) ? a.v[i] * b.v[j] : 0.f;
			}
		}
		return r;
	};

	float s = sinf(angle);
	float c = cosf(angle);

	if (magnitude(axis) > 1e-4) {
		normalize(axis);
		Mat4x4f T = get_matrix(axis, axis);

		Mat4x4f S = {
			{{           0,  axis.v[2], -axis.v[1], 0},
			 {  -axis.v[2],          0,  axis.v[0], 0},
			 {   axis.v[1], -axis.v[0],          0, 0},
			 {           0,          0,          0,0}}
		};
		S = S * s;

		Mat4x4f C;
		matrix_identity(C);
		C = C - T;
		C = C * c;

		T = T + C;
		T = T + S;

		T.m[3].v[3] = 1.f;
		m = m * T;
	}
}

void matrix_rotate_x(Mat4x4f& m, float angle) {
	float s = sinf(angle);
	float c = cosf(angle);
	Mat4x4f rotation = {
		{{1.f, 0.f, 0.f, 0.f},
		 {0.f,   c,  -s, 0.f},
		 {0.f,   s,   c, 0.f},
		 {0.f, 0.f, 0.f, 1.f}}
	};
	m = m * rotation;
}

void matrix_rotate_y(Mat4x4f& m, float angle) {
	float s = sinf(angle);
	float c = cosf(angle);
	Mat4x4f rotation = {
		{{  c, 0.f,   s, 0.f},
		 {0.f, 1.f, 0.f, 0.f},
		 { -s, 0.f,   c, 0.f},
		 {0.f, 0.f, 0.f, 1.f}}
	};
	m = m * rotation;
}

void matrix_rotate_z(Mat4x4f& m, float angle) {
	float s = sinf(angle);
	float c = cosf(angle);
	Mat4x4f rotation = {
		{{  c,  -s, 0.f, 0.f},
		 {  s,   c, 0.f, 0.f},
		 {0.f, 0.f, 1.f, 0.f},
		 {0.f, 0.f, 0.f, 1.f}}
	};
	m = m * rotation;
}