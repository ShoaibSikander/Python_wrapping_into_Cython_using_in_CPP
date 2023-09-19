from code_py import perform_division
from code_py import perform_multiplication
from code_py import perform_addition
from code_py import perform_subtraction

cpdef divide_withoutParam():
    cdef result = perform_division(10, 5)
    return result

cpdef multiply_withoutParam():
    cdef result = perform_multiplication(10, 5)
    return result

cpdef add_withoutParam():
    cdef result = perform_addition(10, 5)
    return result

cpdef subtract_withoutParam():
    cdef result = perform_subtraction(10, 5)
    return result

cpdef divide(float a, float b):
    cdef result = perform_division(a, b)
    return result

cpdef multiply(float a, float b):
    cdef result = perform_multiplication(a, b)
    return result

cpdef add(float a, float b):
    cdef result = perform_addition(a, b)
    return result

cpdef subtract(float a, float b):
    cdef result = perform_subtraction(a, b)
    return result
