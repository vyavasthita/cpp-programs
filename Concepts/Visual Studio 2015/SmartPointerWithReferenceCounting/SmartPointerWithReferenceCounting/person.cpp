#include "person.h"

Person::Person() : m_strName("")
{
	age = new int;
}

Person::~Person()
{
	std::cout << "Person dtor called\n";
	delete age;
	age = NULL;
}

void Person::setPersonName(std::string strName)
{
	m_strName = strName;
}

std::string Person::getPersonName()
{
	return m_strName;
}