#include <iostream>
#include <conio.h>

using namespace std;

class Stack
{
	public:
		Stack()
		{
			tos = 0;
		}
		void welcomeScreem();
		void createArray(int);
		void push(int);
		int pop();
		void userInput();
		void print();
	private:
		int *inputArray;
		int number;
		int tos;
};

void Stack::welcomeScreem()
{
	int choice = 0;
	bool bFlag = true;
	while(bFlag)
	{
		cout<<"Select a choice\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Print\n";
		cout<<"4. Exit\n";
		cin>>choice;  

		switch(choice)
		{
			case 1:
				{
					int item;
					cout<<"Enter an Item\n";
					cin>>item;
					push(item);
					break;
				}
			case 2:
				{
					pop();
					break;
				}
			case 3:
				{
					print();
					break;
				}
			case 4:
				{
					bFlag = false;
					break;
				}
			default:
				{
				}
		}
	}
	
}
void Stack::createArray(int size)
{
	inputArray = new int[size];
}

void Stack::userInput()
{
	cout<<"Enter the number of items you want to enter\n";
	cin>>number;
	createArray(number);
}

void Stack::push(int item)
{
	 if(tos > number)
	 {
		 cout<<"Stack Overflow\n";
		 return;
	 }
	 inputArray[tos++] = item;
	 cout<<"Pushed Successfully\n";
}

int Stack::pop()
{
	if(tos < 1)
	{
		 cout<<"Stack Underflow\n";
		 return 0;
	}
	cout<<"Popped Successfully\n";
	return inputArray[--tos];
}

void Stack::print()
{
	if(tos < 1)
	{
		 cout<<"Stack Underflow\n";
		 return;
	}
	for(int i = 0; i < tos; i++)
	{
		cout<<inputArray[i]<<" ";
	}
}

void main()
{
	Stack ob;
	ob.userInput();
	ob.welcomeScreem();
	getch();
}