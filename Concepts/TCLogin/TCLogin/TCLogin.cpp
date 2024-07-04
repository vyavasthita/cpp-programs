// TCLogin.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <tc.h>
#include <iostream>
#include <set>

bool LoginToTC(const char *const_pcUserName, const char *const_pcPassword,
				const char *const_pcGroup)
{
	bool bLogin = false;
	int nITKStatus = ITK_init_module(const_pcUserName, const_pcPassword, const_pcGroup);

	if (nITKStatus == ITK_ok)
	{
		bLogin = true;
	}
	return bLogin;
}

int ITK_user_main(int argc, char* argv[])
{
	return 1;
}


