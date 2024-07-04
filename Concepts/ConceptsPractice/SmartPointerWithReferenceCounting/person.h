#pragma once
#include <iostream>

using namespace std;


class Person
{
	public:
		Person();
		~Person();

		void setName(string name);
		string getName();

		void setAge(int age);
		int getAge();

	private:
		string* m_pstrName;
		int* m_pnAge;
};
