#include "UI.h"
#include "../SDK/KeyAuth-API/API.h"

bool bShowLicense = false;
bool bShowPassword = false;

int Tab = 0;

void cUISetup::bOverlayMain(HWND hwnd)
{
    

	ImGui::SetNextWindowPos(ImVec2(vWindowPos.x, vWindowPos.y), ImGuiCond_Once);
	ImGui::SetNextWindowSize(ImVec2(vWindowSize.x, vWindowSize.y));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowTitleAlign, ImVec2(0.5f, 0.5f));
    ImGui::Begin((("Login Interface")), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);
    {
      

        switch (Tab)
        {
            case 0:
                bOverlayLogin(hwnd);
				break;
			case 1:
				bOverlayHome(hwnd);
                break;
            default:
				break;
        }

    }
    ImGui::PopStyleVar();
    ImGui::End();
}

void cUISetup::bOverlayLogin(HWND hwnd)
{
    ImGui::BeginChild("##LoginChild", ImVec2(vWindowSize.x, vWindowSize.y), false, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);
    {
        int PasswordFlags = bShowPassword ? ImGuiInputTextFlags_None : ImGuiInputTextFlags_Password;
        int LicenseFlags = bShowLicense ? ImGuiInputTextFlags_None : ImGuiInputTextFlags_Password;

        ImGui::Text("Username:");



        ImGui::InputText("##UsernameInput", cUsername, sizeof(cUsername));

        ImGui::Text("Password:");



        ImGui::InputText("##PasswordInput", cPassword, sizeof(cPassword), PasswordFlags); ImGui::SameLine(); ImGui::Checkbox("Show##", &bShowPassword);

        ImGui::Text("License:");


        ImGui::InputText("##LicenseInput", cLicense, sizeof(cLicense), LicenseFlags); ImGui::SameLine(); ImGui::Checkbox("Show", &bShowLicense);

        if (ImGui::Button("Action"))
        {
            switch (iCurrentAction)
            {
            case 0:
                cAPI.bStatusKeyAuth(cAPI.bLoginKeyAuth(cUsername, cPassword));
                break;
            case 1:
                cAPI.bStatusKeyAuth(cAPI.bRegisterKeyAuth(cUsername, cPassword, cLicense, cEmail));
                break;
            case 2:
                cAPI.bStatusKeyAuth(cAPI.bUpgradeKeyAuth(cUsername, cLicense));
                break;
            case 3:
                cAPI.bStatusKeyAuth(cAPI.bLicenseKeyOnlyKeyAuth(cLicense));
                break;
            default:
                break;
            }

            MessageBoxA(hwnd, cAPI.strDataKeyAuth.c_str(), cAPI.strDataKeyAuth.c_str(), NULL);

            if(cAPI.bKeepStatusLogged)
				Tab = 1;
            else
				Tab = 0;
        }
        ImGui::SameLine();
        ImGui::Combo("##Actionabc", &iCurrentAction, "Login \0Register \0Upgrade \0License key only \0");
    }
    ImGui::EndChild();
}

void cUISetup::bOverlayHome(HWND hwnd)
{
    ImGui::BeginChild("##LoginChild", ImVec2(vWindowSize.x, vWindowSize.y), false, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);
    {
		cAPI.bInfosKeyAuth(cAPI.bKeepStatusLogged);

		ImGui::Text("Username: %s", cAPI.strUsername.c_str());
		ImGui::Text("HWID: %s", cAPI.strHWID.c_str());
		ImGui::Text("IP: %s", cAPI.strIP.c_str());
		ImGui::Text("Create date: %s", cAPI.strCreateDate.c_str());
		ImGui::Text("Last login: %s", cAPI.strLastLogin.c_str());

    }
    ImGui::EndChild();
}

bool cUISetup::bOverlaySetup()
{
    cAPI.bInitializeKeyAuthAPI();

    if(!bInitializedStyleSetup)
	    ImGui::StyleColorsDark();

    if (!bInitializedStyleSetup)
        bInitializedStyleSetup = true;

    return bInitializedStyleSetup;
}
