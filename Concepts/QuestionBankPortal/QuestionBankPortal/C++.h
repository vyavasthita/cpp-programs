#include <iostream>
#include "Technical.h"

namespace Exams
{
	class CPlusPlus:public Technical
	{
		public:
			void setSubjectName(std::string);
			std::string getSubjectName();
	};
}