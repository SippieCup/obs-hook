#include "stdafx.h"
#include "cMemory.h"


HANDLE cMemory::GetProcHandle(const char * ProcessName)
{
	HandleInfo = (safe_HANDLE_INFO)malloc(HandleSize);
	while ((STATUS = cApi->safe_NtQuerySyS(16, HandleInfo, HandleSize, NULL)))
		HandleInfo = (safe_HANDLE_INFO)realloc(HandleInfo, HandleSize *= 2);

	for (HandleLoop = 0; HandleLoop < HandleInfo->HandleCount; HandleLoop++)
	{
		SysHandle = HandleInfo->Handles[HandleLoop];
		if (SysHandle.ProcessId == cApi->safe_getcurrentprocess())
		{
			char NameBlock[MAX_PATH] = { 0 }; //nameblock resetting every 7sec
			cApi->safe_getmodulebasename((HANDLE)SysHandle.Handle, 0, NameBlock, MAX_PATH);
			if (!strcmp(NameBlock, ProcessName))
			{
				free(HandleInfo);
				return (HANDLE(SysHandle.Handle));
			}

		}
	}
	free(HandleInfo);
	return (HANDLE(0));
}

DWORD cMemory::GetModuleHandleEX(const char * ModuleName)
{
	HMODULE hMods[1024] = { 0 }; //hMods resetting every 7sec
	if (cApi->safe_enumprocessmodules(hProc, hMods, 1024, &ModuleCount, LIST_MODULES_32BIT))
	{
		for (ModuleLoop = 0; ModuleLoop < DWORD(ModuleCount / sizeof(HMODULE)); ModuleLoop++)
		{
			char szModName[MAX_PATH] = { 0 };
			cApi->safe_getmodulebasename(hProc, hMods[ModuleLoop], szModName, MAX_PATH);
			if (!strcmp(szModName, ModuleName))
			{
				return (DWORD(hMods[ModuleLoop]));
			}
		}
	}
	return 0;
}

NTSTATUS cMemory::RPM(PVOID lpBaseAddress, PVOID lpBuffer, ULONG nSize, PULONG lpNumberOfBytesRead)
{
	return cApi->safe_read_mem(hProc, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead);
}

