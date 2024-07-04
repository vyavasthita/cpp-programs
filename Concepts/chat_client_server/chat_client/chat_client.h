/***
		Chat Client 
						***/
#include<iostream>
#include<conio.h>
#include <winsock2.h>

class Client
{
	public:
		Client();
		~Client();

		void initialize(std::string strIPAddress, int iPort);
		int sendMessage(std::string strMessage);
		int recMessage();

		bool isConnected()
		{
			return m_bIsConnected;
		}
	private:
		bool m_bIsConnected;
		std::string m_strServerIPAddress;
		int m_iServerPort;
		SOCKET conn; // socket connected to server
};