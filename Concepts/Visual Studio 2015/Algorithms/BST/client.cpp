#include "file.h"
#include <conio.h>

using namespace std;
using namespace Algorithms;


void userInput()
{
	int userInput = 0;
	int result = NULL;
	bool bContinue = true;
	bool bContinueTraversal = true;
	BST oBST;

	while (bContinue)
	{
		cout << "Please select a choice ...\n\n";
		cout << "1. Add a node.\n";
		cout << "2. Delete a node.\n";
		cout << "3. Search Data.\n";
		cout << "4. Traversal Data.\n";
		cout << "5. Min.\n";
		cout << "6. Max.\n";
		cout << "7. Height.\n";
		cout << "8. 2nd Smallest.\n";
		cout << "9. Exit.\n\n";

		cin >> userInput;

		switch (userInput)
		{
		case CHOICE::ADD:
			cout << "Enter a value to add -->";
			cin >> userInput;
			if (oBST.addNode(userInput))
			{
				cout << "\n Value " << userInput << " added successfully\n";
			}
			break;
		case CHOICE::DELETE:
			cout << "Enter a value to delete -->";
			cin >> userInput;
			if (oBST.deleteNode(userInput))
			{
				cout << "\nValue " << userInput << " deleted successfully\n";
			}
			else
			{
				cout << "\nValue " << userInput << " not found in Tree\n";
			}
			break;
		case CHOICE::SEARCH:
			cout << "Enter a value to search -->";
			cin >> userInput;
			if (oBST.searchTree(userInput) != NULL)
			{
				cout << "Value Found in tree\n";
			}
			else
			{
				cout << "Value NOT Found in tree\n";
			}
			break;
		case CHOICE::TRAVERSAL:	
			bContinueTraversal = true;
			while (bContinueTraversal)
			{
				cout << "\nPlease select a Travasal ...\n\n";
				cout << "1. Preorder.\n";
				cout << "2. Inorder.\n";
				cout << "3. Postorder.\n";
				cout << "4. Back.\n";

				cin >> userInput;

				switch (userInput)
				{
				case TRAVERSAL::PREORDER:
					oBST.preorderTraversal();
					cout << endl << endl;
					break;
				case TRAVERSAL::INORDER:
					oBST.inorderTraversal();
					cout << endl << endl;
					break;
				case TRAVERSAL::POSTORDER:
					oBST.postorderTraversal();
					cout << endl << endl;
					break;
				case TRAVERSAL::BACK:
					bContinueTraversal = false;
					break;
				default:
					cout << "Invalid Choice\n\n";
					break;
				}
				break;
		case CHOICE::MIN:
			cout << "Min is : " << oBST.getMin() << endl;		
			break;

		case CHOICE::MAX:
			cout << "Max is : " << oBST.getMax() << endl;
			break;
		case CHOICE::HEIGHT:
			break;
		case CHOICE::SECOND_SMALLEST:
			cout << "Enter a value to find 2nd smallest -->";
			cin >> userInput;
			
			result = oBST.get2ndSmallestToGivenElement(userInput);

			if (result != NULL)
			{
				cout << "2nd Smallest element to value :" << userInput << ": is " << result << endl;
			}
			else
			{
				cout << "Value not Found in tree\n";
			}
			break;
		case CHOICE::EXIT:
			cout << "Going to EXIT...";
			bContinue = false;
			break;

		default:
			cout << "Invalid Choice\n\n";
			break;
			}
		}
	}
}

int main()
{
	userInput();

	_getch();
	return 0;
}