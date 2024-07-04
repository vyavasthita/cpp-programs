#include <Python.h>


void cpp_calling_python()
{
	Py_Initialize();

	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('/home/aspect/Documents/practice')");

	PyObject* oModuleNameObject = PyUnicode_FromString("pythonsample");
	PyObject* outModuleObject = PyImport_Import(oModuleNameObject);

	PyObject* oMethodObject = PyObject_GetAttrString(outModuleObject, "python_function");

	PyObject* oCallObject = PyObject_CallObject(oMethodObject, NULL);

	Py_Finalize();
}