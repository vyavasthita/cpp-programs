#include "assign_op.h"

using namespace NamespaceAssignOp;

AssignOp::AssignOp(int size)
{
	m_nSize = size;

	m_pValue = new int[m_nSize];

	for (unsigned int ui = 0; ui < m_nSize; ui++)
	{
		m_pValue[ui] = ui + 1;
	}
}

AssignOp& AssignOp::operator=(AssignOp& contPAssignOp)
{
	std::cout << "Assignment Operator Called\n";

	if (this == &contPAssignOp)
	{
		return (*this);
	}

	delete [] m_pValue;
	m_pValue = NULL;

	m_nSize = contPAssignOp.m_nSize;

	m_pValue = new int[m_nSize];

	for (unsigned int ui = 0; ui < m_nSize; ui++)
	{
		m_pValue[ui] = contPAssignOp.m_pValue[ui];
	}
	std::cout << std::endl;

	return (*this);
}

AssignOp::~AssignOp()
{
	std::cout << "Dtor Called\n";

	delete [] m_pValue;
}

// When we pass object
void AssignOp::DummyFunForCopyCtorCall(AssignOp ob)
{

}

//When we return object
AssignOp AssignOp::DummyFunForCopyCtorCall2()
{
	return *this;
}

void AssignOp::print()
{
	std::cout << "Contents are \n";

	for (unsigned int ui = 0; ui < m_nSize; ui++)
	{
		std::cout << m_pValue[ui] << " ";
	}
	std::cout << "\n";
}