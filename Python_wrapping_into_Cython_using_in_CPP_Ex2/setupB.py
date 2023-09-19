from distutils.extension import Extension
from Cython.Distutils import build_ext
from distutils.core import setup

ext_modules = [Extension("wrapper_cython_B", ["wrapper_cython_B.pyx"], include_dirs=['.'])]
setup(name='wrapper_cython', cmdclass={'build_ext': build_ext}, ext_modules=ext_modules, script_args=['build_ext'], options={'build_ext':{'inplace':True, 'force':True}})