#pragma once
class cCvars : private cMiscs
{
private:
//=======================================================================//
	void aim_settings();
	void hardware_settings();
	void encrypt_paths();
//=======================================================================//
	 char * buffer = new char[MAX_PATH];
	 char * encrypted_filepath = new char[MAX_PATH];
	 char * encrypted_aimbot = new char[MAX_PATH];
	 char * encrypted_game = new char[MAX_PATH];
//=======================================================================//
public: int Start();
//=======================================================================//
	int aim_key = 0;
	int aim_visible = 0;
	float aim_fov = 0;
//=======================================================================//
	float m_sensitivity = 0;
	int refresh_key = 0;
	int r_width = 0;
	int r_height = 0;
//=======================================================================//
};