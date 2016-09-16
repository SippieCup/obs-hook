#pragma once
class cAimbot
{
//==============================================================================//
/*Variables*/
	INT mSpeed = 0;
	INT EntityCount = 0;
	INT BoneCount = 0;
	FLOAT max_fov = 0.f;
	FLOAT min_max_fov = 0.f;
//==============================================================================//
/*Classes*/
	cClientPlayer * Local = new cClientPlayer();
	cClientPlayer * Entity = new cClientPlayer();
	cClientEngine * gEngine = new cClientEngine();
//==============================================================================//
/*Vectors*/
	cVector ViewAngles;
	cVector BoneID;
	cVector AimAngle;
	cVector bAimAngle;
	cVector AimAngle2D;
//==============================================================================//
/*ThreadHandles*/
	HANDLE hAimbot = nullptr;
	HANDLE hCheckProcesses = nullptr; 
//==============================================================================//
/*Threads*/
	void static tAimbot();
	void static tCheckProcesses();
//==============================================================================//
/*CheckProcesses*/
	void CheckProcesses();
//==============================================================================//
/*Aimbot*/
	void SlowAimbot();
	void Aimbot();
//==============================================================================//
/*Start Aimbot*/
	public: int Start();
//==============================================================================//
};

