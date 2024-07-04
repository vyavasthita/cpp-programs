#include <iostream>
#include <conio.h>
#include "Book.h"
#include "ClearScreen.h"
#include "File.h"
#include <ctime>


using namespace std;
enum Choice
{
	ISSUE_BOOK = 1,
	RETURN_BOOK,
	HELP,
	EXIT
};

enum BookIssue
{
	BY_BOOK_ID = 1,
	BY_BOOK_NAME
};

struct book
{
	int st_iBookID;
	char st_bookName[20];
	int st_totalBooks;
}bookInfo;

void Book::displayInfo()
{
	unsigned int uiChoice;

	Clear clearObj;
	clearObj.clearScreen();

	std::cout<<"Login Successfully\n\n";

	cout<<"Please Select A Choice : \n\n";
	cout<<"1. Issue a Book "<<endl;
	cout<<"2. Return a Book "<<endl;
	cout<<"3. Help "<<endl;
	cout<<"4. Exit "<<endl;

	cin>>uiChoice;

	switch(uiChoice)
	{
		case ISSUE_BOOK:
			{
				bookIssue();
				break;
			}
		case RETURN_BOOK:
			{
				returnBook();
				break;
			}
		case HELP:
			{
				clearObj.clearScreen();
				printBookDetails();	
				getch();
				displayInfo();
				break;
			}
		case EXIT:
			{
				return;
			}
		default:
			{
				cout<<"Wrong Choice"<<std::endl;
				break;
			}
	}
}

void Book::bookIssue()
{
	bool bResult = false;
	unsigned int uiChoice = 0;

	File fileObj;
	Clear clearObj;
	clearObj.clearScreen();

	cout<<"*****BOOK ISSUE*****"<<endl;
	cout<<"1. Search by Book ID"<<endl;
	cout<<"2. Search by Book Name"<<endl;
	
	cin>>uiChoice;

	clearObj.clearScreen();

	switch(uiChoice)
	{
		case BY_BOOK_ID:
			{	
				cout<<"Enter Book ID : ";
				cin>>bookInfo.st_iBookID;

				bResult = fileObj.findBookName(bookInfo.st_iBookID);

				if(bResult)
				{
					cout<<"Book Name is : "<<fileObj.getBookName().c_str()<<endl;
					setTotalBooks(bookInfo.st_iBookID);
				}
				else
				{
					cout<<"Book Not Found"<<endl;
					return;
				}
				
				break;
			}
		case BY_BOOK_NAME:
			{			
				int bookID = 0;

				cout<<"Enter Book Name : ";
				cin>>bookInfo.st_bookName;

				bResult = fileObj.findBookByName(bookInfo.st_bookName);
				if(bResult)
					{
						bookID = fileObj.getBookID(bookInfo.st_bookName);
						bookInfo.st_iBookID = bookID;
						setTotalBooks(bookID);
					}
				else
					{
						cout<<"Book Not Found"<<endl;
						return;
					}
				break;
			}
		default:
			{
				break;
			}
		}
			
		cout<<"total available books are : "<<getTotalBooks()<<endl;
		cout<<"Book issued successfully : "<<endl;
		cout<<"Date of Returning book is : "<<getDate(bookInfo.st_iBookID).c_str()<<endl;	
}
void Book::returnBook()
{
	bool bResult = false;
	unsigned int uiChoice = 0;

	File fileObj;
	Clear clearObj;
	clearObj.clearScreen();

	cout<<"*****BOOK RETURN*****"<<endl;
	cout<<"1. Provide Book ID"<<endl;
	cout<<"2. Provide Book Name"<<endl;
	cin>>uiChoice;

	clearObj.clearScreen();

	switch(uiChoice)
	{
		case BY_BOOK_ID:
			{		   				
				cout<<"Enter Book ID : ";
				cin>>bookInfo.st_iBookID;

				bResult = fileObj.findBookName(bookInfo.st_iBookID);

				if(bResult)
				{
					cout<<"Book Name is : "<<fileObj.getBookName().c_str()<<endl;
					setTotalBooks(bookInfo.st_iBookID);
				}
				else
				{
					cout<<"Book Not Found"<<endl;
					return;
				}
				
				break;
			}
		case BY_BOOK_NAME:
			{			
				int bookID = 0;
				cout<<"Enter Book Name : ";
				cin>>bookInfo.st_bookName;
				bResult = fileObj.findBookByName(bookInfo.st_bookName);
				if(bResult)
					{
						bookID = fileObj.getBookID(bookInfo.st_bookName);
						bookInfo.st_iBookID = bookID;
						setTotalBooks(bookID);
					}
				else
					{
						cout<<"Book Not Found"<<endl;
						return;
					}
				break;
			}
	}	

	cout<<"Date of Book Issue : "<<getDate(bookInfo.st_iBookID).c_str()<<endl;
	cout<<"Book Returned successfully on: "<<getCurrentTime()<<endl;
}

void Book::setTotalBooks(int bookID)
{
	switch(bookID)
	{
		case 1:
			{
				iTotalBooks = 1;
				break;
			}
		case 2:
			{
				iTotalBooks = 2;
				break;
			}
		case 3:
			{
				iTotalBooks = 3;
				break;
			}
		default:
			{
				break;
			}
	}
}

int Book::getTotalBooks()
{
	return iTotalBooks;
}

string Book::getDate(int bookID)
{
	string strDate;

	strDate += getDay(bookID);
	strDate += " ";
	strDate += getMonth(bookID);
	strDate += " ";
	strDate += getYear(bookID);
	
	return strDate;
}

string Book::getDay(int bookID)
{
	string strDay;

	switch(bookID)
	{
		case 1 :
			{
				strDay = "1";
				break;
			}
		case 2 :
			{
				strDay = "2";
				break;
			}
		case 3 :
			{
				strDay = "3";
				break;
			}
		default:
			break;
	}
	return strDay;
}

string Book::getMonth(int bookID)
{
	string strMonth;\

	switch(bookID)
	{
		case 1 :
			{
				strMonth = "Jan";
				break;
			}
		case 2 :
			{
				strMonth = "Feb";
				break;
			}
		case 3 :
			{
				strMonth = "Mar";
				break;
			}
		default:
			break;
	}
	return strMonth;
}

string Book::getYear(int bookID)
{
	string strYear;

	switch(bookID)
	{
		case 1 :
			{
				strYear = "2012";
				break;
			}
		case 2 :
			{
				strYear = "2013";
				break;
			}
		case 3 :
			{
				strYear = "2014";
				break;
			}
		default:
			break;
	}
	return strYear;
}
char * Book::getCurrentTime()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	return dt;
}
void Book::printBookDetails()
{
	File fileObj;
	bookMap = fileObj.getBookDetails();

	it = bookMap.begin();

	cout<<"Book ID\t"<<"Book Name\n\n";
	for(it; it != bookMap.end(); it++)
	{
		cout<<it->first<<"\t"<<it->second.c_str()<<endl;
	}
}