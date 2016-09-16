#pragma once
class cVector
{
public:
	cVector(void)
	{
		x = y = z = 0.0f;
	}

	cVector(float X, float Y, float Z)
	{
		x = X; y = Y; z = Z;
	}

	cVector(float* v)
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	cVector(const float* v)
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	cVector(const cVector& v)
	{
		x = v.x; y = v.y; z = v.z;
	}


	cVector& operator=(const cVector& v)
	{
		x = v.x; y = v.y; z = v.z; return *this;
	}


	float& operator[](int i)
	{
		return ((float*)this)[i];
	}

	float operator[](int i) const
	{
		return ((float*)this)[i];
	}

	cVector& operator+=(const cVector& v)
	{
		x += v.x; y += v.y; z += v.z; return *this;
	}

	cVector& operator-=(const cVector& v)
	{
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	cVector& operator*=(const cVector& v)
	{
		x *= v.x; y *= v.y; z *= v.z; return *this;
	}

	cVector& operator/=(const cVector& v)
	{
		x /= v.x; y /= v.y; z /= v.z; return *this;
	}

	cVector& operator+=(float v)
	{
		x += v; y += v; z += v; return *this;
	}

	cVector& operator-=(float v)
	{
		x -= v; y -= v; z -= v; return *this;
	}

	cVector& operator*=(float v)
	{
		x *= v; y *= v; z *= v; return *this;
	}

	cVector& operator/=(float v)
	{
		x /= v; y /= v; z /= v; return *this;
	}

	cVector operator+(const cVector& v) const
	{
		return cVector(x + v.x, y + v.y, z + v.z);
	}

	cVector operator-(const cVector& v) const
	{
		return cVector(x - v.x, y - v.y, z - v.z);
	}

	cVector operator*(const cVector& v) const
	{
		return cVector(x * v.x, y * v.y, z * v.z);
	}

	cVector operator/(const cVector& v) const
	{
		return cVector(x / v.x, y / v.y, z / v.z);
	}

	cVector operator+(float v) const
	{
		return cVector(x + v, y + v, z + v);
	}

	cVector operator-(float v) const
	{
		return cVector(x - v, y - v, z - v);
	}

	cVector operator*(float v) const
	{
		return cVector(x * v, y * v, z * v);
	}

	cVector operator/(float v) const
	{
		return cVector(x / v, y / v, z / v);
	}

	void Set(float X = 0.0f, float Y = 0.0f, float Z = 0.0f)
	{
		x = X; y = Y; z = Z;
	}

	float Length(void) const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	float LengthSqr(void) const
	{
		return (x * x + y * y + z * z);
	}

	float Length2d(void) const
	{
		return sqrtf(x * x + y * y);
	}

	float Length2dSqr(void) const
	{
		return (x * x + y * y);
	}

	float DistTo(const cVector& v) const
	{
		return (*this - v).Length();
	}

	float DistToSqr(const cVector& v) const
	{
		return (*this - v).LengthSqr();
	}

	float Dot(const cVector& v) const
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	cVector Cross(const cVector& v) const
	{
		return cVector(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	bool IsZero(void) const
	{
		return (x > -0.01f && x < 0.01f &&
			y > -0.01f && y < 0.01f &&
			z > -0.01f && z < 0.01f);
	}

public:
	float x, y, z;
};
typedef float mat34x[3][4];