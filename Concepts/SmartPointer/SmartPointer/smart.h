#include <iostream>


template <typename T> class SmartPointer
{
	public:
		SmartPointer();

		~SmartPointer();

		void SmartPointer(T* ptr);

		T* release();

	private:
		T* m_pPointer;
};