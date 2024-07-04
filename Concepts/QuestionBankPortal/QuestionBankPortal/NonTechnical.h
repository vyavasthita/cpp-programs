#include <iostream>
#include "Subject.h"

namespace Exams
{
	class NonTechnical:virtual public Subject
	{
		public:
			void setSubjectName(std::string);
			std::string getSubjectName();
	};
}