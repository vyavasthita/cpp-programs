#include "person.h"
#include "SmartPointer.h"
#include <conio.h>
#include <memory>


int main()
{
	{
		Person* p1 = NULL;
		{
			p1 = new Person;

			p1->setName("Goolu Goolu");

			SmartPointer<Person> sp1;

			SmartPointer<Person> sp2(p1);

			SmartPointer<Person> sp3(sp2);

			SmartPointer<Person> sp4(sp3);

			SmartPointer<Person> sp5(sp4);

			SmartPointer<Person> sp6;

			sp6 = sp3;

			sp6 = sp1;
		}
	}

	_getch();
	return 0;
}