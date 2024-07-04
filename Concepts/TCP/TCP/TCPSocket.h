#ifndef __TCP_SOCKET_
#define __TCP_SOCKET_

#include <WinSock2.h>
#include <iostream>

namespace TCPComm
{
	class CMySocket
	{
		public:
			CMySocket(int nPortNumber);

			virtual ~CMySocket()
			{
				closesocket(m_nSocketId);
			}

			int	GetSocketId()
			{
				return m_nSocketId;
			}

			int	GetPortNumber()
			{
				return m_nPortNumber;
			}

		protected:
			/*
			 * only used when the socket is used for client communication
			 * once this is done, the next necessary call is SetSocketId(int)
			 */
			CMySocket() 
			{
			}

			void SetSocketId(int nSocketId) 
			{ 
				m_nSocketId = nSocketId; 
			}

		protected:
			int m_nPortNumber;        // Socket port number    
			int m_nSocketId;          // Socket file descriptor

			int m_nBlocking;          // Blocking flag
			int m_nBindFlag;          // Binding flag

			struct sockaddr_in m_st_ClientAddr;    // Address of the client that sent data

		private:
			char* GetOpenWinSocketErrorMsg();
			char* GetGetSocketOptionErrorMsg();
	};

	class CTCPSocket : public CMySocket 
	{
		public:
			CTCPSocket()
			{
			};

			~CTCPSocket()
			{
			};

			// Constructor.  Used to create a new TCP socket given a port
			CTCPSocket(int nPortNumber) : CMySocket(nPortNumber) 
			{ 
			};

			/*
			 *  Sends a message to a connected host. The number of bytes sent is returned
			 *  can be either server call or client call
			 */
			int SendMessage(std::string & r_strMsg);

			/*
			   receive messages and stores the message in a buffer
			*/
			int RecieveMessage(std::string & r_strMsg);

			/*
			   Binds the socket to an address and port number
			   a server call
			*/
			void BindSocket();

			/*
			 *  accepts a connecting client.  The address of the connected client 
			 *  is stored in the parameter
			 *  a server call
			 */
			CTCPSocket* AcceptClient(std::string& r_strClientAddr);

			// Listens to connecting clients, a server call
			void ListenToClient(int nNumPorts = 5);

			// connect to the server, a client call
			virtual void ConnectToServer(const std::string &const_r_strServerName);		

		private:
			char* GetBindErrorMsg();
			char* GetSendErrorMsg();
			char* GetRecvErrorMsg();
			char* GetConnectErrorMsg();
			char* GetAcceptErrorMsg();
			char* GetListenErrorMsg();
	};
};

#endif __TCP_SOCKET_