#include "stdafx.h"
#include "cApis.h"



int cApis::LoadModules()
{	
	while (safe_User32 == nullptr)safe_User32 = cMisc->safe_GetModuleHandle("R[@_23", 0xc7641232111d587);
	while (safe_Kernel32 == nullptr)safe_Kernel32 = cMisc->safe_GetModuleHandle("LMWCDI61", 0xc864323551d587);
	while (safe_Ntdll == nullptr)safe_Ntdll = cMisc->safe_GetModuleHandle("i|aam/goo", 0xc7246333311d587);
	return 0;
}

int cApis::LoadAddresses()
{
	/*kernel32*/
	while (this->safe_getcurrentprocess == nullptr)this->safe_getcurrentprocess = (safe_getcurrentprocessA(cMisc->safe_GetProcAddress(safe_Kernel32, "ObwAtzuih|Wqnamt{Ng", 0x78213786c7812378)));
	while (this->safe_terminatethread == nullptr)this->safe_terminatethread = (safe_terminatethreadA(cMisc->safe_GetProcAddress(safe_Kernel32, "VhpllmhtgUnuf`f", 0x82137612093512d2)));
	while (this->safe_enumprocessmodules == nullptr)this->safe_enumprocessmodules = (safe_enumprocessmodulesA(cMisc->safe_GetProcAddress(safe_Kernel32, "I;3ImwlYzlddq{Dcf}mipGy", 0xc98217389123c182)));
	while (this->safe_getmodulebasename == nullptr)this->safe_getmodulebasename = (safe_getmodulebasenameA(cMisc->safe_GetProcAddress(safe_Kernel32, "N05NguAf`pkmKbqdKbjlC", 0x123987549c129735)));
	while (this->safe_DisableThreadCalls == nullptr)this->safe_DisableThreadCalls = (safe__DisableThreadCalls(cMisc->safe_GetProcAddress(safe_Kernel32, "F`{flogSi{mfhMngphz~Mbnkr", 0x571C7891723E7892)));
	while (this->safe_get_string == nullptr)this->safe_get_string = (safe_get_stringA(cMisc->safe_GetProcAddress(safe_Kernel32, "Kg}Xukwj~lQumgaiiQ}znlfJ", 0x5812719AB127892C)));
	while (this->safe_closehandle == nullptr)this->safe_closehandle = (safe_closehandleA(cMisc->safe_GetProcAddress(safe_Kernel32, "BedzmKfleem", 0x8137589127389B91)));
	while (this->safe_createthread == nullptr)this->safe_createthread = (safe_createthreadA(cMisc->safe_GetProcAddress(safe_Kernel32, "Jzbb}mViulog", 0x8d123e9712893789)));
	while (this->safe_sleep == nullptr)this->safe_sleep = (safe_sleepA(cMisc->safe_GetProcAddress(safe_Kernel32, "Zddbx", 0x791239EB12387189)));
	while (this->safe_get_int == nullptr)this->safe_get_int = (safe_get_intA(cMisc->safe_GetProcAddress(safe_Kernel32, "Nd}Rpjwc|eVrldhelHgvC", 0x9123060821322919)));
	/*ntdll*/
	while (this->safe_NtQuerySyS == nullptr)this->safe_NtQuerySyS = (safe__NtQuerySyS(cMisc->safe_GetProcAddress(safe_Ntdll, "Ov]vgsu[quwdkJoanpabvhcf", 0x713613688c123c21)));
	while (this->safe_read_mem == nullptr)this->safe_read_mem = (safe_read_memA(cMisc->safe_GetProcAddress(safe_Ntdll, "MvPdglUk|u}`oOdelp{", 0x8123181e23861223)));

	/*user32*/
	while (this->safe_getkey == nullptr)this->safe_getkey = (safe_getkeyA(cMisc->safe_GetProcAddress(safe_User32, "FdwIqxnjCkqPvhub", 0x719238E890128311)));
	while (this->safe_setpcursorpos == nullptr)this->safe_setpcursorpos = (safe_setcursorA(cMisc->safe_GetProcAddress(safe_User32, "Re}XfxpihhjFzqqnsPf{", 0x123F569b031E8901)));
	return 0;
}

int cApis::Start(HMODULE hMod)
{
	this->LoadModules();
	this->LoadAddresses();
	this->safe_DisableThreadCalls(hMod);
	return 0;
}
