#ifndef MYPYC_NATIVE_H
#define MYPYC_NATIVE_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_a_v;
    PyObject *_a_vt;
    PyObject *_a_vn;
    PyObject *_b_v;
    PyObject *_b_vt;
    PyObject *_b_vn;
    PyObject *_c_v;
    PyObject *_c_vt;
    PyObject *_c_vn;
} object___faceObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_vertices;
    PyObject *_uvs;
    PyObject *_normals;
    PyObject *_faces;
} object___objectObject;

#endif
