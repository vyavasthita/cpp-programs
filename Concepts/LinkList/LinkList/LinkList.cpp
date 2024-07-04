#include <iostream>
#include <conio.h>

using namespace std;

enum choice
{
	ADD = 1,
	ADD_AFTER,
	DELETE,
	PRINT,
	MAKE_CIRCULAR,
	MAKE_LINEAR,
	REVERSE,
	SORT,
	EXIT
};

enum ListType
{
	LINEAR,
	CIRCULAR
}type;

struct node
{
	int item;
	struct node *next;
}*ptr, *start;

class LinkList
{
	int size;
	public:
		LinkList();
		~LinkList();
		void clear();
		void init();
		void choiceSelection(unsigned int);
		void addItem(int);
		void addAfter(int, int);
		void deleteNode(int);
		void print();
		void makeCircular();
		void makeLinear();
		void reverse();
		void sortList();
		ListType getListType();
		void setListType(ListType);
		void swapItems(int&, int&);
}list;

LinkList::LinkList()
{
	ptr = NULL;
	start = NULL;
	type = LINEAR;
}

LinkList::~LinkList()
{
	if(ptr == NULL)
	{
	}
	else
	{
		node *temp;
		while(ptr != NULL)
		{
			temp = ptr;
			ptr = ptr->next;
			delete temp;
		}
	}
}

void LinkList::init()
{
	unsigned int uiChoice = 0;

	cout<<"Welcome To Link List\n";
	cout<<"Select An Option\n";
	cout<<"\n1. Add\n";
	cout<<"\n2. Add After\n";
	cout<<"\n3. Delete\n";
	cout<<"\n4. Print\n";
	cout<<"\n5. Circular\n";
	cout<<"\n6. Linear\n";
	cout<<"\n7. Reverse\n";
	cout<<"\n8. Sort\n";
	cout<<"\n9. Exit\n";

	cin>>uiChoice;

	list.choiceSelection(uiChoice);
}

void LinkList::clear()
{
	system("clear");
}

void LinkList::choiceSelection(unsigned int choice)
{
	int iItem = 0, iLoc = 0;
	list.clear();
	switch(choice)
	{
		case ADD:
			{
				
				cout<<"Enter an item to add\n";
				cin>>iItem;
				list.addItem(iItem);
				break;
			}
		case ADD_AFTER:
			{
				cout<<"Enter an item\n";
				cin>>iItem;

				cout<<"Enter Item location\n";
				cin>>iLoc;

				list.addAfter(iItem, iLoc);
				break;
			}
		case DELETE:
			{
				cout<<"Enter an item to delete\n";
				cin>>iItem;
				list.deleteNode(iItem);
				break;
			}
		case PRINT:
			{
				list.print();
				break;
			}
		case MAKE_CIRCULAR:
			{
				list.makeCircular();
				break;
			}
		case MAKE_LINEAR:
			{
				list.makeLinear();
				break;
			}
		case REVERSE:
			{	
				list.reverse();
				break;
			}
		case SORT:
			{	
				list.sortList();
				break;
			}
		case EXIT:
			{
				break;
			}
		default:
			{
				cout<<"Wrong choice\n";
				break;
			}
	}
}

void LinkList::addItem(int i)
{
	node *newNode = new node;
	newNode->item = i;
	newNode->next = NULL;

	if(ptr == NULL)
	{		
		start = ptr = newNode;
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
	size++;
	ptr = start;
	cout<<"Item added successfully\n";
	list.init();
}

void LinkList::addAfter(int item, int loc)
{
	node *newNode = new node;
	newNode->item = item;
	newNode->next = NULL;

	bool bFound = false;

	while(ptr != NULL)
	{
		if(ptr->item == loc)
		{
			if(ptr->next == NULL)
			{
				ptr->next = newNode;
			}
			else
			{
				newNode->next = ptr->next;
				ptr->next = newNode;
			}
			bFound = true;			
			break;
		}
		ptr = ptr->next;		
	}

	if(bFound)
	{
		size++;
		cout<<"Item Added successfully\n";
	}
	else
	{
		cout<<"Location not found\n";
	}
	
	ptr = start;
	list.init();
}

void LinkList::deleteNode(int item)
{
	node *prev;
	bool bFound = false;

	while(ptr != NULL)
	{
		if(ptr->item == item)
		{
			if(start == ptr)
			{
				start = ptr->next;
				ptr->next = NULL;
				delete ptr;
			}
			else if(ptr->next == NULL)
			{
				prev->next = NULL;
				delete ptr;
			}
			else
			{
				prev->next = ptr->next;
				ptr->next = NULL;
				delete ptr;
			}
			bFound = true;			
			break;
		}
		prev = ptr;
		ptr = ptr->next;		
	}

	if(bFound)
	{
		size--;
		cout<<"Item deleted successfully\n";
	}
	else
	{
		cout<<"Item not found\n";
	}
	
	
	ptr = start;
	list.init();
}

void LinkList::print()
{
	if(ptr == NULL)
	{
		cout<<"Empty\n";
	}
	else
	{
		cout<<"Items are : ";
		while(ptr != NULL)
		{
			cout<<ptr->item<<" ";
			ptr = ptr->next;
		}
	}
	ptr = start;
	list.init();
}

void LinkList::makeCircular()
{
	if(ptr == NULL)
	{
		cout<<"List is Empty\n";
	}
	else if(ptr->next == NULL)
	{
		cout<<"List's size must be greater than 1 \n";
	}
	else
	{
		if(getListType() == CIRCULAR)
		{
			cout<<"List is already Circular\n";
		}
		else
		{
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = start;
			//start = NULL;
			setListType(CIRCULAR);
			cout<<"List is Circular now\n";
		}
	}
	list.init();
}

void LinkList::makeLinear()
{
	node *currNode, *temp;
	ptr = temp = start;
	bool bFound = false;
	int iLoc = 0;

	if(ptr == NULL)
	{
		cout<<"List is Empty\n";
	}
	else if(getListType() == LINEAR)
	{
		cout<<"List is already Linear\n";
	}
	else
	{
		cout<<"Enter starting location\n";
		cin>>iLoc;

		while(ptr)
		{
			if(ptr->item == iLoc)
			{
				currNode = ptr;
				bFound = true;
				break;
			}
			ptr = ptr->next;
			if(ptr == temp)
			{
				break;
			}
		}	

		///
		if(bFound)
		{
			temp = currNode;
			while(temp != currNode->next)
			{				
				currNode = currNode->next;
			}
			currNode->next = NULL;

			start = temp;
			ptr = start;

			setListType(LINEAR);
			cout<<"List is Linear now\n";
		}
		else
		{
			cout<<"starting location not found\n";
		}
		///
	}
	list.init();
}

void LinkList::setListType(ListType listType)
{
	type = listType;
}

ListType LinkList::getListType()
{
	return type;
}

void LinkList::reverse()
{
	node *rev = NULL;
	node *prev = NULL;
	node *revStart = NULL;
	node *temp = ptr;

	while(ptr->next != NULL)
	{
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		
		prev->next = NULL;

		if(revStart == NULL)
		{
			revStart = rev = temp;
		}
		else
		{
			rev->next = temp;
			rev = rev->next;
		}
		temp = start;
	}

	rev->next = ptr;
	ptr = revStart;
	list.init();
}

void LinkList::sortList()
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if((ptr->item) > (ptr->next->item))
			{
				swapItems(ptr->item, ptr->next->item);
			}
			ptr = ptr->next;
		}
		ptr = start;
	}
	ptr = start;
	list.init();
}

void LinkList::swapItems(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void main()
{
	list.init();
	getch();
}