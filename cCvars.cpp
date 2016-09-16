#include "stdafx.h"
#include "cCvars.h"


void cCvars::encrypt_paths()
{
	buffer = cMisc->get_file_path();
	strcpy(encrypted_filepath, buffer);


	buffer = cMisc->get_aimbot_settings();
	strcpy(encrypted_aimbot, buffer);


	buffer = cMisc->get_game_settings();
	strcpy(encrypted_game, buffer);
}

void cCvars::aim_settings()
{
	aim_key = cMisc->safe_GetPrivateProfileInt(encrypted_aimbot, cMisc->safe_GetName("d`lWbax", 0x5839240891498195), 0, encrypted_filepath);
	aim_fov = cMisc->safe_GetPrivateProfileFloat(encrypted_aimbot, cMisc->safe_GetName("ihnXdf~", 0x9823971cd8927318), 0.f, encrypted_filepath);
	aim_visible = cMisc->safe_GetPrivateProfileInt(encrypted_aimbot, cMisc->safe_GetName("ihoWzovnkdf", 0x89721389756c8218), 0, encrypted_filepath);
}

void cCvars::hardware_settings()
{
	r_width = (cMisc->safe_GetPrivateProfileInt(encrypted_game, cMisc->safe_GetName("tjevd", 0x56156142156c2133), 0, encrypted_filepath) / 2);
	r_height = (cMisc->safe_GetPrivateProfileInt(encrypted_game, cMisc->safe_GetName("kfhkdr", 0x66156542156cc133), 0, encrypted_filepath) / 2);
	m_sensitivity = cMisc->safe_GetPrivateProfileFloat(encrypted_game, cMisc->safe_GetName("e]rhmta}huk}q", 0x967892319873d128), 0.f, encrypted_filepath);
}

int cCvars::Start()
{
	this->encrypt_paths();
	this->aim_settings();
	this->hardware_settings();
	return 0;
}

