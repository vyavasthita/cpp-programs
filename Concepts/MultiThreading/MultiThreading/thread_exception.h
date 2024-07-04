#include <iostream>

class ThreadException
{
	public:
		ThreadException();
		ThreadException(const char* errorMsg);

		virtual ~ThreadException();

		const char* getErrorMsg() const;

	private:
		const char* m_const_cErrorMsg;
};