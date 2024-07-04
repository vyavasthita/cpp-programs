#ifndef __MUTEX_H_
#define __MUTEX_H_

#include <iostream>

/** class Mutex
	 * Represents a Mutex object to synchronize
	 * access to shaed resources.
**/
class Mutex 
{
	private:
		// unsigned long* to the low-level mutex object
		unsigned long* m_Mutex;

		// name to identify the mutex
		std::string m_strName;

	public:
		Mutex();
		Mutex(const char* nm);

		void create(const char* nm);
		unsigned long* getMutexHandle();
		std::string getName();
		void release();
		~Mutex();
};

#endif __MUTEX_H_