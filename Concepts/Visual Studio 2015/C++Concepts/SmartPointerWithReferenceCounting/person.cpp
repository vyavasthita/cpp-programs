#include "person.h"


Person::Person() : m_pstrName(NULL), m_pnAge(0)
{
	m_pstrName = new string;
	m_pnAge = new int;
}

Person::~Person()
{
	cout << "Dtor of Person called\n";
	delete m_pstrName;
	delete m_pnAge;
}

void Person::setName(string name)
{
	*m_pstrName = name;
}

string Person::getName()
{
	return *m_pstrName;
}

void Person::setAge(int age)
{
	*m_pnAge = age;
}

int Person::getAge()
{
	return *m_pnAge;
}