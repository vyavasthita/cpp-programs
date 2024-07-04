#include <iostream>
#include <exception>


#ifndef __EXCP_H_
#define __EXCP_H_

namespace ThreadNameSpace
{
	class CThreadException : public std::exception
	{
		public:
			CThreadException(const char* cpThreadException);
			virtual ~CThreadException();

			virtual const char* what() const throw();

		private:
			const char* m_const_cpThreadException;
	};

	class CFileException : public std::exception
	{
		public:
			CFileException(const char* cpFileException);
			virtual ~CFileException();

			virtual const char* what() const throw();

		private:
			const char* m_const_cpFileException;
	};
};

#endif __EXCP_H_ 