#pragma once

#include "person.h"
#include "reference_count.h"


template <typename T> class SmartPointer
{
	public:
		SmartPointer(T* ptr)
		{
			m_ptr = ptr;
			m_oReferenceCount.incrementCount();
		}
		SmartPointer(SmartPointer<T>& f)
		{
			m_oReferenceCount.incrementCount();
			f.m_oReferenceCount.incrementCount();
		}

		~SmartPointer()
		{
			m_oReferenceCount.decrementCount();

			if (m_oReferenceCount.getCount() == 0)
			{
				std::cout << "Smart Pointer dtor called\n";

				delete m_ptr;
				m_ptr = NULL;
			}			
		}
	private:
		T* m_ptr;
		ReferenceCount m_oReferenceCount;
};
