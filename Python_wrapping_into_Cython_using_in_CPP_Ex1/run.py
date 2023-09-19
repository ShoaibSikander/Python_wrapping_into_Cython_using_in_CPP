from code_py import perform_division
from code_py import perform_multiplication
from code_py import perform_addition
from code_py import perform_subtraction

from wrapper_cy import divide_withoutParam
from wrapper_cy import multiply_withoutParam
from wrapper_cy import add_withoutParam
from wrapper_cy import subtract_withoutParam
from wrapper_cy import divide
from wrapper_cy import multiply
from wrapper_cy import add
from wrapper_cy import subtract

if __name__ == "__main__":
    
    num_1 = 10.0
    num_2 = 5.0

    #---------------------------------------------------------------------------
    # python functions calls
    result = perform_division(num_1, num_2)
    print('result: '+ str(result))

    result = perform_multiplication(num_1, num_2)
    print('result: '+ str(result))

    result = perform_addition(num_1, num_2)
    print('result: '+ str(result))

    result = perform_subtraction(num_1, num_2)
    print('result: '+ str(result))
    #---------------------------------------------------------------------------

    #---------------------------------------------------------------------------
    # cython function calls (functions without parameters)
    result = divide_withoutParam()
    print('result: '+ str(result))

    result = multiply_withoutParam()
    print('result: '+ str(result))

    result = add_withoutParam()
    print('result: '+ str(result))

    result = subtract_withoutParam()
    print('result: '+ str(result))
    #---------------------------------------------------------------------------

    #---------------------------------------------------------------------------
    # cython function calls (functions with parameters)
    result = divide(num_1, num_2)
    print('result: '+ str(result))

    result = multiply(num_1, num_2)
    print('result: '+ str(result))

    result = add(num_1, num_2)
    print('result: '+ str(result))

    result = subtract(num_1, num_2)
    print('result: '+ str(result))
    #---------------------------------------------------------------------------