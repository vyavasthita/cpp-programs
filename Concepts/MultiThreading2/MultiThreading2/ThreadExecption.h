#ifndef __THRD_EXP_H_
#define __THRD_EXP_H_

#include <iostream>

/** class ThreadException
	 * thrown by Thread and Mutex function 
	 * calls
**/
class ThreadException 
{
	public:
		ThreadException(const char* exception);
		std::string getMessage() const;
	private:
		std::string strErrMsg;
};

#endif __THRD_EXP_H_