#pragma once
#include <iostream>


class Person
{
	public:
		Person();
		~Person();

		void setPersonName(std::string strName);
		std::string getPersonName();

	private:
		std::string m_strName;
		int* age;
};
