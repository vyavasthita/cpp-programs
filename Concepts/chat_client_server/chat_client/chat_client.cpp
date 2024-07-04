#include "chat_client.h"
#include <fstream>

using namespace std;
Client::Client()
{
	m_bIsConnected = false;
}
Client::~Client()
{
	if(m_bIsConnected)
		closesocket(conn);
}

void Client::initialize(std::string strIPAddress, int iPort)
{
	m_strServerIPAddress = strIPAddress;
	m_iServerPort = iPort;

	struct hostent *hp;
	unsigned int addr;
	struct sockaddr_in server;

	WSADATA wsaData;

	int wsaret = WSAStartup(0x101, &wsaData);


	if(wsaret!=0)
	{
		return;
	}

	conn = socket(AF_INET,SOCK_STREAM, 0);
	if(conn == INVALID_SOCKET)
	{
		return;
	}

	addr = inet_addr(m_strServerIPAddress.c_str());
	hp = gethostbyaddr((char*)&addr, sizeof(addr), AF_INET);
	
	if(hp == NULL)
	{
		closesocket(conn);
		return;
	}

	server.sin_addr.s_addr=*((unsigned long*)hp->h_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(m_iServerPort);
	if(connect(conn, (struct sockaddr*)&server ,sizeof(server)))
	{
		closesocket(conn);
		return;	
	}
	m_bIsConnected = true;
	return;
}
int main(int argc, char* argv[])
{
	char ch[20];
	
	Client object;
	cout<<"This is a client TCP/IP application\nConnecting to port 8088\n";
	cout<<"\nPress ONLY ENTER to quit";
	cout<<"\nWritten by Dilip Sharma";
	cout<<"\n===============================================\n";


	//FILE *fp = fopen("server.ini","r");
	string strServerAddress;
	ifstream fp;
	fp.open("server.ini");
	
	if(fp == NULL)
	{
		cout<<"\nUnable to open server.ini. Please specify server IPsddress in server.ini";
		return 1; // main failed
	}

	fp>>ch;
	fp.close();

	for(int i = 0; ch[i] != 0; i++)
	{
		strServerAddress += ch[i];
	}

	if(strServerAddress.size() == 0)
	{
		cout<<"\nUnable to find server IPaddress in server.ini";
		cout<<"\nPlease set server IPaddress";
		cout<<"\nThis is Dilip Signing off. BYE:";
		getch();
		return 0;
	}
	object.initialize(strServerAddress, 8080);

	if(!object.IsConnected())
	{
		cout<<"\nUnable to connect to the IPaddress specified in server.ini";
		cout<<"\nPlease check server IPaddress";
		cout<<"\nThis is Dilip Signing off. BYE:";
		getch();
		return 0;	
	}

	getch();
}

