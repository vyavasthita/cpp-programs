#ifndef __XML_PARSER_H_
#define __XML_PARSER_H_

#include <iostream>
#include <conio.h>
#include <map>
#include <string>
#include <stdexcept>

#include <xercesc\parsers\XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMText.hpp>


XERCES_CPP_NAMESPACE_USE
using namespace std;

class MyXMLParser
{
	public:
		MyXMLParser();
		virtual ~MyXMLParser();

		void processXMLFileParser();
		void initializeXMLParser();	
		void parseXMLFile();
		void readXMLNode(DOMNode* pXMLNode);
		void processChild(DOMNode* pXMLNode);
		void processElement(const DOMElement* cpXMLElement);
		void setElementData(const XMLCh* cpXMLElementValue, const XMLCh* cpXMLElementText);
		void terminateXMLParser();
		void printXMLValues();
		void setXMLData();

	private:
		XercesDOMParser* m_pXMLParser;
		DOMNode* m_pXMLNode;
		DOMElement* m_pXMLElement;

		map<string, string> m_mapXMLParser;

		static const char* const m_scpcXMLFileName;
		static const char* const m_scpcXMLErrorAttrName;
		static const char* const m_scpcXMLErrorAttrValue;
};

#endif __XML_PARSER_H_