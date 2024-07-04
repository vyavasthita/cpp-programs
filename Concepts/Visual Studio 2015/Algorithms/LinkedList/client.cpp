#include "file.h"
#include <conio.h>

using namespace std;
using namespace Algorithms;

void userInput()
{
	int userInput = 0;
	bool bContinue = true;

	LinkedList linkedList;

	while (bContinue)
	{
		cout << "Please select a choice ...\n\n";
		cout << "1. Add a node.\n";
		cout << "2. Delete a node.\n";
		cout << "3. Reverse Data.\n";
		cout << "4. Print Data.\n";
		cout << "5. Exit.\n\n";

		cin >> userInput;

		switch (userInput)
		{
		case CHOICE::ADD:
			cout << "Enter a value to add -->";
			cin >> userInput;
			linkedList.addNode(userInput);
			break;
		case CHOICE::DELETE:
			cout << "Enter a value to delete -->";
			cin >> userInput;
			linkedList.deleteNode(userInput);
			break;
		case CHOICE::REVERSE:
			linkedList.reverseList();
			break;
		case CHOICE::PRINT:
			cout << "Available data : \n";
			linkedList.printData();
			break;
		case CHOICE::EXIT:
			bContinue = false;
			break;

		default:
			cout << "Invalid Choice\n\n";
			break;
		}
	}
}

int main()
{
	userInput();

	_getch();
	return 0;
}