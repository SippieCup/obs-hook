// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
extern int Engine_Start(HMODULE hMod);

BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwrea, LPVOID lpres)
{
	switch (dwrea)
	{
	case DLL_PROCESS_ATTACH:
		Engine_Start(hMod);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

