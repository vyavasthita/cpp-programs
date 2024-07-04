#include <xercesc\util\PlatformUtils.hpp>
#include <xercesc\dom\DOM.hpp>
#include <xercesc\parsers\XercesDOMParser.hpp>
#include <xercesc\util\XMLString.hpp>

#include <iostream>

using namespace std;

XERCES_CPP_NAMESPACE_USE

class XMLParser
{
	public:
		void initialize();
		void getDocument();
		void printNode(const DOMNode* inNode);

	private:
		XercesDOMParser* domParser;
		DOMNode* domNode;
		DOMDocument* domDocument;
};