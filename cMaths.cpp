#include "stdafx.h"
#include "cMaths.h"


void cMaths::SinCos(float radians, float * sine, float * cosine)
{
	*sine = sin(radians);
	*cosine = cos(radians);
}

void cMaths::ClampAngles(cVector& v) {
	if (v.x > 89.0f && v.x <= 180.0f)
		v.x = 89.0f;

	if (v.x > 180.0f)
		v.x = v.x - 360.0f;

	if (v.x < -89.0f)
		v.x = -89.0f;

	v.y = fmodf(v.y + 180, 360) - 180;

	v.z = 0;
}

cVector cMaths::AnglesToPixels(cVector ViewAngles, cVector AimAngles, float sensitivity)
{
	AnglePixels = (ViewAngles - AimAngles);
	this->ClampAngles(AnglePixels);
	AnglePixels.x = ((AnglePixels.x / sensitivity) / -0.022f);
	AnglePixels.y = ((AnglePixels.y / sensitivity) / 0.022f);
	return cVector(AnglePixels.y, AnglePixels.x, 0.0f);
}


void cMaths::VectorNormalize(cVector& vec)
{
	float iradius = 1.f / (sqrtf(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z) + 1.192092896e-07f);
	vec.x *= iradius;
	vec.y *= iradius;
	vec.z *= iradius;
}

void cMaths::VectorAngles(cVector & forward, cVector & angles)
{
	float tmp, yaw, pitch;
	if (forward[1] == 0 && forward[0] == 0)
	{
		yaw = 0;
		if (forward[2] > 0)pitch = 270;
		else pitch = 90;
	}
	else
	{
		yaw = (atan2(forward[1], forward[0]) * 180 / 3.14159265358979323846f);
		if (yaw < 0)yaw += 360;

		tmp = sqrt(forward[0] * forward[0] + forward[1] * forward[1]);
		pitch = (atan2(-forward[2], tmp) * 180 / 3.14159265358979323846f);
		if (pitch < 0)pitch += 360;
	}
	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0;
}

void cMaths::AngleNormalize(cVector & v)
{
	for (AngleCount = 0; AngleCount < 3; AngleCount++)
	{
		if (v[AngleCount] < -180.0f) v[AngleCount] += 360.0f;
		if (v[AngleCount] >  180.0f) v[AngleCount] -= 360.0f;
	}
}

void cMaths::AngleVectors(const cVector & angles, cVector * forward)
{
	float sp, sy, cp, cy;

	this->SinCos(DEG2RAD(angles.x), &sp, &cp);
	this->SinCos(DEG2RAD(angles.y), &sy, &cy);


	forward->x = cp * cy;
	forward->y = cp * sy;
	forward->z = -sp;
}

float cMaths::GetFov(const cVector & viewAngle, const cVector & aimAngle)
{
	this->AngleVectors(viewAngle, &aim);
	this->AngleVectors(aimAngle, &ang);
	return RAD2DEG(acos(aim.Dot(ang) / aim.LengthSqr()));
}

float cMaths::GetPixelFov(cVector Angles)
{
	xfov = Angles.x;
	yfov = Angles.y;
	if (xfov < 0)xfov = (xfov* -1.f);
	if (yfov < 0)yfov = (yfov* -1.f);
	return sqrt(pow(xfov, 1.283f) + pow(yfov, 1.283f));
}
