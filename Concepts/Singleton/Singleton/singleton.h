#include <iostream>


class CSingleton
{
	public:
		static CSingleton* getInstance();
		void singletonFunction();

	private:
		CSingleton();
		~CSingleton();

		static CSingleton* singletonObject;
		static int var;
};	