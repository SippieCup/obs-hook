#pragma once
class cClientEngine
{
private:
	float pad[0x4D0C / 0x2];
	DWORD dwgEngine = 0;
public:
	bool CheckProcess();
	void GetEngine();
	cVector GetViewAngles();
};

