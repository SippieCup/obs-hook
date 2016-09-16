#pragma once
typedef struct
{
	ULONG ProcessId;
	BYTE ObjectTypeNumber;
	BYTE Flags;
	USHORT Handle;
	PVOID Object;
	DWORD GrantedAccess;
} safe_SYS_HANDLE;

typedef struct
{
	ULONG HandleCount;
	safe_SYS_HANDLE Handles[1];
}*safe_HANDLE_INFO;

class cMemory
{
private:
//=========================================================================//
//HANDLES
	NTSTATUS STATUS = 0;
	DWORD HandleLoop = 0;
	DWORD HandleSize = 0x10000;
	safe_HANDLE_INFO HandleInfo = nullptr;
	safe_SYS_HANDLE SysHandle;
//=========================================================================//
//MODULES
	DWORD ModuleCount = 0;
	DWORD ModuleLoop = 0;
//=========================================================================//
public:
//=========================================================================//
	HANDLE GetProcHandle(const char * ProcessName);
	DWORD GetModuleHandleEX(const char * ModuleName);
//=========================================================================//
//Process
	HANDLE hProc = nullptr;
	DWORD client_dll = 0;
	DWORD engine_dll = 0;
	NTSTATUS RPM(PVOID lpBaseAddress, PVOID lpBuffer, ULONG nSize, PULONG lpNumberOfBytesRead);
//==============================================================================//
};

