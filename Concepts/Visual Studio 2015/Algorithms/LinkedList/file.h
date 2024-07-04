#pragma once

#include <iostream>


namespace Algorithms
{
	struct node
	{
		int value;
		struct node* next;
	};

	enum CHOICE
	{
		ADD = 1,
		DELETE = 2,
		REVERSE = 3,
		PRINT = 4,
		EXIT = 5
	};

	class LinkedList
	{
		public:
			LinkedList();
			~LinkedList();
			struct node* CreateNewNode(int value);
			void addNode(int value);
			void deleteNode(int value);
			void reverseList();
			void printData();

		private:
			struct node* start;
	};
}
