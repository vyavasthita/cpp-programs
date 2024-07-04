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

struct node
{
	int value;
	struct node* next;
}*start, *frontPtr, *rearPtr;

class DeQueue
{
	public:
		DeQueue()
		{		
			frontPtr = NULL;
			rearPtr = NULL;
			start = NULL;
		}
		~DeQueue();

		void welcomeScreen();
		void addFirst(int);
		void addLast(int);
		void deleteFirst();
		void deleteLast();
		void print();
};

DeQueue::~DeQueue()
{
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
	node *newNode = new node;
	newNode->value = item;
	newNode->next = NULL;

	if(rearPtr == NULL)
	{
		rearPtr = newNode;
		frontPtr = start = rearPtr;
	}
	else
	{
		newNode->next = frontPtr;
		frontPtr = start = newNode;
	}
	
	cout<<"Item : "<<item<<" added successfully at first\n";
}

void DeQueue::addLast(int item)
{
	node *newNode = new node;
	newNode->value = item;
	newNode->next = NULL;

	if(rearPtr == NULL)
	{
		rearPtr = newNode;
		frontPtr = start = rearPtr;
	}

	while(rearPtr->next != NULL)
	{
		rearPtr = rearPtr->next;
	}
	rearPtr->next = newNode;
	rearPtr = rearPtr->next;

	cout<<"Item : "<<item<<" added successfully at Last \n";
}

void DeQueue::deleteFirst()
{
	if(rearPtr == NULL)
	{
		cout<<"List is empty\n";
		return;
	}

	node* temp;
	if(rearPtr->next = NULL)
	{		 
		temp = rearPtr;
		delete temp;
		rearPtr = NULL;
		frontPtr = NULL;
		start = NULL;
	}
	else
	{
		temp = frontPtr;
		frontPtr = frontPtr->next;
		temp->next = NULL;
		delete temp;
		start = frontPtr;
	}
	cout<<"Item deleted successfully\n"; 	
}

void DeQueue::deleteLast()
{
	if(rearPtr == NULL)
	{
		cout<<"List is empty\n";
		return;
	}

	node* temp;
	if(rearPtr->next == NULL)
	{		 
		delete rearPtr;
		rearPtr = start = NULL;
	}
	else
	{
		while(rearPtr->next != NULL)
		{
			temp = rearPtr;
			rearPtr = rearPtr->next;
		}
		temp->next = NULL;
		delete rearPtr;
		rearPtr = temp;
	}
	cout<<"Item deleted successfully\n"; 	
}
void DeQueue::print()
{
	if(rearPtr == NULL)
	{
		cout<<"List is empty\n";
		return;
	}
	while(frontPtr)
	{
		cout<<frontPtr->value<<" ";
		frontPtr = frontPtr->next;
	}
	frontPtr = start;
}

void main()
{ 
	DeQueue dqueue;
	dqueue.welcomeScreen();
	getch();
}