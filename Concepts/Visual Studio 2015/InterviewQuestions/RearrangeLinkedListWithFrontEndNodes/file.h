#pragma once
#include <iostream>


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
		LinkedList(int size);
		~LinkedList();

		NODE* createNewNode(int value);
		void rearrangeNodes();
		void print();

	private:
		NODE* head;
		int m_nSize;
	};
};