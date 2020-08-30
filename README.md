## [PyCExtension](https://msatyan.github.io/PyCExtension/)
This is a sample Python package to demonstrate how to extent functionality of CPython by using C language routines. The Python provides flexibility, at the same time it is inherently slow. The C language extensions can act as a turbocharger for Python modules where it needs speed and efficiency.  

#### Prerequisite
- Python
- setuptools
- pip
- wheel


##### build
```bash
cd PyCExtension/MyCLib1
python setup.py build
python setup.py install
```

##### Windows Installer Exe
```bash
cd PyCExtension/MyCLib1
python setup.py bdist_wininst
```

#### [Wheels](https://pythonwheels.com/)
- [wheel](https://pypi.org/project/wheel/)
- [wheel documentation](https://wheel.readthedocs.io/en/stable/)
- [The file format](https://www.python.org/dev/peps/pep-0427/)
- [The reference implementation](https://github.com/pypa/wheel)
- [Py2: Writing the Setup Script](https://docs.python.org/2.7/distutils/setupscript.html)
- [Py3: Writing the Setup Script](https://docs.python.org/3/distutils/setupscript.html)

```bash
pip install wheel

cd PyCExtension/MyCLib1

# Set MY_PY_DIR ENV to your python installation, eg:
SET MY_PY_DIR=C:\Dev\Anaconda3

# Wheel build
python setup.py bdist_wheel

# Install
# if you are on Python 3.7.4, then 
# pip install  dist\MyCLib1-<package version>-cp37-cp37m-win_amd64.whl
pip install  dist/MyCLib1-3.0.7-cp37-cp37m-win_amd64.whl


# upload to PyPi
twine upload dist/*

# To check status of the upload
# https://pypi.org/project/<sampleproject>
https://pypi.org/project/MyCLib1
```

### un/install the package 
```bash
# to uninstall 
pip uninstall MyCLib1

# to install
pip install MyCLib1
```

### [Miscellaneous](Miscellaneous.md)


## Reference Links
------------------

### Creating extension
Following source of information may help you to creat python native extension.  
* [Extending Python with C or C++](https://docs.python.org/3/extending/extending.html) 
* [Building C and C++ Extensions](https://docs.python.org/3/extending/building.html#building)
* [Packaging binary extensions](https://packaging.python.org/guides/packaging-binary-extensions/)
* [Python Packaging User Guide](https://media.readthedocs.org/pdf/python-packaging-user-guide/latest/python-packaging-user-guide.pdf)
* [Distributing Python Modules](https://docs.python.org/3/distutils/index.html#distutils-index)
* [VS Creating a C++ extension for Python](https://docs.microsoft.com/en-us/visualstudio/python/cpp-and-python) 
* [YouTube: Extending Python with C](https://www.youtube.com/watch?v=CYDakDJv2p4)
* [python extensions and embedding Python in C++ Apps](https://www.youtube.com/watch?v=bJq1n4gQFfw)
* [Writing Safe C Extensions - PyCon 2016](https://www.youtube.com/watch?v=Yq__HtUIH5Y)
* [Writing a C Python extension in 2017 PyCon 2017](https://www.youtube.com/watch?v=phe1s6p38gk)
* [Writing Python 2-3 compatible code](http://python-future.org/compatible_idioms.html)

* [Python Data Structures](http://thomas-cokelaer.info/tutorials/python/data_structures.html)
* [Parsing arguments](https://docs.python.org/3/c-api/arg.html)


#### Debug (so far all windows)
* [Debugging Python and C++ together](https://docs.microsoft.com/en-us/visualstudio/python/debugging-mixed-mode)
* [Installing Debugging Symbols for Python Interpreters](https://docs.microsoft.com/en-us/visualstudio/python/debugging-symbols-for-mixed-mode)
* [Profiling Python Code](https://docs.microsoft.com/en-us/visualstudio/python/profiling)




### [Packaging and Distributing]
* [Packaging and Distributing Projects](https://packaging.python.org/tutorials/distributing-packages/)
* [Setuptools’ documentation](https://setuptools.readthedocs.io/en/latest/)
* [Building and Distributing Packages with Setuptools](https://setuptools.readthedocs.io/en/latest/setuptools.html)
* [Automatic Script Creation](https://setuptools.readthedocs.io/en/latest/setuptools.html#automatic-script-creation)
* [Creating and publishing a Python package](http://blog.securem.eu/tips%20and%20tricks/2016/02/29/creating-and-publishing-a-python-module/)
* [How to Publish Your Package on PyPI](https://blog.jetbrains.com/pycharm/2017/05/how-to-publish-your-package-on-pypi/)
* [Uploading to PyPI](https://tom-christie.github.io/articles/pypi/)
* [How to submit a package to PyPI](http://peterdowns.com/posts/first-time-with-pypi.html)
* [How to Host your Python Package on PyPI with GitHub](https://www.codementor.io/arpitbhayani/host-your-python-package-using-github-on-pypi-du107t7ku)
* [Submitting a Python package with GitHub and PyPI](http://sherifsoliman.com/2016/09/30/Python-package-with-GitHub-PyPI/)
* [Wheel: A built-package format for Python](https://pypi.python.org/pypi/wheel)
* [Packaging Your Code](http://docs.python-guide.org/en/latest/shipping/packaging/)
* [Sharing Your Labor of Love: PyPI Quick and Dirty](https://hynek.me/articles/sharing-your-labor-of-love-pypi-quick-and-dirty/)


## [Platform Wheels](https://packaging.python.org/tutorials/distributing-packages/#platform-wheels)
#### [Wheels](https://wheel.readthedocs.io/en/stable/)
 The wheel is a ZIP-format archive with a specially formatted filename and the .whl extension. It is designed to contain all the files for a PEP 376 compatible install in a way that is very close to the on-disk format
https://pip.pypa.io/en/stable/reference/pip_wheel/

* [Platform Wheels](https://packaging.python.org/tutorials/distributing-packages/#platform-wheels)
* [PEP 425 -- Compatibility Tags for Built Distributions](https://www.python.org/dev/peps/pep-0425/)
* [PyPI - the Python Package Index](https://pypi.python.org/pypi?%3Aaction=home)
```
python setup.py bdist_wheel

bdist_wheel will detect that the code is not pure Python, and build a 
wheel that’s named such that it’s only usable on the platform that it was built on. 
For details on the naming of wheel files, see PEP 425.
https://www.python.org/dev/peps/pep-0425/
```

### Distribution format
By comparing the tags it supports with the tags listed by the distribution, an installer can make an educated decision about whether to download a particular built distribution without having to read its full metadata  
  
The wheel built package format includes these tags in its filenames, of the form   
{distribution}-{version}(-{build tag})?-{python tag}-{abi tag}-{platform tag}.whl.   
Other package formats may have their own conventions.  

```
Overview
The tag format is {python tag}-{abi tag}-{platform tag}

python tag
‘py27’, ‘cp33’
abi tag
‘cp32dmu’, ‘none’
platform tag
‘linux_x86_64’, ‘any’
For example, the tag py27-none-any indicates compatible with Python 2.7 (any Python 2.7 implementation) with no abi requirement, on any platform.
```

#### Python Tag
```
The Python tag indicates the implementation and version required by a distribution. Major implementations have abbreviated codes, initially:

py: Generic Python (does not require implementation-specific features)
cp: CPython
ip: IronPython
pp: PyPy
jy: Jython
```

#### ABI Tag
```
The ABI tag indicates which Python ABI is required by any included extension modules. For implementation-specific ABIs, the implementation is abbreviated in the same way as the Python Tag, e.g. cp33d would be the CPython 3.3 ABI with debugging.

The CPython stable ABI is abi3 as in the shared library suffix.
```

#### Platform Tag
```
The platform tag is simply distutils.util.get_platform() with all hyphens - and periods . replaced with underscore
win32
linux_i386
linux_x86_64
```

#### Setup
```python
pip install wheel 
pip install twine 
pip install tox 
pip install cookiecutter
```
* [Why setup.py bdist_wheel does not work](http://www.xavierdupre.fr/app/pymyinstall/helpsphinx/blog/2016/2016-02-27_setup_bdist_wheel.html)

### cookiecutter
http://cookiecutter.readthedocs.io/en/latest/usage.html
https://github.com/DerThorsten/xtensor-python-cookiecutter-v2
https://www.pydanny.com/cookie-project-templates-made-easy.html


### Continuous integration
* [Travis CI](https://github.com/travis-ci/travis-ci)


#### VS setting for the C proj (MyCLib1) to build native lib

System Env
```
SET MY_PY_DIR=C:\Dev\Anaconda3
```

#### MyCLib1 project properties -> Configuration Properties
General
```
1) Configuration Type : Dynamic Library (.dll)
2) Appy Change by clicking the Apply button
3) Target Extension change from .dll to .pyd
```

C/C++
```bash
# All Platforms
Additional Include Directories : $(MY_PY_DIR)\include
```

Linker
```bash
# All Platforms
Additional Library Directories : $(MY_PY_DIR)\libs
```

