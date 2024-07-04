#include <iostream>
#include <exception>


class MyException : public std::exception
{
	public:
		MyException();

		//MyException(char *errorMsg);
		MyException(const char *const_pcErrorMsg);

		//~MyException();
		virtual ~MyException() throw();

		void expFunction();

		//char* getErrorMsg();

		virtual const char* what() const throw();

	private:
		const char *m_const_pcErrorMessage;
};