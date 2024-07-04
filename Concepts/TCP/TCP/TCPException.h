#ifndef __TCP_EXP_
#define __TCP_EXP_

namespace TCPComm
{
	class CTCPException
	{
		public:
			CTCPException(const char* const_pcErrorMsg);
			const char* GetErrorMsg();
		private:
			const char *m_const_pcErrorMsg;
	};
};
#endif __TCP_EXP_