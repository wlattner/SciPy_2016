#include <stdio.h>
#include "Python.h"
#include "tally.h"

static PyObject *tally_(PyObject *self, PyObject *args) {
    PyObject *buf;
    if (!PyArg_ParseTuple(args, "O", &buf)) {
        return NULL;
    }

    Py_buffer view;
    int buf_flags = PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT;
    if (PyObject_GetBuffer(buf, &view, buf_flags) == -1) {
        return NULL;
    }
    
    if (strcmp(view.format,"d") != 0) {
        PyErr_SetString(PyExc_TypeError, "we only take floats :(");
        PyBuffer_Release(&view);
        return NULL;
    }

    double result = tally(view.buf, view.shape[0]);
    PyBuffer_Release(&view);
    return Py_BuildValue("d", result);
}

static PyMethodDef MethodTable[] = {
    {"tally", &tally_, METH_VARARGS, "Compute the sum of an array"}, 
    { NULL, NULL, 0, NULL}
};

static struct PyModuleDef tally_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "tally_",
    .m_size = -1,
    .m_methods = MethodTable
};


PyMODINIT_FUNC PyInit_tally_(void) {
    return PyModule_Create(&tally_module);
}
