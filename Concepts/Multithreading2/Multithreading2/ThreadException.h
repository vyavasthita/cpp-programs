#include <iostream>
#include <exception>

#ifndef __THREAD_EXCP_H_
#define __THREAD_EXCP_H_

namespace MyThread
{
	class ThreadException : public std::exception
	{
		public:
			ThreadException(const char *const_pcErrorMsg);
			virtual ~ThreadException();

			virtual const char* what() const throw();

		protected:
			const char *m_const_pcErrorMessage;
	};
};

#endif __THREAD_EXCP_H_