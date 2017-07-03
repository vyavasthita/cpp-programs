#include <iostream>

#ifndef __SMART_PT_INT_H__
#define __SMART_PT_INT_H__

namespace NamespaceSmartPointerForInt
{
	class ReferenceCount
	{
		public:
			ReferenceCount();
			~ReferenceCount();

			void incrementCount();
			void decrementCount();
			void setCount(int count);
			int getCount() const;

		private:
			int m_refCount;
	};

	class SmartPointerForInt
	{
		public:
			SmartPointerForInt();
			SmartPointerForInt(int* ob);
			~SmartPointerForInt();

			SmartPointerForInt(const SmartPointerForInt& ob);
			SmartPointerForInt& operator = (const SmartPointerForInt& ob);

			int* get();
			int operator * ();
			int* operator -> ();

			int& operator = (int* ob);

			void release();

		private:
			int *m_pSmartPointer;
			bool isReleased;
			ReferenceCount oReferenceCount;
	};
}
#endif __SMART_PT_INT_H__