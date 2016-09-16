#include "stdafx.h"
#include "cNetvars.h"



int cNetvars::Start()
{
//=======================================================================//
	this->encrypt_paths();
//=======================================================================//
//engpad
	dw_ViewAngles = cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("sh`whfdkmz", 0x8975109873890515), 0, encrypted_filepath);
	dw_ViewAngles_x = (dw_ViewAngles / 0x4);
	dw_ViewAngles_y = ((dw_ViewAngles + 0x4) / 0x4);
//=======================================================================//
//floatpad
	m_vecOrigin = cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("n^tikfu`oho", 0x156c21189798c213), 0, encrypted_filepath);
	m_iVecPunch = cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("o^~loxthda", 0x89715897618c9812), 0, encrypted_filepath);
	m_vecView = cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("l]zbawalp", 0x2187896798127c21), 0, encrypted_filepath);
//=======================================================================//
	m_vecOrigin_x = ((m_vecOrigin - 0x8) / 0x4);
	m_vecOrigin_y = ((m_vecOrigin - 0x4) / 0x4);
	m_vecOrigin_z = (m_vecOrigin / 0x4);
//=======================================================================//
	m_iVecPunch_x = ((m_iVecPunch - 0x8) / 0x4);
	m_iVecPunch_y = ((m_iVecPunch - 0x4) / 0x4);
//=======================================================================//
	m_vecView_z = (m_vecView / 0x4);
//=======================================================================//
//dwpad
	dw_BoneMatrix = ((cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("cfmbo`|peq", 0x7c18929c28127391), 0, encrypted_filepath) - 0x4) / 0x4);
//=======================================================================//
//intpads
	m_iTeam = (cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("o^xffo", 0x8129597891273c12), 0, encrypted_filepath) / 0x4);
	m_bSpottedByMask = (cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("eV`r|h|}geeqkfzc", 0x89768712987c1298), 0, encrypted_filepath) / 0x4);
	m_iHealth = (cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("lS`lfdsj", 0x78978691278798c1), 0, encrypted_filepath) / 0x4);
	m_iIndex = (cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("e^kimiy", 0x5761627621c97218), 0, encrypted_filepath) / 0x4);
	m_iShotsFired = (cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("eVrjc}{aksam", 0x85129412789c2198), 0, encrypted_filepath) / 0x4);
	m_iLifeState = (cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("o]o`nbqumwm", 0x6297083c12789322), 0, encrypted_filepath) / 0x4);
	m_iDormant = (cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("d]ehwdiiw", 0x8908219378957129), 0, encrypted_filepath) / 0x4);
//=======================================================================//
//none
	dw_LocalPlayer = cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("mgoclyofqlp", 0x1578129873902c81), 0, encrypted_filepath);
	dw_EnginePointer = cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("goknmmynki|fp", 0x8912387219837c12), 0, encrypted_filepath);
	dw_EntityList = cMisc->safe_GetPrivateProfileInt(encrypted_offsets, cMisc->safe_GetName("dhqkxznhwq", 0x48974654123c2561), 0, encrypted_filepath);
	return 0;
//=======================================================================//
}

void cNetvars::encrypt_paths()
{

	buffer = cMisc->get_file_path();
	strcpy(encrypted_filepath, buffer);

	buffer = cMisc->get_cheat_offsets();
	strcpy(encrypted_offsets, buffer);
}