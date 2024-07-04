#include "Parsing.h"
#include <typeinfo>
#include <conio.h>

void XMLParser::initialize()
{
	XMLPlatformUtils::Initialize();
	domParser = new XercesDOMParser();
	domParser->parse("C:\\C++ Practice 2014\\XercesXMLParser\\application.xml");
}

void XMLParser::getDocument()
{
	domNode = domParser->getDocument();

	domDocument = dynamic_cast<DOMDocument*>(domNode);

	DOMElement* domElement = NULL;

	if (domDocument != NULL)
	{
		domElement = domDocument->getDocumentElement();
	}
	printNode(domElement);
}

void XMLParser::printNode(const DOMNode* inNode)
{
	try 
	{
		const DOMText& textNode = dynamic_cast<const DOMText&>(*inNode);
		char* text = XMLString::transcode(textNode.getData());
		cout << "Found text data: " << text << endl;
		XMLString::release(&text);
	} 
	catch (bad_cast) 
	{
		// Not a text node . . .
	}
}

void main()
{
	XMLParser xmlParser;
	xmlParser.initialize();
	xmlParser.getDocument();

	getch();
}