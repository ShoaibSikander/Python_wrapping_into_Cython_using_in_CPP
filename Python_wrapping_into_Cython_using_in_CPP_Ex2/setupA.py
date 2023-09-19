from setuptools import setup
from Cython.Build import cythonize

setup(name='exp', ext_modules=cythonize("wrapper_cython_A.pyx"), libraries=[('python3.8', {'include_dirs': ["~/usr/include/python3.8"]})], library_dirs=['~/lib'])