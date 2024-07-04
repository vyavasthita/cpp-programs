																		#include <iostream>
#include <conio.h>

using namespace std;

enum Choice
{
	ADD_FIRST= 1,
	ADD_LAST,
	DELETE_FIRST,
	DELETE_LAST,
	PRINT,
	EXIT
};
class DeQueue
{
	public:
		DeQueue()
		{		
			front = rear = 0;
		}
		~DeQueue()
		{
			//delete [] inputArray;
		}
		void setSize();
		void createArray(int size)
		{
			inputArray = new int[size];
		}
		void welcomeScreen();
		void addFirst(int);
		void addLast(int);
		void deleteFirst();
		void deleteLast();
		void print();
	
	private:		
		int front, rear;
		int *inputArray;
		int sizeOfArray;
}q;


void DeQueue::setSize()
{
	cout<<"Enter the size of the DeQueue : ";
	cin>>sizeOfArray;
	createArray(sizeOfArray);
}
void DeQueue::welcomeScreen()
{
	unsigned int uiChoice = 0;
	int iItem = 0;
	bool bFlag = true;

	while(bFlag)
	{
		cout<<"\n*****Welcome to DeQueue****\n";
		cout<<"Select a Choice\n";

		cout<<"1. Add First\n";
		cout<<"2. Add Last\n";
		cout<<"3. Delete first\n";
		cout<<"4. Delete last\n";
		cout<<"5. Print\n";
		cout<<"6. Exit\n";

		cin>>uiChoice;
		switch(uiChoice)
		{
			case ADD_FIRST:
			{
				cout<<"Enter an item to add\n";
				cin>>iItem;

				addFirst(iItem);
				break;
			}
			case ADD_LAST:
			{
				cout<<"Enter an item to add\n";
				cin>>iItem;

				addLast(iItem);
				break;
			}
			case DELETE_FIRST:
			{
				deleteFirst();
				break;
			}
			case DELETE_LAST:
			{
				deleteLast();
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
void DeQueue::addFirst(int item)
{
	if(rear == sizeOfArray)
	{
		cout<<"Overflow\n";
		return;
	}
	
	if(rear == 0)
	{
		inputArray[rear++] = item;
	}

	else
	{
		for(int i = rear - 1; i >= front; i--)
		{
			inputArray[i + 1] = inputArray[i];
		}
		inputArray[front] = item;
		++rear;
	}
	
	cout<<"Item : "<<item<<" added successfully at first\n";
}

void DeQueue::addLast(int item)
{
	if(rear == sizeOfArray)
	{
		cout<<"Overflow\n";
		return;
	}
	
	inputArray[rear++] = item; 

	cout<<"Item : "<<item<<" added successfully at Last \n";
}

void DeQueue::deleteFirst()
{
	if(rear == 0)
	{
		cout<<"Underflow\n";
		return;
	}
	if(rear == 1)
	{
		inputArray[--rear] = NULL;
	}
	else
	{
		for(unsigned int ui = 0; ui < rear - 1; ui++)
		{
			inputArray[ui] = inputArray[ui + 1];
		}
		--rear;
	}
	cout<<"Item deleted successfully\n"; 	
}

void DeQueue::deleteLast()
{
	if(rear == 0)
	{
		cout<<"Underflow\n";
		return;
	}

	inputArray[--rear] = NULL;
	cout<<"Item deleted successfully\n"; 	
}
void DeQueue::print()
{
	if(rear == 0)
	{
		cout<<"Underflow\n";
		return;
	}
	for(unsigned int ui = 0; ui < rear; ui++)
	{
		cout<<inputArray[ui]<<" ";
	}
}

void main()
{ 
	q.setSize();
	q.welcomeScreen();
	getch();
}