#include "ReferenceCount.h"


#pragma once


template<typename T> class SmartPointer
{
	public:
		SmartPointer() : m_ptr(NULL), m_poReferenceCount(NULL)
		{
			m_poReferenceCount = new ReferenceCount;
			m_poReferenceCount->incrementRefCount();
		}

		SmartPointer(T* ptr) : m_ptr(ptr), m_poReferenceCount(NULL)
		{
			m_poReferenceCount = new ReferenceCount;

			m_poReferenceCount->incrementRefCount();
		}

		~SmartPointer()
		{
			cout << "Before calling SmartPointer Dtor." << endl;

			if (m_poReferenceCount->getReferenceCount() > 0)
			{
				m_poReferenceCount->decrementRefCount();
			}

			if (m_poReferenceCount->getReferenceCount() == 0)
			{
				cout << "Checking deletion\n";
				if (m_ptr != NULL)
				{
					cout << "Getting deleted\n";
					delete m_ptr;
					m_ptr = NULL;
				}
			}
			
			delete m_poReferenceCount;

			cout << "After calling SmartPointer Dtor.\n\n" << endl;
		}

		SmartPointer(const SmartPointer<T>& smartPointer) : m_ptr(smartPointer.m_ptr)
		{
			m_poReferenceCount = new ReferenceCount;

			m_poReferenceCount->setReferenceCount(smartPointer.m_poReferenceCount->getReferenceCount());
			
			m_poReferenceCount->incrementRefCount();
		}

		void operator = (const SmartPointer<T>& smartPointer)
		{
			m_poReferenceCount = new ReferenceCount;

			m_poReferenceCount->setReferenceCount(smartPointer.m_poReferenceCount->getReferenceCount());

			m_poReferenceCount->incrementRefCount();
		}

		T& operator * ()
		{
			return *m_ptr;
		}
		T* operator -> ()
		{
			return m_ptr;
		}

		ReferenceCount* m_poReferenceCount;

	private:
		T* m_ptr;
};

