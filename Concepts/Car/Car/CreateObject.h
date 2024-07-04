#include <iostream>
#include "Suzuki.h"
#include "Accent.h"
#include "Mercedez.h"


class CreateInstance
{
	Car* instance;
	public:
		CreateInstance();
		CreateInstance(std::string);
		Car* makeObject(std::string);
};