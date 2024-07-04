#include "mycs.h"
#include <iostream>

using namespace std;


MyCS::MyCS()
{

}
MyCS::~MyCS()
{

}

void MyCS::InitializeCS()
{
	::InitializeCriticalSection(&m_cs);
}

