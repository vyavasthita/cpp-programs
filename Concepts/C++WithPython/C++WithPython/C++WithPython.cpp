// C++WithPython.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Python.h>
#include <iostream>
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// Initialize the Python interpreter.
	Py_Initialize();

	// Create some Python objects that will later be assigned values.
	PyObject *pName, *pModule, *pDict, *pFunc, *pArgs, *pValue;

	// Convert the file name to a Python string.
	pName = PyString_FromString("sample");

	// Import the file as a Python module.
	pModule = PyImport_Import(pName);

	// Create a dictionary for the contents of the module.
	pDict = PyModule_GetDict(pModule);

	// Get the add method from the dictionary.
	pFunc = PyDict_GetItemString(pDict, "add");

	// Create a Python tuple to hold the arguments to the method.
	pArgs = PyTuple_New(2);

	// Convert 2 to a Python integer.
	pValue = PyInt_FromLong(2);

	// Set the Python int as the first and second arguments to the method.
	PyTuple_SetItem(pArgs, 0, pValue);
	PyTuple_SetItem(pArgs, 1, pValue);

	// Call the function with the arguments.
	PyObject* pResult = PyObject_CallObject(pFunc, pArgs);

	// Print a message if calling the method failed.
	if(pResult == NULL)
		std::cout << "Calling the add method failed.\n"; 
		
	// Convert the result to a long from a Python object.
	long result = PyInt_AsLong(pResult);

	// Destroy the Python interpreter.
	Py_Finalize();

	// Print the result.
	std::cout << "Result is " << result; 

	getch();
	return 0;
}

