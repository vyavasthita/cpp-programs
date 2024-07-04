#include <iostream>
#include <conio.h>

#include <Python.h>


void main()
{
	PyObject* pModuleName, *pModule, *pDict, *pFunction, *pArguments, *pValue1, *pValue2, *pResult;

	Py_Initialize();

	pModuleName = PyString_FromString("sample");

	pModule = PyImport_Import(pModuleName);

	pDict = PyModule_GetDict(pModule);

	pFunction = PyDict_GetItemString(pDict, "add");

	pArguments = PyTuple_New(2);

	pValue1 = PyInt_FromLong(5);
	pValue2 = PyInt_FromLong(7);

	PyTuple_SetItem(pArguments, 0, pValue1);
	PyTuple_SetItem(pArguments, 1, pValue2);

	pResult = PyObject_CallObject(pFunction, pArguments);

	long result = PyInt_AsLong(pResult);

	std::cout << "Addition is " << result;

	Py_Finalize();

	getch();
}