#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

#include <cassert>

template <typename T, size_t Size>
struct Matrix {
	Vector<T, Size> m[Size];
};

template <typename T, size_t Size>
std::ostream& operator<<(std::ostream& out, const Matrix<T, Size>& m) {
	out << '\n';
	for (int i = 0; i < Size; i++) {
		out << m.m[i] << '\n';
	}
	return out;
}

template <typename T, size_t Size>
void matrix_identity(Matrix<T, Size>& m) {
	m = {};
	for (int i = 0; i < Size; i++) {
		m.m[i].v[i] = 1;
	}
}

template <typename T, size_t Size>
Matrix<T, Size> matrix_identity(void) {
	Matrix<T, Size> m;
	matrix_identity(m);
	return m;
}

template <typename T, size_t Size>
Vector<T, Size> matrix_row(const Matrix<T, Size>& m, size_t i) {
	assert(0 <= i && i <= Size - 1);

	return m.m[i];
}

template <typename T, size_t Size>
Vector<T, Size> matrix_column(const Matrix<T, Size>& m, size_t j) {
	assert(0 <= j && j <= Size - 1);

	Vector<T, Size> col;
	for (int i = 0; i < Size; i++) {
		col.v[i] = m.m[i].v[j];
	}
	return col;
}

template <typename T, size_t Size>
Matrix<T, Size> matrix_transpose(const Matrix<T, Size>& m) {
	Matrix<T, Size> r;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			r.m[i].v[j] = m.m[j].v[i];
		}
	}
	return m;
}

template <typename T, size_t Size>
Matrix<T, Size> operator+(const Matrix<T, Size>& a, const Matrix<T, Size>& b) {
	Matrix<T, Size> r;
	for (int i = 0; i < Size; i++) {
		r.m[i] = a.m[i] + b.m[i];
	}
	return r;
}

template <typename T, size_t Size>
Matrix<T, Size> operator-(const Matrix<T, Size>& a, const Matrix<T, Size>& b) {
	Matrix<T, Size> r;
	for (int i = 0; i < Size; i++) {
		r.m[i] = a.m[i] - b.m[i];
	}
	return r;
}

template <typename T, size_t Size>
Matrix<T, Size> operator*(const Matrix<T, Size>& m, float s) {
	Matrix<T, Size> r;
	for (int i = 0; i < Size; i++) {
		r.m[i] = m.m[i] * s;
	}
	return r;
}

template <typename T, size_t Size>
Matrix<T, Size> operator*(const Matrix<T, Size>& a, const Matrix<T, Size>& b) {
	Matrix<T, Size> m;
	for (int c = 0; c < Size; c++) {
		for (int r = 0; r < Size; r++) {
			m.m[c].v[r] = 0;
			for (int k = 0; k < Size; k++) {
				m.m[c].v[r] += a.m[k].v[r] * b.m[c].v[k];
			}
		}
	}
	return m;
}

template <typename T, size_t Size>
Vector<T, Size> operator*(const Matrix<T, Size>& m, const Vector<T, Size>& v) {
	Vector<T, Size> r;
	for (int j = 0; j < Size; j++) {
		r.v[j] = 0;
		for (int i = 0; i < Size; i++) {
			r.v[j] += m.m[i].v[j] * v.v[i];
		}
	}
	return r;
}

template <typename T, size_t Size>
void matrix_translate(Matrix<T, Size>& m, const Vector<T, Size>& v) {
	for (int j = 0; j < Size - 1; j++) {
		m.m[j].v[Size - 1] = v.v[j];
	}
}

template <typename T, size_t Size>
void matrix_scale(Matrix<T, Size>& m, float s) {
	for (int i = 0; i < Size; i++) {
		m.m[i].v[i] = s;
	}
}

using Mat2x2f = Matrix<float, 2>;
using Mat3x3f = Matrix<float, 3>;
using Mat4x4f = Matrix<float, 4>;

void matrix_rotate(Mat4x4f& m, Vec3f axis, float angle);
void matrix_rotate_x(Mat4x4f& m, float angle);
void matrix_rotate_y(Mat4x4f& m, float angle);
void matrix_rotate_z(Mat4x4f& m, float angle);

#endif //MATRIX_H
