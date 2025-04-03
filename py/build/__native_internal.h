#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[69];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_object_internal;
extern CPyModule *CPyModule_object;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_re;
extern CPyModule *CPyModule_clipping;
extern CPyModule *CPyModule_vertex;
extern PyTypeObject *CPyType_face;
extern PyObject *CPyDef_face(void);
extern PyTypeObject *CPyType_object;
extern PyObject *CPyDef_object(void);
extern char CPyDef_face_____init__(PyObject *cpy_r_self);
extern PyObject *CPyPy_face_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern char CPyDef_object_____init__(PyObject *cpy_r_self);
extern PyObject *CPyPy_object_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_load_obj(PyObject *cpy_r_filepath);
extern PyObject *CPyPy_load_obj(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_draw_object(PyObject *cpy_r_obj, PyObject *cpy_r_vs, PyObject *cpy_r_v_uni, PyObject *cpy_r_fs, PyObject *cpy_r_f_uni, PyObject *cpy_r_tri_draw_func);
extern PyObject *CPyPy_draw_object(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
