#include <iostream>
#include <conio.h>

using namespace std;

namespace first
{
	int var = 10;
}
namespace second
{
	int var = 20;
}
void main()
{
	using namespace first;
	cout<<var<<endl;
	cout<<second::var;

	getch();
}