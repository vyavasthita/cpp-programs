#include "file.h"


int main()
{
	const char* cpDLLPath = "C:\\Raja\\TechnicalStudy\\Source_Code\\CPP_Source_Code\\MyDLL\\Debug\\MyDLL.dll";
	{
	CLearning ob(cpDLLPath);

	try
	{
		ob.LoadMyDLL();
	}
	catch(const char* error)
	{
		cout << error;
	}
	int result = 0;
	try
	{
		result = ob.Add(5, 7);
	}
	catch(const char* error)
	{
		cout << error;
	}
	cout << "Addition is " << result << endl;
	}

	getch();
};