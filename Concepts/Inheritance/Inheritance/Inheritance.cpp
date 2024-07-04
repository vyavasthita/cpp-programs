#include <iostream>
#include <conio.h>

using namespace std;


class Car
{
	public:
		void Wheel()
		{
			cout<<"Car\n";
		}
};

class Alto:public Car
{
	public:
		void musicSystem()
		{
			cout<<"Alto\n";
		}
};

class Accent:public Alto
{
	public:
		void powerSteering()
		{
			cout<<"Accent\n";
		}
};

class Mercedez:public Accent
{
	public:
		void powerAC()
			{
				cout<<"<Mercedez\n";
			}
};

void main()
{

	cout<<"***Alto***\n";
	Alto altoObj;

	altoObj.Wheel();
	altoObj.musicSystem();
	
	cout<<"\n***Accent***\n";
	Accent accObj;

	accObj.Wheel();
	accObj.musicSystem();
	accObj.powerSteering();

	cout<<"\n***Mercedez***\n";	
	Mercedez merObj;

	merObj.Wheel();
	merObj.musicSystem();
	merObj.powerSteering();
	merObj.powerAC();

	getch();
}