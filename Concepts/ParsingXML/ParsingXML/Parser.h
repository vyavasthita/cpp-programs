#include <iostream>
#include <xercesc\util\PlatformUtils.hpp>
#include <xercesc\dom\DOM.hpp>
#include <xercesc\parsers\XercesDOMParser.hpp>
#include <xercesc\util\XMLString.hpp>
#include <stdexcept>


XERCES_CPP_NAMESPACE_USE


class XMLParser
{
	public:
		XMLParser();
		~XMLParser();

		void openXMLFile();
		void printXMLNode(const DOMNode* domNode);
	
	private:
		XercesDOMParser* mpXMLParser;
		DOMNode* mpXMLNode;
		DOMDocument* mpXMLDocument;

		static const char* scXMLFilePath;
};