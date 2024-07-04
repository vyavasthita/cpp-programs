#include <iostream>
#include "User.h"

namespace Exams
{
	class Subject
	{
		public:
			virtual void setSubjectName(std::string) = 0;
			virtual std::string getSubjectName() = 0;
		protected:
			std::string mStrSubjectName;
	};
}