#include <iostream>

class CTesting
{
	public:
		__declspec(dllexport) bool LoginToTC(const char *const_pcUserName, const char *const_pcPassword,
				const char *const_pcGroup);
};