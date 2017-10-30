// Extending Python with C or C++
// https://docs.python.org/2/extending/extending.html


#include <stdio.h>
#include <stdlib.h>


// #include <Python.h> 
#ifdef _DEBUG
#undef _DEBUG
#include <python.h>
#define _DEBUG
#else
#include <python.h>
#endif


// #include <structmember.h>
// #include "MyCLib1Src.h"
// {
#define INIT_MyCLib1  PyInit_MyCLib1
// }




static PyObject *MyC_Add(PyObject *self, PyObject *args)
{
    int rc = 0;
    int a=0;
    int b=0;

    // https://docs.python.org/3/c-api/arg.html
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
    {
        return NULL;
    }

    rc = a + b;

    // https://docs.python.org/3/c-api/arg.html
    PyObject *ret = Py_BuildValue("i", rc);
    return ret;
}

static PyObject *MyC_Multiply(PyObject *self, PyObject *args)
{
    double rc = 0;
    double a=0;
    double b=0;

    // https://docs.python.org/3/c-api/arg.html
    // d (float) [double] Convert a Python floating point number to a C double.
    if (!PyArg_ParseTuple(args, "dd", &a, &b))
    {
        return NULL;
    }

    rc = a * b;

    // https://docs.python.org/3/c-api/arg.html
    PyObject *ret = Py_BuildValue("d", rc);
    return ret;
}


static PyMethodDef MyCLib1_Methods[] = 
{
    // pattern : PyMehodName, CFunction, FFunctionType, Doc
    { "Add", (PyCFunction)MyC_Add, METH_VARARGS, "My C function to Add Int values" },
    { "Multiply", (PyCFunction)MyC_Multiply, METH_VARARGS, "My C function to Multiply Decimals." },
    
    // An end-of-listing sentinel:
    { NULL, NULL, 0, NULL }
};


static const char MyCLib1_ModuleName[] = "MyCLib1";
static const char MyCLib1_Description[] = "My Python Native Extension Module1.";

// Python 3 and above
#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = 
{
    PyModuleDef_HEAD_INIT,
    MyCLib1_ModuleName,
    MyCLib1_Description,
    -1,
    MyCLib1_Methods,
};
#endif


// https://docs.python.org/2/extending/newtypes.html
// https://docs.python.org/3/extending/newtypes.html
// Module initialization function  
PyMODINIT_FUNC INIT_MyCLib1(void)
{
    PyObject* m=NULL;

#if PY_MAJOR_VERSION < 3
    // m = Py_InitModule3("IfxPy", IfxPy_Methods, "Informix Native Driver for Python.");
    m = Py_InitModule3(MyCLib1_ModuleName, MyCLib1_Methods, MyCLib1_Description);
#else
    m = PyModule_Create(&moduledef);
#endif

	return(m);
}