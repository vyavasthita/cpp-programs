#include <iostream>
#include "NonTechnical.h"

namespace Exams
{
	class English:public NonTechnical
	{
		public:
			void setSubjectName(std::string);
			std::string getSubjectName();
	};
}