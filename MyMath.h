#include <math/Vector3.h>
#include <math/Matrix4x4.h>

using namespace KamataEngine;

class MyMath {
public:
	Vector3 Normalize(const Vector3& v);

	Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

};