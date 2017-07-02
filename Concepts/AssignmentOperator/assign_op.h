#include <iostream>


#ifndef __ASSIGN_OP_H__
#define __ASSIGN_OP_H__

namespace NamespaceAssignOp
{
	class AssignOp
	{
	public:
		AssignOp(int size);

		AssignOp& operator = (AssignOp& contPAssignOp);
		~AssignOp();

		void DummyFunForCopyCtorCall(AssignOp ob);
		AssignOp DummyFunForCopyCtorCall2();

		void print();

	private:
		int *m_pValue;
		int m_nSize;
	};

}
#endif __ASSIGN_OP_H__