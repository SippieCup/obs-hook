#include "stdafx.h"
#include "cMiscs.h"

void * cMiscs::safe_GetProcAddress(HMODULE hMod, const char * name, UINT64 seed)
{
	strcpy(obschar, name);
	safe_obs_str(obschar, seed);
	return GetProcAddress(hMod, obschar);
}
char * cMiscs::safe_GetName(const char * name, UINT64 seed)
{
	strcpy(obschar, name);
	safe_obs_str(obschar, seed);
	return obschar;
}
void cMiscs::safe_obs_str(char *str, UINT64 val)
{
	UINT8 *dec_val = (UINT8*)&val;
	int i = 0;

	while (*str != 0) {
		int pos = i / 2;
		bool bottom = (i % 2) == 0;
		UINT8 *ch = (UINT8*)str;
		UINT8 xor = bottom ?
			(dec_val[pos] & 0xF) :
			(dec_val[pos]) >> 4 & 0xF;

		*ch ^= xor;

		if (++i == sizeof(UINT64) * 2)
			i = 0;

		str++;
	}
}

HMODULE cMiscs::safe_GetModuleHandle(const char* dllname, UINT64 seed)
{
	strcpy(obschar, dllname);
	safe_obs_str(obschar, seed);
	return GetModuleHandleA(obschar);
}

float cMiscs::safe_GetPrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, FLOAT flDefault, LPCSTR lpFileName)
{
	cApi->safe_get_string(lpAppName, lpKeyName, std::to_string(flDefault).c_str(), obschar, MAX_PATH, lpFileName);
	return (float(atof(obschar)));
}
int cMiscs::safe_GetPrivateProfileInt(LPCSTR lpAppName, LPCSTR lpKeyName, INT flDefault, LPCSTR lpFileName)
{
	return cApi->safe_get_int(lpAppName, lpKeyName, flDefault, lpFileName);
}

char* cMiscs::get_file_path()
{
	return this->safe_GetName("-(u2;%||oslbfr)xge", 0x871239178c891273);
}

char* cMiscs::get_aimbot_settings()
{
	return this->safe_GetName("`kncms", 0x74038231c8721321);
}

char* cMiscs::get_game_settings()
{
	return this->safe_GetName("b`ol", 0x87941c9812739215);
}

char* cMiscs::get_cheat_offsets()
{
	return this->safe_GetName("nndvb|p", 0x612908c213875281);
}