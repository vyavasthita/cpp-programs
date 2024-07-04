#include <iostream>

template <typename T> class CDKVector
{
	public:
		CDKVector();
		CDKVector(int size);
		~CDKVector();

		void setVectorDefaultValues();
		void setVectorSize(T& size);
		void freeVector();

		void append(T element);
		int size();

		void operator () (T& size);
	private:
		T* vecDataType;
		T vectorSize;
};