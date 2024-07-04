#include <iostream>

#ifndef INC_CAR_H
#define INC_CAR_H

class Car
{


	public:
		Car();
		virtual ~Car();
		virtual void design() = 0;
};

#endif /* INC_CAR_H */