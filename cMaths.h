#pragma once
class cMaths
{
private:
//===============================================================================//
	#define DEG2RAD( x  )  ( (float)(x) * (float)(3.14159265358979323846f / 180.f) )
	#define RAD2DEG( x  )  ( (float)(x) * (float)(180.f / 3.14159265358979323846f) )
//===============================================================================//
	int AngleCount = 0;
	float cDistance = 0.f;
	float xfov = 0.f;
	float yfov = 0.f;
	cVector AnglePixels;
	cVector ang, aim;
public:
//===============================================================================//
	void SinCos(float x, float * s, float * c);
	void ClampAngles(cVector& v);
	void VectorNormalize(cVector& vec);
	void VectorAngles(cVector & forward, cVector & angles);
	void AngleNormalize(cVector & v);
	void AngleVectors(const cVector & angles, cVector * forward);
	float GetFov(const cVector& viewAngle, const cVector& aimAngle);
	float GetPixelFov(cVector Angles);
//===============================================================================//
	cVector AnglesToPixels(cVector ViewAngles, cVector AimAngles, float sensitivity);
//===============================================================================//
};

