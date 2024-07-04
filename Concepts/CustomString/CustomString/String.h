#ifndef __STRING_H_
#define __STRING_H_

#include <iostream>
#include <stdexcept>

namespace MyCustomString
{
	class MyString
	{
		public:
			//Ctors
			MyString();
			MyString(const char* cpstr);
			MyString(const MyString& crstr);
			MyString(const MyString& crstr, unsigned int uiPos, unsigned int uiNPos = scnpos);
			MyString(const char* cpstr, unsigned int uiNpos);
			MyString(unsigned int uiN, char cCharRepet);
			~MyString();

			//Overloaded Operators
			MyString& operator = (const MyString& crstr);
			MyString& operator = (const char *cptr);
			MyString& operator = (char c);

			//to be done
			MyString MyOperatorPlus(const char* cpLHS, const char* cpRHS); 

			MyString operator + (const MyString& crstrRHS);
			MyString operator + (const char *cpRHS);
			MyString operator + (char cRHS);

			friend MyString operator + (const char *cpLHS, const MyString& crstrRHS);
			friend MyString operator + (char cLHS, const MyString& crstrRHS);


			MyString& operator += (const MyString& crstr);
			MyString& operator += (const char *cptr);
			MyString& operator += (char c);

			bool operator == (const MyString& crstr);
			char& operator [] (size_t pos);
			friend std::ostream& operator << (std::ostream& stream, const MyString& crstr);
			

			//Capasity
			unsigned int size(const char* cptr);
			unsigned int size();
			size_t length();		
			void resize(size_t n);
			void resize(size_t n, char c);

			void clear();
			bool empty();
			char& at(size_t pos);

			//Modifiers
			MyString& append(const char *cptr);
			MyString& append(const MyString& crstr);
			MyString& append(const MyString& crstr, unsigned int uiPos, unsigned int uiN);
			MyString& append(const char *cptr, unsigned int uiN);
			MyString& append(unsigned int uiN, char c);

			void push_back(char c);

			MyString& MyAssign(const char *cptr, unsigned int uiPos, unsigned int uiN);
			MyString& assign(const MyString& crstr);
			MyString& assign(const MyString& crstr, unsigned int uiPos, unsigned int uiN);
			MyString& assign(const char *cptr, unsigned int uiN);
			MyString& assign(const char *cptr);
			MyString& assign(unsigned int uiN, char c);

			MyString& MyInsert(unsigned int uiPos1, const char *cptr, unsigned int uiPos2, unsigned int uiN);
			MyString& insert(unsigned int uiPos, const MyString& crstr);
			MyString& insert(unsigned int uiPos1, const MyString& crstr, unsigned int uiPos2, unsigned int uiN);
			MyString& insert(unsigned int uiPos1, const char *cptr, unsigned int uiN);
			MyString& insert(unsigned int uiPos, const char *cptr);
			MyString& insert(unsigned int uiPos, unsigned int uiN, char c);

			void swap(MyString &rstr);
			//String Operation
			MyString substr(unsigned int uiPos = 0, unsigned int uiNPos = scnpos);

			int compare(const MyString &crstr);
			int compare(const char *cptr);
			int compare(unsigned int uiPos1, unsigned int uiN, const MyString &crstr);
			int compare(unsigned int uiPos1, unsigned int uiN, const char *cptr);
			int compare(unsigned int uiPos1, unsigned int uiN, const MyString &crstr, unsigned int uiPos2, unsigned int uiN2);
			int compare(unsigned int uiPos1, unsigned int uiN, const char *cptr, unsigned int uiN2);

			//Others
			MyString& CopyCtor(const char *cptr);
			void myStrCpy(char* pstr, const char* source);
		
		private:
			char* ptr;
			unsigned int muiSize;	
			static const unsigned int scnpos;
	};
};
#endif __STRING_H_


