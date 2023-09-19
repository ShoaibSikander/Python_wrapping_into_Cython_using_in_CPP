#include <iostream>
#include "Python.h"

int main()
{
       setenv("PYTHONPATH",".",1);
       
       // Initialize the Python Interpreter
       Py_Initialize();

       PyObject *pName, *pModule, *pDict, *pArgs;
       PyObject *pFunc_Division, *pFunc_Multiplication, *pFunc_Addition, *pFunc_Subtraction;
       PyObject *pResult_divide, *pResult_multiply, *pResult_add, *pResult_subtract;
   
       // Build the name object
       pName = PyUnicode_FromString((char*)"wrapper_cython_A");

       // Load the module object
       pModule = PyImport_Import(pName);

       // pDict is a borrowed reference 
       pDict = PyModule_GetDict(pModule);

       // pFunc is also a borrowed reference 
       pFunc_Division = PyDict_GetItemString(pDict, (char*)"divide_withoutParam");
       pFunc_Multiplication = PyDict_GetItemString(pDict, (char*)"multiply_withoutParam");
       pFunc_Addition = PyDict_GetItemString(pDict, (char*)"add_withoutParam");
       pFunc_Subtraction = PyDict_GetItemString(pDict, (char*)"subtract_withoutParam");

       pResult_divide = PyObject_CallObject(pFunc_Division, NULL);
       pResult_multiply = PyObject_CallObject(pFunc_Multiplication, NULL);
       pResult_add = PyObject_CallObject(pFunc_Addition, NULL);
       pResult_subtract = PyObject_CallObject(pFunc_Subtraction, NULL);

       float result_divide, result_multiply, result_add, result_subtract;
       result_divide = PyLong_AsLong(pResult_divide);
       result_multiply = PyLong_AsLong(pResult_multiply);
       result_add = PyLong_AsLong(pResult_add);
       result_subtract = PyLong_AsLong(pResult_subtract);
       
       std::cout << "Division: " << result_divide << "\n";
       std::cout << "Multiplication: " << result_multiply << "\n";
       std::cout << "Addition: " << result_add << "\n";
       std::cout << "Subtraction: " << result_subtract << "\n";
       std::cout << "--------------------------------" << "\n";

       // pFunc is also a borrowed reference 
       pFunc_Division = PyDict_GetItemString(pDict, (char*)"divide");
       pFunc_Multiplication = PyDict_GetItemString(pDict, (char*)"multiply");
       pFunc_Addition = PyDict_GetItemString(pDict, (char*)"add");
       pFunc_Subtraction = PyDict_GetItemString(pDict, (char*)"subtract");

       double num_1 = 10.0;
       double num_2 = 5.0;
       pArgs = PyTuple_New(2);
       PyTuple_SetItem(pArgs, 0, PyFloat_FromDouble(num_1));
       PyTuple_SetItem(pArgs, 1, PyFloat_FromDouble(num_2));

       pResult_divide = PyObject_CallObject(pFunc_Division, pArgs);
       pResult_multiply = PyObject_CallObject(pFunc_Multiplication, pArgs);
       pResult_add = PyObject_CallObject(pFunc_Addition, pArgs);
       pResult_subtract = PyObject_CallObject(pFunc_Subtraction, pArgs);

       result_divide = PyFloat_AsDouble(pResult_divide);
       result_multiply = PyFloat_AsDouble(pResult_multiply);
       result_add = PyFloat_AsDouble(pResult_add);
       result_subtract = PyFloat_AsDouble(pResult_subtract);
       
       std::cout << "Division: " << result_divide << "\n";
       std::cout << "Multiplication: " << result_multiply << "\n";
       std::cout << "Addition: " << result_add << "\n";
       std::cout << "Subtraction: " << result_subtract << "\n";
       std::cout << "--------------------------------" << "\n";

       Py_DECREF(pName);
       Py_DECREF(pModule);
       Py_DECREF(pDict);
       Py_DECREF(pArgs);
       
       Py_DECREF(pFunc_Division);
       Py_DECREF(pFunc_Multiplication);
       Py_DECREF(pFunc_Addition);
       Py_DECREF(pFunc_Subtraction);

       Py_DECREF(pResult_divide);
       Py_DECREF(pResult_multiply);
       Py_DECREF(pResult_add);
       Py_DECREF(pResult_subtract);

       Py_Finalize();
}