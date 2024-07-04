#pragma once
#include <iostream>
#include <vector>

namespace LINKEDLIST
{
	typedef struct node
	{
		int value;
		struct node* next;
	}NODE;

	class LinkedList
	{
		public:
			LinkedList();
			~LinkedList();

			NODE* createNewNode(int value);
			void createLinkedListFromArray(int* item, int length);

			void processList(NODE* ptr = NULL);

		private:
			NODE* m_rootFirst;
			NODE* m_rootSecond;

			NODE* m_rootOuput;
	};
};
