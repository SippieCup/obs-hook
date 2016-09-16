#pragma once
class cNetvars
{
private:
//=============================================================//
	void encrypt_paths();
//=============================================================//
	char * buffer = new char[MAX_PATH];
	char * encrypted_filepath = new char[MAX_PATH];
	char * encrypted_offsets = new char[MAX_PATH];
//=============================================================//
	int m_iVecPunch = 0;
	int m_vecView = 0;
	int m_vecOrigin = 0;
//=============================================================//
public:	int Start();
//=============================================================//
	int dw_LocalPlayer = 0;
	int dw_EntityList = 0;
	int dw_EnginePointer = 0;
	int dw_ViewAngles = 0;
	int dw_ViewAngles_x = 0;
	int dw_ViewAngles_y = 0;
//=============================================================//
//dwpads
	int dw_BoneMatrix = 0;
//=============================================================//
//intpads
	int m_iTeam = 0;
	int m_iHealth = 0;
	int m_iIndex = 0;
	int m_iShotsFired = 0;
	int m_iLifeState = 0;
	int m_iDormant = 0;
	int m_bSpottedByMask = 0;
//=============================================================//
//floatpads
	int m_vecOrigin_x = 0;
	int m_vecOrigin_y = 0;
	int m_vecOrigin_z = 0;
//=============================================================//
	int m_iVecPunch_x = 0;
	int m_iVecPunch_y = 0;
//=============================================================//
	int m_vecView_z = 0;
//=============================================================//
};

