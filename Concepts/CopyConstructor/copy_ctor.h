#include <iostream>


#ifndef __COPY_CTOR_H__
#define __COPY_CTOR_H__

namespace NamespaceCopyCtor
{
	class CopyCtor
	{
		public:
			CopyCtor(int size);
			
			CopyCtor(CopyCtor& contPCopyCtor);
			~CopyCtor();

			void DummyFunForCopyCtorCall(CopyCtor ob);
			CopyCtor DummyFunForCopyCtorCall2();

			void print();

		private:
			int *m_pValue;
			int m_nSize;
	};

}
#endif __COPY_CTOR_H__