from code_py import perform_division
from code_py import perform_multiplication
from code_py import perform_addition
from code_py import perform_subtraction

cdef public int i

cdef divide_withoutParam():
    cdef result = perform_division(10, 5)
    return result

cdef multiply_withoutParam():
    cdef result = perform_multiplication(10, 5)
    return result

cdef add_withoutParam():
    cdef result = perform_addition(10, 5)
    return result

cdef subtract_withoutParam():
    cdef result = perform_subtraction(10, 5)
    return result

cdef divide(float a, float b):
    cdef result = perform_division(a, b)
    return result

cdef multiply(float a, float b):
    cdef result = perform_multiplication(a, b)
    return result

cdef add(float a, float b):
    cdef result = perform_addition(a, b)
    return result

cdef subtract(float a, float b):
    cdef result = perform_subtraction(a, b)
    return result
