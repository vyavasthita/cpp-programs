#pragma once

#include <iostream>
#include <vector>

namespace Algorithms
{
	typedef struct node
	{
		int value;
		struct node* left;
		struct node* right;
	}NODE;

	enum CHOICE
	{
		ADD = 1,
		DELETE = 2,
		SEARCH = 3,
		TRAVERSAL = 4,
		MIN = 5,
		MAX = 6,
		HEIGHT = 7, 
		SECOND_SMALLEST = 8,
		EXIT = 9
	};

	enum TRAVERSAL
	{
		PREORDER = 1,
		INORDER = 2,
		POSTORDER = 3,
		BACK = 4
	};

	class BST
	{
		public:
			BST();
			~BST();
			void deleteTree(NODE* ptr);

			NODE* CreateNewNode(int value);
			bool addNode(int value);

			bool deleteNode(int value);
			void deleteNode(NODE* searchNode);

			NODE* searchTree(int value);

			void preorderTraversal();
			void preorder(NODE* ptr);

			void inorderTraversal();
			void inorder(NODE* ptr);

			void postorderTraversal();
			void postorder(NODE* ptr);

			int getMin();
			int getMax();

			// TO DO : Following function not in working conditions
			int getTreeLevel();
			int getHeight(NODE* ptr);
			
			int get2ndSmallestToGivenElement(int value);
			void get2ndSmallest(NODE* ptr);

	private:
		NODE* root;
		std::vector<int> m_vTempValues;

		int m_nSmallest;
		int m_n2ndSmallest;
	};
}
