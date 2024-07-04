#include <iostream>
#include "Java.h"

using namespace std;
namespace Exams
{
	void Java::setSubjectName(string subjectName)
	{
		mStrSubjectName = subjectName;
	}

	string Java::getSubjectName()
	{
		return mStrSubjectName;
	}
}