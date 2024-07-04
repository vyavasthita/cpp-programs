#include <conio.h>
#include "Parser.h"
#include <stdexcept>

using namespace std;

const char* XMLParser::scXMLFilePath = "F:\\Personal\\C++ Learning\\XMLParser\\XMLParser\\SampleXML.xml";

XMLParser::XMLParser() : mpXMLParser(NULL), mpXMLNode(NULL), mpXMLDocument(NULL)
{
	XMLPlatformUtils::Initialize();
}

XMLParser::~XMLParser()
{
	if(mpXMLParser != NULL)
	{
		delete mpXMLParser;
	}
	XMLPlatformUtils::Terminate();
}

void XMLParser::openXMLFile()
{
	try
	{
		mpXMLParser = new XercesDOMParser;
	}
	catch(const bad_alloc& rError)
	{
		cout<<"Exception : "<<rError.what();
	}

	mpXMLParser->parse(scXMLFilePath);

	mpXMLNode = mpXMLParser->getDocument();
	
	try
	{
		mpXMLDocument = dynamic_cast<DOMDocument*>(mpXMLNode);
	}
	catch(const bad_cast& rError)
	{
		cout<<"Exception : "<<rError.what();
	}

	printXMLNode(mpXMLDocument->getDocumentElement());
}

void printXMLNode(const DOMNode* domNode)
{
	try
	{
		const DOMText& rDomText = dynamic_cast<const DOMText&>(*domNode);
		char* cNodeText = XMLString::transcode(rDomText.getData());
		cout<<"Text : "<<cNodeText<<endl;
		XMLString::release(&cNodeText);
	}
	catch(const bad_cast& rError)
	{
		cout<<"Exception : "<<rError.what();
	}
}

void main()
{
	XMLParser oXMLParser;
	oXMLParser.openXMLFile();
	getch();
}