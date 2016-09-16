#include "stdafx.h"
#include "cClientPlayer.h"



int cClientPlayer::GetTeam()
{
	return int(intpad[cNetvar->m_iTeam]);
}

int cClientPlayer::GetHealth()
{
	return int((intpad[cNetvar->m_iHealth]));
}


int cClientPlayer::GetLifeState()
{
	return int(intpad[cNetvar->m_iLifeState]);
}

int cClientPlayer::GetShotsFired()
{
	return int(intpad[cNetvar->m_iShotsFired]);
}


int cClientPlayer::GetIndex()
{
	return int(intpad[cNetvar->m_iIndex]);
}
int cClientPlayer::GetbSpotted()
{
	return int(intpad[cNetvar->m_bSpottedByMask]);
}


cVector cClientPlayer::GetVecPunch()
{
	return  cVector(floatpad[cNetvar->m_iVecPunch_x], floatpad[cNetvar->m_iVecPunch_y], 0);
}

bool cClientPlayer::IsValid()
{
	if (this->GetHealth() < 1)
		return false;

	if (this->GetLifeState() != 2)
		return false;

	if (this->GetDormant())
		return false;

	return true;
}

bool cClientPlayer::IsValid(cClientPlayer * Local)
{
	if (!this->IsValid())
		return false;

	if (!Local->IsValid())
		return false;

	if (this->GetTeam() == Local->GetTeam())
		return false;

	if (this->GetIndex() == Local->GetIndex())
		return false;

	return true;
}

bool cClientPlayer::IsVisible(cClientPlayer * Entity)
{
	return bool((Entity->GetbSpotted() & (1 << (this->GetIndex() - 1))) > 0);
}

bool cClientPlayer::CheckProcess()
{
	if (!cMem->hProc)
		return false;

	if (!cMem->client_dll)
		return false;
	return true;
}

int cClientPlayer::GetDormant()
{
	return (int(intpad[cNetvar->m_iDormant]));
}

DWORD cClientPlayer::GetBoneMatrix()
{
	return DWORD(dwpad[cNetvar->dw_BoneMatrix]);
}


cVector cClientPlayer::GetEyePosition()
{
	return cVector(this->GetVecOrigin() + this->GetVecView());
}

cVector cClientPlayer::GetBones(int num)
{
	cMem->RPM(PVOID(this->GetBoneMatrix() + num * 0x30), fixbones, sizeof(mat34x), 0);
	return cVector(fixbones[0][3], fixbones[1][3], fixbones[2][3]);
}

cVector cClientPlayer::GetVecView()
{
	return cVector(0, 0, floatpad[cNetvar->m_vecView_z]);
}

cVector cClientPlayer::GetVecOrigin()
{
	return cVector(floatpad[cNetvar->m_vecOrigin_x], floatpad[cNetvar->m_vecOrigin_y], floatpad[cNetvar->m_vecOrigin_z]);
}

void cClientPlayer::GetPlayer()
{
	if (this->CheckProcess())
	{
		cMem->RPM(PVOID(cMem->client_dll + cNetvar->dw_LocalPlayer), &dwLocal, sizeof(DWORD), 0);
		if (!dwLocal)return;
		cMem->RPM(PVOID(dwLocal), this, sizeof(cClientPlayer), 0);
		if (!this)return;
	}
}

void cClientPlayer::GetPlayer(int EntityCount)
{
	if (this->CheckProcess())
	{
		cMem->RPM(PVOID(cMem->client_dll + cNetvar->dw_EntityList + EntityCount * 0x10), &dwEntity, sizeof(DWORD), 0);
		if (!dwEntity)return;
		cMem->RPM(PVOID(dwEntity), this, sizeof(cClientPlayer), 0);
		if (!this)return;
	}
}