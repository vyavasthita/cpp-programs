#include "String.h"
#include "StringExceptionHandle.h"

#define ZERO 0
#define ONE 1
#define SPACE ' '

using namespace MyCustomString;

const unsigned int MyString::scnpos = 4294967295;


MyString::MyString() : muiSize(0)
{
	muiSize = ONE;

	try
	{
		ptr = new char[muiSize];
	}
	catch(std::bad_alloc error)
	{
		std::cout<<"Memory Allocation Error\n";
	}
	myStrCpy(ptr,"");
}

MyString::MyString(const char* cpstr)
{
	try
	{
		ptr = new char[size(cpstr) + ONE];
	}
	catch(std::bad_alloc error)
	{
		std::cout<<"Memory Allocation Error\n";
	}
	
	myStrCpy(ptr, cpstr);
}

MyString::MyString(const MyString& crstr)
{
	CopyCtor(crstr);
}

MyString::MyString(const MyString& crstr, unsigned int uiPos, unsigned int uiNPos)
{
	//same as substr
}

MyString::~MyString()
{
}

//Others

MyString& MyString::CopyCtor(const MyString &crstr)
{
	unsigned int uiSize = size(crstr.ptr);
	unsigned int uiIterator = 0;

	ptr = new char[uiSize + ONE];

	for( uiIterator; uiIterator < uiSize - ONE; uiIterator++)
	{
		ptr[uiIterator] = crstr.ptr[uiIterator];
	}
	ptr[uiIterator] = NULL;
	return (*this);
}

void MyString::myStrCpy(char* str, const char* source)
{
	int iIterator = 0;

	for(iIterator; iIterator < size(source); ++iIterator)
	{
		ptr[iIterator] = source[iIterator];
	}
	ptr[iIterator] = NULL;
}

//Capacity

unsigned int MyString::size(const char* cptr)
{
	size_t uiLength = 0;

	while(*cptr != NULL)
	{
		++uiLength;
		++cptr;
	}
	return (uiLength);
}

unsigned int MyString::size()
{
	unsigned int uiLength = size(ptr);
	return (uiLength);
}

size_t MyString::length()
{
	size_t uiLength = size();
	return (uiLength);
}

void MyString::resize(size_t n)
{
	resize(n, SPACE);
}

void MyString::resize(size_t n, char c)
{
	char* temp = ptr;
	bool bIsBig = false;
	int iIterator = 0;

	size_t old_size = size(ptr);
	size_t new_size = 0;

	if(n > old_size)
	{
		new_size = old_size + n;
	}
	else
	{
		new_size = n;
	}

	ptr = new char[new_size + ONE];

	for(iIterator; iIterator < new_size; ++iIterator)
	{
		if(iIterator >= old_size)
		{
			ptr[iIterator] = c;
		}
		else
		{
			ptr[iIterator] = temp[iIterator];
		}
	}
	ptr[iIterator] = NULL;
	delete [] temp;
}

void MyString::clear()
{
	resize(ZERO);
}

bool MyString::empty()
{
	bool bIsEmpty = false;
	size_t uiSize = size();

	if(uiSize == 0)
	{
		bIsEmpty = true;
	}
	return (bIsEmpty);
}

//Overloaded Operator
bool MyString::operator == (const MyString& crstr)
{
	bool bIsEqual = true;

	while(ptr != NULL && crstr.ptr != NULL)
	{
		if(*ptr != *crstr.ptr)
		{
			bIsEqual = false;
			break;
		}
	}
	return (bIsEqual);
}

MyString& MyString::operator = (const MyString &str)
{
	if(this == &str)
	{
		return (*this);
	}

	delete [] ptr;

	unsigned int uiIterator = 0;

	unsigned int uiSize = size(str.ptr);
	ptr = new char[uiSize + ONE];

	for(uiIterator; uiIterator < uiSize; uiIterator++)
	{ 
		ptr[uiIterator] = str.ptr[uiIterator];
	}
	ptr[uiIterator] = NULL;
	return(*this);
}

MyString& MyString::operator += (const MyString &str)
{
	(*this) += str.ptr;
	return (*this);
}

MyString& MyString::operator += (const char *cptr)
{
	char *oldPtr = ptr;
	int iIterator = 0;

	size_t oldSize = size(ptr);
	size_t newSize = oldSize + size(cptr) + ONE;

	ptr = new char[newSize];

	for(iIterator; iIterator < oldSize; iIterator++)
	{
		ptr[iIterator] = oldPtr[iIterator];
	}

	for(int iIterator2 = 0; iIterator2 < size(cptr); iIterator2++)
	{
		ptr[iIterator++] = cptr[iIterator2];
	}

	ptr[iIterator] = NULL;
	delete [] oldPtr;

	return(*this);
}

MyString& MyString::operator += (char c)
{
	char * oldPtr = ptr;
	int iIterator = 0;

	size_t oldSize = size(ptr);
	size_t newSize = oldSize + ONE + ONE;

	ptr = new char[newSize];

	for(iIterator; iIterator < oldSize; iIterator++)
	{
		ptr[iIterator] = oldPtr[iIterator];
	}

	ptr[iIterator++] = c;
	ptr[iIterator] = NULL;

	return (*this);
}

std::ostream& MyCustomString::operator << (std::ostream& stream, const MyString& str)
{
	stream << str.ptr;
	return (stream);
}

char& MyString::operator [] (size_t pos)
{
	try
	{
		return (ptr[pos]);
	}
	catch(std::out_of_range ex)
	{
		std::cout<<ex.what();
	}
}

char& MyString::at(size_t pos)
{
	if(pos > size() || pos < ZERO)
	{
		throw StringException::STRING_SUBSRICT_OUT_OF_RANGE;
	}
	return (ptr[pos]);
}


//String Operation

MyString MyString::substr(unsigned int uiPos, unsigned int uiNPos)
{
	unsigned int uiIterator = 0;
	unsigned int uiStringSize = size();
	unsigned int uiSubStringSize = 0;
	
	char* tempPtr;

	if(uiPos > uiStringSize)
	{
		throw StringException::SUBSTRING_SUBSRICT_OUT_OF_RANGE;
	}

	if(uiNPos >= uiStringSize)
	{
		uiSubStringSize = uiStringSize - uiPos;
	}
	else
	{
		uiSubStringSize = uiNPos - uiPos + ONE;
	}

	tempPtr = new char[uiSubStringSize + ONE];
	
	while(uiSubStringSize--)
	{
		tempPtr[uiIterator++] = ptr[uiPos++];
	}
	
	tempPtr[uiIterator] = NULL;
	return tempPtr;
}

int MyString::compare(const MyString &str)
{
	int iCompResult = 0;
	return (iCompResult);
}

int MyString::compare(const char *s)
{
	int iCompResult = 0;

	for(unsigned int uiIterator = 0; (uiIterator < size() || uiIterator < size(s)); uiIterator++)
	{
		if(ptr[uiIterator] < s[uiIterator])
		{
			iCompResult = -1;
		}
		else if(ptr[uiIterator] > s[uiIterator])
		{
			iCompResult = 1;
		}
	}
	return (iCompResult);
}

int MyString::compare(unsigned int uiPos1, unsigned int uiN, const MyString &str)
{
	int iCompResult = 0;
	MyString strTemp;
	strTemp = substr(uiPos1, uiN);

	iCompResult = strTemp.compare(strTemp.ptr);
	return (iCompResult);
}

int MyString::compare(unsigned int uiPos1, unsigned int uiN, const char *s)
{
	int iCompResult = 0;
	MyString strTemp = NULL;

	strTemp = substr(uiPos1, uiN);
	iCompResult = strTemp.compare(s);

	return (iCompResult);
}

int MyString::compare(unsigned int uiPos1, unsigned int uiN, const MyString &str, unsigned int uiPos2, unsigned int uiN2)
{
	int iCompResult = 0;
	return (iCompResult);
}

int MyString::compare(unsigned int uiPos1, unsigned int uiN, const char *s, unsigned int uiN2)
{
	int iCompResult = 0;
	return (iCompResult);
}

