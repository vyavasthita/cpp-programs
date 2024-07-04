#include "file.h"
#include <vector>

using namespace Algorithms;
using namespace std;


BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	deleteTree(root);
}

void BST::deleteTree(NODE* ptr)
{
	if (ptr == NULL)
	{
		return;
	}

	if (ptr->left != NULL)
	{
		deleteTree(ptr->left);
	}

	if (ptr->right != NULL)
	{
		deleteTree(ptr->right);
	}
	else
	{
		delete ptr;
		ptr = NULL;
	}
}

struct node* BST::CreateNewNode(int value)
{
	NODE* newNode = new NODE;
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

bool BST::addNode(int value)
{
	NODE* ptr = NULL;
	NODE* newNode = NULL;
	bool bAdded = false;

	newNode = CreateNewNode(value);

	if (root == NULL) // Tree is empty
	{
		root = newNode;
		bAdded = true;
	}
	ptr = root;

	while (!bAdded)
	{
		if (value <= ptr->value)
		{
			if (ptr->left == NULL)
			{
				ptr->left = newNode;
				bAdded = true;
			}
			else
			{
				ptr = ptr->left;
			}
		}
		else
		{
			if (ptr->right == NULL)
			{
				ptr->right = newNode;
				bAdded = true;
			}
			else
			{
				ptr = ptr->right;
			}
		}
	}
	return bAdded;
}

bool BST::deleteNode(int value)
{
	NODE* searchNode = searchTree(value);

	if (searchNode == NULL)
	{
		return false;
	}
	else
	{
		deleteNode(searchNode);

		cout << "Value inside 1\n";
		vector<int>::iterator it;

		for (it = m_vTempValues.begin(); it != m_vTempValues.end(); it++)
		{
			cout << *it << " ";
			//addNode(*it);
		}
		return true;
	}
}

void BST::deleteNode(NODE* searchNode)
{
	static NODE* parentNode = NULL;

	if (searchNode->left != NULL)
	{
		parentNode = searchNode;
		deleteNode(searchNode->left);
	}
	if (searchNode->right != NULL)
	{
		parentNode = searchNode;
		deleteNode(searchNode->right);
	}
	m_vTempValues.push_back(searchNode->value);

	delete searchNode;
	searchNode = NULL;
}

NODE* BST::searchTree(int value)
{
	NODE*searchNode = root;

	if (searchNode == NULL)	// Tree is empty
	{
		return searchNode;
	}

	while (searchNode)
	{
		if (searchNode->value == value)
		{
			return searchNode;
		}
		else if (value <= searchNode->value)
		{
			searchNode = searchNode->left;
		}
		else
		{
			searchNode = searchNode->right;
		}
	}
	return searchNode;
}

void BST::preorderTraversal()
{
	NODE* start = root;
	preorder(root);
	root = start;
}

void BST::inorderTraversal()
{
	NODE* start = root;
	inorder(root);
	root = start;
}

void BST::postorderTraversal()
{
	NODE* start = root;
	postorder(root);
	root = start;
}

void BST::preorder(NODE* ptr)
{
	if (ptr != NULL)
	{
		cout << ptr->value << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void BST::inorder(NODE* ptr)
{
	if (ptr != NULL)
	{
		preorder(ptr->left);
		cout << ptr->value << " ";
		preorder(ptr->right);
	}
}

void BST::postorder(NODE* ptr)
{
	if (ptr != NULL)
	{
		preorder(ptr->left);
		preorder(ptr->right);
		cout << ptr->value << " ";
	}
}

int BST::getMin()
{
	NODE* ptr = root;

	if (ptr == NULL)
	{
		cout << "Tree is empty\n";
		return 0;
	}

	while (ptr->left)
	{
		ptr = ptr->left;
	}
	return ptr->value;
}

int BST::getMax()
{
	NODE* ptr = root;

	if (ptr == NULL)
	{
		cout << "Tree is empty\n";
		return 0;
	}

	while (ptr->right)
	{
		ptr = ptr->right;
	}
	return ptr->value;
}

int BST::getTreeLevel()
{
	NODE* ptr = root;
	getHeight(ptr);
	//TODO : Yet to implement
	return 0;
}

int BST::getHeight(NODE* node)
{
	if (node == NULL)// 1
		return 0;
	else//2
	{
		/* compute the depth of each subtree */
		int lDepth = getHeight(node->left);//2a, 2b
		int rDepth = getHeight(node->right);//3a, 3b

		/* use the larger one */
		if (lDepth > rDepth)	//4
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}

int BST::get2ndSmallestToGivenElement(int value)
{
	NODE* searchedElement = searchTree(value);

	if (searchedElement == NULL)
	{
		cout << "Element not found in Tree\n";
		return 0;
	}

	m_n2ndSmallest = searchedElement->value;

	if (searchedElement->left == NULL)
	{
		return m_n2ndSmallest;
	}
	else
	{
		m_nSmallest = searchedElement->left->value;
	}
	cout << "Came here\n";
	get2ndSmallest(searchedElement->left);
	return m_n2ndSmallest;
}

void BST::get2ndSmallest(NODE* ptr)
{
	if (ptr->left != NULL)
	{
		get2ndSmallest(ptr->left);
	}

	if (ptr->right != NULL)
	{
		get2ndSmallest(ptr->right);
	}

	if (ptr->value < m_nSmallest)
	{
		m_n2ndSmallest = m_nSmallest;
		m_nSmallest = ptr->value;
	}
	else if(ptr->value < m_n2ndSmallest)
	{
		m_n2ndSmallest = ptr->value;
	}
}
