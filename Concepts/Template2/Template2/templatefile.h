#include <iostream>
#include <conio.h>

using namespace std;

template <typename placeholder, int size> class MyTemplate
{
	public:
		MyTemplate();
		~MyTemplate();
		MyTemplate(const MyTemplate& object);
		void printValues();
	private:
		placeholder* dynamicArray;
};


template <typename placeholder, int size> MyTemplate <placeholder, size>::MyTemplate()
{
	dynamicArray = new int[size];

	for (int i = 0; i < size; i++)
	{
		dynamicArray[i] = i + 1;
	}
}

template <typename placeholder, int size> MyTemplate <placeholder, size>::MyTemplate(const MyTemplate& object)
{
	dynamicArray = new placeholder[size];

	for (int i = 0; i < size; i++)
	{
		dynamicArray[i] = object.dynamicArray[i];
	} 
}

template <typename placeholder, int size> MyTemplate <placeholder, size>::~MyTemplate()
{
	cout << "Dtor Called\n";
}

template <typename placeholder, int size> void MyTemplate <placeholder, size>::printValues()
{
	for (int i = 0; i < size; i++)
	{
		cout << dynamicArray[i] << " ";
	} 
	cout << "\n\n";
}