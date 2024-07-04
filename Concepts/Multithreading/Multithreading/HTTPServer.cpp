/****************************************************************************************
* ///////////////////////////////////////////////////////////////////////////////////////
*	Original Filename: 	HTTPServer.cpp
*
*	History:
*	Created/Modified by				Date			Main Purpose/Changes
*	Souren M. Abeghyan				2001/05/25		Implementation of the CHTTPServer class
*	
*	Comments:	
* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
****************************************************************************************/
#include "stdafx.h"
#include "WebServer.h"
#include "HTTPServer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHTTPServer::CHTTPServer()
{
	//
	// Init MIME Types
	//
	MimeTypes["doc"]	= "application/msword";
	MimeTypes["bin"]	= "application/octet-stream";
	MimeTypes["dll"]	= "application/octet-stream";
	MimeTypes["exe"]	= "application/octet-stream";
	MimeTypes["pdf"]	= "application/pdf";
	MimeTypes["p7c"]	= "application/pkcs7-mime";
	MimeTypes["ai"]		= "application/postscript";
	MimeTypes["eps"]	= "application/postscript";
	MimeTypes["ps"]		= "application/postscript";
	MimeTypes["rtf"]	= "application/rtf";
	MimeTypes["fdf"]	= "application/vnd.fdf";
	MimeTypes["arj"]	= "application/x-arj";
	MimeTypes["gz"]		= "application/x-gzip";
	MimeTypes["class"]	= "application/x-java-class";
	MimeTypes["js"]		= "application/x-javascript";
	MimeTypes["lzh"]	= "application/x-lzh";
	MimeTypes["lnk"]	= "application/x-ms-shortcut";
	MimeTypes["tar"]	= "application/x-tar";
	MimeTypes["hlp"]	= "application/x-winhelp";
	MimeTypes["cert"]	= "application/x-x509-ca-cert";
	MimeTypes["zip"]	= "application/zip";
	MimeTypes["cab"]	= "application/x-compressed";
	MimeTypes["arj"]	= "application/x-compressed";
	MimeTypes["aif"]	= "audio/aiff";
	MimeTypes["aifc"]	= "audio/aiff";
	MimeTypes["aiff"]	= "audio/aiff";
	MimeTypes["au"]		= "audio/basic";
	MimeTypes["snd"]	= "audio/basic";
	MimeTypes["mid"]	= "audio/midi";
	MimeTypes["rmi"]	= "audio/midi";
	MimeTypes["mp3"]	= "audio/mpeg";
	MimeTypes["vox"]	= "audio/voxware";
	MimeTypes["wav"]	= "audio/wav";
	MimeTypes["ra"]		= "audio/x-pn-realaudio";
	MimeTypes["ram"]	= "audio/x-pn-realaudio";
	MimeTypes["bmp"]	= "image/bmp";
	MimeTypes["gif"]	= "image/gif";
	MimeTypes["jpeg"]	= "image/jpeg";
	MimeTypes["jpg"]	= "image/jpeg";
	MimeTypes["tif"]	= "image/tiff";
	MimeTypes["tiff"]	= "image/tiff";
	MimeTypes["xbm"]	= "image/xbm";
	MimeTypes["wrl"]	= "model/vrml";
	MimeTypes["htm"]	= "text/html";
	MimeTypes["html"]	= "text/html";
	MimeTypes["c"]		= "text/plain";
	MimeTypes["cpp"]	= "text/plain";
	MimeTypes["def"]	= "text/plain";
	MimeTypes["h"]		= "text/plain";
	MimeTypes["txt"]	= "text/plain";
	MimeTypes["rtx"]	= "text/richtext";
	MimeTypes["rtf"]	= "text/richtext";
	MimeTypes["java"]	= "text/x-java-source";
	MimeTypes["css"]	= "text/css";
	MimeTypes["mpeg"]	= "video/mpeg";
	MimeTypes["mpg"]	= "video/mpeg";
	MimeTypes["mpe"]	= "video/mpeg";
	MimeTypes["avi"]	= "video/msvideo";
	MimeTypes["mov"]	= "video/quicktime";
	MimeTypes["qt"]		= "video/quicktime";
	MimeTypes["shtml"]	= "wwwserver/html-ssi";
	MimeTypes["asa"]	= "wwwserver/isapi";
	MimeTypes["asp"]	= "wwwserver/isapi";
	MimeTypes["cfm"]	= "wwwserver/isapi";
	MimeTypes["dbm"]	= "wwwserver/isapi";
	MimeTypes["isa"]	= "wwwserver/isapi";
	MimeTypes["plx"]	= "wwwserver/isapi";
	MimeTypes["url"]	= "wwwserver/isapi";
	MimeTypes["cgi"]	= "wwwserver/isapi";
	MimeTypes["php"]	= "wwwserver/isapi";
	MimeTypes["wcgi"]	= "wwwserver/isapi";
}

CHTTPServer::~CHTTPServer()
{

}


int CHTTPServer::GotConnection(char*, int)
{
	return 0;
}


int CHTTPServer::DataSent(DWORD)
{
	return 0;
}



BOOL CHTTPServer::Start(string HomeDir, string DefIndex, int Port, int PersTO)
{
	m_HomeDir		= HomeDir;
	m_DefIndex		= DefIndex;

	if(m_HomeDir.substr(m_HomeDir.size() - 1, 1) != "\\")
		m_HomeDir += "\\";

	return Run(Port, PersTO);
}


BOOL CHTTPServer::IsComplete(string szRequest)
{
	if(szRequest.substr(szRequest.size() - 4, 4) == "\r\n\r\n")
		return TRUE;
	else
		return FALSE;
}




BOOL CHTTPServer::ParseRequest(string szRequest, string &szResponse, BOOL &bKeepAlive)
{
	//
	// Simple Parsing of Request
	//
	string szMethod;
	string szFileName;
	string szFileExt;
	string szStatusCode("200 OK");
	string szContentType("text/html");
	string szConnectionType("close");
	string szNotFoundMessage;
	string szDateTime;
	char pResponseHeader[2048];
	fpos_t lengthActual = 0, length = 0;
	char *pBuf = NULL;
	int n;
				
	//
	// Check Method
	//
	n = szRequest.find(" ", 0);
	if(n != string::npos)
	{
		szMethod = szRequest.substr(0, n);
		if(szMethod == "GET")
		{
			//
			// Get file name
			// 
			int n1 = szRequest.find(" ", n + 1);
			if(n != string::npos)
			{
				szFileName = szRequest.substr(n + 1, n1 - n - 1);
				if(szFileName == "/")
				{
					szFileName = m_DefIndex;
				}
			}
			else
			{
				LogMessage(LOGFILENAME, "No 'space' found in Request String #1", "ParseRequest");
				return FALSE;
			}
		}
		else
		{
			szStatusCode = "501 Not Implemented";
			szFileName = ERROR501;
		}
	}
	else
	{
		LogMessage(LOGFILENAME, "No 'space' found in Request String #2", "ParseRequest");
		return FALSE;
	}

	//
	// Determine Connection type
	//
	n = szRequest.find("\nConnection: Keep-Alive", 0);
	if(n != string::npos)
		bKeepAlive = TRUE;

	//
	// Figure out content type
	//
	int nPointPos = szFileName.rfind(".");
	if(nPointPos != string::npos)
	{
		szFileExt = szFileName.substr(nPointPos + 1, szFileName.size());
		strlwr((char*)szFileExt.c_str());
		MIMETYPES::iterator it;
		it = MimeTypes.find(szFileExt);
		if(it != MimeTypes.end())
			szContentType = (*it).second;
	}

	//
	// Obtain current GMT date/time
	//
	char szDT[128];
	struct tm *newtime;
	long ltime;
	
	time(&ltime);
	newtime = gmtime(&ltime);
	strftime(szDT, 128,
		"%a, %d %b %Y %H:%M:%S GMT", newtime);

	//
	// Read the file
	//
	FILE *f;
	f = fopen((m_HomeDir + szFileName).c_str(), "r+b");
	if(f != NULL)				
	{
		// Retrive file size
		fseek(f, 0, SEEK_END);
		fgetpos(f, &lengthActual);
		fseek(f, 0, SEEK_SET);
		
		pBuf = new char[lengthActual + 1];

		length = fread(pBuf, 1, lengthActual, f);
		fclose(f);

		//
		// Make Response
		//
		sprintf(pResponseHeader, "HTTP/1.0 %s\r\nDate: %s\r\nServer: %s\r\nAccept-Ranges: bytes\r\nContent-Length: %d\r\nConnection: %s\r\nContent-Type: %s\r\n\r\n",
			szStatusCode.c_str(), szDT, SERVERNAME, (int)length, bKeepAlive ? "Keep-Alive" : "close", szContentType.c_str());
	}
	else
	{
		//
		// In case of file not found	   
		//
		f = fopen((m_HomeDir + ERROR404).c_str(), "r+b");
		if(f != NULL)				
		{
			// Retrive file size
			fseek(f, 0, SEEK_END);
			fgetpos(f, &lengthActual);
			fseek(f, 0, SEEK_SET);
			pBuf = new char[lengthActual + 1];
			length = fread(pBuf, 1, lengthActual, f);
			fclose(f);
			szNotFoundMessage = string(pBuf, length);
			delete pBuf;
			pBuf = NULL;
		}
		szStatusCode = "404 Resource not found";

		sprintf(pResponseHeader, "HTTP/1.0 %s\r\nContent-Length: %d\r\nContent-Type: text/html\r\nDate: %s\r\nServer: %s\r\n\r\n%s",
			szStatusCode.c_str(), szNotFoundMessage.size(), szDT, SERVERNAME, szNotFoundMessage.c_str());
		bKeepAlive = FALSE;  
	}

	szResponse = string(pResponseHeader);
	if(pBuf)
		szResponse += string(pBuf, length);
	delete pBuf;
	pBuf = NULL;
	

	return TRUE;
}
