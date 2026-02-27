#pragma once
//#include "Includes.h"
#include <string>
#include <Windows.h>
#include <string>
#include <memory>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include "../SDK/Libraries/ImGui/imgui.h"

class cUISetup final
{
public:


	void bOverlayMain(HWND hwnd);

	void bOverlayLogin(HWND hwnd);

	void bOverlayHome(HWND hwnd);

	bool bOverlaySetup();

	bool bInitializedStyleSetup = false;


	ImVec2 vWindowSize{ 350, 200 };

	ImVec2 vWindowPos{ 0, 0 };

	int iCurrentAction = 0;


	char cUsername[64];
	char cPassword[64];
	char cEmail[64];
	char cLicense[64];

private:


	


};
inline cUISetup g_UISetup;