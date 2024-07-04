#include <iostream>

#ifndef __CAR_H_
#define __CAR_H_

namespace FactoryPattern
{
	class CCar
	{
		public:
			virtual const char* getCarInfo() = 0;
			virtual long getCarPrice() = 0;
		private:
			std::string m_strCarInfo;
	};
};

#endif __CAR_H_