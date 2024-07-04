#include <iostream>

class CSingleton
{
	public:
		static CSingleton* getInstance();

		void fun();

		~CSingleton();

	private:
		CSingleton();
};