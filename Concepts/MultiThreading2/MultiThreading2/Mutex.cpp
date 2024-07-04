#include "Mutex.h"
#include "ThreadExecption.h"
#include "multithreading.h"

/**@ The Mutex class implementation
**@/

/** Mutex()
  * default constructor
**/  
Mutex::Mutex() 
{
	m_Mutex = NULL;
	m_strName = "";
}

/** Mutex(const char* nm)
  * overloaded constructor
  * creates a Mutex object identified by "nm"
**/  
Mutex::Mutex(const char* nm) 
{	
	m_strName = nm;	
	m_Mutex = (unsigned long*)CreateMutex(NULL, FALSE, nm);
	
	if(m_Mutex == NULL) 
	{
		throw ThreadException("Failed to create mutex");
	}
}

/** create(const char* nm)
  * frees the current mutex handle.
  * creates a Mutex object identified by "nm"
**/ 
void Mutex::create(const char* nm) 
{
	if(m_Mutex != NULL) 
	{
		CloseHandle(m_Mutex);
		m_Mutex = NULL;
	}

	m_strName = nm;
	m_Mutex = (unsigned long*)CreateMutex(NULL, FALSE, nm);

	if(m_Mutex == NULL) 
	{
		throw ThreadException("Failed to create mutex");
	}
}

/** getMutexHandle()
  * returns the handle of the low-level mutex object
**/  
unsigned long* Mutex::getMutexHandle() 
{
	return m_Mutex;
}

/** getName()
  * returns the name of the mutex
**/ 
std::string Mutex::getName() 
{
	return m_strName;
}

void Mutex::release() 
{
	if(m_Mutex != NULL) 
	{
		CloseHandle(m_Mutex);
	}
}

Mutex::~Mutex() 
{
	/*if(m_Mutex != NULL) 
	{
		CloseHandle(m_Mutex);
	}*/
}