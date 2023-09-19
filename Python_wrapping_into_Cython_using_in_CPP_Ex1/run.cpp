#include <iostream>
#include <dlfcn.h>
#include "Python.h"

int main(int argc, char *argv[])
{
   setenv("PYTHONPATH",".",1);
   
   // Initialize the Python Interpreter
   Py_Initialize();

   //----------------------------------------------------------------------------------------------
   double num_1 = 10.0;
   double num_2 = 5.0;

   FILE* pDateiOut = NULL;

   PyObject *pName, *pModule, *pDict;
   PyObject *pFunc_div_1, *pFunc_div_2, *pFunc_mul_1, *pFunc_mul_2, *pFunc_add_1, *pFunc_add_2, *pFunc_sub_1, *pFunc_sub_2;
   PyObject *pRes_div_1, *pRes_div_2, *pRes_mul_1, *pRes_mul_2, *pRes_add_1, *pRes_add_2, *pRes_sub_1, *pRes_sub_2;
   PyObject *pArgs_div, *pArgs_mul, *pArgs_add, *pArgs_sub;

   // Build the name object
   pName = PyUnicode_FromString((char*)"wrapper_cy");

   // Load the module object
   pModule = PyImport_Import(pName);

   // pDict is a borrowed reference 
   pDict = PyModule_GetDict(pModule);

   // pFunc is also a borrowed reference 
   // cython function calls (functions without parameters)
   pFunc_div_1 = PyDict_GetItemString(pDict, (char*)"divide_withoutParam");
   pFunc_mul_1 = PyDict_GetItemString(pDict, (char*)"multiply_withoutParam");
   pFunc_add_1 = PyDict_GetItemString(pDict, (char*)"add_withoutParam");
   pFunc_sub_1 = PyDict_GetItemString(pDict, (char*)"subtract_withoutParam");
   
   pRes_div_1 = PyObject_CallObject(pFunc_div_1, NULL);
   pRes_mul_1 = PyObject_CallObject(pFunc_mul_1, NULL);
   pRes_add_1 = PyObject_CallObject(pFunc_add_1, NULL);
   pRes_sub_1 = PyObject_CallObject(pFunc_sub_1, NULL);

   double result_div_1 = PyFloat_AsDouble(pRes_div_1);
   double result_mul_1 = PyFloat_AsDouble(pRes_mul_1);
   double result_add_1 = PyFloat_AsDouble(pRes_add_1);
   double result_sub_1 = PyFloat_AsDouble(pRes_sub_1);

   pDateiOut = fopen("Results1.txt", "w");
   fprintf(pDateiOut, "%lf / %lf = %lf\n", num_1, num_2, result_div_1);
   fprintf(pDateiOut, "%lf * %lf = %lf\n", num_1, num_2, result_mul_1);
   fprintf(pDateiOut, "%lf + %lf = %lf\n", num_1, num_2, result_add_1);
   fprintf(pDateiOut, "%lf - %lf = %lf\n", num_1, num_2, result_sub_1);
   fclose(pDateiOut);

   // cython function calls (functions with parameters)
   pArgs_div = PyTuple_New(2);
   PyTuple_SetItem(pArgs_div, 0, PyFloat_FromDouble(num_1));
   PyTuple_SetItem(pArgs_div, 1, PyFloat_FromDouble(num_2));
   pArgs_mul = PyTuple_New(2);
   PyTuple_SetItem(pArgs_mul, 0, PyFloat_FromDouble(num_1));
   PyTuple_SetItem(pArgs_mul, 1, PyFloat_FromDouble(num_2));
   pArgs_add = PyTuple_New(2);
   PyTuple_SetItem(pArgs_add, 0, PyFloat_FromDouble(num_1));
   PyTuple_SetItem(pArgs_add, 1, PyFloat_FromDouble(num_2));
   pArgs_sub = PyTuple_New(2);
   PyTuple_SetItem(pArgs_sub, 0, PyFloat_FromDouble(num_1));
   PyTuple_SetItem(pArgs_sub, 1, PyFloat_FromDouble(num_2));
   
   pFunc_div_2 = PyDict_GetItemString(pDict, (char*)"divide");
   pFunc_mul_2 = PyDict_GetItemString(pDict, (char*)"multiply");
   pFunc_add_2 = PyDict_GetItemString(pDict, (char*)"add");
   pFunc_sub_2 = PyDict_GetItemString(pDict, (char*)"subtract");

   pRes_div_2 = PyObject_CallObject(pFunc_div_2, pArgs_div);
   pRes_mul_2 = PyObject_CallObject(pFunc_mul_2, pArgs_mul);
   pRes_add_2 = PyObject_CallObject(pFunc_add_2, pArgs_add);
   pRes_sub_2 = PyObject_CallObject(pFunc_sub_2, pArgs_sub);

   double result_div_2 = PyFloat_AsDouble(pRes_div_2);
   double result_mul_2 = PyFloat_AsDouble(pRes_mul_2);
   double result_add_2 = PyFloat_AsDouble(pRes_add_2);
   double result_sub_2 = PyFloat_AsDouble(pRes_sub_2);

   pDateiOut = fopen("Results2.txt", "w");
   fprintf(pDateiOut, "%lf / %lf = %lf\n", num_1, num_2, result_div_2);
   fprintf(pDateiOut, "%lf * %lf = %lf\n", num_1, num_2, result_mul_2);
   fprintf(pDateiOut, "%lf + %lf = %lf\n", num_1, num_2, result_add_2);
   fprintf(pDateiOut, "%lf - %lf = %lf\n", num_1, num_2, result_sub_2);
   fclose(pDateiOut);

   // Clean up
   Py_DECREF(pName);
   Py_DECREF(pModule);
   Py_DECREF(pDict);

   Py_DECREF(pFunc_div_1);
   Py_DECREF(pFunc_div_2);
   Py_DECREF(pFunc_mul_1);
   Py_DECREF(pFunc_mul_2);
   Py_DECREF(pFunc_add_1);
   Py_DECREF(pFunc_add_2);
   Py_DECREF(pFunc_sub_1);
   Py_DECREF(pFunc_sub_2);

   Py_DECREF(pRes_div_1);
   Py_DECREF(pRes_div_2);
   Py_DECREF(pRes_mul_1);
   Py_DECREF(pRes_mul_2);
   Py_DECREF(pRes_add_1);
   Py_DECREF(pRes_add_2);
   Py_DECREF(pRes_sub_1);
   Py_DECREF(pRes_sub_2);

   Py_DECREF(pArgs_div);
   Py_DECREF(pArgs_mul);
   Py_DECREF(pArgs_add);
   Py_DECREF(pArgs_sub);
   //----------------------------------------------------------------------------------------------

   PyRun_SimpleString("from time import time,ctime\n"
        "print('Today is',ctime(time()))\n");
   std::cout << "----------------------" << "\n";
   
   //----------------------------------------------------------------------------------------------

   char filename[] = "code_py_1.py";
   FILE* fp;
   fp = _Py_fopen(filename, "r");
   PyRun_SimpleFile(fp, filename);
   std::cout << "----------------------" << "\n";

   //----------------------------------------------------------------------------------------------

   PyObject* obj = Py_BuildValue("s", "code_py_1.py");
   FILE* file = _Py_fopen_obj(obj, "r+");
   if (file != NULL)
   {
      PyRun_SimpleFile(file, "code_py_1.py");
   }
   std::cout << "----------------------" << "\n";

   //----------------------------------------------------------------------------------------------

   PyObject* pModule_Example(0), *pDict_Example, *pArg_Example, *pFunc_Example, *pResult_Example;
   pModule_Example = PyImport_ImportModule("code_py_2");
   pDict_Example = PyModule_GetDict(pModule_Example);
   pArg_Example= PyTuple_New(1);
   PyTuple_SetItem(pArg_Example, 0, PyUnicode_FromString((char*)"shoaib"));
   pFunc_Example = PyDict_GetItemString(pDict_Example, "print_py");
   pResult_Example = PyObject_CallObject(pFunc_Example, pArg_Example);
   const char* result = PyUnicode_AsUTF8(pResult_Example);
   std::cout << "Printing from C++: " << result << "\n";
   std::cout << "----------------------" << "\n";

   Py_DECREF(pModule_Example);
   Py_DECREF(pDict_Example);
   Py_DECREF(pArg_Example);
   Py_DECREF(pFunc_Example);
   Py_DECREF(pResult_Example);

   //----------------------------------------------------------------------------------------------

   PyObject *pName_work, *pModule_work, *pDict_work, *pFunc_work, *pArgs_work, *pResult_work;

   // Build the name object
   pName_work = PyUnicode_FromString((char*)"wrapper_cy");

   // Load the module object
   pModule_work = PyImport_Import(pName_work);

   // pDict is a borrowed reference 
   pDict_work = PyModule_GetDict(pModule_work);

   // pFunc is also a borrowed reference 
   pFunc_work = PyDict_GetItemString(pDict_work, (char*)"work_cy");
  
   pArgs_work = PyTuple_New(3);
   PyTuple_SetItem(pArgs_work, 0, PyUnicode_FromString((char*)"Muhammad "));
   PyTuple_SetItem(pArgs_work, 1, PyUnicode_FromString((char*)"Shoaib "));
   PyTuple_SetItem(pArgs_work, 2, PyUnicode_FromString((char*)"Sikander "));
    
   pResult_work = PyObject_CallObject(pFunc_work, pArgs_work);

   int counter = 0;
   PyObject *pList = PyList_New(counter);
   PyObject *iterator1 = PyObject_GetIter(pResult_work);
   PyObject *item1;
   if (iterator1 == NULL)
   {
      std::cout << "Error" << std::endl;
   }
   while((item1 = PyIter_Next(iterator1)))
   {
         counter = counter+1;
         PyList_Append(pList, item1);
   }

   PyObject *listElem1, *listElem2, *listElem3;
   listElem1 = PyList_GET_ITEM(pList, 0);
   listElem2 = PyList_GET_ITEM(pList, 1);
   listElem3 = PyList_GET_ITEM(pList, 2);

   PyObject* temp1s = PyDict_GetItemString(listElem1, (char*)"name");
   PyObject* temp2s = PyDict_GetItemString(listElem2, (char*)"name");
   PyObject* temp3s = PyDict_GetItemString(listElem3, (char*)"name");
   
   PyObject *encodedString1 = PyUnicode_AsEncodedString(temp1s, "UTF-8", "strict");
   PyObject *encodedString2 = PyUnicode_AsEncodedString(temp2s, "UTF-8", "strict");
   PyObject *encodedString3 = PyUnicode_AsEncodedString(temp3s, "UTF-8", "strict");
   
   const char* name1 = PyBytes_AsString(encodedString1); 
   const char* name2 = PyBytes_AsString(encodedString2); 
   const char* name3 = PyBytes_AsString(encodedString3);

   PyObject* temp1f = PyDict_GetItemString(listElem1, (char*)"year");
   PyObject* temp2f = PyDict_GetItemString(listElem2, (char*)"year");
   PyObject* temp3f = PyDict_GetItemString(listElem3, (char*)"year");
   
   int year1 = PyFloat_AsDouble(temp1f);
   int year2 = PyFloat_AsDouble(temp2f);
   int year3 = PyFloat_AsDouble(temp3f);

   std::cout << name1 << '\t' << year1 << '\n';
   std::cout << name2 << '\t' << year2 << '\n';
   std::cout << name3 << '\t' << year3 << '\n';
   std::cout << "----------------------" << "\n";

   pDateiOut = fopen("Results3.txt", "w");
   fprintf(pDateiOut, "name=%s year=%d \n", name1, year1);
   fprintf(pDateiOut, "name=%s year=%d \n", name2, year2);
   fprintf(pDateiOut, "name=%s year=%d \n", name3, year3);
   fclose(pDateiOut);
   
   // Clean up
   Py_DECREF(pName_work);
   Py_DECREF(pModule_work);
   //Py_DECREF(pDict_work);
   Py_DECREF(pFunc_work);
   Py_DECREF(pArgs_work);
   Py_DECREF(pResult_work);

   //----------------------------------------------------------------------------------------------

   Py_Finalize();
}