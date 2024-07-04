#include <iostream>
#include <conio.h>

using namespace std;

namespace Binary
{
	enum CHOICE
	{
		INSERT = 1,
		DELETE,
		TRAVERSE,
		EXIT
	};

	enum Traverse
	{
		PREORDER = 1,
		INORDER,
		POSTORDER
	};

	struct Leaf
	{
		int data;
		struct Leaf* left;
		struct Leaf* right;
	};

	class BinaryTree
	{
		public:
			BinaryTree();
			~BinaryTree();

			void init();
			void choiceSelection();

			void insertLeaf(int leafItem);
			void traverseBinaryTree();
			void preorderTraversal(struct Leaf*);
			void InorderTraversal(struct Leaf*);
			void deleteTree(struct Leaf*);

		private:
			struct Leaf* root;
			struct Leaf* start;
	};
};