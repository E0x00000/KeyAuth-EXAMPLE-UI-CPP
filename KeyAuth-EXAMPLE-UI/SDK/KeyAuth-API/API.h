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

class cKeyAuthAPI final
{
public:

	bool bInitializeKeyAuthAPI();

	bool bLoginKeyAuth(std::string strUsername, std::string strPassword);

	bool bRegisterKeyAuth(std::string strUsername, std::string strPassword, std::string strLicense, std::string strEmail = "");

	bool bUpgradeKeyAuth(std::string strUsername, std::string strLicense);

	bool bLicenseKeyOnlyKeyAuth(std::string strLicense);

	bool bStatusKeyAuth(bool bStatus);

	bool bInfosKeyAuth(bool bStatus);

	bool bKeepStatusLogged;

	std::string strDataKeyAuth;


	//// KeyAuthAPI variables bc im lazy and dont want to make a struct for it

	std::string strUsername;
	std::string strIP;
	std::string strHWID;
	std::string strCreateDate;
	std::string strLastLogin;

private:

	bool bFindInfosKeyAuth = false;

	bool bInitializedKeyAuthAPI = false;

	bool bLoggedInKeyAuth = false;

	bool bRegisteredKeyAuth = false;

	bool bUpgradedKeyAuth = false;

	bool bLicensedKeyOnlyKeyAuth = false;
};
inline cKeyAuthAPI cAPI;