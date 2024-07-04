#include <iostream>
#include <conio.h>
using namespace std;

class Base
{
	private:
		int basePri;
	protected:
		int basePro;
	public:
		int basePub;
		virtual void pubFun() = 0;
};
class Derived:public Base
{
	private:
		int derPri;
	public:
		void pubFun();
};
//void Base::pubFun()
//{
//	cout<<"Base Class"<<endl;
//}
void Derived::pubFun()
{
	cout<<"Derived Class";
}
int main () 
{
	Base * basePtr = new Derived;
	basePtr->pubFun();
	getch();
	delete basePtr;
	return 0;
}