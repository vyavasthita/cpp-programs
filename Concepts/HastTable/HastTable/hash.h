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

class CHashMap
{
	public:
		CHashMap();
		~CHashMap();

		void userConsole();

		struct node* createNewNode(int item);

		void InitializeHashMap(int item);

		void addItem(int item);

		void deleteItem(int item);

		bool searchItem(int item);

		int hashFunction(int item);

	private:
		struct node* ptr;

		static int hashMapSize;
		struct node* hashMapArray;
};