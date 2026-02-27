#include "API.h"
#include "KeyAuth-SDK/auth.hpp"
#include "KeyAuth-SDK/utils.hpp"
#include "KeyAuth-SDK/skStr.h"

std::string name = skCrypt("").decrypt(); // App name
std::string ownerid = skCrypt("").decrypt(); // Account ID
std::string version = skCrypt("1.0").decrypt(); // Application version. Used for automatic downloads see video here https://www.youtube.com/watch?v=kW195PLCBKs
std::string url = skCrypt("https://keyauth.win/api/1.3/").decrypt(); // change if using KeyAuth custom domains feature
std::string path = skCrypt("").decrypt(); // (OPTIONAL) see tutorial here https://www.youtube.com/watch?v=I9rxt821gMk&t=1s


KeyAuth::api KeyAuthApp(name, ownerid, version, url, path);

bool cKeyAuthAPI::bInitializeKeyAuthAPI()
{
	if (bInitializedKeyAuthAPI)
		return false;

	if (!bInitializedKeyAuthAPI)
		KeyAuthApp.init();
	else
		bInitializedKeyAuthAPI = false;

	if(KeyAuthApp.response.success)
		bInitializedKeyAuthAPI = true;
	else
		bInitializedKeyAuthAPI = false;

	return bInitializedKeyAuthAPI;
}

bool cKeyAuthAPI::bLoginKeyAuth(std::string strUsername, std::string strPassword)
{
	if (bLoggedInKeyAuth)
		return false;

	if(strUsername.empty() || strPassword.empty())
		return false;

	if (!bLoggedInKeyAuth)
		KeyAuthApp.login(strUsername, strPassword);

	if (KeyAuthApp.response.success)
		bLoggedInKeyAuth = true;
	else
		bLoggedInKeyAuth = false;

	return bLoggedInKeyAuth;
}

bool cKeyAuthAPI::bRegisterKeyAuth(std::string strUsername, std::string strPassword, std::string strLicense, std::string strEmail)
{
	if (bRegisteredKeyAuth)
		return false;

	if (strUsername.empty() || strPassword.empty() || strLicense.empty())
		return false;

	if (!bRegisteredKeyAuth)
		KeyAuthApp.regstr(strUsername, strPassword, strLicense);

	if (KeyAuthApp.response.success)
		bRegisteredKeyAuth = true;
	else
		bRegisteredKeyAuth = false;

	return bRegisteredKeyAuth;
}

bool cKeyAuthAPI::bUpgradeKeyAuth(std::string strUsername, std::string strLicense)
{
	if (bUpgradedKeyAuth)
		return false;

	if (strUsername.empty() || strLicense.empty())
		return false;

	if (!bUpgradedKeyAuth)
		KeyAuthApp.upgrade(strUsername, strLicense);

	if (KeyAuthApp.response.success)
		bUpgradedKeyAuth = true;
	else
		bUpgradedKeyAuth = false;

	return bUpgradedKeyAuth;
}

bool cKeyAuthAPI::bLicenseKeyOnlyKeyAuth(std::string strLicense)
{
	if (bLicensedKeyOnlyKeyAuth)
		return false;

	if (strLicense.empty())
		return false;

	if (!bLicensedKeyOnlyKeyAuth)
		KeyAuthApp.license(strLicense);

	if (KeyAuthApp.response.success)
		bLicensedKeyOnlyKeyAuth = true;
	else
		bLicensedKeyOnlyKeyAuth = false;

	return bLicensedKeyOnlyKeyAuth;
}


bool cKeyAuthAPI::bInfosKeyAuth(bool bStatus)
{
	if(bFindInfosKeyAuth)
		return false;

	if (!bFindInfosKeyAuth)
	{
		strUsername = (KeyAuthApp.user_data.username);
		strIP = (KeyAuthApp.user_data.ip);
		strHWID = (KeyAuthApp.user_data.hwid);
		strCreateDate = (KeyAuthApp.user_data.createdate);
		strLastLogin = (KeyAuthApp.user_data.lastlogin);

		bFindInfosKeyAuth = true;
	}
	else
		bFindInfosKeyAuth = false;

	return bFindInfosKeyAuth;
}

bool cKeyAuthAPI::bStatusKeyAuth(bool bStatus)
{
	if (bStatus)
	{
		bKeepStatusLogged = bStatus;
		strDataKeyAuth = (KeyAuthApp.response.message);
		return true;
	}
	else
	{
		bKeepStatusLogged = bStatus;
		strDataKeyAuth = (KeyAuthApp.response.message);
		return false;
	}
		
	
}


