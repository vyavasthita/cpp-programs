#include <iostream>

struct node
{
	int nodeValue;
	struct node* leftChild;
	struct node* rightChild;
};

enum ListChoice
{
	TRAVERSE = 1,
	ADD = 2,
	DELETE = 3,
	SEARCH = 4,
	EXIT = 5,
};

class CBinaryTree
{
	public:
		CBinaryTree();
		~CBinaryTree();

		void userConsole();

		void traverseTree();

		struct node* createNewNode(int item);

		void InitializeList(int item);

		void addNode(int item);

		void addNodeAt(int item);

		void deleteNode(int item);

		bool searchNode(int item);

	private:
		struct node* rootNode;
		struct node* traverseNode;
};