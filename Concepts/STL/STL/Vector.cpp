#include <iostream>
#include <conio.h>
#include <algorithm>
#include <vector>


using namespace std;

void main()
{
	vector<char> vec, vec2(100);

	for(int i = 0; i < 26; i++)
	{
		vec.push_back('A' + i);
	}


	vector<char>::iterator it;
	it = vec.begin();
	cout<<"Input Sequence"<<endl;

	for(it; it < vec.end(); it++)
	{
		cout<<*it<<" ";
	}

	reverse(vec.begin(), vec.end());

	it = vec.begin();
	cout<<endl<<"Reversed Sequence"<<endl;

	for(it; it < vec.end(); it++)
	{
		cout<<*it<<" ";
	}
	//remove_copy(vec.begin(), vec.end(), vec2.begin(), 'D');

	//it = vec2.begin();
	//cout<<endl<<"Changed Contents"<<endl;
	//for(it; it < vec2.end(); it++)
	//{
	//	cout<<*it<<" ";
	//}

	//replace_copy(vec.begin(), vec.end(), vec2.begin(), 'A', 'S');

	//it = vec2.begin();
	//cout<<endl<<"Replaced Contents"<<endl;
	//for(it; it < vec2.end(); it++)
	//{
	//	cout<<*it<<" ";
	//}
	getch();
}