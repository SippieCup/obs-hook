#pragma once
class cMiscs
{
private:
	void static safe_obs_str(char *str, UINT64 val);
//==============================================================================//
	char * obschar = new char[MAX_PATH];

//==============================================================================//
public:
	/*Encrypt*/
	void * safe_GetProcAddress(HMODULE hMod, const char * name, UINT64 seed);
	char * safe_GetName(const char * name, UINT64 seed);
	HMODULE safe_GetModuleHandle(const char* dllname, UINT64 seed);
	float safe_GetPrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, FLOAT flDefault, LPCSTR lpFileName);
	int safe_GetPrivateProfileInt(LPCSTR lpAppName, LPCSTR lpKeyName, INT flDefault, LPCSTR lpFileName);
	char* get_file_path();
	char* get_game_settings();
	char* get_aimbot_settings();
	char* get_cheat_offsets();
//==============================================================================//
};

