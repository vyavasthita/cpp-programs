#include <iostream>
#include "C++.h"

using namespace std;
namespace Exams
{
	void CPlusPlus::setSubjectName(string subjectName)
	{
		mStrSubjectName = subjectName;
	}

	string CPlusPlus::getSubjectName()
	{
		return mStrSubjectName;
	}
}