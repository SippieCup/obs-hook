#include "stdafx.h"
#include "cAimbot.h"

int cAimbot::Start()
{
	hCheckProcesses = cApi->safe_createthread(0, 0, (PTHREAD_START_ROUTINE(tCheckProcesses)), 0, 0, 0);
	return 0;
}

void cAimbot::SlowAimbot()
{
	
	if (cApi->safe_getkey(cVars->aim_key) || cApi->safe_getkey(0x01))
	{
		max_fov = 180.f;
		ViewAngles = gEngine->GetViewAngles();
		for (BoneCount = 1; BoneCount < 7; BoneCount++)
		{
			BoneID = Entity->GetBones(BoneCount);
			BoneID = (BoneID - Local->GetEyePosition());
			cMath->VectorNormalize(BoneID);
			cMath->VectorAngles(BoneID, AimAngle);

			if (Local->GetShotsFired() > 1)
				AimAngle -= Local->GetVecPunch() * 2.0f;

			cMath->ClampAngles(AimAngle);
			min_max_fov = cMath->GetFov(ViewAngles, AimAngle);
			if (max_fov > min_max_fov)
			{
				max_fov = min_max_fov;
				bAimAngle = AimAngle;
			}
		}		

		if (cVars->aim_visible && !Local->IsVisible(Entity))
			return;

		AimAngle2D = cMath->AnglesToPixels(ViewAngles, bAimAngle, cVars->m_sensitivity);
		if (cMath->GetPixelFov(AimAngle2D) < cVars->aim_fov)
		{
			cApi->safe_setpcursorpos((int(cVars->r_width + AimAngle2D.x)), (int(cVars->r_height + AimAngle2D.y)));
		}
		
	}
}

void cAimbot::Aimbot()
{
	Local->GetPlayer();
	gEngine->GetEngine();
	for (EntityCount = 0; EntityCount < 32; EntityCount++)
	{
		Entity->GetPlayer(EntityCount);
		if (Entity->IsValid(Local))
		{
			SlowAimbot();
		}
	}
	
}



void cAimbot::tAimbot()
{
	while (1)
	{
		cApi->safe_sleep(1);
		cAim->Aimbot();
	}
}

void cAimbot::tCheckProcesses()
{
	while (1)
	{
		cApi->safe_sleep(7000);
		cAim->CheckProcesses();
	}
}

void cAimbot::CheckProcesses()
{
	cMem->hProc = cMem->GetProcHandle(cMisc->safe_GetName("mpom!kyb", 0xC234758971EF283E));
	if (cMem->hProc)
	{
		if (!hAimbot)
		{
			hAimbot = cApi->safe_createthread(0, 0, (PTHREAD_START_ROUTINE(tAimbot)), 0, 0, 0);
		}
		if (!cMem->client_dll)
		{
			cMem->client_dll = cMem->GetModuleHandleEX(cMisc->safe_GetName("dddbmv/mdd", 0x8518EF8891237D87));
		}
		if (!cMem->engine_dll)
		{
			cMem->engine_dll = cMem->GetModuleHandleEX(cMisc->safe_GetName("hlfn`m-fdm", 0x61786918238E712d));
		}
	}
	else
	{
		cMem->hProc = nullptr;
		if (hAimbot)
		{
			cApi->safe_terminatethread(hAimbot, 0);
			cApi->safe_closehandle(hAimbot);
			hAimbot = nullptr;
		}
		if (cMem->client_dll)
		{
			cMem->client_dll = 0;
		}
		if (cMem->engine_dll)
		{
			cMem->engine_dll = 0;
		}
	}
}
