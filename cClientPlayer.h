#pragma once
class cClientPlayer
{
private:
//====================================================================//
	int intpad[0x1];
	DWORD dwpad[0x1];
	float floatpad[0xAA54 / 0x2];
//====================================================================//
	DWORD dwLocal = 0;
	DWORD dwEntity = 0;
	mat34x fixbones;
//====================================================================//
	DWORD GetBoneMatrix();
public: 
	cVector GetVecPunch();
	cVector GetEyePosition();
	cVector GetBones(int num);
	cVector GetVecView();
	cVector GetVecOrigin();
//====================================================================//
	int GetTeam();
	int GetHealth();
	int GetLifeState();
	int GetShotsFired();
	int GetIndex();
	int GetDormant();
	int GetbSpotted();
	bool IsValid();
	bool IsValid(cClientPlayer * Local);
	bool IsVisible(cClientPlayer * Entity);
	bool CheckProcess();
//====================================================================//
	void GetPlayer();
	void GetPlayer(int EntityCount);
//====================================================================//
};

