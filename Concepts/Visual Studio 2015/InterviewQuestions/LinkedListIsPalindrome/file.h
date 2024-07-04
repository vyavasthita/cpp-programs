#pragma once
#include <iostream>
#include <vector>

using namespace std;


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
			void addNode(int item);
			bool isPalindrome();
			void traverseList();
			void print();
			void printInReverseOrder(NODE* ptr);

		private:
			NODE* head;
			NODE* prev;

			vector<int> m_vecItems;
	};
}; 
