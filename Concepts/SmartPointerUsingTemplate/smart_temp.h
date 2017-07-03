#include <iostream>

#ifndef __SMART_PT_TMP_H__
#define __SMART_PT_TMP_H__

/*
Template class defination sould be in the same file where declaration is.
*/
namespace NamespaceSmartPointerWithTemp
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

	template <typename T> class SmartPointerWithTemp
	{
		public:
			SmartPointerWithTemp();
			SmartPointerWithTemp(T* ob);
			~SmartPointerWithTemp();

			SmartPointerWithTemp(const SmartPointerWithTemp<T>& ob);
			SmartPointerWithTemp<T>& operator = (const SmartPointerWithTemp<T>& ob);

			T* get();
			T operator * ();
			T* operator -> ();

			int& operator = (T* ob);

			void release();

		private:
			T* m_pSmartPointer;
			bool isReleased;
			ReferenceCount oReferenceCount;
	};

	template <typename T> SmartPointerWithTemp<T>::SmartPointerWithTemp()
	{
		m_pSmartPointer = NULL;
	}

	template <typename T> SmartPointerWithTemp<T>::SmartPointerWithTemp(T* ob) :
		isReleased(false)
	{
		m_pSmartPointer = ob;
		oReferenceCount.incrementCount();
	}

	template <typename T> SmartPointerWithTemp<T>::SmartPointerWithTemp(const SmartPointerWithTemp<T>& ob)
	{
		if (this != &ob)
		{
			m_pSmartPointer = ob.m_pSmartPointer;
			oReferenceCount.setCount(ob.oReferenceCount.getCount() + 1);
		}
	}

	template <typename T> SmartPointerWithTemp<T>::~SmartPointerWithTemp()
	{
		if (isReleased == false)
		{
			oReferenceCount.decrementCount();
		}

		if (oReferenceCount.getCount() == 0 && isReleased == false)
		{
			delete m_pSmartPointer;
		}
	}

	template <typename T> T* SmartPointerWithTemp<T>::get()
	{
		return m_pSmartPointer;
	}

	template <typename T> T SmartPointerWithTemp<T>::operator * ()
	{
		return *m_pSmartPointer;
	}

	template <typename T> T* SmartPointerWithTemp<T>::operator -> ()
	{
		return m_pSmartPointer;
	}

	template <typename T> void SmartPointerWithTemp<T>::release()
	{
		m_pSmartPointer = NULL;
		isReleased = true;
		oReferenceCount.decrementCount();
	}

	template <typename T> SmartPointerWithTemp<T>& SmartPointerWithTemp<T>::operator = (const SmartPointerWithTemp<T>& ob)
	{
		if (this != &ob)
		{
			m_pSmartPointer = ob.m_pSmartPointer;
			oReferenceCount.setCount(ob.oReferenceCount.getCount() + 1);
		}

		return *this;
	}
}
#endif __SMART_PT_TMP_H__