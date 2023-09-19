#include <iostream>
#include "wrapper_cython_B.h"
#include "wrapper_cython_B.c"
#include "Python.h"

int main()
{
       setenv("PYTHONPATH",".",1);
       
       auto err =  PyImport_AppendInittab("wrapper_cython_B", PyInit_wrapper_cython_B);
       if (err)
       {
              std::cout << "ERROR!\n";
              return 1;
       }
       
       // Initialize the Python Interpreter
       Py_Initialize();
       
       PyImport_ImportModule("wrapper_cython_B");

       PyObject *pResult_divide, *pResult_multiply, *pResult_add, *pResult_subtract;
       float result_divide, result_multiply, result_add, result_subtract;

       pResult_divide = __pyx_f_16wrapper_cython_B_divide_withoutParam();
       pResult_multiply = __pyx_f_16wrapper_cython_B_multiply_withoutParam();
       pResult_add = __pyx_f_16wrapper_cython_B_add_withoutParam();
       pResult_subtract = __pyx_f_16wrapper_cython_B_subtract_withoutParam();

       result_divide = PyLong_AsLong(pResult_divide);
       result_multiply = PyLong_AsLong(pResult_multiply);
       result_add = PyLong_AsLong(pResult_add);
       result_subtract = PyLong_AsLong(pResult_subtract);
       
       std::cout << "Division: " << result_divide << "\n";
       std::cout << "Multiplication: " << result_multiply << "\n";
       std::cout << "Addition: " << result_add << "\n";
       std::cout << "Subtraction: " << result_subtract << "\n";
       std::cout << "--------------------------------" << "\n";

       float num_1 = 10.0;
       float num_2 = 5.0;

       pResult_divide = __pyx_f_16wrapper_cython_B_divide(num_1, num_2);
       pResult_multiply = __pyx_f_16wrapper_cython_B_multiply(num_1, num_2);
       pResult_add = __pyx_f_16wrapper_cython_B_add(num_1, num_2);
       pResult_subtract = __pyx_f_16wrapper_cython_B_subtract(num_1, num_2);

       result_divide = PyLong_AsLong(pResult_divide);
       result_multiply = PyLong_AsLong(pResult_multiply);
       result_add = PyLong_AsLong(pResult_add);
       result_subtract = PyLong_AsLong(pResult_subtract);
       
       std::cout << "Division: " << result_divide << "\n";
       std::cout << "Multiplication: " << result_multiply << "\n";
       std::cout << "Addition: " << result_add << "\n";
       std::cout << "Subtraction: " << result_subtract << "\n";
       std::cout << "--------------------------------" << "\n";

       Py_DECREF(pResult_divide);
       Py_DECREF(pResult_multiply);
       Py_DECREF(pResult_add);
       Py_DECREF(pResult_subtract);
 
       Py_Finalize();
}