#include "myxml.h";

const char* const MyXMLParser::m_scpcXMLFileName = "I:\\Data\\C++ Learning\\ParseXML\\sample.xml";
const char* const MyXMLParser::m_scpcXMLErrorAttrName = "error";
const char* const MyXMLParser::m_scpcXMLErrorAttrValue = "id";

MyXMLParser::MyXMLParser()
{
	
}

MyXMLParser::~MyXMLParser()
{
	delete m_pXMLParser;
	terminateXMLParser();
}

void MyXMLParser::processXMLFileParser()
{
	initializeXMLParser();
}

void MyXMLParser::initializeXMLParser()
{
	try
	{
		XMLPlatformUtils::Initialize();  // Initialize Xerces infrastructure
	}
	catch(const XMLException& crException)
	{
		char* cpErrorMessage = XMLString::transcode(crException.getMessage());
		cerr << "XML toolkit initialization error: " << cpErrorMessage << endl;
		XMLString::release( &cpErrorMessage );
		//log
		return;
	}

	m_pXMLParser = new XercesDOMParser;
	m_pXMLParser->setValidationScheme(XercesDOMParser::Val_Always);
	m_pXMLParser->setDoNamespaces(true);    // optional

	parseXMLFile();
}

void MyXMLParser::parseXMLFile()
{
	//file validation needs to be done here...
	try
	{
		m_pXMLParser->parse(m_scpcXMLFileName);
	}
	catch(const XMLException& crException) 
	{
        char* cpErrorMessage = XMLString::transcode(crException.getMessage());
        cout << "Exception message is: \n"
                 << cpErrorMessage << "\n";
        XMLString::release(&cpErrorMessage);
		//log
        return;
    }
    catch(const DOMException& crException) 
	{
        char* cpErrorMessage = XMLString::transcode(crException.msg);
        cout << "Exception message is: \n"
                 << cpErrorMessage << "\n";
        XMLString::release(&cpErrorMessage);
		//log
        return;
    }
    catch(...) 
	{
        cout << "Unknown Exception \n" ;
        return;
    }

	DOMDocument* pXMLDocument = NULL;
	m_pXMLNode = m_pXMLParser->getDocument();

	if(m_pXMLNode == NULL)
	{
		cout<<"Error Occured\n";
		//log
		return;
	}

	pXMLDocument = dynamic_cast<DOMDocument*>(m_pXMLNode);

	if(pXMLDocument == NULL)
	{
		//bad dynamic cast
		return;
	}

	m_pXMLElement = pXMLDocument->getDocumentElement();		//root element

	if(m_pXMLElement == NULL)
	{
		cout<<"XML File is Blank\n";
		//log
		return;
	}
	readXMLNode(m_pXMLElement);
}

void MyXMLParser::readXMLNode(DOMNode* pXMLNode)
{
	DOMNodeList* pXMLNodeList = NULL;

	m_pXMLElement = dynamic_cast<DOMElement*>(pXMLNode);
	
	if(m_pXMLElement == NULL)
	{
		//bad dynamic cast
		return;
	}
	
	pXMLNodeList = m_pXMLElement->getChildNodes();
	
	for(unsigned int uiIterator = 0; uiIterator < pXMLNodeList->getLength(); uiIterator++)
	{
		DOMNode* pCurrentXMLNode = pXMLNodeList->item(uiIterator);
		processChild(pCurrentXMLNode);
	}
}

void MyXMLParser::processChild(DOMNode* pXMLNode)
{
	DOMElement* pCurrentXMLElement = NULL;

	pCurrentXMLElement = dynamic_cast<DOMElement*>(pXMLNode);

	if(pCurrentXMLElement == NULL)
	{
		//bad dynamic cast
		return;
	}

	if(XMLString::equals(pCurrentXMLElement->getTagName(), XMLString::transcode(m_scpcXMLErrorAttrName)))
	{
		processElement(pCurrentXMLElement);					
	}
	else if(pCurrentXMLElement->hasChildNodes())
	{
		readXMLNode(pCurrentXMLElement);
	}
}

void MyXMLParser::processElement(const DOMElement* cpXMLElement)
{
	DOMNamedNodeMap* pXMLAttributes = cpXMLElement->getAttributes();
						
	for (unsigned int uiIterator2 = 0; uiIterator2 < pXMLAttributes->getLength(); uiIterator2++) 
	{
		try 
		{
			const DOMAttr& crXMLAttr = dynamic_cast<const DOMAttr&>(*pXMLAttributes->item(uiIterator2));

			if(XMLString::equals(crXMLAttr.getName(), XMLString::transcode(m_scpcXMLErrorAttrValue)))
			{
				setElementData(crXMLAttr.getValue(), cpXMLElement->getTextContent());
			}			
		}
		catch(const std::bad_cast& crException)
		{
			cout<<"Exception : "<<crException.what();
		}
	}	
}

void MyXMLParser::setElementData(const XMLCh* cpXMLElementValue, const XMLCh* cpXMLElementText)
{
	m_mapXMLParser.insert(make_pair(XMLString::transcode(cpXMLElementValue), XMLString::transcode(cpXMLElementText)));
}

void MyXMLParser::printXMLValues()
{
	map<string, string>::iterator it = m_mapXMLParser.begin();

	cout<<"XML Values are : "<<endl;
	for(it; it != m_mapXMLParser.end(); it++)
	{
		cout<<it->first.c_str()<<" : "<<it->second.c_str()<<endl;
	}
}

void MyXMLParser::terminateXMLParser()
{
	try
    {
		XMLPlatformUtils::Terminate();  // Terminate after release of memory
	}
	catch(const XMLException& crException)
	{
		char* cpErrorMessage = xercesc::XMLString::transcode(crException.getMessage());

		cout << "XML toolkit teardown error: " << cpErrorMessage << endl;
		XMLString::release( &cpErrorMessage );
	}
}

void MyXMLParser::setXMLData()
{
}

int main()
{
	MyXMLParser oMyXMLParser;

	oMyXMLParser.processXMLFileParser();
	oMyXMLParser.printXMLValues();

	getch();
	return 1;
}