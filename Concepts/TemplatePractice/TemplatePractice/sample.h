#include <iostream>
#include <conio.h>

using namespace std;

template <typename T> 
class SmartPointer
{
	public:
		SmartPointer(T *s);
		~SmartPointer();

	private:
		T *m_ptr;
};