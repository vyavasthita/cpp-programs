#pragma once

template <typename T> class SmartPointer
{
	public:
		SmartPointer()
		{

		}
		SmartPointer(T* ptr)
		{
			m_ptr = ptr;
		}
		SmartPointer(const T& ref)
		{

		}
		~SmartPointer()
		{
			delete m_ptr;
		}

	private:
		T* m_ptr;
};
