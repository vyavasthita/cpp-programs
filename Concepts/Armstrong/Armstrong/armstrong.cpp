#include <iostream>
#include <conio.h>

using namespace std;

class Armstrong
{
	static int iSize;
	long int iNum;
	long int iRes;
	
	public:
		Armstrong()
		{
			iNum = 0;
			iRes = 0;
		}

		void input();
		void calculateSize();
		void getArmstrong();
		long int powerFun(int, int);
		void print();
};

int Armstrong::iSize = 0;

void Armstrong::input()
{
	cout<<"Enter a num\n";
	cin>>iNum;
	cout<<"Length = "<<iNum;
}

void Armstrong::calculateSize()
{
	long int temp = iNum;
	while(temp >= 1)
	{
		temp = temp/10;
		++iSize;
	}
}

long int Armstrong::powerFun(int n, int p)
{
	long int res = 1;
	while(p)
	{
		res = res*n;
		--p;
	}
	
	return res;
}
void Armstrong::getArmstrong()
{
	long int temp = iNum;
	int rem = 0;

	while(temp)
	{
		rem = temp%10;
		temp = temp/10;
		iRes = iRes + powerFun(rem, iSize);
	}
}

void Armstrong::print()
{
	if(iNum == iRes)
	{
		cout<<"Armstrong\n";
	}
	else
	{
		cout<<"Not Armstrong\n";
	}
}

void main()
{
	Armstrong arms;
	arms.input();
	arms.calculateSize();
	arms.getArmstrong();
	arms.print();
	getch();
}