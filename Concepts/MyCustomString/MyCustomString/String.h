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
			MyString(const MyString& crstr, unsigned int uiPos = 0, unsigned int uiNPos = scnpos);
			MyString(const char* cpstr, unsigned int uiNpos);
			~MyString();

			//Overloaded Operators
			MyString& operator = (const MyString& crstr);
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
			MyString& append(const MyString& crstr);

			//String Operation
			MyString substr(unsigned int uiPos = 0, unsigned int uiNPos = scnpos);
			int compare(const MyString &str);
			int compare(const char *s);
			int compare(unsigned int uiPos1, unsigned int uiN, const MyString &str);
			int compare(unsigned int uiPos1, unsigned int uiN, const char *s);
			int compare(unsigned int uiPos1, unsigned int uiN, const MyString &str, unsigned int uiPos2, unsigned int uiN2);
			int compare(unsigned int uiPos1, unsigned int uiN, const char *s, unsigned int uiN2);

			//Others
			MyString& CopyCtor(const MyString & crstr);
			void myStrCpy(char* pstr, const char* source);
		
		private:
			char* ptr;
			unsigned int muiSize;	
			static const unsigned int scnpos;
	};
};
#endif __STRING_H_


