#include "stdafx.h"
#include "cEngine.h"


int cEngine::Start(HMODULE hMod)
{
	cApi->Start(hMod);
	cNetvar->Start();
	cVars->Start();
	cAim->Start();
	return 0;
}

int Engine_Start(HMODULE hMod)
{
	cEng->Start(hMod);
	return 0;
}
