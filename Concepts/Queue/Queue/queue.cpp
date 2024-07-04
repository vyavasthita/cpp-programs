#include <iostream>
#include <conio.h>

using namespace std;

enum Choice
{
	ADD = 1,
	DELETE,
	PRINT,
	EXIT
};
class Queue
{
	public:
		Queue()
		{		
			front = rear = 0; 			
		}
		~Queue()
		{
			//delete [] inputArray;
		}
		void createArray(int size)
		{
			inputArray = new int[size];
		}
		void inputScreen();
		void welcomeScreen();
		void addItem(int);
		void deleteItem();
		void print();
	
	private:		
		int front, rear;
		int *inputArray;
		int sizeOfArray;
}q;

void Queue::inputScreen()
{
	cout<<"enter size of the queue\n";
	cin>>sizeOfArray;
	createArray(sizeOfArray);
}
void Queue::welcomeScreen()
{
	unsigned int uiChoice = 0;
	int iItem = 0;
	bool bFlag = true;

	while(bFlag)
	{
		cout<<"*****Welcome to Queue****\n";
		cout<<"Select a Choice\n";

		cout<<"1. Add\n";
		cout<<"2. Delete\n";
		cout<<"3. Print\n";
		cout<<"4. Exit\n";

		cin>>uiChoice;

		switch(uiChoice)
		{
			case ADD:
			{
				cout<<"Enter an item to add\n";
				cin>>iItem;

				addItem(iItem);
				break;
			}
			case DELETE:
			{
				deleteItem();
				break;
			}
			case PRINT:
			{
				print();
				break;
			}
			case EXIT:
			{
				bFlag = false;
				break;
			}
			default:
			{
				cout<<"Wrong Choice\n";
				break;
			}
		}
	}
}
void Queue::addItem(int item)
{
	if(rear == sizeOfArray)
	{
		cout<<"Overflow\n";
		return;
	}

	inputArray[rear++] = item;

	cout<<"Item : "<<item<<" added successfully\n";
}
void Queue::deleteItem()
{
	if(rear == 0)
	{
		cout<<"Underflow\n";
		return;
	}
		
	for(unsigned int ui = front; ui <= rear; ui++)
	{
		inputArray[ui] = inputArray[ui + 1];
	}
	--rear;
	cout<<"Item deleted successfully\n"; 
}
void Queue::print()
{
	for(unsigned int ui = 0; ui < rear; ui++)
	{
		cout<<inputArray[ui]<<" ";
	}
}
void main()
{ 
	q.inputScreen();
	q.welcomeScreen();
	getch();
}