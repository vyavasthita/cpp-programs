#include <iostream>
#include <conio.h>

using namespace std;

class SingleObject
{
	 static bool flag;
	 static SingleObject *instance;
	 SingleObject()
	 {
		 
	 }
	
	 
	public:
		static SingleObject* getInstance();
	~SingleObject()
	 {
		 delete instance;
	 }
};

bool SingleObject::flag = false;
SingleObject* SingleObject::instance = NULL;

SingleObject* SingleObject::getInstance()
{
	  if(!flag)
	  {
		  instance = new SingleObject;
		  flag = true;
		  return instance;
	  }
	  else
	  {
		  return instance;
	  }
}

void main()
{
	SingleObject *ob1, *ob2;
	ob1	= SingleObject::getInstance();
	ob2	= SingleObject::getInstance();

	cout<<ob1<<" "<<ob2;
	getch();
}