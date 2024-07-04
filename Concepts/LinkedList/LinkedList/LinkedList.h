#include <iostream>

struct node
{
	int data;
	struct node* next;
};

enum ListChoice
{
	TRAVERSE = 1,
	ADD = 2,
	DELETE = 3,
	SEARCH = 4,
	EXIT = 5,
};

class CLinkedList
{
	public:
		CLinkedList();
		~CLinkedList();

		void userConsole();

		void TraverseList();

		struct node* createNewNode(int item);
		void InitializeList(int item);
		void addAtFirst(int item);
		void addAtLast(int item);
		void addInBetween(int item);

		void addNode(int item);

		void deleteNode(int item);

		bool searchNode(int item);

	private:
		struct node* ptr;
		struct node* start;
};