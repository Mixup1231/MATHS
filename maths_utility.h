#ifndef MATHS_UTILITY_H
#define MATHS_UTILITY_H

#include "vector.h"

#define PI 3.1415926535898
#define to_radians(x) ((x * PI) / 180)
#define to_degrees(x) ((x * 180) / PI)

Vec3f to_direction(const Vec3f& euler);
Vec3f to_euler(const Vec3f& direction);

#endif //MATHS_UTILITY_H