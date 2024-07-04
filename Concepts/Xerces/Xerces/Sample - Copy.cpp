#include "sample.h"

const char* const MyXMLParser::m_scpcXMLFileName = "C:\\C++ Practice\\Xerces\\Xerces\\sample.xml";
const char* const MyXMLParser::m_scpcXMLErrorAttrName = "error";

MyXMLParser::MyXMLParser()
{
	
}

MyXMLParser::~MyXMLParser()
{
	terminateXMLParser();
//	delete m_pXMLParser;
}

void MyXMLParser::processXMLFileParser()
{
	initializeXMLParser();
	terminateXMLParser();
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

	try
	{
		pXMLDocument = dynamic_cast<DOMDocument*>(m_pXMLNode);
	}
	catch(const std::bad_cast& crException)
	{
		cout<<"Exception : "<<crException.what();
		//log
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

	try
	{
		m_pXMLElement = dynamic_cast<DOMElement*>(pXMLNode);
	}
	catch(const std::bad_cast& crException)
	{
		cout<<"Exception : "<<crException.what();
	}

	pXMLNodeList = m_pXMLElement->getChildNodes();

	for(unsigned int uiIterator = 0; uiIterator < pXMLNodeList->getLength(); uiIterator++)
	{
		DOMNode* pCurrentXMLNode = pXMLNodeList->item(uiIterator);

		try
		{
			DOMElement* pCurrentXMLElement
                        = dynamic_cast<DOMElement*>(pCurrentXMLNode);

			if(pCurrentXMLElement != NULL)
			{
				if(XMLString::equals(pCurrentXMLElement->getTagName(), XMLString::transcode(m_scpcXMLErrorAttrName)))
				{
					DOMNamedNodeMap* pXMLAttributes = pCurrentXMLElement->getAttributes();
						
					for (unsigned int uiIterator2 = 0; uiIterator2 < pXMLAttributes->getLength(); uiIterator2++) 
					{
						try 
						{
							const DOMAttr& crXMLAttr =
										dynamic_cast<const DOMAttr&>(*pXMLAttributes->item(uiIterator2));

							m_mapXMLParser.insert(make_pair(XMLString::transcode(crXMLAttr.getValue()), 
												XMLString::transcode(pCurrentXMLElement->getTextContent())));
						}
						catch(const std::bad_cast crException)
						{
							cout<<"Exception : "<<crException.what();
						}
					}						
				}
				else if(pCurrentXMLElement->hasChildNodes())
				{
					readXMLNode(pCurrentXMLElement);
				}
			}
		}
		catch(const std::bad_cast& crException)
		{
			cout<<"Exception : "<<crException.what();
		}
	}
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

		cout << "XML ttolkit teardown error: " << cpErrorMessage << endl;
		XMLString::release( &cpErrorMessage );
	}
}

void MyXMLParser::setXMLData()
{
}

int main()
{
	MyXMLParser oMyXMLParser;

	oMyXMLParser.initializeXMLParser();
	oMyXMLParser.processXMLFileParser();
	oMyXMLParser.printXMLValues();
	oMyXMLParser.terminateXMLParser();

	getch();
	return 1;
}