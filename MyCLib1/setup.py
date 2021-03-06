import os
import sys

# https://stackoverflow.com/questions/26664102/why-can-i-not-create-a-wheel-in-python
from setuptools import setup

PACKAGE = 'MyCLib1'
VERSION = '3.0.7'
LICENSE = 'Apache License 2.0'

py_home = os.environ['MY_PY_DIR']

from distutils.core import setup, Extension


module1 = Extension('MyCLib1',
                    include_dirs = [ py_home,  py_home + '/Include'],
                    sources = ['MyCLib1Src.c'])

setup (name    = PACKAGE,
       version = VERSION,
       license = LICENSE,
       description = 'This is my MyCLib1 Extension',
       author = 'Sathyanesh Krishnan',
       ext_modules = [module1])
