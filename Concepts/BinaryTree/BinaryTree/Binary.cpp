#include "Binary.h"

using namespace Binary;

BinaryTree::BinaryTree() : root(NULL)
{
}

BinaryTree::~BinaryTree()
{
	deleteTree(root);
}

void BinaryTree::deleteTree(struct Leaf*)
{
}

void BinaryTree::init()
{
	cout<<"Binary Tree Structure : "<<endl;
	choiceSelection();
}

void BinaryTree::choiceSelection()
{
	bool bIsExit = false;
	int iItem = 0;
	unsigned short usChoice = 0;

	while(!bIsExit)
	{
		cout<<"Select an Option : "<<endl;
		cout<<"1. Insertion"<<endl;
		cout<<"2. Deletion"<<endl;
		cout<<"3. Traverse"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>usChoice;

		switch(usChoice)
		{
			case INSERT:
			{
				cout<<"Enter an item to be added\n";
				cin>>iItem;

				insertLeaf(iItem);

				break;
			}

			case DELETE:
			{
				break;
			}

			case TRAVERSE:
			{
				traverseBinaryTree();
				break;
			}

			case EXIT:
			{
				bIsExit = true;
				break;				
			}
			default:
			{
				cout<<"Wrong Selection\n";
			}
		}
	}
}

void BinaryTree::insertLeaf(int leafItem)
{
	struct Leaf* newLeaf = new struct Leaf;

	newLeaf->data = leafItem;
	newLeaf->left = NULL;
	newLeaf->right = NULL;

	if(root == NULL)
	{
		root = newLeaf;
		start = root;
	}
	else
	{
	    while(true)
		{
			if(leafItem <= root->data)
			{
				if(root->left == NULL)
				{
					root->left = newLeaf;
					break;
				}
				else
				{
					root = root->left;
				}
			}
			else
			{
				if(root->right == NULL)
				{
					root->right = newLeaf;
					break;
				}
				else
				{
					root = root->right;
				}
			}
		}	
	}

	root = start;
	cout<<"Node Inserted Successfully\n";
}

void BinaryTree::traverseBinaryTree()
{
	bool bIsExit = false;
	unsigned short usChoice = 0;

	cout<<"Select The Traversing Method : "<<endl;
	cout<<"1. Preorder"<<endl;
	cout<<"2. Inorder"<<endl;
	cout<<"3. Postorder"<<endl;
	cout<<"4. Exit"<<endl;

	cin>>usChoice;

	switch(usChoice)
	{
		case PREORDER:
		{
			preorderTraversal(root);
			cout<<endl;
			break;
		}

		case INORDER:
		{
			InorderTraversal(root);
			cout<<endl;
			break;
		}

		case POSTORDER:
		{
			break;
		}

		case EXIT:
		{
	
			break;				
		}
		default:
		{
			cout<<"Wrong Selection\n";
		}
	}
}

void BinaryTree::preorderTraversal(struct Leaf* rootNode)
{
	struct Leaf* traversalNode = rootNode;

	if(traversalNode == NULL)
	{
		cout<<"Tree is empty :\n";
		return;
	}
	else
	{
		cout<<traversalNode->data<<" ";
		if(traversalNode->left != NULL)
		{
			preorderTraversal(traversalNode->left);
		}
		if(traversalNode->right != NULL)
		{
			preorderTraversal(traversalNode->right);
		}
	}
	root = start;
}

void BinaryTree::InorderTraversal(struct Leaf* rootNode)
{
	struct Leaf* traversalNode = rootNode;

	if(traversalNode == NULL)
	{
		cout<<"Tree is empty :\n";
		return;
	}
	else
	{
		if(traversalNode->left != NULL)
		{
			preorderTraversal(traversalNode->left);
		}
		cout<<traversalNode->data<<" ";
		if(traversalNode->right != NULL)
		{
			preorderTraversal(traversalNode->right);
		}
	}
	root = start;
}

void main()
{
	BinaryTree tree;
	tree.init();
	getch();
}