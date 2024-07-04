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

struct node
{
	int value;
	struct node* next;
}*frontPtr, *rearPtr, *start;

class Queue
{
	public:
		Queue()
		{		
			frontPtr = rearPtr = NULL;
		}
		~Queue();	

		void welcomeScreen();
		void addItem(int);
		void deleteItem();
		void print();
};

Queue::~Queue()
{
	node *temp;
	while(rearPtr)
	{
		temp = rearPtr;
		rearPtr = rearPtr->next;
		temp->next = NULL;
		delete temp;
	}
}

void Queue::welcomeScreen()
{
	unsigned int uiChoice = 0;
	int iItem = 0;
	bool bFlag = true;

	while(bFlag)
	{
		cout<<"\n*****Welcome to Queue****\n";
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
	node *newNode = new node;
	newNode->value = item;
	newNode->next = NULL;

	if(rearPtr == NULL)
	{
		rearPtr =  newNode;
		frontPtr = start = rearPtr; 
	}
	else
	{
		rearPtr->next = newNode;
		rearPtr = rearPtr->next;
	}

	cout<<"Item : "<<item<<" added successfully\n";
}
void Queue::deleteItem()
{
	struct node* temp;

	temp = frontPtr;
	frontPtr = frontPtr->next;
	temp->next = NULL;
	delete temp;
	
	cout<<"Item deleted successfully\n"; 
}
void Queue::print()
{
	while(frontPtr)
	{
		cout<<frontPtr->value<<" ";
		frontPtr = frontPtr->next;
	}
	frontPtr = start;
}
void main()
{ 
	Queue queue;
	queue.welcomeScreen();
	getch();
}