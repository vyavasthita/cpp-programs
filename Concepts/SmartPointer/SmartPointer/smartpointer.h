#include <iostream>

template <typename T> class TCSmartPointer
{
	public:
		TCSmartPointer();
		TCSmartPointer(T* value);
		~TCSmartPointer();

		void setReleaseStatus(bool bStatus);
		bool getReleaseStatus();

		void operator = (T* value);
		
		T operator -> ();

		T* get();
		T* release();
		
	private:
		T* ptValue;
		bool bReleaseStatus;
};