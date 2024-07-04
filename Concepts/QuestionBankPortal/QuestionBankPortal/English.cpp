#include <iostream>
#include "English.h"

using namespace std;
namespace Exams
{
	void English::setSubjectName(string subjectName)
	{
		mStrSubjectName = subjectName;
	}

	string English::getSubjectName()
	{
		return mStrSubjectName;
	}
}