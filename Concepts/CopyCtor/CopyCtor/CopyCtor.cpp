
#include <iostream>
#include <conio.h>

using namespace std;

template <class family> void bubbleSort(family *ptr, int length)
{
	family temp;
	family *start = ptr;

	for(unsigned int ui = 1; ui < length ; ui++ )
	{
		ptr = start;
		cout<<"add = "<<ptr<<"******"<<endl;
		for(unsigned int uj = 0; uj < length - ui ; uj++ )
		{
			cout<<"***temp add = "<<ptr<<"**";
			if(ptr[uj] > ptr[uj + 1])
			{
				temp = ptr[uj];
				ptr[uj] = ptr[uj + 1];
				ptr[uj + 1] = temp;
				ptr++;
			}
		}
	}
}

int main()
{
	int arr [5] = {3, 1, 5, 2, 4};
	bubbleSort(arr, 5);

	for(unsigned int ui = 0; ui < 5 ; ui++ )
	{
		cout<<arr[ui]<<" ";
	}
	getch();
	return 0;
}