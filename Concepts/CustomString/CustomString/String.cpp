#include "String.h"
#include "StringExceptionHandle.h"

#define ZERO 0
#define ONE 1
#define SPACE ' '

using namespace MyCustomString;

const unsigned int MyString::scnpos = 4294967295;

MyString::MyString() : muiSize(0), ptr(NULL)
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
	CopyCtor(crstr.ptr);
}

MyString::MyString(const MyString& crstr, unsigned int uiPos, unsigned int uiNPos)
{
	MyString tempString(crstr);
	
	MyString myStr = tempString.substr(uiPos, uiNPos);

	unsigned int uiSubStrSize = myStr.size(); 

	ptr = new char[uiSubStrSize + ONE];

	myStrCpy(ptr, myStr.ptr);

}

MyString::MyString(const char* cpstr, unsigned int uiNpos)
{
	MyString tempString(cpstr);
	
	MyString myStr = tempString.substr(0, uiNpos);

	unsigned int uiSubStrSize = myStr.size(); 

	ptr = new char[uiSubStrSize + ONE];

	myStrCpy(ptr, myStr.ptr);
}

MyString::MyString(unsigned int uiN, char cCharRepet) : ptr(NULL)
{
	resize(uiN, cCharRepet);
}

MyString::~MyString()
{
	if(ptr != NULL)
	{
		delete [] ptr;
	}
}

//Others

MyString& MyString::CopyCtor(const char *cptr)
{
	unsigned int uiSize = size(cptr);
	unsigned int uiIterator = 0;

	ptr = new char[uiSize + ONE];

	for( uiIterator; uiIterator < uiSize; uiIterator++)
	{
		ptr[uiIterator] = cptr[uiIterator];
	}
	ptr[uiIterator] = NULL;
	return (*this);
}

void MyString::myStrCpy(char* str, const char* source)
{
	unsigned int uiIterator = 0;

	ptr = new char[size(source) + ONE];

	for(uiIterator; uiIterator < size(source); ++uiIterator)
	{
		ptr[uiIterator] = source[uiIterator];
	}
	ptr[uiIterator] = NULL;
}

//Capacity

unsigned int MyString::size(const char* cptr)
{
	size_t uiLength = 0;

	if(cptr == NULL)
	{
		return 0;
	}

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
	unsigned int uiIterator = 0;

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

	for(uiIterator; uiIterator < new_size; ++uiIterator)
	{
		if(uiIterator >= old_size)
		{
			ptr[uiIterator] = c;
		}
		else
		{
			ptr[uiIterator] = temp[uiIterator];
		}
	}
	ptr[uiIterator] = NULL;
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

MyString& MyString::operator = (const char *cptr)
{
	return (MyAssign(cptr, 0, size(cptr)));
}

MyString& MyString::operator = (const MyString &str)
{
	return (assign(str));
}

MyString& MyString::operator = (char c)
{
	ptr = NULL;
	resize(1, c);
	return (*this);
}

MyString MyString::MyOperatorPlus(const char* cpLHS, const char* cpRHS)
{
	char *cpResult = NULL;
	unsigned int uiIterator = 0;
	unsigned int uiSizeLHS = size(cpLHS);
	unsigned int uiSizeRHS = size(cpRHS);

	cpResult = new char[uiSizeLHS + uiSizeRHS + ONE];

	for(uiIterator; uiIterator < uiSizeLHS; uiIterator++)
	{
		cpResult[uiIterator] = cpLHS[uiIterator];
	}
	
	for(unsigned int uiIterator2 = 0; uiIterator2 < uiSizeRHS; uiIterator2++)
	{
		cpResult[uiIterator++] = cpRHS[uiIterator2];
	}
	cpResult[uiIterator] = NULL;

	MyString tempStr(cpResult);
	return (tempStr);
}

MyString MyString::operator + (const MyString& crstrRHS)
{
	MyString tempMyStr = NULL;

	tempMyStr = MyOperatorPlus(ptr, crstrRHS.ptr);

	return (tempMyStr);
}

MyString operator + (const char *cpLHS, const MyString &crstrRHS)
{
	MyString tempMyStr;

	//to be done

	return (tempMyStr);
}

MyString operator + (char cLHS, const MyString &crstrRHS)
{
	MyString tempMyStr;
	//to be done

	return (tempMyStr);
}

MyString MyString::operator + (const char *cpRHS)
{
	MyString tempMyStr = NULL;

	tempMyStr = MyOperatorPlus(ptr, cpRHS);

	return (tempMyStr);
}

MyString MyString::operator + (char cRHS)
{
	MyString tempMyStr = NULL;
	MyString myStrLHS = NULL;
	myStrLHS = cRHS;

	tempMyStr = MyOperatorPlus(ptr, myStrLHS.ptr);

	return (tempMyStr);
}

MyString& MyString::operator += (const MyString &str)
{
	return (*this);
}

MyString& MyString::operator += (const char *cptr)
{
	MyString myStr;
	myStr = myStr.MyOperatorPlus(ptr, cptr);
	return (myStr);
}

MyString& MyString::operator += (char c)
{
	MyString myStr;

	myStr.resize(ONE, c);
	return (myStr);
}

std::ostream& operator << (std::ostream& stream, const MyString& str)
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
	unsigned int uiStringSize = size();

	if(uiPos > uiStringSize)
	{
		throw StringException::SUBSTRING_SUBSRICT_OUT_OF_RANGE;
	}

	unsigned int uiIterator = 0;	
	unsigned int uiSubStringSize = 0;

	if(uiNPos >= uiStringSize)
	{
		uiSubStringSize = uiStringSize;
	}
	else
	{
		uiSubStringSize = uiNPos;
	}

	char* tempPtr = new char[uiSubStringSize + ONE];
	
	for(uiIterator; uiIterator < uiSubStringSize; uiIterator++)
	{
		tempPtr[uiIterator] = ptr[uiPos++];
	}
	
	tempPtr[uiIterator] = NULL;

	MyString str(tempPtr);
	delete [] tempPtr;
	return str;
}

int MyString::compare(const MyString &crstr)
{
	int iCompResult = compare(crstr.ptr);
	return (iCompResult);
}

int MyString::compare(const char *cptr)
{
	int iCompResult = 0;

	for(unsigned int uiIterator = 0; (uiIterator < size() || uiIterator < size(cptr)); uiIterator++)
	{
		if(ptr[uiIterator] < cptr[uiIterator])
		{
			iCompResult = -1;
		}
		else if(ptr[uiIterator] > cptr[uiIterator])
		{
			iCompResult = 1;
		}
	}
	return (iCompResult);
}

int MyString::compare(unsigned int uiPos1, unsigned int uiN, const MyString &crstr)
{
	int iCompResult = 0;

	MyString myStr = substr(uiPos1, uiN);
	iCompResult = myStr.compare(crstr.ptr);
	return (iCompResult);
}

int MyString::compare(unsigned int uiPos1, unsigned int uiN, const char *cptr)
{
	int iCompResult = 0;

	MyString myStr = substr(uiPos1, uiN);
	iCompResult = myStr.compare(cptr);

	return (iCompResult);
}

int MyString::compare(unsigned int uiPos1, unsigned int uiN, const MyString &crstr, unsigned int uiPos2, unsigned int uiN2)
{
	int iCompResult = 0;

	MyString temp(crstr);
	MyString myStr1 = substr(uiPos1, uiN);
	MyString myStr2 = temp.substr(uiPos2, uiN2);

	iCompResult = myStr1.compare(myStr2.ptr);

	return (iCompResult);
}

int MyString::compare(unsigned int uiPos1, unsigned int uiN, const char *cptr, unsigned int uiN2)
{
	int iCompResult = 0;

	MyString temp(cptr);
	MyString myStr1 = substr(uiPos1, uiN);
	MyString myStr2 = temp.substr(0, uiN2);

	iCompResult = myStr1.compare(myStr2.ptr);

	return (iCompResult);
}

//Modifiers

MyString& MyString::append(const char *cptr)
{
	MyString myStr;

	myStr = myStr.MyOperatorPlus(ptr, cptr);
	return (myStr);
}

MyString& MyString::append(const MyString& crstr)
{
	MyString myStr;

	myStr = myStr.MyOperatorPlus(ptr, crstr.ptr);
	return (myStr);
}

MyString& MyString::append(const MyString& crstr, unsigned int uiPos, unsigned int uiN)
{
	MyString myStr;
	MyString myStrTemp(crstr);

	myStrTemp = myStrTemp.substr(uiPos, uiN);
	myStr = myStr.MyOperatorPlus(ptr, myStrTemp.ptr);

	return (myStr);
}

MyString& MyString::append(const char *cptr, unsigned int uiN)
{
	MyString myStr;
	MyString myStrTemp(cptr);

	myStrTemp = myStrTemp.substr(0, uiN);
	myStr = myStr.MyOperatorPlus(ptr, myStrTemp.ptr);

	return (myStr);
}

MyString& MyString::append(unsigned int uiN, char c)
{
	MyString myStr;
	MyString myStrTemp;

	myStrTemp.resize(uiN, c);
	
	myStr = myStr.MyOperatorPlus(ptr, myStrTemp.ptr);

	return (myStr);
}
		
void MyString::push_back(char c)
{
	MyString myStr;
	myStr = c;

	MyOperatorPlus(ptr, myStr.ptr);
}

MyString& MyString::MyAssign(const char *cptr, unsigned int uiPos, unsigned int uiN)
{
	delete [] ptr;

	MyString myStr(cptr);
	myStr = myStr.substr(uiPos, uiN);

	return (CopyCtor(myStr.ptr));
}

MyString& MyString::assign(const MyString& crstr)
{
	if(this == &crstr)
	{
		return (*this);
	}

	return (CopyCtor(crstr.ptr));
}

MyString& MyString::assign(const MyString& crstr, unsigned int uiPos, unsigned int uiN)
{
	return (MyAssign(crstr.ptr, uiPos, uiN));
}

MyString& MyString::assign(const char *cptr, unsigned int uiN)
{
	return (MyAssign(cptr, 0, uiN));
}

MyString& MyString::assign(const char *cptr)
{
	return (MyAssign(cptr, 0, size(cptr)));
}

MyString& MyString::assign(unsigned int uiN, char c)
{
	MyString myStr;
	myStr = c;

	return (MyAssign(myStr.ptr, 0, myStr.size()));
}

MyString& MyString::insert(unsigned int uiPos, const char *cptr)
{
	unsigned int uiSubStrSize = size(cptr);
	unsigned int uiStrOldSize = size();

	resize(uiSubStrSize);		// resize the *this

	unsigned int uiStrNewSize = size();

	for(unsigned int uiIterator = uiStrNewSize - ONE; uiIterator > (uiStrOldSize - uiPos); uiIterator--)
	{
		ptr[uiIterator] = ptr[uiIterator - uiPos];
	}

	for(unsigned int uiIterator = 0; uiIterator < uiSubStrSize; uiIterator++)
	{
		ptr[uiPos] = cptr[uiIterator];
	}

	return (*this);
}

MyString& MyString::insert(unsigned int uiPos1, const MyString& crstr, unsigned int uiPos2, unsigned int uiN)
{
	MyString mySubString(crstr);

	mySubString = mySubString.substr(uiPos2, uiN);

	return (insert(uiPos1, mySubString.ptr));
}

MyString& MyString::insert(unsigned int uiPos, const MyString& crstr)
{
	return (insert(uiPos, crstr.ptr));
}

MyString& MyString::insert(unsigned int uiPos1, const char *cptr, unsigned int uiN)
{
	MyString mySubString(cptr);

	mySubString = mySubString.substr(ZERO, uiN);

	return (insert(uiPos1, mySubString.ptr));
}

MyString& MyString::insert(unsigned int uiPos, unsigned int uiN, char c)
{
	return (insert(uiPos, assign(uiN, c)));
}

void MyString::swap(MyString &rstr)
{
	MyString myStrTemp(ptr);

	delete [] ptr;
	ptr = NULL;

	myStrCpy(ptr, rstr.ptr);
	myStrCpy(rstr.ptr, myStrTemp.ptr);
}