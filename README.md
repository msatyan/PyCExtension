## [PyCExtension](https://msatyan.github.io/PyCExtension/)
This is a sample Python package to demonstrate how to extent functionality of CPython by using C language routines. The Python provides flexibility, at the same time it is inherently slow. The C language extensions can act as a turbocharger for Python modules where it needs speed and efficiency.  

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

#### Wheels
```bash
pip install wheel

cd PyCExtension/MyCLib1

# Wheel build
python setup.py bdist_wheel

# Install
# pip install  dist\MyCLib1-<package version>-cp36-cp36m-win_amd64.whl
pip install  dist/MyCLib1-3.0.7-cp36-cp36m-win_amd64.whl
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


#### [Wheels](https://wheel.readthedocs.io/en/stable/)
 The wheel is a ZIP-format archive with a specially formatted filename and the .whl extension. It is designed to contain all the files for a PEP 376 compatible install in a way that is very close to the on-disk format
https://pip.pypa.io/en/stable/reference/pip_wheel/


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

