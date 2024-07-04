#include "person.h"
#include "smart.h"
#include <conio.h>


using namespace std;

int main()
{
	{
		Person* person = new Person;

		SmartPointer<Person> sp1(person);
		SmartPointer<Person> sp2(sp1);
	}	

	_getch();
	return 0;
}