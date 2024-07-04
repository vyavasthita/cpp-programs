#include "ParseXML.h"


XERCES_CPP_NAMESPACE_USE


XercesDOMParser* parser;
DOMNode* m_pXMLNode;
DOMElement* m_pXMLElement;
char*  m_scpcXMLErrorAttrValue;
char*  m_scpcXMLErrorAttrName;
char* xmlFile;


int parse_xml (int args, char** arg) 
{
        try
		{
            XMLPlatformUtils::Initialize();
        }
        catch (const XMLException& toCatch) 
		{
            char* message = XMLString::transcode(toCatch.getMessage());
            printf("Error during initialization! :\n", message);
            XMLString::release(&message);
            return 0;
        }

        parser = new XercesDOMParser();
        parser->setValidationScheme(XercesDOMParser::Val_Always);
        parser->setDoNamespaces(true);    // optional

        ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
        parser->setErrorHandler(errHandler);
		xmlFile = "E:\\CKPhase2\\Siemens\\Teamcenter8\\JTCreation.xml";
       
        try 
		{
            parser->parse(xmlFile);
        }
        catch (const XMLException& toCatch)
		{
            char* message = XMLString::transcode(toCatch.getMessage());
            printf("Exception message is:\n",message);
            XMLString::release(&message);
            return 0;
        }
        catch (const DOMException& toCatch)
		{
            char* message = XMLString::transcode(toCatch.msg);
            printf("Exception message is: \n",message);
            XMLString::release(&message);
            return 0;
        }
        catch (...)
		{
            printf("Unexpected Exception \n") ;
            return 0;
        }
		xercesc::DOMDocument* pXMLDocument = NULL;
		m_pXMLNode = parser->getDocument();

		if(m_pXMLNode == NULL)
		{
			printf("Error Occured\n");
			//log
			return 0;
		}
		
	    pXMLDocument = dynamic_cast<xercesc::DOMDocument*>(m_pXMLNode);

		if(pXMLDocument == NULL)
		{
			//bad dynamic cast
			return 0;
		}

		m_pXMLElement = pXMLDocument->getDocumentElement();		//root element

		DOMNode* ptrDomNode = NULL;
		DOMNodeList* ptrNodeList = pXMLDocument->getElementsByTagName(XMLString::transcode("Description"));

		for (unsigned int unIterator = 0; unIterator < ptrNodeList->getLength(); unIterator++)
		{
			ptrDomNode = ptrNodeList->item(unIterator);
			break;
		}

		const XMLCh* res =  ptrDomNode->getTextContent();

		*arg = XMLString::transcode(res);

		if(m_pXMLElement == NULL)
		{
			printf("XML File is Blank\n");
			//log
			return 0;
		}
	return 0;
		
}
