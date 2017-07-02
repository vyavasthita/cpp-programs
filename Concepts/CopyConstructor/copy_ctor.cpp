#include "copy_ctor.h"

using namespace NamespaceCopyCtor;

CopyCtor::CopyCtor(int size)
{
	m_nSize = size;

	m_pValue = new int[m_nSize];

	for (unsigned int ui = 0; ui < m_nSize; ui++)
	{
		m_pValue[ui] = ui + 1;
	}
}

CopyCtor::CopyCtor(CopyCtor& contPCopyCtor)
{
	std::cout << "Copy Ctor Called\n";

	m_nSize = contPCopyCtor.m_nSize;
	m_pValue = new int[m_nSize];
	
	for (unsigned int ui = 0; ui < m_nSize; ui++)
	{
		m_pValue[ui] = contPCopyCtor.m_pValue[ui];
	}
}

CopyCtor::~CopyCtor()
{
	std::cout << "Dtor Called\n";

	delete [] m_pValue;
}

// When we pass object
void CopyCtor::DummyFunForCopyCtorCall(CopyCtor ob)
{

}

//When we return object
CopyCtor CopyCtor::DummyFunForCopyCtorCall2()
{
	return *this;
}

void CopyCtor::print()
{
	std::cout << "Contents are \n";

	for (unsigned int ui = 0; ui < m_nSize; ui++)
	{
		std::cout << m_pValue[ui] << " " ;
	}
	std::cout << "\n";
}