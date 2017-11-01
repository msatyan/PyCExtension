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
    int rc=0;
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
    double rc=0;
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

// We can use this for SPEED TEST between Py and C
// Find the number of prime numbers between X and Y
static PyObject *MyCPrimeCount(PyObject *self, PyObject *args)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int VRange = 0;
	int isPrime = 0;
	int PrimeCount = 0;

	
	//printf("\n");
	if (!PyArg_ParseTuple(args, "ii", &x, &y))
	{
		return NULL;
	}

	if (x < 2)
		x = 2;

	++y;
	for ( i=x; i<y; i++)
	{
		isPrime = 1;

		VRange = i / 2; //This Validation Range is good enough
		++VRange;
		for (j=2; j<VRange; j++)
		{
			// Check whether it is  divisible by any number other than 1 
			if ( !(i%j) )
			{
				isPrime = 0;
				break;
			}
		}

		if (isPrime)
		{
			//printf(" [%d] ", i);
			++PrimeCount;
		}
	}

	PyObject *ret = Py_BuildValue("i", PrimeCount);
	return ret;
}




////////////////////////////////////////////////////////////////////

static PyMethodDef MyCLib1_Methods[] = 
{
    // The flag METH_VARARGS: will tell the interpreter the calling convention to be used for the C function
    // When using only METH_VARARGS, the function should expect the Python-level parameters to be 
    // passed in as a tuple acceptable for parsing via PyArg_ParseTuple()

    // (METH_VARARGS |  METH_KEYWORDS) : In this case, the C function should accept a 
    // third PyObject * parameter which will be a dictionary of keywords. 
    // Use PyArg_ParseTupleAndKeywords() to parse the arguments to such a function.

    // pattern : PyMehodName, CFunction, FFunctionType, Doc
    { "Add", (PyCFunction)MyC_Add, METH_VARARGS, "My C function to Add Int values" },
    { "Multiply", (PyCFunction)MyC_Multiply, METH_VARARGS, "My C function to Multiply Decimals." },
	{ "CPrimeCount", (PyCFunction)MyCPrimeCount, METH_VARARGS, "Find the number of prime numbers between X and Y" },
    
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
    -1, //size of per-interpreter state of the module, or -1 if the module keeps state in global variables
    MyCLib1_Methods,
};
#endif


// https://docs.python.org/2/extending/newtypes.html
// https://docs.python.org/3/extending/newtypes.html
// Module initialization function  
PyMODINIT_FUNC INIT_MyCLib1(void)
{
    // The initialization function must be named PyInit_<name>(), 
    // where <name> is the name of the 'module', and should be the only 
    // non-static item defined in the module file:
    PyObject* m=NULL;

#if PY_MAJOR_VERSION < 3
    m = Py_InitModule3(MyCLib1_ModuleName, MyCLib1_Methods, MyCLib1_Description);
#else
    m = PyModule_Create(&moduledef);
#endif

	return(m);
}