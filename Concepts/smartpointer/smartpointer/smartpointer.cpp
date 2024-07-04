//#include <iostream>
//#include <conio.h>
//
//using namespace std;
//
//template <typename T> class smartpointer
//{
//	public:
//		smartpointer(T *inPtr);
//		~smartpointer();
//	private:
//		T* mPtr;
//};
//
//template <typename T> smartpointer<T>::smartpointer<(T* inPtr)
//{
//	mPtr = inPtr;
//}
//
//template <typename T> smartpointer<T>::~smartpointer()
//{
//	delete mPtr;
//}
//
//void main()
//{
//	smartpointer<int> smart;
//	auto_ptr<int> p;
//
//	int *ptr = new int;
//	
//	smart = ptr;
//}

#include <iostream>
#include <conio.h>

class smartpointer
{
	public:
		smartpointer(int* ptr);
		~smartpointer();
	private:
		int* p;
};

smartpointer::smartpointer(int* ptr)
{
	p = ptr;
}

smartpointer::~smartpointer()
{
	delete p;
	std::cout <<"deleted successfully\n";
}

void main()
{
	{
		int *ptr = new int;
		smartpointer ob = ptr;
	}
	getch();
}