#include <iostream>
#include "Subject.h"

namespace Exams
{
	class Technical:virtual public Subject
	{
		public:
			void setSubjectName(std::string);
			std::string getSubjectName();
	};
}