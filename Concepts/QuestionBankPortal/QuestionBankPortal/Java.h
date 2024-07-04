#include <iostream>
#include "Technical.h"

namespace Exams
{
	class Java:public Technical
	{
		public:
			void setSubjectName(std::string);
			std::string getSubjectName();
	};
}