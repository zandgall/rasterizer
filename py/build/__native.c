#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "__native.h"
#include "__native_internal.h"

static int
face_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *face_setup(PyTypeObject *type);
PyObject *CPyDef_face(void);

static PyObject *
face_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_face) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = face_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_face_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
face_traverse(object___faceObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_a_v);
    Py_VISIT(self->_a_vt);
    Py_VISIT(self->_a_vn);
    Py_VISIT(self->_b_v);
    Py_VISIT(self->_b_vt);
    Py_VISIT(self->_b_vn);
    Py_VISIT(self->_c_v);
    Py_VISIT(self->_c_vt);
    Py_VISIT(self->_c_vn);
    return 0;
}

static int
face_clear(object___faceObject *self)
{
    Py_CLEAR(self->_a_v);
    Py_CLEAR(self->_a_vt);
    Py_CLEAR(self->_a_vn);
    Py_CLEAR(self->_b_v);
    Py_CLEAR(self->_b_vt);
    Py_CLEAR(self->_b_vn);
    Py_CLEAR(self->_c_v);
    Py_CLEAR(self->_c_vt);
    Py_CLEAR(self->_c_vn);
    return 0;
}

static void
face_dealloc(object___faceObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, face_dealloc)
    face_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem face_vtable[1];
static bool
CPyDef_face_trait_vtable_setup(void)
{
    CPyVTableItem face_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_face_____init__,
    };
    memcpy(face_vtable, face_vtable_scratch, sizeof(face_vtable));
    return 1;
}

static PyObject *
face_get_a_v(object___faceObject *self, void *closure);
static int
face_set_a_v(object___faceObject *self, PyObject *value, void *closure);
static PyObject *
face_get_a_vt(object___faceObject *self, void *closure);
static int
face_set_a_vt(object___faceObject *self, PyObject *value, void *closure);
static PyObject *
face_get_a_vn(object___faceObject *self, void *closure);
static int
face_set_a_vn(object___faceObject *self, PyObject *value, void *closure);
static PyObject *
face_get_b_v(object___faceObject *self, void *closure);
static int
face_set_b_v(object___faceObject *self, PyObject *value, void *closure);
static PyObject *
face_get_b_vt(object___faceObject *self, void *closure);
static int
face_set_b_vt(object___faceObject *self, PyObject *value, void *closure);
static PyObject *
face_get_b_vn(object___faceObject *self, void *closure);
static int
face_set_b_vn(object___faceObject *self, PyObject *value, void *closure);
static PyObject *
face_get_c_v(object___faceObject *self, void *closure);
static int
face_set_c_v(object___faceObject *self, PyObject *value, void *closure);
static PyObject *
face_get_c_vt(object___faceObject *self, void *closure);
static int
face_set_c_vt(object___faceObject *self, PyObject *value, void *closure);
static PyObject *
face_get_c_vn(object___faceObject *self, void *closure);
static int
face_set_c_vn(object___faceObject *self, PyObject *value, void *closure);

static PyGetSetDef face_getseters[] = {
    {"a_v",
     (getter)face_get_a_v, (setter)face_set_a_v,
     NULL, NULL},
    {"a_vt",
     (getter)face_get_a_vt, (setter)face_set_a_vt,
     NULL, NULL},
    {"a_vn",
     (getter)face_get_a_vn, (setter)face_set_a_vn,
     NULL, NULL},
    {"b_v",
     (getter)face_get_b_v, (setter)face_set_b_v,
     NULL, NULL},
    {"b_vt",
     (getter)face_get_b_vt, (setter)face_set_b_vt,
     NULL, NULL},
    {"b_vn",
     (getter)face_get_b_vn, (setter)face_set_b_vn,
     NULL, NULL},
    {"c_v",
     (getter)face_get_c_v, (setter)face_set_c_v,
     NULL, NULL},
    {"c_vt",
     (getter)face_get_c_vt, (setter)face_set_c_vt,
     NULL, NULL},
    {"c_vn",
     (getter)face_get_c_vn, (setter)face_set_c_vn,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef face_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_face_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_face_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "face",
    .tp_new = face_new,
    .tp_dealloc = (destructor)face_dealloc,
    .tp_traverse = (traverseproc)face_traverse,
    .tp_clear = (inquiry)face_clear,
    .tp_getset = face_getseters,
    .tp_methods = face_methods,
    .tp_init = face_init,
    .tp_basicsize = sizeof(object___faceObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_face_template = &CPyType_face_template_;

static PyObject *
face_setup(PyTypeObject *type)
{
    object___faceObject *self;
    self = (object___faceObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = face_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_face(void)
{
    PyObject *self = face_setup(CPyType_face);
    if (self == NULL)
        return NULL;
    char res = CPyDef_face_____init__(self);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
face_get_a_v(object___faceObject *self, void *closure)
{
    if (unlikely(self->_a_v == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'a_v' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_a_v);
    PyObject *retval = self->_a_v;
    return retval;
}

static int
face_set_a_v(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'a_v' cannot be deleted");
        return -1;
    }
    if (self->_a_v != NULL) {
        CPy_DECREF(self->_a_v);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_a_v = tmp;
    return 0;
}

static PyObject *
face_get_a_vt(object___faceObject *self, void *closure)
{
    if (unlikely(self->_a_vt == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'a_vt' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_a_vt);
    PyObject *retval = self->_a_vt;
    return retval;
}

static int
face_set_a_vt(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'a_vt' cannot be deleted");
        return -1;
    }
    if (self->_a_vt != NULL) {
        CPy_DECREF(self->_a_vt);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_a_vt = tmp;
    return 0;
}

static PyObject *
face_get_a_vn(object___faceObject *self, void *closure)
{
    if (unlikely(self->_a_vn == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'a_vn' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_a_vn);
    PyObject *retval = self->_a_vn;
    return retval;
}

static int
face_set_a_vn(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'a_vn' cannot be deleted");
        return -1;
    }
    if (self->_a_vn != NULL) {
        CPy_DECREF(self->_a_vn);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_a_vn = tmp;
    return 0;
}

static PyObject *
face_get_b_v(object___faceObject *self, void *closure)
{
    if (unlikely(self->_b_v == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'b_v' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_b_v);
    PyObject *retval = self->_b_v;
    return retval;
}

static int
face_set_b_v(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'b_v' cannot be deleted");
        return -1;
    }
    if (self->_b_v != NULL) {
        CPy_DECREF(self->_b_v);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_b_v = tmp;
    return 0;
}

static PyObject *
face_get_b_vt(object___faceObject *self, void *closure)
{
    if (unlikely(self->_b_vt == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'b_vt' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_b_vt);
    PyObject *retval = self->_b_vt;
    return retval;
}

static int
face_set_b_vt(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'b_vt' cannot be deleted");
        return -1;
    }
    if (self->_b_vt != NULL) {
        CPy_DECREF(self->_b_vt);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_b_vt = tmp;
    return 0;
}

static PyObject *
face_get_b_vn(object___faceObject *self, void *closure)
{
    if (unlikely(self->_b_vn == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'b_vn' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_b_vn);
    PyObject *retval = self->_b_vn;
    return retval;
}

static int
face_set_b_vn(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'b_vn' cannot be deleted");
        return -1;
    }
    if (self->_b_vn != NULL) {
        CPy_DECREF(self->_b_vn);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_b_vn = tmp;
    return 0;
}

static PyObject *
face_get_c_v(object___faceObject *self, void *closure)
{
    if (unlikely(self->_c_v == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'c_v' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_c_v);
    PyObject *retval = self->_c_v;
    return retval;
}

static int
face_set_c_v(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'c_v' cannot be deleted");
        return -1;
    }
    if (self->_c_v != NULL) {
        CPy_DECREF(self->_c_v);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_c_v = tmp;
    return 0;
}

static PyObject *
face_get_c_vt(object___faceObject *self, void *closure)
{
    if (unlikely(self->_c_vt == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'c_vt' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_c_vt);
    PyObject *retval = self->_c_vt;
    return retval;
}

static int
face_set_c_vt(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'c_vt' cannot be deleted");
        return -1;
    }
    if (self->_c_vt != NULL) {
        CPy_DECREF(self->_c_vt);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_c_vt = tmp;
    return 0;
}

static PyObject *
face_get_c_vn(object___faceObject *self, void *closure)
{
    if (unlikely(self->_c_vn == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'c_vn' of 'face' undefined");
        return NULL;
    }
    CPy_INCREF(self->_c_vn);
    PyObject *retval = self->_c_vn;
    return retval;
}

static int
face_set_c_vn(object___faceObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'face' object attribute 'c_vn' cannot be deleted");
        return -1;
    }
    if (self->_c_vn != NULL) {
        CPy_DECREF(self->_c_vn);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_c_vn = tmp;
    return 0;
}

static int
object_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *object_setup(PyTypeObject *type);
PyObject *CPyDef_object(void);

static PyObject *
object_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_object) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = object_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_object_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
object_traverse(object___objectObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_vertices);
    Py_VISIT(self->_uvs);
    Py_VISIT(self->_normals);
    Py_VISIT(self->_faces);
    return 0;
}

static int
object_clear(object___objectObject *self)
{
    Py_CLEAR(self->_vertices);
    Py_CLEAR(self->_uvs);
    Py_CLEAR(self->_normals);
    Py_CLEAR(self->_faces);
    return 0;
}

static void
object_dealloc(object___objectObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, object_dealloc)
    object_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem object_vtable[1];
static bool
CPyDef_object_trait_vtable_setup(void)
{
    CPyVTableItem object_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_object_____init__,
    };
    memcpy(object_vtable, object_vtable_scratch, sizeof(object_vtable));
    return 1;
}

static PyObject *
object_get_vertices(object___objectObject *self, void *closure);
static int
object_set_vertices(object___objectObject *self, PyObject *value, void *closure);
static PyObject *
object_get_uvs(object___objectObject *self, void *closure);
static int
object_set_uvs(object___objectObject *self, PyObject *value, void *closure);
static PyObject *
object_get_normals(object___objectObject *self, void *closure);
static int
object_set_normals(object___objectObject *self, PyObject *value, void *closure);
static PyObject *
object_get_faces(object___objectObject *self, void *closure);
static int
object_set_faces(object___objectObject *self, PyObject *value, void *closure);

static PyGetSetDef object_getseters[] = {
    {"vertices",
     (getter)object_get_vertices, (setter)object_set_vertices,
     NULL, NULL},
    {"uvs",
     (getter)object_get_uvs, (setter)object_set_uvs,
     NULL, NULL},
    {"normals",
     (getter)object_get_normals, (setter)object_set_normals,
     NULL, NULL},
    {"faces",
     (getter)object_get_faces, (setter)object_set_faces,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef object_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_object_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_object_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "object",
    .tp_new = object_new,
    .tp_dealloc = (destructor)object_dealloc,
    .tp_traverse = (traverseproc)object_traverse,
    .tp_clear = (inquiry)object_clear,
    .tp_getset = object_getseters,
    .tp_methods = object_methods,
    .tp_init = object_init,
    .tp_basicsize = sizeof(object___objectObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_object_template = &CPyType_object_template_;

static PyObject *
object_setup(PyTypeObject *type)
{
    object___objectObject *self;
    self = (object___objectObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = object_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_object(void)
{
    PyObject *self = object_setup(CPyType_object);
    if (self == NULL)
        return NULL;
    char res = CPyDef_object_____init__(self);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
object_get_vertices(object___objectObject *self, void *closure)
{
    if (unlikely(self->_vertices == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'vertices' of 'object' undefined");
        return NULL;
    }
    CPy_INCREF(self->_vertices);
    PyObject *retval = self->_vertices;
    return retval;
}

static int
object_set_vertices(object___objectObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'object' object attribute 'vertices' cannot be deleted");
        return -1;
    }
    if (self->_vertices != NULL) {
        CPy_DECREF(self->_vertices);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_vertices = tmp;
    return 0;
}

static PyObject *
object_get_uvs(object___objectObject *self, void *closure)
{
    if (unlikely(self->_uvs == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'uvs' of 'object' undefined");
        return NULL;
    }
    CPy_INCREF(self->_uvs);
    PyObject *retval = self->_uvs;
    return retval;
}

static int
object_set_uvs(object___objectObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'object' object attribute 'uvs' cannot be deleted");
        return -1;
    }
    if (self->_uvs != NULL) {
        CPy_DECREF(self->_uvs);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_uvs = tmp;
    return 0;
}

static PyObject *
object_get_normals(object___objectObject *self, void *closure)
{
    if (unlikely(self->_normals == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'normals' of 'object' undefined");
        return NULL;
    }
    CPy_INCREF(self->_normals);
    PyObject *retval = self->_normals;
    return retval;
}

static int
object_set_normals(object___objectObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'object' object attribute 'normals' cannot be deleted");
        return -1;
    }
    if (self->_normals != NULL) {
        CPy_DECREF(self->_normals);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_normals = tmp;
    return 0;
}

static PyObject *
object_get_faces(object___objectObject *self, void *closure)
{
    if (unlikely(self->_faces == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'faces' of 'object' undefined");
        return NULL;
    }
    CPy_INCREF(self->_faces);
    PyObject *retval = self->_faces;
    return retval;
}

static int
object_set_faces(object___objectObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'object' object attribute 'faces' cannot be deleted");
        return -1;
    }
    if (self->_faces != NULL) {
        CPy_DECREF(self->_faces);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_faces = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {"load_obj", (PyCFunction)CPyPy_load_obj, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"draw_object", (PyCFunction)CPyPy_draw_object, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "object",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_object(void)
{
    PyObject* modname = NULL;
    if (CPyModule_object_internal) {
        Py_INCREF(CPyModule_object_internal);
        return CPyModule_object_internal;
    }
    CPyModule_object_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_object_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_object_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_object_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_object_internal;
    fail:
    Py_CLEAR(CPyModule_object_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_face);
    Py_CLEAR(CPyType_object);
    return NULL;
}

char CPyDef_face_____init__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r0);
    ((object___faceObject *)cpy_r_self)->_a_v = cpy_r_r0;
    cpy_r_r1 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r1);
    ((object___faceObject *)cpy_r_self)->_a_vt = cpy_r_r1;
    cpy_r_r2 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r2);
    ((object___faceObject *)cpy_r_self)->_a_vn = cpy_r_r2;
    cpy_r_r3 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r3);
    ((object___faceObject *)cpy_r_self)->_b_v = cpy_r_r3;
    cpy_r_r4 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r4);
    ((object___faceObject *)cpy_r_self)->_b_vt = cpy_r_r4;
    cpy_r_r5 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r5);
    ((object___faceObject *)cpy_r_self)->_b_vn = cpy_r_r5;
    cpy_r_r6 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r6);
    ((object___faceObject *)cpy_r_self)->_c_v = cpy_r_r6;
    cpy_r_r7 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r7);
    ((object___faceObject *)cpy_r_self)->_c_vt = cpy_r_r7;
    cpy_r_r8 = CPyStatics[55]; /* -1 */
    CPy_INCREF(cpy_r_r8);
    ((object___faceObject *)cpy_r_self)->_c_vn = cpy_r_r8;
    return 1;
}

PyObject *CPyPy_face_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "", "__init__", kwlist)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    char retval = CPyDef_face_____init__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("object.py", "__init__", 6, CPyStatic_globals);
    return NULL;
}

char CPyDef_object_____init__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    char cpy_r_r4;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("object.py", "__init__", 21, CPyStatic_globals);
        goto CPyL5;
    }
    ((object___objectObject *)cpy_r_self)->_vertices = cpy_r_r0;
    cpy_r_r1 = PyList_New(0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("object.py", "__init__", 22, CPyStatic_globals);
        goto CPyL5;
    }
    ((object___objectObject *)cpy_r_self)->_uvs = cpy_r_r1;
    cpy_r_r2 = PyList_New(0);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("object.py", "__init__", 23, CPyStatic_globals);
        goto CPyL5;
    }
    ((object___objectObject *)cpy_r_self)->_normals = cpy_r_r2;
    cpy_r_r3 = PyList_New(0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("object.py", "__init__", 24, CPyStatic_globals);
        goto CPyL5;
    }
    ((object___objectObject *)cpy_r_self)->_faces = cpy_r_r3;
    return 1;
CPyL5: ;
    cpy_r_r4 = 2;
    return cpy_r_r4;
}

PyObject *CPyPy_object_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "", "__init__", kwlist)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    char retval = CPyDef_object_____init__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("object.py", "__init__", 20, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_load_obj(PyObject *cpy_r_filepath) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_out;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_line_number;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_file;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_line;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    int32_t cpy_r_r32;
    char cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_nums;
    CPyTagged cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject **cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject **cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject **cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject **cpy_r_r90;
    PyObject *cpy_r_r91;
    int32_t cpy_r_r92;
    char cpy_r_r93;
    char cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject **cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject **cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    CPyTagged cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    int32_t cpy_r_r114;
    char cpy_r_r115;
    char cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject **cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject **cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject **cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject **cpy_r_r147;
    PyObject *cpy_r_r148;
    int32_t cpy_r_r149;
    char cpy_r_r150;
    char cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject **cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject **cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    CPyTagged cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    int32_t cpy_r_r171;
    char cpy_r_r172;
    char cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject **cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject **cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject **cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject **cpy_r_r206;
    PyObject *cpy_r_r207;
    int32_t cpy_r_r208;
    char cpy_r_r209;
    char cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject **cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject **cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    CPyTagged cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_f;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject **cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    CPyTagged cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    CPyTagged cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    int32_t cpy_r_r248;
    char cpy_r_r249;
    char cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    int32_t cpy_r_r259;
    char cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    int32_t cpy_r_r269;
    char cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    PyObject *cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    int32_t cpy_r_r279;
    char cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    CPyTagged cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    int32_t cpy_r_r287;
    char cpy_r_r288;
    char cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    PyObject *cpy_r_r292;
    PyObject *cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    int32_t cpy_r_r298;
    char cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    PyObject *cpy_r_r307;
    int32_t cpy_r_r308;
    char cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject *cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    int32_t cpy_r_r318;
    char cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    PyObject *cpy_r_r322;
    PyObject *cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    int32_t cpy_r_r328;
    char cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    int32_t cpy_r_r338;
    char cpy_r_r339;
    PyObject *cpy_r_r340;
    PyObject *cpy_r_r341;
    PyObject *cpy_r_r342;
    PyObject *cpy_r_r343;
    PyObject *cpy_r_r344;
    PyObject *cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    int32_t cpy_r_r348;
    char cpy_r_r349;
    PyObject *cpy_r_r350;
    PyObject *cpy_r_r351;
    CPyTagged cpy_r_r352;
    PyObject *cpy_r_r353;
    PyObject *cpy_r_r354;
    PyObject *cpy_r_r355;
    int32_t cpy_r_r356;
    char cpy_r_r357;
    char cpy_r_r358;
    PyObject *cpy_r_r359;
    PyObject *cpy_r_r360;
    PyObject *cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    int32_t cpy_r_r367;
    char cpy_r_r368;
    PyObject *cpy_r_r369;
    PyObject *cpy_r_r370;
    PyObject *cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    int32_t cpy_r_r377;
    char cpy_r_r378;
    PyObject *cpy_r_r379;
    PyObject *cpy_r_r380;
    PyObject *cpy_r_r381;
    PyObject *cpy_r_r382;
    PyObject *cpy_r_r383;
    PyObject *cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    int32_t cpy_r_r387;
    char cpy_r_r388;
    PyObject *cpy_r_r389;
    PyObject *cpy_r_r390;
    PyObject *cpy_r_r391;
    PyObject *cpy_r_r392;
    PyObject *cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    int32_t cpy_r_r397;
    char cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject *cpy_r_r400;
    PyObject *cpy_r_r401;
    PyObject *cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    PyObject *cpy_r_r405;
    PyObject *cpy_r_r406;
    int32_t cpy_r_r407;
    char cpy_r_r408;
    PyObject *cpy_r_r409;
    PyObject *cpy_r_r410;
    PyObject *cpy_r_r411;
    PyObject *cpy_r_r412;
    PyObject *cpy_r_r413;
    PyObject *cpy_r_r414;
    PyObject *cpy_r_r415;
    PyObject *cpy_r_r416;
    int32_t cpy_r_r417;
    char cpy_r_r418;
    PyObject *cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    PyObject *cpy_r_r423;
    PyObject *cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    int32_t cpy_r_r427;
    char cpy_r_r428;
    PyObject *cpy_r_r429;
    PyObject *cpy_r_r430;
    PyObject *cpy_r_r431;
    PyObject *cpy_r_r432;
    PyObject *cpy_r_r433;
    PyObject *cpy_r_r434;
    PyObject *cpy_r_r435;
    PyObject *cpy_r_r436;
    int32_t cpy_r_r437;
    char cpy_r_r438;
    PyObject *cpy_r_r439;
    PyObject *cpy_r_r440;
    PyObject *cpy_r_r441;
    PyObject *cpy_r_r442;
    PyObject *cpy_r_r443;
    PyObject *cpy_r_r444;
    PyObject *cpy_r_r445;
    PyObject *cpy_r_r446;
    int32_t cpy_r_r447;
    char cpy_r_r448;
    PyObject *cpy_r_r449;
    PyObject *cpy_r_r450;
    PyObject *cpy_r_r451;
    PyObject *cpy_r_r452;
    PyObject *cpy_r_r453;
    PyObject *cpy_r_r454;
    PyObject *cpy_r_r455;
    PyObject *cpy_r_r456;
    int32_t cpy_r_r457;
    char cpy_r_r458;
    PyObject *cpy_r_r459;
    PyObject *cpy_r_r460;
    PyObject *cpy_r_r461;
    PyObject *cpy_r_r462;
    PyObject *cpy_r_r463;
    PyObject *cpy_r_r464;
    PyObject *cpy_r_r465;
    PyObject *cpy_r_r466;
    int32_t cpy_r_r467;
    char cpy_r_r468;
    PyObject *cpy_r_r469;
    PyObject *cpy_r_r470;
    PyObject *cpy_r_r471;
    PyObject *cpy_r_r472;
    PyObject *cpy_r_r473;
    PyObject *cpy_r_r474;
    PyObject *cpy_r_r475;
    PyObject *cpy_r_r476;
    int32_t cpy_r_r477;
    char cpy_r_r478;
    PyObject *cpy_r_r479;
    PyObject *cpy_r_r480;
    PyObject *cpy_r_r481;
    PyObject *cpy_r_r482;
    PyObject *cpy_r_r483;
    PyObject *cpy_r_r484;
    PyObject *cpy_r_r485;
    PyObject *cpy_r_r486;
    int32_t cpy_r_r487;
    char cpy_r_r488;
    PyObject *cpy_r_r489;
    PyObject *cpy_r_r490;
    PyObject *cpy_r_r491;
    PyObject *cpy_r_r492;
    PyObject *cpy_r_r493;
    PyObject *cpy_r_r494;
    PyObject *cpy_r_r495;
    PyObject *cpy_r_r496;
    int32_t cpy_r_r497;
    char cpy_r_r498;
    PyObject *cpy_r_r499;
    PyObject *cpy_r_r500;
    PyObject *cpy_r_r501;
    PyObject *cpy_r_r502;
    PyObject *cpy_r_r503;
    PyObject *cpy_r_r504;
    PyObject *cpy_r_r505;
    PyObject *cpy_r_r506;
    int32_t cpy_r_r507;
    char cpy_r_r508;
    tuple_T3OOO cpy_r_r509;
    tuple_T3OOO cpy_r_r510;
    PyObject *cpy_r_r511;
    PyObject *cpy_r_r512;
    PyObject *cpy_r_r513;
    PyObject **cpy_r_r515;
    PyObject *cpy_r_r516;
    int32_t cpy_r_r517;
    char cpy_r_r518;
    char cpy_r_r519;
    char cpy_r_r520;
    tuple_T3OOO cpy_r_r521;
    tuple_T3OOO cpy_r_r522;
    tuple_T3OOO cpy_r_r523;
    PyObject *cpy_r_r524;
    PyObject **cpy_r_r526;
    PyObject *cpy_r_r527;
    char cpy_r_r528;
    PyObject *cpy_r_r529;
    cpy_r_r0 = CPyDef_object();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 27, CPyStatic_globals);
        goto CPyL261;
    }
    cpy_r_out = cpy_r_r0;
    cpy_r_r1 = CPyStatics[56]; /* 0 */
    CPy_INCREF(cpy_r_r1);
    cpy_r_line_number = cpy_r_r1;
    cpy_r_r2 = CPyStatics[3]; /* 'r' */
    cpy_r_r3 = CPyModule_builtins;
    cpy_r_r4 = CPyStatics[4]; /* 'open' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 30, CPyStatic_globals);
        goto CPyL262;
    }
    PyObject *cpy_r_r6[2] = {cpy_r_filepath, cpy_r_r2};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = _PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 2, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 30, CPyStatic_globals);
        goto CPyL262;
    }
    cpy_r_r9 = PyObject_Type(cpy_r_r8);
    cpy_r_r10 = CPyStatics[5]; /* '__exit__' */
    cpy_r_r11 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 30, CPyStatic_globals);
        goto CPyL263;
    }
    cpy_r_r12 = CPyStatics[6]; /* '__enter__' */
    cpy_r_r13 = CPyObject_GetAttr(cpy_r_r9, cpy_r_r12);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 30, CPyStatic_globals);
        goto CPyL264;
    }
    PyObject *cpy_r_r14[1] = {cpy_r_r8};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = _PyObject_Vectorcall(cpy_r_r13, cpy_r_r15, 1, 0);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 30, CPyStatic_globals);
        goto CPyL264;
    }
    cpy_r_r17 = 1;
    cpy_r_file = cpy_r_r16;
CPyL8: ;
    cpy_r_r18 = CPyStatics[7]; /* 'readline' */
    PyObject *cpy_r_r19[1] = {cpy_r_file};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = PyObject_VectorcallMethod(cpy_r_r18, cpy_r_r20, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 31, CPyStatic_globals);
        goto CPyL265;
    }
    CPy_INCREF(cpy_r_r21);
    cpy_r_line = cpy_r_r21;
    cpy_r_r22 = PyObject_IsTrue(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("object.py", "load_obj", 31, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r24 = cpy_r_r22;
    if (!cpy_r_r24) goto CPyL267;
    cpy_r_r25 = CPyStatics[57]; /* 1 */
    cpy_r_r26 = PyNumber_InPlaceAdd(cpy_r_line_number, cpy_r_r25);
    CPy_DECREF(cpy_r_line_number);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 32, CPyStatic_globals);
        goto CPyL268;
    }
    cpy_r_line_number = cpy_r_r26;
    cpy_r_r27 = CPyStatics[8]; /* 'v ' */
    cpy_r_r28 = CPyStatics[9]; /* 'startswith' */
    PyObject *cpy_r_r29[2] = {cpy_r_line, cpy_r_r27};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = PyObject_VectorcallMethod(cpy_r_r28, cpy_r_r30, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 33, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r32 = PyObject_IsTrue(cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    cpy_r_r33 = cpy_r_r32 >= 0;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("object.py", "load_obj", 33, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r34 = cpy_r_r32;
    if (!cpy_r_r34) goto CPyL38;
    cpy_r_r35 = (PyObject *)&PyFloat_Type;
    cpy_r_r36 = CPyStatics[10]; /* '-?\\d+\\.\\d*' */
    cpy_r_r37 = CPyModule_re;
    cpy_r_r38 = CPyStatics[11]; /* 'findall' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 34, CPyStatic_globals);
        goto CPyL266;
    }
    PyObject *cpy_r_r40[2] = {cpy_r_r36, cpy_r_line};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = _PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 2, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 34, CPyStatic_globals);
        goto CPyL266;
    }
    CPy_DECREF(cpy_r_line);
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[12]; /* 'map' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 34, CPyStatic_globals);
        goto CPyL269;
    }
    PyObject *cpy_r_r46[2] = {cpy_r_r35, cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 2, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 34, CPyStatic_globals);
        goto CPyL269;
    }
    CPy_DECREF(cpy_r_r42);
    cpy_r_r49 = PySequence_List(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 34, CPyStatic_globals);
        goto CPyL265;
    }
    cpy_r_nums = cpy_r_r49;
    cpy_r_r50 = CPyObject_Size(cpy_r_nums);
    if (unlikely(cpy_r_r50 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "load_obj", 35, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r51 = CPyTagged_StealAsObject(cpy_r_r50);
    cpy_r_r52 = CPyStatics[58]; /* 3 */
    cpy_r_r53 = PyObject_RichCompare(cpy_r_r51, cpy_r_r52, 0);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 35, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r54 = PyObject_IsTrue(cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("object.py", "load_obj", 35, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r56 = cpy_r_r54;
    if (!cpy_r_r56) goto CPyL30;
    cpy_r_r57 = CPyStatics[13]; /* 'Error: vertex at line #' */
    cpy_r_r58 = PyObject_Str(cpy_r_line_number);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 36, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r59 = PyUnicode_Concat(cpy_r_r57, cpy_r_r58);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 36, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r60 = CPyStatics[14]; /* " doesn't have 3 or more coordinates" */
    cpy_r_r61 = PyUnicode_Concat(cpy_r_r59, cpy_r_r60);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 36, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r62 = CPyModule_builtins;
    cpy_r_r63 = CPyStatics[15]; /* 'print' */
    cpy_r_r64 = CPyObject_GetAttr(cpy_r_r62, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 36, CPyStatic_globals);
        goto CPyL271;
    }
    PyObject *cpy_r_r65[1] = {cpy_r_r61};
    cpy_r_r66 = (PyObject **)&cpy_r_r65;
    cpy_r_r67 = _PyObject_Vectorcall(cpy_r_r64, cpy_r_r66, 1, 0);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 36, CPyStatic_globals);
        goto CPyL271;
    } else
        goto CPyL272;
CPyL29: ;
    CPy_DECREF(cpy_r_r61);
CPyL30: ;
    cpy_r_r68 = CPyStatics[16]; /* 'vertices' */
    cpy_r_r69 = CPyObject_GetAttr(cpy_r_out, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 37, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r70 = CPyStatics[56]; /* 0 */
    cpy_r_r71 = PyObject_GetItem(cpy_r_nums, cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 37, CPyStatic_globals);
        goto CPyL273;
    }
    cpy_r_r72 = CPyStatics[57]; /* 1 */
    cpy_r_r73 = PyObject_GetItem(cpy_r_nums, cpy_r_r72);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 37, CPyStatic_globals);
        goto CPyL274;
    }
    cpy_r_r74 = CPyStatics[59]; /* 2 */
    cpy_r_r75 = PyObject_GetItem(cpy_r_nums, cpy_r_r74);
    CPy_DECREF(cpy_r_nums);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 37, CPyStatic_globals);
        goto CPyL275;
    }
    cpy_r_r76 = CPyModule_vertex;
    cpy_r_r77 = CPyStatics[17]; /* 'vec4' */
    cpy_r_r78 = CPyObject_GetAttr(cpy_r_r76, cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 37, CPyStatic_globals);
        goto CPyL276;
    }
    cpy_r_r79 = CPyStatics[57]; /* 1 */
    PyObject *cpy_r_r80[4] = {cpy_r_r71, cpy_r_r73, cpy_r_r75, cpy_r_r79};
    cpy_r_r81 = (PyObject **)&cpy_r_r80;
    cpy_r_r82 = _PyObject_Vectorcall(cpy_r_r78, cpy_r_r81, 4, 0);
    CPy_DECREF(cpy_r_r78);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 37, CPyStatic_globals);
        goto CPyL276;
    }
    CPy_DECREF(cpy_r_r71);
    CPy_DECREF(cpy_r_r73);
    CPy_DECREF(cpy_r_r75);
    cpy_r_r83 = CPyStatics[18]; /* 'append' */
    PyObject *cpy_r_r84[2] = {cpy_r_r69, cpy_r_r82};
    cpy_r_r85 = (PyObject **)&cpy_r_r84;
    cpy_r_r86 = PyObject_VectorcallMethod(cpy_r_r83, cpy_r_r85, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 37, CPyStatic_globals);
        goto CPyL277;
    } else
        goto CPyL278;
CPyL37: ;
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r82);
    goto CPyL8;
CPyL38: ;
    cpy_r_r87 = CPyStatics[19]; /* 'vt ' */
    cpy_r_r88 = CPyStatics[9]; /* 'startswith' */
    PyObject *cpy_r_r89[2] = {cpy_r_line, cpy_r_r87};
    cpy_r_r90 = (PyObject **)&cpy_r_r89;
    cpy_r_r91 = PyObject_VectorcallMethod(cpy_r_r88, cpy_r_r90, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 38, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r92 = PyObject_IsTrue(cpy_r_r91);
    CPy_DECREF(cpy_r_r91);
    cpy_r_r93 = cpy_r_r92 >= 0;
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("object.py", "load_obj", 38, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r94 = cpy_r_r92;
    if (!cpy_r_r94) goto CPyL63;
    cpy_r_r95 = (PyObject *)&PyFloat_Type;
    cpy_r_r96 = CPyStatics[10]; /* '-?\\d+\\.\\d*' */
    cpy_r_r97 = CPyModule_re;
    cpy_r_r98 = CPyStatics[11]; /* 'findall' */
    cpy_r_r99 = CPyObject_GetAttr(cpy_r_r97, cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 39, CPyStatic_globals);
        goto CPyL266;
    }
    PyObject *cpy_r_r100[2] = {cpy_r_r96, cpy_r_line};
    cpy_r_r101 = (PyObject **)&cpy_r_r100;
    cpy_r_r102 = _PyObject_Vectorcall(cpy_r_r99, cpy_r_r101, 2, 0);
    CPy_DECREF(cpy_r_r99);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 39, CPyStatic_globals);
        goto CPyL266;
    }
    CPy_DECREF(cpy_r_line);
    cpy_r_r103 = CPyModule_builtins;
    cpy_r_r104 = CPyStatics[12]; /* 'map' */
    cpy_r_r105 = CPyObject_GetAttr(cpy_r_r103, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 39, CPyStatic_globals);
        goto CPyL279;
    }
    PyObject *cpy_r_r106[2] = {cpy_r_r95, cpy_r_r102};
    cpy_r_r107 = (PyObject **)&cpy_r_r106;
    cpy_r_r108 = _PyObject_Vectorcall(cpy_r_r105, cpy_r_r107, 2, 0);
    CPy_DECREF(cpy_r_r105);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 39, CPyStatic_globals);
        goto CPyL279;
    }
    CPy_DECREF(cpy_r_r102);
    cpy_r_r109 = PySequence_List(cpy_r_r108);
    CPy_DECREF(cpy_r_r108);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 39, CPyStatic_globals);
        goto CPyL265;
    }
    cpy_r_nums = cpy_r_r109;
    cpy_r_r110 = CPyObject_Size(cpy_r_nums);
    if (unlikely(cpy_r_r110 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "load_obj", 40, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r111 = CPyTagged_StealAsObject(cpy_r_r110);
    cpy_r_r112 = CPyStatics[59]; /* 2 */
    cpy_r_r113 = PyObject_RichCompare(cpy_r_r111, cpy_r_r112, 0);
    CPy_DECREF(cpy_r_r111);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 40, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r114 = PyObject_IsTrue(cpy_r_r113);
    CPy_DECREF(cpy_r_r113);
    cpy_r_r115 = cpy_r_r114 >= 0;
    if (unlikely(!cpy_r_r115)) {
        CPy_AddTraceback("object.py", "load_obj", 40, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r116 = cpy_r_r114;
    if (!cpy_r_r116) goto CPyL56;
    cpy_r_r117 = CPyStatics[20]; /* 'Error: vertex texture at line #' */
    cpy_r_r118 = PyObject_Str(cpy_r_line_number);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 41, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r119 = PyUnicode_Concat(cpy_r_r117, cpy_r_r118);
    CPy_DECREF(cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 41, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r120 = CPyStatics[21]; /* " doesn't have 2 or more coordinates" */
    cpy_r_r121 = PyUnicode_Concat(cpy_r_r119, cpy_r_r120);
    CPy_DECREF(cpy_r_r119);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 41, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r122 = CPyModule_builtins;
    cpy_r_r123 = CPyStatics[15]; /* 'print' */
    cpy_r_r124 = CPyObject_GetAttr(cpy_r_r122, cpy_r_r123);
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 41, CPyStatic_globals);
        goto CPyL280;
    }
    PyObject *cpy_r_r125[1] = {cpy_r_r121};
    cpy_r_r126 = (PyObject **)&cpy_r_r125;
    cpy_r_r127 = _PyObject_Vectorcall(cpy_r_r124, cpy_r_r126, 1, 0);
    CPy_DECREF(cpy_r_r124);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 41, CPyStatic_globals);
        goto CPyL280;
    } else
        goto CPyL281;
CPyL55: ;
    CPy_DECREF(cpy_r_r121);
CPyL56: ;
    cpy_r_r128 = CPyStatics[22]; /* 'uvs' */
    cpy_r_r129 = CPyObject_GetAttr(cpy_r_out, cpy_r_r128);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 42, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r130 = CPyStatics[56]; /* 0 */
    cpy_r_r131 = PyObject_GetItem(cpy_r_nums, cpy_r_r130);
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 42, CPyStatic_globals);
        goto CPyL282;
    }
    cpy_r_r132 = CPyStatics[57]; /* 1 */
    cpy_r_r133 = PyObject_GetItem(cpy_r_nums, cpy_r_r132);
    CPy_DECREF(cpy_r_nums);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 42, CPyStatic_globals);
        goto CPyL283;
    }
    cpy_r_r134 = CPyModule_vertex;
    cpy_r_r135 = CPyStatics[23]; /* 'vec2' */
    cpy_r_r136 = CPyObject_GetAttr(cpy_r_r134, cpy_r_r135);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 42, CPyStatic_globals);
        goto CPyL284;
    }
    PyObject *cpy_r_r137[2] = {cpy_r_r131, cpy_r_r133};
    cpy_r_r138 = (PyObject **)&cpy_r_r137;
    cpy_r_r139 = _PyObject_Vectorcall(cpy_r_r136, cpy_r_r138, 2, 0);
    CPy_DECREF(cpy_r_r136);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 42, CPyStatic_globals);
        goto CPyL284;
    }
    CPy_DECREF(cpy_r_r131);
    CPy_DECREF(cpy_r_r133);
    cpy_r_r140 = CPyStatics[18]; /* 'append' */
    PyObject *cpy_r_r141[2] = {cpy_r_r129, cpy_r_r139};
    cpy_r_r142 = (PyObject **)&cpy_r_r141;
    cpy_r_r143 = PyObject_VectorcallMethod(cpy_r_r140, cpy_r_r142, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 42, CPyStatic_globals);
        goto CPyL285;
    } else
        goto CPyL286;
CPyL62: ;
    CPy_DECREF(cpy_r_r129);
    CPy_DECREF(cpy_r_r139);
    goto CPyL8;
CPyL63: ;
    cpy_r_r144 = CPyStatics[24]; /* 'vn ' */
    cpy_r_r145 = CPyStatics[9]; /* 'startswith' */
    PyObject *cpy_r_r146[2] = {cpy_r_line, cpy_r_r144};
    cpy_r_r147 = (PyObject **)&cpy_r_r146;
    cpy_r_r148 = PyObject_VectorcallMethod(cpy_r_r145, cpy_r_r147, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 43, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r149 = PyObject_IsTrue(cpy_r_r148);
    CPy_DECREF(cpy_r_r148);
    cpy_r_r150 = cpy_r_r149 >= 0;
    if (unlikely(!cpy_r_r150)) {
        CPy_AddTraceback("object.py", "load_obj", 43, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r151 = cpy_r_r149;
    if (!cpy_r_r151) goto CPyL89;
    cpy_r_r152 = (PyObject *)&PyFloat_Type;
    cpy_r_r153 = CPyStatics[10]; /* '-?\\d+\\.\\d*' */
    cpy_r_r154 = CPyModule_re;
    cpy_r_r155 = CPyStatics[11]; /* 'findall' */
    cpy_r_r156 = CPyObject_GetAttr(cpy_r_r154, cpy_r_r155);
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 44, CPyStatic_globals);
        goto CPyL266;
    }
    PyObject *cpy_r_r157[2] = {cpy_r_r153, cpy_r_line};
    cpy_r_r158 = (PyObject **)&cpy_r_r157;
    cpy_r_r159 = _PyObject_Vectorcall(cpy_r_r156, cpy_r_r158, 2, 0);
    CPy_DECREF(cpy_r_r156);
    if (unlikely(cpy_r_r159 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 44, CPyStatic_globals);
        goto CPyL266;
    }
    CPy_DECREF(cpy_r_line);
    cpy_r_r160 = CPyModule_builtins;
    cpy_r_r161 = CPyStatics[12]; /* 'map' */
    cpy_r_r162 = CPyObject_GetAttr(cpy_r_r160, cpy_r_r161);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 44, CPyStatic_globals);
        goto CPyL287;
    }
    PyObject *cpy_r_r163[2] = {cpy_r_r152, cpy_r_r159};
    cpy_r_r164 = (PyObject **)&cpy_r_r163;
    cpy_r_r165 = _PyObject_Vectorcall(cpy_r_r162, cpy_r_r164, 2, 0);
    CPy_DECREF(cpy_r_r162);
    if (unlikely(cpy_r_r165 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 44, CPyStatic_globals);
        goto CPyL287;
    }
    CPy_DECREF(cpy_r_r159);
    cpy_r_r166 = PySequence_List(cpy_r_r165);
    CPy_DECREF(cpy_r_r165);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 44, CPyStatic_globals);
        goto CPyL265;
    }
    cpy_r_nums = cpy_r_r166;
    cpy_r_r167 = CPyObject_Size(cpy_r_nums);
    if (unlikely(cpy_r_r167 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "load_obj", 45, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r168 = CPyTagged_StealAsObject(cpy_r_r167);
    cpy_r_r169 = CPyStatics[58]; /* 3 */
    cpy_r_r170 = PyObject_RichCompare(cpy_r_r168, cpy_r_r169, 0);
    CPy_DECREF(cpy_r_r168);
    if (unlikely(cpy_r_r170 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 45, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r171 = PyObject_IsTrue(cpy_r_r170);
    CPy_DECREF(cpy_r_r170);
    cpy_r_r172 = cpy_r_r171 >= 0;
    if (unlikely(!cpy_r_r172)) {
        CPy_AddTraceback("object.py", "load_obj", 45, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r173 = cpy_r_r171;
    if (!cpy_r_r173) goto CPyL81;
    cpy_r_r174 = CPyStatics[25]; /* 'Error: vertex normal at line #' */
    cpy_r_r175 = PyObject_Str(cpy_r_line_number);
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 46, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r176 = PyUnicode_Concat(cpy_r_r174, cpy_r_r175);
    CPy_DECREF(cpy_r_r175);
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 46, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r177 = CPyStatics[14]; /* " doesn't have 3 or more coordinates" */
    cpy_r_r178 = PyUnicode_Concat(cpy_r_r176, cpy_r_r177);
    CPy_DECREF(cpy_r_r176);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 46, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r179 = CPyModule_builtins;
    cpy_r_r180 = CPyStatics[15]; /* 'print' */
    cpy_r_r181 = CPyObject_GetAttr(cpy_r_r179, cpy_r_r180);
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 46, CPyStatic_globals);
        goto CPyL288;
    }
    PyObject *cpy_r_r182[1] = {cpy_r_r178};
    cpy_r_r183 = (PyObject **)&cpy_r_r182;
    cpy_r_r184 = _PyObject_Vectorcall(cpy_r_r181, cpy_r_r183, 1, 0);
    CPy_DECREF(cpy_r_r181);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 46, CPyStatic_globals);
        goto CPyL288;
    } else
        goto CPyL289;
CPyL80: ;
    CPy_DECREF(cpy_r_r178);
CPyL81: ;
    cpy_r_r185 = CPyStatics[26]; /* 'normals' */
    cpy_r_r186 = CPyObject_GetAttr(cpy_r_out, cpy_r_r185);
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 47, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r187 = CPyStatics[56]; /* 0 */
    cpy_r_r188 = PyObject_GetItem(cpy_r_nums, cpy_r_r187);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 47, CPyStatic_globals);
        goto CPyL290;
    }
    cpy_r_r189 = CPyStatics[57]; /* 1 */
    cpy_r_r190 = PyObject_GetItem(cpy_r_nums, cpy_r_r189);
    if (unlikely(cpy_r_r190 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 47, CPyStatic_globals);
        goto CPyL291;
    }
    cpy_r_r191 = CPyStatics[59]; /* 2 */
    cpy_r_r192 = PyObject_GetItem(cpy_r_nums, cpy_r_r191);
    CPy_DECREF(cpy_r_nums);
    if (unlikely(cpy_r_r192 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 47, CPyStatic_globals);
        goto CPyL292;
    }
    cpy_r_r193 = CPyModule_vertex;
    cpy_r_r194 = CPyStatics[27]; /* 'vec3' */
    cpy_r_r195 = CPyObject_GetAttr(cpy_r_r193, cpy_r_r194);
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 47, CPyStatic_globals);
        goto CPyL293;
    }
    PyObject *cpy_r_r196[3] = {cpy_r_r188, cpy_r_r190, cpy_r_r192};
    cpy_r_r197 = (PyObject **)&cpy_r_r196;
    cpy_r_r198 = _PyObject_Vectorcall(cpy_r_r195, cpy_r_r197, 3, 0);
    CPy_DECREF(cpy_r_r195);
    if (unlikely(cpy_r_r198 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 47, CPyStatic_globals);
        goto CPyL293;
    }
    CPy_DECREF(cpy_r_r188);
    CPy_DECREF(cpy_r_r190);
    CPy_DECREF(cpy_r_r192);
    cpy_r_r199 = CPyStatics[18]; /* 'append' */
    PyObject *cpy_r_r200[2] = {cpy_r_r186, cpy_r_r198};
    cpy_r_r201 = (PyObject **)&cpy_r_r200;
    cpy_r_r202 = PyObject_VectorcallMethod(cpy_r_r199, cpy_r_r201, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r202 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 47, CPyStatic_globals);
        goto CPyL294;
    } else
        goto CPyL295;
CPyL88: ;
    CPy_DECREF(cpy_r_r186);
    CPy_DECREF(cpy_r_r198);
    goto CPyL8;
CPyL89: ;
    cpy_r_r203 = CPyStatics[28]; /* 'f ' */
    cpy_r_r204 = CPyStatics[9]; /* 'startswith' */
    PyObject *cpy_r_r205[2] = {cpy_r_line, cpy_r_r203};
    cpy_r_r206 = (PyObject **)&cpy_r_r205;
    cpy_r_r207 = PyObject_VectorcallMethod(cpy_r_r204, cpy_r_r206, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r207 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 48, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r208 = PyObject_IsTrue(cpy_r_r207);
    CPy_DECREF(cpy_r_r207);
    cpy_r_r209 = cpy_r_r208 >= 0;
    if (unlikely(!cpy_r_r209)) {
        CPy_AddTraceback("object.py", "load_obj", 48, CPyStatic_globals);
        goto CPyL266;
    }
    cpy_r_r210 = cpy_r_r208;
    if (!cpy_r_r210) goto CPyL296;
    cpy_r_r211 = (PyObject *)&PyLong_Type;
    cpy_r_r212 = CPyStatics[29]; /* '\\d+' */
    cpy_r_r213 = CPyModule_re;
    cpy_r_r214 = CPyStatics[11]; /* 'findall' */
    cpy_r_r215 = CPyObject_GetAttr(cpy_r_r213, cpy_r_r214);
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 49, CPyStatic_globals);
        goto CPyL266;
    }
    PyObject *cpy_r_r216[2] = {cpy_r_r212, cpy_r_line};
    cpy_r_r217 = (PyObject **)&cpy_r_r216;
    cpy_r_r218 = _PyObject_Vectorcall(cpy_r_r215, cpy_r_r217, 2, 0);
    CPy_DECREF(cpy_r_r215);
    if (unlikely(cpy_r_r218 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 49, CPyStatic_globals);
        goto CPyL266;
    }
    CPy_DECREF(cpy_r_line);
    cpy_r_r219 = CPyModule_builtins;
    cpy_r_r220 = CPyStatics[12]; /* 'map' */
    cpy_r_r221 = CPyObject_GetAttr(cpy_r_r219, cpy_r_r220);
    if (unlikely(cpy_r_r221 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 49, CPyStatic_globals);
        goto CPyL297;
    }
    PyObject *cpy_r_r222[2] = {cpy_r_r211, cpy_r_r218};
    cpy_r_r223 = (PyObject **)&cpy_r_r222;
    cpy_r_r224 = _PyObject_Vectorcall(cpy_r_r221, cpy_r_r223, 2, 0);
    CPy_DECREF(cpy_r_r221);
    if (unlikely(cpy_r_r224 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 49, CPyStatic_globals);
        goto CPyL297;
    }
    CPy_DECREF(cpy_r_r218);
    cpy_r_r225 = PySequence_List(cpy_r_r224);
    CPy_DECREF(cpy_r_r224);
    if (unlikely(cpy_r_r225 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 49, CPyStatic_globals);
        goto CPyL265;
    }
    cpy_r_nums = cpy_r_r225;
    cpy_r_r226 = CPyStatics[30]; /* 'faces' */
    cpy_r_r227 = CPyObject_GetAttr(cpy_r_out, cpy_r_r226);
    if (unlikely(cpy_r_r227 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 50, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r228 = CPyObject_Size(cpy_r_r227);
    CPy_DECREF(cpy_r_r227);
    if (unlikely(cpy_r_r228 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "load_obj", 50, CPyStatic_globals);
        goto CPyL270;
    }
    cpy_r_r229 = CPyTagged_StealAsObject(cpy_r_r228);
    cpy_r_f = cpy_r_r229;
    cpy_r_r230 = CPyStatics[30]; /* 'faces' */
    cpy_r_r231 = CPyObject_GetAttr(cpy_r_out, cpy_r_r230);
    if (unlikely(cpy_r_r231 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 51, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r232 = CPyDef_face();
    if (unlikely(cpy_r_r232 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 51, CPyStatic_globals);
        goto CPyL299;
    }
    cpy_r_r233 = CPyStatics[18]; /* 'append' */
    PyObject *cpy_r_r234[2] = {cpy_r_r231, cpy_r_r232};
    cpy_r_r235 = (PyObject **)&cpy_r_r234;
    cpy_r_r236 = PyObject_VectorcallMethod(cpy_r_r233, cpy_r_r235, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r236 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 51, CPyStatic_globals);
        goto CPyL300;
    } else
        goto CPyL301;
CPyL102: ;
    CPy_DECREF(cpy_r_r231);
    CPy_DECREF(cpy_r_r232);
    cpy_r_r237 = CPyStatics[22]; /* 'uvs' */
    cpy_r_r238 = CPyObject_GetAttr(cpy_r_out, cpy_r_r237);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 52, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r239 = CPyObject_Size(cpy_r_r238);
    CPy_DECREF(cpy_r_r238);
    if (unlikely(cpy_r_r239 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "load_obj", 52, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r240 = CPyTagged_StealAsObject(cpy_r_r239);
    cpy_r_r241 = CPyStatics[26]; /* 'normals' */
    cpy_r_r242 = CPyObject_GetAttr(cpy_r_out, cpy_r_r241);
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 52, CPyStatic_globals);
        goto CPyL302;
    }
    cpy_r_r243 = CPyObject_Size(cpy_r_r242);
    CPy_DECREF(cpy_r_r242);
    if (unlikely(cpy_r_r243 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "load_obj", 52, CPyStatic_globals);
        goto CPyL302;
    }
    cpy_r_r244 = CPyTagged_StealAsObject(cpy_r_r243);
    cpy_r_r245 = PyNumber_Add(cpy_r_r240, cpy_r_r244);
    CPy_DECREF(cpy_r_r240);
    CPy_DECREF(cpy_r_r244);
    if (unlikely(cpy_r_r245 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 52, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r246 = CPyStatics[56]; /* 0 */
    cpy_r_r247 = PyObject_RichCompare(cpy_r_r245, cpy_r_r246, 2);
    CPy_DECREF(cpy_r_r245);
    if (unlikely(cpy_r_r247 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 52, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r248 = PyObject_IsTrue(cpy_r_r247);
    CPy_DECREF(cpy_r_r247);
    cpy_r_r249 = cpy_r_r248 >= 0;
    if (unlikely(!cpy_r_r249)) {
        CPy_AddTraceback("object.py", "load_obj", 52, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r250 = cpy_r_r248;
    if (!cpy_r_r250) goto CPyL125;
    cpy_r_r251 = CPyStatics[56]; /* 0 */
    cpy_r_r252 = PyObject_GetItem(cpy_r_nums, cpy_r_r251);
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 53, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r253 = CPyStatics[57]; /* 1 */
    cpy_r_r254 = PyNumber_Subtract(cpy_r_r252, cpy_r_r253);
    CPy_DECREF(cpy_r_r252);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 53, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r255 = CPyStatics[30]; /* 'faces' */
    cpy_r_r256 = CPyObject_GetAttr(cpy_r_out, cpy_r_r255);
    if (unlikely(cpy_r_r256 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 53, CPyStatic_globals);
        goto CPyL303;
    }
    cpy_r_r257 = PyObject_GetItem(cpy_r_r256, cpy_r_f);
    CPy_DECREF(cpy_r_r256);
    if (unlikely(cpy_r_r257 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 53, CPyStatic_globals);
        goto CPyL303;
    }
    cpy_r_r258 = CPyStatics[31]; /* 'a_v' */
    cpy_r_r259 = PyObject_SetAttr(cpy_r_r257, cpy_r_r258, cpy_r_r254);
    CPy_DECREF(cpy_r_r257);
    CPy_DECREF(cpy_r_r254);
    cpy_r_r260 = cpy_r_r259 >= 0;
    if (unlikely(!cpy_r_r260)) {
        CPy_AddTraceback("object.py", "load_obj", 53, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r261 = CPyStatics[57]; /* 1 */
    cpy_r_r262 = PyObject_GetItem(cpy_r_nums, cpy_r_r261);
    if (unlikely(cpy_r_r262 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 54, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r263 = CPyStatics[57]; /* 1 */
    cpy_r_r264 = PyNumber_Subtract(cpy_r_r262, cpy_r_r263);
    CPy_DECREF(cpy_r_r262);
    if (unlikely(cpy_r_r264 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 54, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r265 = CPyStatics[30]; /* 'faces' */
    cpy_r_r266 = CPyObject_GetAttr(cpy_r_out, cpy_r_r265);
    if (unlikely(cpy_r_r266 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 54, CPyStatic_globals);
        goto CPyL304;
    }
    cpy_r_r267 = PyObject_GetItem(cpy_r_r266, cpy_r_f);
    CPy_DECREF(cpy_r_r266);
    if (unlikely(cpy_r_r267 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 54, CPyStatic_globals);
        goto CPyL304;
    }
    cpy_r_r268 = CPyStatics[32]; /* 'b_v' */
    cpy_r_r269 = PyObject_SetAttr(cpy_r_r267, cpy_r_r268, cpy_r_r264);
    CPy_DECREF(cpy_r_r267);
    CPy_DECREF(cpy_r_r264);
    cpy_r_r270 = cpy_r_r269 >= 0;
    if (unlikely(!cpy_r_r270)) {
        CPy_AddTraceback("object.py", "load_obj", 54, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r271 = CPyStatics[59]; /* 2 */
    cpy_r_r272 = PyObject_GetItem(cpy_r_nums, cpy_r_r271);
    CPy_DECREF(cpy_r_nums);
    if (unlikely(cpy_r_r272 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 55, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r273 = CPyStatics[57]; /* 1 */
    cpy_r_r274 = PyNumber_Subtract(cpy_r_r272, cpy_r_r273);
    CPy_DECREF(cpy_r_r272);
    if (unlikely(cpy_r_r274 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 55, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r275 = CPyStatics[30]; /* 'faces' */
    cpy_r_r276 = CPyObject_GetAttr(cpy_r_out, cpy_r_r275);
    if (unlikely(cpy_r_r276 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 55, CPyStatic_globals);
        goto CPyL306;
    }
    cpy_r_r277 = PyObject_GetItem(cpy_r_r276, cpy_r_f);
    CPy_DECREF(cpy_r_r276);
    CPy_DECREF(cpy_r_f);
    if (unlikely(cpy_r_r277 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 55, CPyStatic_globals);
        goto CPyL307;
    }
    cpy_r_r278 = CPyStatics[33]; /* 'c_v' */
    cpy_r_r279 = PyObject_SetAttr(cpy_r_r277, cpy_r_r278, cpy_r_r274);
    CPy_DECREF(cpy_r_r277);
    CPy_DECREF(cpy_r_r274);
    cpy_r_r280 = cpy_r_r279 >= 0;
    if (unlikely(!cpy_r_r280)) {
        CPy_AddTraceback("object.py", "load_obj", 55, CPyStatic_globals);
        goto CPyL265;
    } else
        goto CPyL8;
CPyL125: ;
    cpy_r_r281 = CPyStatics[26]; /* 'normals' */
    cpy_r_r282 = CPyObject_GetAttr(cpy_r_out, cpy_r_r281);
    if (unlikely(cpy_r_r282 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 56, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r283 = CPyObject_Size(cpy_r_r282);
    CPy_DECREF(cpy_r_r282);
    if (unlikely(cpy_r_r283 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "load_obj", 56, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r284 = CPyTagged_StealAsObject(cpy_r_r283);
    cpy_r_r285 = CPyStatics[56]; /* 0 */
    cpy_r_r286 = PyObject_RichCompare(cpy_r_r284, cpy_r_r285, 2);
    CPy_DECREF(cpy_r_r284);
    if (unlikely(cpy_r_r286 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 56, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r287 = PyObject_IsTrue(cpy_r_r286);
    CPy_DECREF(cpy_r_r286);
    cpy_r_r288 = cpy_r_r287 >= 0;
    if (unlikely(!cpy_r_r288)) {
        CPy_AddTraceback("object.py", "load_obj", 56, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r289 = cpy_r_r287;
    if (!cpy_r_r289) goto CPyL160;
    cpy_r_r290 = CPyStatics[56]; /* 0 */
    cpy_r_r291 = PyObject_GetItem(cpy_r_nums, cpy_r_r290);
    if (unlikely(cpy_r_r291 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 57, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r292 = CPyStatics[57]; /* 1 */
    cpy_r_r293 = PyNumber_Subtract(cpy_r_r291, cpy_r_r292);
    CPy_DECREF(cpy_r_r291);
    if (unlikely(cpy_r_r293 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 57, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r294 = CPyStatics[30]; /* 'faces' */
    cpy_r_r295 = CPyObject_GetAttr(cpy_r_out, cpy_r_r294);
    if (unlikely(cpy_r_r295 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 57, CPyStatic_globals);
        goto CPyL308;
    }
    cpy_r_r296 = PyObject_GetItem(cpy_r_r295, cpy_r_f);
    CPy_DECREF(cpy_r_r295);
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 57, CPyStatic_globals);
        goto CPyL308;
    }
    cpy_r_r297 = CPyStatics[31]; /* 'a_v' */
    cpy_r_r298 = PyObject_SetAttr(cpy_r_r296, cpy_r_r297, cpy_r_r293);
    CPy_DECREF(cpy_r_r296);
    CPy_DECREF(cpy_r_r293);
    cpy_r_r299 = cpy_r_r298 >= 0;
    if (unlikely(!cpy_r_r299)) {
        CPy_AddTraceback("object.py", "load_obj", 57, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r300 = CPyStatics[57]; /* 1 */
    cpy_r_r301 = PyObject_GetItem(cpy_r_nums, cpy_r_r300);
    if (unlikely(cpy_r_r301 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 58, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r302 = CPyStatics[57]; /* 1 */
    cpy_r_r303 = PyNumber_Subtract(cpy_r_r301, cpy_r_r302);
    CPy_DECREF(cpy_r_r301);
    if (unlikely(cpy_r_r303 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 58, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r304 = CPyStatics[30]; /* 'faces' */
    cpy_r_r305 = CPyObject_GetAttr(cpy_r_out, cpy_r_r304);
    if (unlikely(cpy_r_r305 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 58, CPyStatic_globals);
        goto CPyL309;
    }
    cpy_r_r306 = PyObject_GetItem(cpy_r_r305, cpy_r_f);
    CPy_DECREF(cpy_r_r305);
    if (unlikely(cpy_r_r306 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 58, CPyStatic_globals);
        goto CPyL309;
    }
    cpy_r_r307 = CPyStatics[34]; /* 'a_vt' */
    cpy_r_r308 = PyObject_SetAttr(cpy_r_r306, cpy_r_r307, cpy_r_r303);
    CPy_DECREF(cpy_r_r306);
    CPy_DECREF(cpy_r_r303);
    cpy_r_r309 = cpy_r_r308 >= 0;
    if (unlikely(!cpy_r_r309)) {
        CPy_AddTraceback("object.py", "load_obj", 58, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r310 = CPyStatics[59]; /* 2 */
    cpy_r_r311 = PyObject_GetItem(cpy_r_nums, cpy_r_r310);
    if (unlikely(cpy_r_r311 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 59, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r312 = CPyStatics[57]; /* 1 */
    cpy_r_r313 = PyNumber_Subtract(cpy_r_r311, cpy_r_r312);
    CPy_DECREF(cpy_r_r311);
    if (unlikely(cpy_r_r313 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 59, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r314 = CPyStatics[30]; /* 'faces' */
    cpy_r_r315 = CPyObject_GetAttr(cpy_r_out, cpy_r_r314);
    if (unlikely(cpy_r_r315 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 59, CPyStatic_globals);
        goto CPyL310;
    }
    cpy_r_r316 = PyObject_GetItem(cpy_r_r315, cpy_r_f);
    CPy_DECREF(cpy_r_r315);
    if (unlikely(cpy_r_r316 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 59, CPyStatic_globals);
        goto CPyL310;
    }
    cpy_r_r317 = CPyStatics[32]; /* 'b_v' */
    cpy_r_r318 = PyObject_SetAttr(cpy_r_r316, cpy_r_r317, cpy_r_r313);
    CPy_DECREF(cpy_r_r316);
    CPy_DECREF(cpy_r_r313);
    cpy_r_r319 = cpy_r_r318 >= 0;
    if (unlikely(!cpy_r_r319)) {
        CPy_AddTraceback("object.py", "load_obj", 59, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r320 = CPyStatics[58]; /* 3 */
    cpy_r_r321 = PyObject_GetItem(cpy_r_nums, cpy_r_r320);
    if (unlikely(cpy_r_r321 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 60, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r322 = CPyStatics[57]; /* 1 */
    cpy_r_r323 = PyNumber_Subtract(cpy_r_r321, cpy_r_r322);
    CPy_DECREF(cpy_r_r321);
    if (unlikely(cpy_r_r323 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 60, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r324 = CPyStatics[30]; /* 'faces' */
    cpy_r_r325 = CPyObject_GetAttr(cpy_r_out, cpy_r_r324);
    if (unlikely(cpy_r_r325 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 60, CPyStatic_globals);
        goto CPyL311;
    }
    cpy_r_r326 = PyObject_GetItem(cpy_r_r325, cpy_r_f);
    CPy_DECREF(cpy_r_r325);
    if (unlikely(cpy_r_r326 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 60, CPyStatic_globals);
        goto CPyL311;
    }
    cpy_r_r327 = CPyStatics[35]; /* 'b_vt' */
    cpy_r_r328 = PyObject_SetAttr(cpy_r_r326, cpy_r_r327, cpy_r_r323);
    CPy_DECREF(cpy_r_r326);
    CPy_DECREF(cpy_r_r323);
    cpy_r_r329 = cpy_r_r328 >= 0;
    if (unlikely(!cpy_r_r329)) {
        CPy_AddTraceback("object.py", "load_obj", 60, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r330 = CPyStatics[60]; /* 4 */
    cpy_r_r331 = PyObject_GetItem(cpy_r_nums, cpy_r_r330);
    if (unlikely(cpy_r_r331 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 61, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r332 = CPyStatics[57]; /* 1 */
    cpy_r_r333 = PyNumber_Subtract(cpy_r_r331, cpy_r_r332);
    CPy_DECREF(cpy_r_r331);
    if (unlikely(cpy_r_r333 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 61, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r334 = CPyStatics[30]; /* 'faces' */
    cpy_r_r335 = CPyObject_GetAttr(cpy_r_out, cpy_r_r334);
    if (unlikely(cpy_r_r335 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 61, CPyStatic_globals);
        goto CPyL312;
    }
    cpy_r_r336 = PyObject_GetItem(cpy_r_r335, cpy_r_f);
    CPy_DECREF(cpy_r_r335);
    if (unlikely(cpy_r_r336 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 61, CPyStatic_globals);
        goto CPyL312;
    }
    cpy_r_r337 = CPyStatics[33]; /* 'c_v' */
    cpy_r_r338 = PyObject_SetAttr(cpy_r_r336, cpy_r_r337, cpy_r_r333);
    CPy_DECREF(cpy_r_r336);
    CPy_DECREF(cpy_r_r333);
    cpy_r_r339 = cpy_r_r338 >= 0;
    if (unlikely(!cpy_r_r339)) {
        CPy_AddTraceback("object.py", "load_obj", 61, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r340 = CPyStatics[61]; /* 5 */
    cpy_r_r341 = PyObject_GetItem(cpy_r_nums, cpy_r_r340);
    CPy_DECREF(cpy_r_nums);
    if (unlikely(cpy_r_r341 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 62, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r342 = CPyStatics[57]; /* 1 */
    cpy_r_r343 = PyNumber_Subtract(cpy_r_r341, cpy_r_r342);
    CPy_DECREF(cpy_r_r341);
    if (unlikely(cpy_r_r343 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 62, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r344 = CPyStatics[30]; /* 'faces' */
    cpy_r_r345 = CPyObject_GetAttr(cpy_r_out, cpy_r_r344);
    if (unlikely(cpy_r_r345 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 62, CPyStatic_globals);
        goto CPyL313;
    }
    cpy_r_r346 = PyObject_GetItem(cpy_r_r345, cpy_r_f);
    CPy_DECREF(cpy_r_r345);
    CPy_DECREF(cpy_r_f);
    if (unlikely(cpy_r_r346 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 62, CPyStatic_globals);
        goto CPyL314;
    }
    cpy_r_r347 = CPyStatics[36]; /* 'c_vt' */
    cpy_r_r348 = PyObject_SetAttr(cpy_r_r346, cpy_r_r347, cpy_r_r343);
    CPy_DECREF(cpy_r_r346);
    CPy_DECREF(cpy_r_r343);
    cpy_r_r349 = cpy_r_r348 >= 0;
    if (unlikely(!cpy_r_r349)) {
        CPy_AddTraceback("object.py", "load_obj", 62, CPyStatic_globals);
        goto CPyL265;
    } else
        goto CPyL8;
CPyL160: ;
    cpy_r_r350 = CPyStatics[22]; /* 'uvs' */
    cpy_r_r351 = CPyObject_GetAttr(cpy_r_out, cpy_r_r350);
    if (unlikely(cpy_r_r351 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 63, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r352 = CPyObject_Size(cpy_r_r351);
    CPy_DECREF(cpy_r_r351);
    if (unlikely(cpy_r_r352 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "load_obj", 63, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r353 = CPyTagged_StealAsObject(cpy_r_r352);
    cpy_r_r354 = CPyStatics[56]; /* 0 */
    cpy_r_r355 = PyObject_RichCompare(cpy_r_r353, cpy_r_r354, 2);
    CPy_DECREF(cpy_r_r353);
    if (unlikely(cpy_r_r355 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 63, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r356 = PyObject_IsTrue(cpy_r_r355);
    CPy_DECREF(cpy_r_r355);
    cpy_r_r357 = cpy_r_r356 >= 0;
    if (unlikely(!cpy_r_r357)) {
        CPy_AddTraceback("object.py", "load_obj", 63, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r358 = cpy_r_r356;
    if (!cpy_r_r358) goto CPyL195;
    cpy_r_r359 = CPyStatics[56]; /* 0 */
    cpy_r_r360 = PyObject_GetItem(cpy_r_nums, cpy_r_r359);
    if (unlikely(cpy_r_r360 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 64, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r361 = CPyStatics[57]; /* 1 */
    cpy_r_r362 = PyNumber_Subtract(cpy_r_r360, cpy_r_r361);
    CPy_DECREF(cpy_r_r360);
    if (unlikely(cpy_r_r362 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 64, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r363 = CPyStatics[30]; /* 'faces' */
    cpy_r_r364 = CPyObject_GetAttr(cpy_r_out, cpy_r_r363);
    if (unlikely(cpy_r_r364 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 64, CPyStatic_globals);
        goto CPyL315;
    }
    cpy_r_r365 = PyObject_GetItem(cpy_r_r364, cpy_r_f);
    CPy_DECREF(cpy_r_r364);
    if (unlikely(cpy_r_r365 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 64, CPyStatic_globals);
        goto CPyL315;
    }
    cpy_r_r366 = CPyStatics[31]; /* 'a_v' */
    cpy_r_r367 = PyObject_SetAttr(cpy_r_r365, cpy_r_r366, cpy_r_r362);
    CPy_DECREF(cpy_r_r365);
    CPy_DECREF(cpy_r_r362);
    cpy_r_r368 = cpy_r_r367 >= 0;
    if (unlikely(!cpy_r_r368)) {
        CPy_AddTraceback("object.py", "load_obj", 64, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r369 = CPyStatics[57]; /* 1 */
    cpy_r_r370 = PyObject_GetItem(cpy_r_nums, cpy_r_r369);
    if (unlikely(cpy_r_r370 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 65, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r371 = CPyStatics[57]; /* 1 */
    cpy_r_r372 = PyNumber_Subtract(cpy_r_r370, cpy_r_r371);
    CPy_DECREF(cpy_r_r370);
    if (unlikely(cpy_r_r372 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 65, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r373 = CPyStatics[30]; /* 'faces' */
    cpy_r_r374 = CPyObject_GetAttr(cpy_r_out, cpy_r_r373);
    if (unlikely(cpy_r_r374 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 65, CPyStatic_globals);
        goto CPyL316;
    }
    cpy_r_r375 = PyObject_GetItem(cpy_r_r374, cpy_r_f);
    CPy_DECREF(cpy_r_r374);
    if (unlikely(cpy_r_r375 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 65, CPyStatic_globals);
        goto CPyL316;
    }
    cpy_r_r376 = CPyStatics[37]; /* 'a_vn' */
    cpy_r_r377 = PyObject_SetAttr(cpy_r_r375, cpy_r_r376, cpy_r_r372);
    CPy_DECREF(cpy_r_r375);
    CPy_DECREF(cpy_r_r372);
    cpy_r_r378 = cpy_r_r377 >= 0;
    if (unlikely(!cpy_r_r378)) {
        CPy_AddTraceback("object.py", "load_obj", 65, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r379 = CPyStatics[59]; /* 2 */
    cpy_r_r380 = PyObject_GetItem(cpy_r_nums, cpy_r_r379);
    if (unlikely(cpy_r_r380 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 66, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r381 = CPyStatics[57]; /* 1 */
    cpy_r_r382 = PyNumber_Subtract(cpy_r_r380, cpy_r_r381);
    CPy_DECREF(cpy_r_r380);
    if (unlikely(cpy_r_r382 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 66, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r383 = CPyStatics[30]; /* 'faces' */
    cpy_r_r384 = CPyObject_GetAttr(cpy_r_out, cpy_r_r383);
    if (unlikely(cpy_r_r384 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 66, CPyStatic_globals);
        goto CPyL317;
    }
    cpy_r_r385 = PyObject_GetItem(cpy_r_r384, cpy_r_f);
    CPy_DECREF(cpy_r_r384);
    if (unlikely(cpy_r_r385 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 66, CPyStatic_globals);
        goto CPyL317;
    }
    cpy_r_r386 = CPyStatics[32]; /* 'b_v' */
    cpy_r_r387 = PyObject_SetAttr(cpy_r_r385, cpy_r_r386, cpy_r_r382);
    CPy_DECREF(cpy_r_r385);
    CPy_DECREF(cpy_r_r382);
    cpy_r_r388 = cpy_r_r387 >= 0;
    if (unlikely(!cpy_r_r388)) {
        CPy_AddTraceback("object.py", "load_obj", 66, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r389 = CPyStatics[58]; /* 3 */
    cpy_r_r390 = PyObject_GetItem(cpy_r_nums, cpy_r_r389);
    if (unlikely(cpy_r_r390 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 67, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r391 = CPyStatics[57]; /* 1 */
    cpy_r_r392 = PyNumber_Subtract(cpy_r_r390, cpy_r_r391);
    CPy_DECREF(cpy_r_r390);
    if (unlikely(cpy_r_r392 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 67, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r393 = CPyStatics[30]; /* 'faces' */
    cpy_r_r394 = CPyObject_GetAttr(cpy_r_out, cpy_r_r393);
    if (unlikely(cpy_r_r394 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 67, CPyStatic_globals);
        goto CPyL318;
    }
    cpy_r_r395 = PyObject_GetItem(cpy_r_r394, cpy_r_f);
    CPy_DECREF(cpy_r_r394);
    if (unlikely(cpy_r_r395 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 67, CPyStatic_globals);
        goto CPyL318;
    }
    cpy_r_r396 = CPyStatics[38]; /* 'b_vn' */
    cpy_r_r397 = PyObject_SetAttr(cpy_r_r395, cpy_r_r396, cpy_r_r392);
    CPy_DECREF(cpy_r_r395);
    CPy_DECREF(cpy_r_r392);
    cpy_r_r398 = cpy_r_r397 >= 0;
    if (unlikely(!cpy_r_r398)) {
        CPy_AddTraceback("object.py", "load_obj", 67, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r399 = CPyStatics[60]; /* 4 */
    cpy_r_r400 = PyObject_GetItem(cpy_r_nums, cpy_r_r399);
    if (unlikely(cpy_r_r400 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 68, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r401 = CPyStatics[57]; /* 1 */
    cpy_r_r402 = PyNumber_Subtract(cpy_r_r400, cpy_r_r401);
    CPy_DECREF(cpy_r_r400);
    if (unlikely(cpy_r_r402 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 68, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r403 = CPyStatics[30]; /* 'faces' */
    cpy_r_r404 = CPyObject_GetAttr(cpy_r_out, cpy_r_r403);
    if (unlikely(cpy_r_r404 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 68, CPyStatic_globals);
        goto CPyL319;
    }
    cpy_r_r405 = PyObject_GetItem(cpy_r_r404, cpy_r_f);
    CPy_DECREF(cpy_r_r404);
    if (unlikely(cpy_r_r405 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 68, CPyStatic_globals);
        goto CPyL319;
    }
    cpy_r_r406 = CPyStatics[33]; /* 'c_v' */
    cpy_r_r407 = PyObject_SetAttr(cpy_r_r405, cpy_r_r406, cpy_r_r402);
    CPy_DECREF(cpy_r_r405);
    CPy_DECREF(cpy_r_r402);
    cpy_r_r408 = cpy_r_r407 >= 0;
    if (unlikely(!cpy_r_r408)) {
        CPy_AddTraceback("object.py", "load_obj", 68, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r409 = CPyStatics[61]; /* 5 */
    cpy_r_r410 = PyObject_GetItem(cpy_r_nums, cpy_r_r409);
    CPy_DECREF(cpy_r_nums);
    if (unlikely(cpy_r_r410 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 69, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r411 = CPyStatics[57]; /* 1 */
    cpy_r_r412 = PyNumber_Subtract(cpy_r_r410, cpy_r_r411);
    CPy_DECREF(cpy_r_r410);
    if (unlikely(cpy_r_r412 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 69, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r413 = CPyStatics[30]; /* 'faces' */
    cpy_r_r414 = CPyObject_GetAttr(cpy_r_out, cpy_r_r413);
    if (unlikely(cpy_r_r414 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 69, CPyStatic_globals);
        goto CPyL320;
    }
    cpy_r_r415 = PyObject_GetItem(cpy_r_r414, cpy_r_f);
    CPy_DECREF(cpy_r_r414);
    CPy_DECREF(cpy_r_f);
    if (unlikely(cpy_r_r415 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 69, CPyStatic_globals);
        goto CPyL321;
    }
    cpy_r_r416 = CPyStatics[39]; /* 'c_vn' */
    cpy_r_r417 = PyObject_SetAttr(cpy_r_r415, cpy_r_r416, cpy_r_r412);
    CPy_DECREF(cpy_r_r415);
    CPy_DECREF(cpy_r_r412);
    cpy_r_r418 = cpy_r_r417 >= 0;
    if (unlikely(!cpy_r_r418)) {
        CPy_AddTraceback("object.py", "load_obj", 69, CPyStatic_globals);
        goto CPyL265;
    } else
        goto CPyL8;
CPyL195: ;
    cpy_r_r419 = CPyStatics[56]; /* 0 */
    cpy_r_r420 = PyObject_GetItem(cpy_r_nums, cpy_r_r419);
    if (unlikely(cpy_r_r420 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 71, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r421 = CPyStatics[57]; /* 1 */
    cpy_r_r422 = PyNumber_Subtract(cpy_r_r420, cpy_r_r421);
    CPy_DECREF(cpy_r_r420);
    if (unlikely(cpy_r_r422 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 71, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r423 = CPyStatics[30]; /* 'faces' */
    cpy_r_r424 = CPyObject_GetAttr(cpy_r_out, cpy_r_r423);
    if (unlikely(cpy_r_r424 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 71, CPyStatic_globals);
        goto CPyL322;
    }
    cpy_r_r425 = PyObject_GetItem(cpy_r_r424, cpy_r_f);
    CPy_DECREF(cpy_r_r424);
    if (unlikely(cpy_r_r425 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 71, CPyStatic_globals);
        goto CPyL322;
    }
    cpy_r_r426 = CPyStatics[31]; /* 'a_v' */
    cpy_r_r427 = PyObject_SetAttr(cpy_r_r425, cpy_r_r426, cpy_r_r422);
    CPy_DECREF(cpy_r_r425);
    CPy_DECREF(cpy_r_r422);
    cpy_r_r428 = cpy_r_r427 >= 0;
    if (unlikely(!cpy_r_r428)) {
        CPy_AddTraceback("object.py", "load_obj", 71, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r429 = CPyStatics[57]; /* 1 */
    cpy_r_r430 = PyObject_GetItem(cpy_r_nums, cpy_r_r429);
    if (unlikely(cpy_r_r430 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 72, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r431 = CPyStatics[57]; /* 1 */
    cpy_r_r432 = PyNumber_Subtract(cpy_r_r430, cpy_r_r431);
    CPy_DECREF(cpy_r_r430);
    if (unlikely(cpy_r_r432 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 72, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r433 = CPyStatics[30]; /* 'faces' */
    cpy_r_r434 = CPyObject_GetAttr(cpy_r_out, cpy_r_r433);
    if (unlikely(cpy_r_r434 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 72, CPyStatic_globals);
        goto CPyL323;
    }
    cpy_r_r435 = PyObject_GetItem(cpy_r_r434, cpy_r_f);
    CPy_DECREF(cpy_r_r434);
    if (unlikely(cpy_r_r435 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 72, CPyStatic_globals);
        goto CPyL323;
    }
    cpy_r_r436 = CPyStatics[34]; /* 'a_vt' */
    cpy_r_r437 = PyObject_SetAttr(cpy_r_r435, cpy_r_r436, cpy_r_r432);
    CPy_DECREF(cpy_r_r435);
    CPy_DECREF(cpy_r_r432);
    cpy_r_r438 = cpy_r_r437 >= 0;
    if (unlikely(!cpy_r_r438)) {
        CPy_AddTraceback("object.py", "load_obj", 72, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r439 = CPyStatics[59]; /* 2 */
    cpy_r_r440 = PyObject_GetItem(cpy_r_nums, cpy_r_r439);
    if (unlikely(cpy_r_r440 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 73, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r441 = CPyStatics[57]; /* 1 */
    cpy_r_r442 = PyNumber_Subtract(cpy_r_r440, cpy_r_r441);
    CPy_DECREF(cpy_r_r440);
    if (unlikely(cpy_r_r442 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 73, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r443 = CPyStatics[30]; /* 'faces' */
    cpy_r_r444 = CPyObject_GetAttr(cpy_r_out, cpy_r_r443);
    if (unlikely(cpy_r_r444 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 73, CPyStatic_globals);
        goto CPyL324;
    }
    cpy_r_r445 = PyObject_GetItem(cpy_r_r444, cpy_r_f);
    CPy_DECREF(cpy_r_r444);
    if (unlikely(cpy_r_r445 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 73, CPyStatic_globals);
        goto CPyL324;
    }
    cpy_r_r446 = CPyStatics[37]; /* 'a_vn' */
    cpy_r_r447 = PyObject_SetAttr(cpy_r_r445, cpy_r_r446, cpy_r_r442);
    CPy_DECREF(cpy_r_r445);
    CPy_DECREF(cpy_r_r442);
    cpy_r_r448 = cpy_r_r447 >= 0;
    if (unlikely(!cpy_r_r448)) {
        CPy_AddTraceback("object.py", "load_obj", 73, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r449 = CPyStatics[58]; /* 3 */
    cpy_r_r450 = PyObject_GetItem(cpy_r_nums, cpy_r_r449);
    if (unlikely(cpy_r_r450 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 74, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r451 = CPyStatics[57]; /* 1 */
    cpy_r_r452 = PyNumber_Subtract(cpy_r_r450, cpy_r_r451);
    CPy_DECREF(cpy_r_r450);
    if (unlikely(cpy_r_r452 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 74, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r453 = CPyStatics[30]; /* 'faces' */
    cpy_r_r454 = CPyObject_GetAttr(cpy_r_out, cpy_r_r453);
    if (unlikely(cpy_r_r454 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 74, CPyStatic_globals);
        goto CPyL325;
    }
    cpy_r_r455 = PyObject_GetItem(cpy_r_r454, cpy_r_f);
    CPy_DECREF(cpy_r_r454);
    if (unlikely(cpy_r_r455 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 74, CPyStatic_globals);
        goto CPyL325;
    }
    cpy_r_r456 = CPyStatics[32]; /* 'b_v' */
    cpy_r_r457 = PyObject_SetAttr(cpy_r_r455, cpy_r_r456, cpy_r_r452);
    CPy_DECREF(cpy_r_r455);
    CPy_DECREF(cpy_r_r452);
    cpy_r_r458 = cpy_r_r457 >= 0;
    if (unlikely(!cpy_r_r458)) {
        CPy_AddTraceback("object.py", "load_obj", 74, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r459 = CPyStatics[60]; /* 4 */
    cpy_r_r460 = PyObject_GetItem(cpy_r_nums, cpy_r_r459);
    if (unlikely(cpy_r_r460 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 75, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r461 = CPyStatics[57]; /* 1 */
    cpy_r_r462 = PyNumber_Subtract(cpy_r_r460, cpy_r_r461);
    CPy_DECREF(cpy_r_r460);
    if (unlikely(cpy_r_r462 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 75, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r463 = CPyStatics[30]; /* 'faces' */
    cpy_r_r464 = CPyObject_GetAttr(cpy_r_out, cpy_r_r463);
    if (unlikely(cpy_r_r464 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 75, CPyStatic_globals);
        goto CPyL326;
    }
    cpy_r_r465 = PyObject_GetItem(cpy_r_r464, cpy_r_f);
    CPy_DECREF(cpy_r_r464);
    if (unlikely(cpy_r_r465 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 75, CPyStatic_globals);
        goto CPyL326;
    }
    cpy_r_r466 = CPyStatics[35]; /* 'b_vt' */
    cpy_r_r467 = PyObject_SetAttr(cpy_r_r465, cpy_r_r466, cpy_r_r462);
    CPy_DECREF(cpy_r_r465);
    CPy_DECREF(cpy_r_r462);
    cpy_r_r468 = cpy_r_r467 >= 0;
    if (unlikely(!cpy_r_r468)) {
        CPy_AddTraceback("object.py", "load_obj", 75, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r469 = CPyStatics[61]; /* 5 */
    cpy_r_r470 = PyObject_GetItem(cpy_r_nums, cpy_r_r469);
    if (unlikely(cpy_r_r470 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 76, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r471 = CPyStatics[57]; /* 1 */
    cpy_r_r472 = PyNumber_Subtract(cpy_r_r470, cpy_r_r471);
    CPy_DECREF(cpy_r_r470);
    if (unlikely(cpy_r_r472 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 76, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r473 = CPyStatics[30]; /* 'faces' */
    cpy_r_r474 = CPyObject_GetAttr(cpy_r_out, cpy_r_r473);
    if (unlikely(cpy_r_r474 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 76, CPyStatic_globals);
        goto CPyL327;
    }
    cpy_r_r475 = PyObject_GetItem(cpy_r_r474, cpy_r_f);
    CPy_DECREF(cpy_r_r474);
    if (unlikely(cpy_r_r475 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 76, CPyStatic_globals);
        goto CPyL327;
    }
    cpy_r_r476 = CPyStatics[38]; /* 'b_vn' */
    cpy_r_r477 = PyObject_SetAttr(cpy_r_r475, cpy_r_r476, cpy_r_r472);
    CPy_DECREF(cpy_r_r475);
    CPy_DECREF(cpy_r_r472);
    cpy_r_r478 = cpy_r_r477 >= 0;
    if (unlikely(!cpy_r_r478)) {
        CPy_AddTraceback("object.py", "load_obj", 76, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r479 = CPyStatics[62]; /* 6 */
    cpy_r_r480 = PyObject_GetItem(cpy_r_nums, cpy_r_r479);
    if (unlikely(cpy_r_r480 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 77, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r481 = CPyStatics[57]; /* 1 */
    cpy_r_r482 = PyNumber_Subtract(cpy_r_r480, cpy_r_r481);
    CPy_DECREF(cpy_r_r480);
    if (unlikely(cpy_r_r482 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 77, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r483 = CPyStatics[30]; /* 'faces' */
    cpy_r_r484 = CPyObject_GetAttr(cpy_r_out, cpy_r_r483);
    if (unlikely(cpy_r_r484 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 77, CPyStatic_globals);
        goto CPyL328;
    }
    cpy_r_r485 = PyObject_GetItem(cpy_r_r484, cpy_r_f);
    CPy_DECREF(cpy_r_r484);
    if (unlikely(cpy_r_r485 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 77, CPyStatic_globals);
        goto CPyL328;
    }
    cpy_r_r486 = CPyStatics[33]; /* 'c_v' */
    cpy_r_r487 = PyObject_SetAttr(cpy_r_r485, cpy_r_r486, cpy_r_r482);
    CPy_DECREF(cpy_r_r485);
    CPy_DECREF(cpy_r_r482);
    cpy_r_r488 = cpy_r_r487 >= 0;
    if (unlikely(!cpy_r_r488)) {
        CPy_AddTraceback("object.py", "load_obj", 77, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r489 = CPyStatics[63]; /* 7 */
    cpy_r_r490 = PyObject_GetItem(cpy_r_nums, cpy_r_r489);
    if (unlikely(cpy_r_r490 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 78, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r491 = CPyStatics[57]; /* 1 */
    cpy_r_r492 = PyNumber_Subtract(cpy_r_r490, cpy_r_r491);
    CPy_DECREF(cpy_r_r490);
    if (unlikely(cpy_r_r492 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 78, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r493 = CPyStatics[30]; /* 'faces' */
    cpy_r_r494 = CPyObject_GetAttr(cpy_r_out, cpy_r_r493);
    if (unlikely(cpy_r_r494 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 78, CPyStatic_globals);
        goto CPyL329;
    }
    cpy_r_r495 = PyObject_GetItem(cpy_r_r494, cpy_r_f);
    CPy_DECREF(cpy_r_r494);
    if (unlikely(cpy_r_r495 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 78, CPyStatic_globals);
        goto CPyL329;
    }
    cpy_r_r496 = CPyStatics[36]; /* 'c_vt' */
    cpy_r_r497 = PyObject_SetAttr(cpy_r_r495, cpy_r_r496, cpy_r_r492);
    CPy_DECREF(cpy_r_r495);
    CPy_DECREF(cpy_r_r492);
    cpy_r_r498 = cpy_r_r497 >= 0;
    if (unlikely(!cpy_r_r498)) {
        CPy_AddTraceback("object.py", "load_obj", 78, CPyStatic_globals);
        goto CPyL298;
    }
    cpy_r_r499 = CPyStatics[64]; /* 8 */
    cpy_r_r500 = PyObject_GetItem(cpy_r_nums, cpy_r_r499);
    CPy_DECREF(cpy_r_nums);
    if (unlikely(cpy_r_r500 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 79, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r501 = CPyStatics[57]; /* 1 */
    cpy_r_r502 = PyNumber_Subtract(cpy_r_r500, cpy_r_r501);
    CPy_DECREF(cpy_r_r500);
    if (unlikely(cpy_r_r502 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 79, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r503 = CPyStatics[30]; /* 'faces' */
    cpy_r_r504 = CPyObject_GetAttr(cpy_r_out, cpy_r_r503);
    if (unlikely(cpy_r_r504 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 79, CPyStatic_globals);
        goto CPyL330;
    }
    cpy_r_r505 = PyObject_GetItem(cpy_r_r504, cpy_r_f);
    CPy_DECREF(cpy_r_r504);
    CPy_DECREF(cpy_r_f);
    if (unlikely(cpy_r_r505 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 79, CPyStatic_globals);
        goto CPyL331;
    }
    cpy_r_r506 = CPyStatics[39]; /* 'c_vn' */
    cpy_r_r507 = PyObject_SetAttr(cpy_r_r505, cpy_r_r506, cpy_r_r502);
    CPy_DECREF(cpy_r_r505);
    CPy_DECREF(cpy_r_r502);
    cpy_r_r508 = cpy_r_r507 >= 0;
    if (unlikely(!cpy_r_r508)) {
        CPy_AddTraceback("object.py", "load_obj", 79, CPyStatic_globals);
        goto CPyL265;
    } else
        goto CPyL8;
CPyL240: ;
    cpy_r_r509 = CPy_CatchError();
    cpy_r_r17 = 0;
    cpy_r_r510 = CPy_GetExcInfo();
    cpy_r_r511 = cpy_r_r510.f0;
    CPy_INCREF(cpy_r_r511);
    cpy_r_r512 = cpy_r_r510.f1;
    CPy_INCREF(cpy_r_r512);
    cpy_r_r513 = cpy_r_r510.f2;
    CPy_INCREF(cpy_r_r513);
    CPy_DecRef(cpy_r_r510.f0);
    CPy_DecRef(cpy_r_r510.f1);
    CPy_DecRef(cpy_r_r510.f2);
    PyObject *cpy_r_r514[4] = {cpy_r_r8, cpy_r_r511, cpy_r_r512, cpy_r_r513};
    cpy_r_r515 = (PyObject **)&cpy_r_r514;
    cpy_r_r516 = _PyObject_Vectorcall(cpy_r_r11, cpy_r_r515, 4, 0);
    if (unlikely(cpy_r_r516 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 30, CPyStatic_globals);
        goto CPyL332;
    }
    CPy_DecRef(cpy_r_r511);
    CPy_DecRef(cpy_r_r512);
    CPy_DecRef(cpy_r_r513);
    cpy_r_r517 = PyObject_IsTrue(cpy_r_r516);
    CPy_DecRef(cpy_r_r516);
    cpy_r_r518 = cpy_r_r517 >= 0;
    if (unlikely(!cpy_r_r518)) {
        CPy_AddTraceback("object.py", "load_obj", 30, CPyStatic_globals);
        goto CPyL246;
    }
    cpy_r_r519 = cpy_r_r517;
    if (cpy_r_r519) goto CPyL245;
    CPy_Reraise();
    if (!0) {
        goto CPyL246;
    } else
        goto CPyL333;
CPyL244: ;
    CPy_Unreachable();
CPyL245: ;
    CPy_RestoreExcInfo(cpy_r_r509);
    CPy_DecRef(cpy_r_r509.f0);
    CPy_DecRef(cpy_r_r509.f1);
    CPy_DecRef(cpy_r_r509.f2);
    goto CPyL248;
CPyL246: ;
    CPy_RestoreExcInfo(cpy_r_r509);
    CPy_DecRef(cpy_r_r509.f0);
    CPy_DecRef(cpy_r_r509.f1);
    CPy_DecRef(cpy_r_r509.f2);
    cpy_r_r520 = CPy_KeepPropagating();
    if (!cpy_r_r520) {
        goto CPyL249;
    } else
        goto CPyL334;
CPyL247: ;
    CPy_Unreachable();
CPyL248: ;
    tuple_T3OOO __tmp1 = { NULL, NULL, NULL };
    cpy_r_r521 = __tmp1;
    cpy_r_r522 = cpy_r_r521;
    goto CPyL250;
CPyL249: ;
    cpy_r_r523 = CPy_CatchError();
    cpy_r_r522 = cpy_r_r523;
CPyL250: ;
    if (!cpy_r_r17) goto CPyL335;
    cpy_r_r524 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r525[4] = {cpy_r_r8, cpy_r_r524, cpy_r_r524, cpy_r_r524};
    cpy_r_r526 = (PyObject **)&cpy_r_r525;
    cpy_r_r527 = _PyObject_Vectorcall(cpy_r_r11, cpy_r_r526, 4, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r527 == NULL)) {
        CPy_AddTraceback("object.py", "load_obj", 30, CPyStatic_globals);
        goto CPyL336;
    } else
        goto CPyL337;
CPyL252: ;
    CPy_DECREF(cpy_r_r8);
CPyL253: ;
    if (cpy_r_r522.f0 == NULL) {
        goto CPyL260;
    } else
        goto CPyL338;
CPyL254: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL256;
    } else
        goto CPyL339;
CPyL255: ;
    CPy_Unreachable();
CPyL256: ;
    if (cpy_r_r522.f0 == NULL) goto CPyL258;
    CPy_RestoreExcInfo(cpy_r_r522);
    CPy_XDECREF(cpy_r_r522.f0);
    CPy_XDECREF(cpy_r_r522.f1);
    CPy_XDECREF(cpy_r_r522.f2);
CPyL258: ;
    cpy_r_r528 = CPy_KeepPropagating();
    if (!cpy_r_r528) goto CPyL261;
    CPy_Unreachable();
CPyL260: ;
    return cpy_r_out;
CPyL261: ;
    cpy_r_r529 = NULL;
    return cpy_r_r529;
CPyL262: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_line_number);
    goto CPyL261;
CPyL263: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    goto CPyL261;
CPyL264: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    goto CPyL261;
CPyL265: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    goto CPyL240;
CPyL266: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_line);
    goto CPyL240;
CPyL267: ;
    CPy_DECREF(cpy_r_line_number);
    CPy_DECREF(cpy_r_file);
    CPy_DECREF(cpy_r_line);
    goto CPyL248;
CPyL268: ;
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_line);
    goto CPyL240;
CPyL269: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r42);
    goto CPyL240;
CPyL270: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    goto CPyL240;
CPyL271: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_r61);
    goto CPyL240;
CPyL272: ;
    CPy_DECREF(cpy_r_r67);
    goto CPyL29;
CPyL273: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_r69);
    goto CPyL240;
CPyL274: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r71);
    goto CPyL240;
CPyL275: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r73);
    goto CPyL240;
CPyL276: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r71);
    CPy_DecRef(cpy_r_r73);
    CPy_DecRef(cpy_r_r75);
    goto CPyL240;
CPyL277: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r82);
    goto CPyL240;
CPyL278: ;
    CPy_DECREF(cpy_r_r86);
    goto CPyL37;
CPyL279: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r102);
    goto CPyL240;
CPyL280: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_r121);
    goto CPyL240;
CPyL281: ;
    CPy_DECREF(cpy_r_r127);
    goto CPyL55;
CPyL282: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_r129);
    goto CPyL240;
CPyL283: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r129);
    CPy_DecRef(cpy_r_r131);
    goto CPyL240;
CPyL284: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r129);
    CPy_DecRef(cpy_r_r131);
    CPy_DecRef(cpy_r_r133);
    goto CPyL240;
CPyL285: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r129);
    CPy_DecRef(cpy_r_r139);
    goto CPyL240;
CPyL286: ;
    CPy_DECREF(cpy_r_r143);
    goto CPyL62;
CPyL287: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r159);
    goto CPyL240;
CPyL288: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_r178);
    goto CPyL240;
CPyL289: ;
    CPy_DECREF(cpy_r_r184);
    goto CPyL80;
CPyL290: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_r186);
    goto CPyL240;
CPyL291: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_r186);
    CPy_DecRef(cpy_r_r188);
    goto CPyL240;
CPyL292: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r186);
    CPy_DecRef(cpy_r_r188);
    CPy_DecRef(cpy_r_r190);
    goto CPyL240;
CPyL293: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r186);
    CPy_DecRef(cpy_r_r188);
    CPy_DecRef(cpy_r_r190);
    CPy_DecRef(cpy_r_r192);
    goto CPyL240;
CPyL294: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r186);
    CPy_DecRef(cpy_r_r198);
    goto CPyL240;
CPyL295: ;
    CPy_DECREF(cpy_r_r202);
    goto CPyL88;
CPyL296: ;
    CPy_DECREF(cpy_r_line);
    goto CPyL8;
CPyL297: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r218);
    goto CPyL240;
CPyL298: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    goto CPyL240;
CPyL299: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r231);
    goto CPyL240;
CPyL300: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r231);
    CPy_DecRef(cpy_r_r232);
    goto CPyL240;
CPyL301: ;
    CPy_DECREF(cpy_r_r236);
    goto CPyL102;
CPyL302: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r240);
    goto CPyL240;
CPyL303: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r254);
    goto CPyL240;
CPyL304: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r264);
    goto CPyL240;
CPyL305: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_f);
    goto CPyL240;
CPyL306: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r274);
    goto CPyL240;
CPyL307: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r274);
    goto CPyL240;
CPyL308: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r293);
    goto CPyL240;
CPyL309: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r303);
    goto CPyL240;
CPyL310: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r313);
    goto CPyL240;
CPyL311: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r323);
    goto CPyL240;
CPyL312: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r333);
    goto CPyL240;
CPyL313: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r343);
    goto CPyL240;
CPyL314: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r343);
    goto CPyL240;
CPyL315: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r362);
    goto CPyL240;
CPyL316: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r372);
    goto CPyL240;
CPyL317: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r382);
    goto CPyL240;
CPyL318: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r392);
    goto CPyL240;
CPyL319: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r402);
    goto CPyL240;
CPyL320: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r412);
    goto CPyL240;
CPyL321: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r412);
    goto CPyL240;
CPyL322: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r422);
    goto CPyL240;
CPyL323: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r432);
    goto CPyL240;
CPyL324: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r442);
    goto CPyL240;
CPyL325: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r452);
    goto CPyL240;
CPyL326: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r462);
    goto CPyL240;
CPyL327: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r472);
    goto CPyL240;
CPyL328: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r482);
    goto CPyL240;
CPyL329: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_nums);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r492);
    goto CPyL240;
CPyL330: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r502);
    goto CPyL240;
CPyL331: ;
    CPy_DecRef(cpy_r_line_number);
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r502);
    goto CPyL240;
CPyL332: ;
    CPy_DecRef(cpy_r_r511);
    CPy_DecRef(cpy_r_r512);
    CPy_DecRef(cpy_r_r513);
    goto CPyL246;
CPyL333: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r509.f0);
    CPy_DecRef(cpy_r_r509.f1);
    CPy_DecRef(cpy_r_r509.f2);
    goto CPyL244;
CPyL334: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    goto CPyL247;
CPyL335: ;
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r11);
    goto CPyL253;
CPyL336: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_r8);
    goto CPyL256;
CPyL337: ;
    CPy_DECREF(cpy_r_r527);
    goto CPyL252;
CPyL338: ;
    CPy_DECREF(cpy_r_out);
    goto CPyL254;
CPyL339: ;
    CPy_XDECREF(cpy_r_r522.f0);
    CPy_XDECREF(cpy_r_r522.f1);
    CPy_XDECREF(cpy_r_r522.f2);
    goto CPyL255;
}

PyObject *CPyPy_load_obj(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"filepath", 0};
    static CPyArg_Parser parser = {"O:load_obj", kwlist, 0};
    PyObject *obj_filepath;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_filepath)) {
        return NULL;
    }
    PyObject *arg_filepath = obj_filepath;
    PyObject *retval = CPyDef_load_obj(arg_filepath);
    return retval;
fail: ;
    CPy_AddTraceback("object.py", "load_obj", 26, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_draw_object(PyObject *cpy_r_obj, PyObject *cpy_r_vs, PyObject *cpy_r_v_uni, PyObject *cpy_r_fs, PyObject *cpy_r_f_uni, PyObject *cpy_r_tri_draw_func) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    CPyPtr cpy_r_r16;
    PyObject *cpy_r_verts;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    int32_t cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    CPyPtr cpy_r_r33;
    CPyPtr cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    int32_t cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    CPyPtr cpy_r_r49;
    CPyPtr cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    int32_t cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject **cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    CPyPtr cpy_r_r72;
    CPyPtr cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    int32_t cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject **cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    CPyPtr cpy_r_r88;
    CPyPtr cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    int32_t cpy_r_r93;
    char cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    int32_t cpy_r_r99;
    char cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject **cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    CPyPtr cpy_r_r111;
    CPyPtr cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    int32_t cpy_r_r116;
    char cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject **cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    CPyPtr cpy_r_r127;
    CPyPtr cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    int32_t cpy_r_r132;
    char cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    CPyTagged cpy_r_r136;
    PyObject *cpy_r_r137;
    CPyTagged cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_i;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    int32_t cpy_r_r142;
    char cpy_r_r143;
    char cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    int32_t cpy_r_r156;
    char cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    int32_t cpy_r_r169;
    char cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    int32_t cpy_r_r182;
    char cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    int32_t cpy_r_r191;
    char cpy_r_r192;
    char cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject **cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    int32_t cpy_r_r207;
    char cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject **cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    int32_t cpy_r_r222;
    char cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject **cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    int32_t cpy_r_r237;
    char cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    int32_t cpy_r_r252;
    char cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    int32_t cpy_r_r267;
    char cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    PyObject *cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    int32_t cpy_r_r282;
    char cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    int32_t cpy_r_r291;
    char cpy_r_r292;
    char cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject **cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    PyObject *cpy_r_r307;
    int32_t cpy_r_r308;
    char cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject *cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject **cpy_r_r317;
    PyObject *cpy_r_r318;
    PyObject *cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    PyObject *cpy_r_r322;
    PyObject *cpy_r_r323;
    int32_t cpy_r_r324;
    char cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject **cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    int32_t cpy_r_r340;
    char cpy_r_r341;
    PyObject *cpy_r_r342;
    PyObject *cpy_r_r343;
    PyObject *cpy_r_r344;
    PyObject *cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    PyObject *cpy_r_r348;
    PyObject *cpy_r_r349;
    PyObject *cpy_r_r350;
    PyObject *cpy_r_r351;
    PyObject *cpy_r_r352;
    PyObject *cpy_r_r353;
    PyObject *cpy_r_r354;
    int32_t cpy_r_r355;
    char cpy_r_r356;
    PyObject *cpy_r_r357;
    PyObject *cpy_r_r358;
    PyObject *cpy_r_r359;
    PyObject *cpy_r_r360;
    PyObject *cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject *cpy_r_r369;
    int32_t cpy_r_r370;
    char cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    PyObject *cpy_r_r377;
    PyObject *cpy_r_r378;
    PyObject *cpy_r_r379;
    PyObject *cpy_r_r380;
    PyObject *cpy_r_r381;
    PyObject *cpy_r_r382;
    PyObject *cpy_r_r383;
    PyObject *cpy_r_r384;
    int32_t cpy_r_r385;
    char cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    PyObject **cpy_r_r391;
    PyObject *cpy_r_r392;
    CPyTagged cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    cpy_r_r0 = CPyModule_vertex;
    cpy_r_r1 = CPyStatics[40]; /* 'vertex' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 83, CPyStatic_globals);
        goto CPyL167;
    }
    cpy_r_r3 = _PyObject_Vectorcall(cpy_r_r2, 0, 0, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 83, CPyStatic_globals);
        goto CPyL167;
    }
    cpy_r_r4 = CPyModule_vertex;
    cpy_r_r5 = CPyStatics[40]; /* 'vertex' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 83, CPyStatic_globals);
        goto CPyL168;
    }
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r6, 0, 0, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 83, CPyStatic_globals);
        goto CPyL168;
    }
    cpy_r_r8 = CPyModule_vertex;
    cpy_r_r9 = CPyStatics[40]; /* 'vertex' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 83, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r11 = _PyObject_Vectorcall(cpy_r_r10, 0, 0, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 83, CPyStatic_globals);
        goto CPyL169;
    }
    cpy_r_r12 = PyList_New(3);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 83, CPyStatic_globals);
        goto CPyL170;
    }
    cpy_r_r13 = (CPyPtr)&((PyListObject *)cpy_r_r12)->ob_item;
    cpy_r_r14 = *(CPyPtr *)cpy_r_r13;
    *(PyObject * *)cpy_r_r14 = cpy_r_r3;
    cpy_r_r15 = cpy_r_r14 + 8;
    *(PyObject * *)cpy_r_r15 = cpy_r_r7;
    cpy_r_r16 = cpy_r_r14 + 16;
    *(PyObject * *)cpy_r_r16 = cpy_r_r11;
    cpy_r_verts = cpy_r_r12;
    cpy_r_r17 = PyList_New(0);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 85, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r18 = CPyStatics[56]; /* 0 */
    cpy_r_r19 = PyObject_GetItem(cpy_r_verts, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 85, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r20 = CPyStatics[41]; /* 'vec4s' */
    cpy_r_r21 = PyObject_SetAttr(cpy_r_r19, cpy_r_r20, cpy_r_r17);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r22 = cpy_r_r21 >= 0;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("object.py", "draw_object", 85, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r23 = CPyModule_vertex;
    cpy_r_r24 = CPyStatics[27]; /* 'vec3' */
    cpy_r_r25 = CPyObject_GetAttr(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 86, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r26 = CPyStatics[56]; /* 0 */
    cpy_r_r27 = CPyStatics[56]; /* 0 */
    cpy_r_r28 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r29[3] = {cpy_r_r26, cpy_r_r27, cpy_r_r28};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = _PyObject_Vectorcall(cpy_r_r25, cpy_r_r30, 3, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 86, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r32 = PyList_New(1);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 86, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r33 = (CPyPtr)&((PyListObject *)cpy_r_r32)->ob_item;
    cpy_r_r34 = *(CPyPtr *)cpy_r_r33;
    *(PyObject * *)cpy_r_r34 = cpy_r_r31;
    cpy_r_r35 = CPyStatics[56]; /* 0 */
    cpy_r_r36 = PyObject_GetItem(cpy_r_verts, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 86, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r37 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r38 = PyObject_SetAttr(cpy_r_r36, cpy_r_r37, cpy_r_r32);
    CPy_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r39 = cpy_r_r38 >= 0;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("object.py", "draw_object", 86, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r40 = CPyModule_vertex;
    cpy_r_r41 = CPyStatics[23]; /* 'vec2' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 87, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r43 = CPyStatics[56]; /* 0 */
    cpy_r_r44 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r45[2] = {cpy_r_r43, cpy_r_r44};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = _PyObject_Vectorcall(cpy_r_r42, cpy_r_r46, 2, 0);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 87, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r48 = PyList_New(1);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 87, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r49 = (CPyPtr)&((PyListObject *)cpy_r_r48)->ob_item;
    cpy_r_r50 = *(CPyPtr *)cpy_r_r49;
    *(PyObject * *)cpy_r_r50 = cpy_r_r47;
    cpy_r_r51 = CPyStatics[56]; /* 0 */
    cpy_r_r52 = PyObject_GetItem(cpy_r_verts, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 87, CPyStatic_globals);
        goto CPyL176;
    }
    cpy_r_r53 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r54 = PyObject_SetAttr(cpy_r_r52, cpy_r_r53, cpy_r_r48);
    CPy_DECREF(cpy_r_r52);
    CPy_DECREF(cpy_r_r48);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("object.py", "draw_object", 87, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r56 = PyList_New(0);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 89, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r57 = CPyStatics[57]; /* 1 */
    cpy_r_r58 = PyObject_GetItem(cpy_r_verts, cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 89, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r59 = CPyStatics[41]; /* 'vec4s' */
    cpy_r_r60 = PyObject_SetAttr(cpy_r_r58, cpy_r_r59, cpy_r_r56);
    CPy_DECREF(cpy_r_r58);
    CPy_DECREF(cpy_r_r56);
    cpy_r_r61 = cpy_r_r60 >= 0;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("object.py", "draw_object", 89, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r62 = CPyModule_vertex;
    cpy_r_r63 = CPyStatics[27]; /* 'vec3' */
    cpy_r_r64 = CPyObject_GetAttr(cpy_r_r62, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 90, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r65 = CPyStatics[56]; /* 0 */
    cpy_r_r66 = CPyStatics[56]; /* 0 */
    cpy_r_r67 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r68[3] = {cpy_r_r65, cpy_r_r66, cpy_r_r67};
    cpy_r_r69 = (PyObject **)&cpy_r_r68;
    cpy_r_r70 = _PyObject_Vectorcall(cpy_r_r64, cpy_r_r69, 3, 0);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 90, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r71 = PyList_New(1);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 90, CPyStatic_globals);
        goto CPyL178;
    }
    cpy_r_r72 = (CPyPtr)&((PyListObject *)cpy_r_r71)->ob_item;
    cpy_r_r73 = *(CPyPtr *)cpy_r_r72;
    *(PyObject * *)cpy_r_r73 = cpy_r_r70;
    cpy_r_r74 = CPyStatics[57]; /* 1 */
    cpy_r_r75 = PyObject_GetItem(cpy_r_verts, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 90, CPyStatic_globals);
        goto CPyL179;
    }
    cpy_r_r76 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r77 = PyObject_SetAttr(cpy_r_r75, cpy_r_r76, cpy_r_r71);
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r71);
    cpy_r_r78 = cpy_r_r77 >= 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("object.py", "draw_object", 90, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r79 = CPyModule_vertex;
    cpy_r_r80 = CPyStatics[23]; /* 'vec2' */
    cpy_r_r81 = CPyObject_GetAttr(cpy_r_r79, cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 91, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r82 = CPyStatics[56]; /* 0 */
    cpy_r_r83 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r84[2] = {cpy_r_r82, cpy_r_r83};
    cpy_r_r85 = (PyObject **)&cpy_r_r84;
    cpy_r_r86 = _PyObject_Vectorcall(cpy_r_r81, cpy_r_r85, 2, 0);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 91, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r87 = PyList_New(1);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 91, CPyStatic_globals);
        goto CPyL180;
    }
    cpy_r_r88 = (CPyPtr)&((PyListObject *)cpy_r_r87)->ob_item;
    cpy_r_r89 = *(CPyPtr *)cpy_r_r88;
    *(PyObject * *)cpy_r_r89 = cpy_r_r86;
    cpy_r_r90 = CPyStatics[57]; /* 1 */
    cpy_r_r91 = PyObject_GetItem(cpy_r_verts, cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 91, CPyStatic_globals);
        goto CPyL181;
    }
    cpy_r_r92 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r93 = PyObject_SetAttr(cpy_r_r91, cpy_r_r92, cpy_r_r87);
    CPy_DECREF(cpy_r_r91);
    CPy_DECREF(cpy_r_r87);
    cpy_r_r94 = cpy_r_r93 >= 0;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("object.py", "draw_object", 91, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r95 = PyList_New(0);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 93, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r96 = CPyStatics[59]; /* 2 */
    cpy_r_r97 = PyObject_GetItem(cpy_r_verts, cpy_r_r96);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 93, CPyStatic_globals);
        goto CPyL182;
    }
    cpy_r_r98 = CPyStatics[41]; /* 'vec4s' */
    cpy_r_r99 = PyObject_SetAttr(cpy_r_r97, cpy_r_r98, cpy_r_r95);
    CPy_DECREF(cpy_r_r97);
    CPy_DECREF(cpy_r_r95);
    cpy_r_r100 = cpy_r_r99 >= 0;
    if (unlikely(!cpy_r_r100)) {
        CPy_AddTraceback("object.py", "draw_object", 93, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r101 = CPyModule_vertex;
    cpy_r_r102 = CPyStatics[27]; /* 'vec3' */
    cpy_r_r103 = CPyObject_GetAttr(cpy_r_r101, cpy_r_r102);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 94, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r104 = CPyStatics[56]; /* 0 */
    cpy_r_r105 = CPyStatics[56]; /* 0 */
    cpy_r_r106 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r107[3] = {cpy_r_r104, cpy_r_r105, cpy_r_r106};
    cpy_r_r108 = (PyObject **)&cpy_r_r107;
    cpy_r_r109 = _PyObject_Vectorcall(cpy_r_r103, cpy_r_r108, 3, 0);
    CPy_DECREF(cpy_r_r103);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 94, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r110 = PyList_New(1);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 94, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r111 = (CPyPtr)&((PyListObject *)cpy_r_r110)->ob_item;
    cpy_r_r112 = *(CPyPtr *)cpy_r_r111;
    *(PyObject * *)cpy_r_r112 = cpy_r_r109;
    cpy_r_r113 = CPyStatics[59]; /* 2 */
    cpy_r_r114 = PyObject_GetItem(cpy_r_verts, cpy_r_r113);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 94, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r115 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r116 = PyObject_SetAttr(cpy_r_r114, cpy_r_r115, cpy_r_r110);
    CPy_DECREF(cpy_r_r114);
    CPy_DECREF(cpy_r_r110);
    cpy_r_r117 = cpy_r_r116 >= 0;
    if (unlikely(!cpy_r_r117)) {
        CPy_AddTraceback("object.py", "draw_object", 94, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r118 = CPyModule_vertex;
    cpy_r_r119 = CPyStatics[23]; /* 'vec2' */
    cpy_r_r120 = CPyObject_GetAttr(cpy_r_r118, cpy_r_r119);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 95, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r121 = CPyStatics[56]; /* 0 */
    cpy_r_r122 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r123[2] = {cpy_r_r121, cpy_r_r122};
    cpy_r_r124 = (PyObject **)&cpy_r_r123;
    cpy_r_r125 = _PyObject_Vectorcall(cpy_r_r120, cpy_r_r124, 2, 0);
    CPy_DECREF(cpy_r_r120);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 95, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r126 = PyList_New(1);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 95, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r127 = (CPyPtr)&((PyListObject *)cpy_r_r126)->ob_item;
    cpy_r_r128 = *(CPyPtr *)cpy_r_r127;
    *(PyObject * *)cpy_r_r128 = cpy_r_r125;
    cpy_r_r129 = CPyStatics[59]; /* 2 */
    cpy_r_r130 = PyObject_GetItem(cpy_r_verts, cpy_r_r129);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 95, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r131 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r132 = PyObject_SetAttr(cpy_r_r130, cpy_r_r131, cpy_r_r126);
    CPy_DECREF(cpy_r_r130);
    CPy_DECREF(cpy_r_r126);
    cpy_r_r133 = cpy_r_r132 >= 0;
    if (unlikely(!cpy_r_r133)) {
        CPy_AddTraceback("object.py", "draw_object", 95, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r134 = CPyStatics[30]; /* 'faces' */
    cpy_r_r135 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r134);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 97, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r136 = CPyObject_Size(cpy_r_r135);
    CPy_DECREF(cpy_r_r135);
    if (unlikely(cpy_r_r136 == CPY_INT_TAG)) {
        CPy_AddTraceback("object.py", "draw_object", 97, CPyStatic_globals);
        goto CPyL171;
    }
    cpy_r_r137 = CPyTagged_StealAsObject(cpy_r_r136);
    cpy_r_r138 = 0;
    CPyTagged_INCREF(cpy_r_r138);
    cpy_r_r139 = CPyTagged_StealAsObject(cpy_r_r138);
    cpy_r_i = cpy_r_r139;
CPyL49: ;
    CPyTagged_INCREF(cpy_r_r138);
    cpy_r_r140 = CPyTagged_StealAsObject(cpy_r_r138);
    cpy_r_r141 = PyObject_RichCompare(cpy_r_r140, cpy_r_r137, 0);
    CPy_DECREF(cpy_r_r140);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 97, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r142 = PyObject_IsTrue(cpy_r_r141);
    CPy_DECREF(cpy_r_r141);
    cpy_r_r143 = cpy_r_r142 >= 0;
    if (unlikely(!cpy_r_r143)) {
        CPy_AddTraceback("object.py", "draw_object", 97, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r144 = cpy_r_r142;
    if (!cpy_r_r144) goto CPyL188;
    cpy_r_r145 = CPyStatics[16]; /* 'vertices' */
    cpy_r_r146 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r145);
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 98, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r147 = CPyStatics[30]; /* 'faces' */
    cpy_r_r148 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 98, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r149 = PyObject_GetItem(cpy_r_r148, cpy_r_i);
    CPy_DECREF(cpy_r_r148);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 98, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r150 = CPyStatics[31]; /* 'a_v' */
    cpy_r_r151 = CPyObject_GetAttr(cpy_r_r149, cpy_r_r150);
    CPy_DECREF(cpy_r_r149);
    if (unlikely(cpy_r_r151 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 98, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r152 = PyObject_GetItem(cpy_r_r146, cpy_r_r151);
    CPy_DECREF(cpy_r_r146);
    CPy_DECREF(cpy_r_r151);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 98, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r153 = CPyStatics[56]; /* 0 */
    cpy_r_r154 = PyObject_GetItem(cpy_r_verts, cpy_r_r153);
    if (unlikely(cpy_r_r154 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 98, CPyStatic_globals);
        goto CPyL190;
    }
    cpy_r_r155 = CPyStatics[44]; /* 'pos' */
    cpy_r_r156 = PyObject_SetAttr(cpy_r_r154, cpy_r_r155, cpy_r_r152);
    CPy_DECREF(cpy_r_r154);
    CPy_DECREF(cpy_r_r152);
    cpy_r_r157 = cpy_r_r156 >= 0;
    if (unlikely(!cpy_r_r157)) {
        CPy_AddTraceback("object.py", "draw_object", 98, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r158 = CPyStatics[16]; /* 'vertices' */
    cpy_r_r159 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r158);
    if (unlikely(cpy_r_r159 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 99, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r160 = CPyStatics[30]; /* 'faces' */
    cpy_r_r161 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r160);
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 99, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r162 = PyObject_GetItem(cpy_r_r161, cpy_r_i);
    CPy_DECREF(cpy_r_r161);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 99, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r163 = CPyStatics[32]; /* 'b_v' */
    cpy_r_r164 = CPyObject_GetAttr(cpy_r_r162, cpy_r_r163);
    CPy_DECREF(cpy_r_r162);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 99, CPyStatic_globals);
        goto CPyL191;
    }
    cpy_r_r165 = PyObject_GetItem(cpy_r_r159, cpy_r_r164);
    CPy_DECREF(cpy_r_r159);
    CPy_DECREF(cpy_r_r164);
    if (unlikely(cpy_r_r165 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 99, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r166 = CPyStatics[57]; /* 1 */
    cpy_r_r167 = PyObject_GetItem(cpy_r_verts, cpy_r_r166);
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 99, CPyStatic_globals);
        goto CPyL192;
    }
    cpy_r_r168 = CPyStatics[44]; /* 'pos' */
    cpy_r_r169 = PyObject_SetAttr(cpy_r_r167, cpy_r_r168, cpy_r_r165);
    CPy_DECREF(cpy_r_r167);
    CPy_DECREF(cpy_r_r165);
    cpy_r_r170 = cpy_r_r169 >= 0;
    if (unlikely(!cpy_r_r170)) {
        CPy_AddTraceback("object.py", "draw_object", 99, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r171 = CPyStatics[16]; /* 'vertices' */
    cpy_r_r172 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r171);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 100, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r173 = CPyStatics[30]; /* 'faces' */
    cpy_r_r174 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r173);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 100, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r175 = PyObject_GetItem(cpy_r_r174, cpy_r_i);
    CPy_DECREF(cpy_r_r174);
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 100, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r176 = CPyStatics[33]; /* 'c_v' */
    cpy_r_r177 = CPyObject_GetAttr(cpy_r_r175, cpy_r_r176);
    CPy_DECREF(cpy_r_r175);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 100, CPyStatic_globals);
        goto CPyL193;
    }
    cpy_r_r178 = PyObject_GetItem(cpy_r_r172, cpy_r_r177);
    CPy_DECREF(cpy_r_r172);
    CPy_DECREF(cpy_r_r177);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 100, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r179 = CPyStatics[59]; /* 2 */
    cpy_r_r180 = PyObject_GetItem(cpy_r_verts, cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 100, CPyStatic_globals);
        goto CPyL194;
    }
    cpy_r_r181 = CPyStatics[44]; /* 'pos' */
    cpy_r_r182 = PyObject_SetAttr(cpy_r_r180, cpy_r_r181, cpy_r_r178);
    CPy_DECREF(cpy_r_r180);
    CPy_DECREF(cpy_r_r178);
    cpy_r_r183 = cpy_r_r182 >= 0;
    if (unlikely(!cpy_r_r183)) {
        CPy_AddTraceback("object.py", "draw_object", 100, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r184 = CPyStatics[30]; /* 'faces' */
    cpy_r_r185 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r184);
    if (unlikely(cpy_r_r185 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 102, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r186 = PyObject_GetItem(cpy_r_r185, cpy_r_i);
    CPy_DECREF(cpy_r_r185);
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 102, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r187 = CPyStatics[34]; /* 'a_vt' */
    cpy_r_r188 = CPyObject_GetAttr(cpy_r_r186, cpy_r_r187);
    CPy_DECREF(cpy_r_r186);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 102, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r189 = CPyStatics[55]; /* -1 */
    cpy_r_r190 = PyObject_RichCompare(cpy_r_r188, cpy_r_r189, 2);
    CPy_DECREF(cpy_r_r188);
    if (unlikely(cpy_r_r190 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 102, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r191 = PyObject_IsTrue(cpy_r_r190);
    CPy_DECREF(cpy_r_r190);
    cpy_r_r192 = cpy_r_r191 >= 0;
    if (unlikely(!cpy_r_r192)) {
        CPy_AddTraceback("object.py", "draw_object", 102, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r193 = cpy_r_r191;
    if (!cpy_r_r193) goto CPyL94;
    cpy_r_r194 = CPyModule_vertex;
    cpy_r_r195 = CPyStatics[23]; /* 'vec2' */
    cpy_r_r196 = CPyObject_GetAttr(cpy_r_r194, cpy_r_r195);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 103, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r197 = CPyStatics[56]; /* 0 */
    cpy_r_r198 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r199[2] = {cpy_r_r197, cpy_r_r198};
    cpy_r_r200 = (PyObject **)&cpy_r_r199;
    cpy_r_r201 = _PyObject_Vectorcall(cpy_r_r196, cpy_r_r200, 2, 0);
    CPy_DECREF(cpy_r_r196);
    if (unlikely(cpy_r_r201 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 103, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r202 = CPyStatics[56]; /* 0 */
    cpy_r_r203 = PyObject_GetItem(cpy_r_verts, cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 103, CPyStatic_globals);
        goto CPyL195;
    }
    cpy_r_r204 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r205 = CPyObject_GetAttr(cpy_r_r203, cpy_r_r204);
    CPy_DECREF(cpy_r_r203);
    if (unlikely(cpy_r_r205 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 103, CPyStatic_globals);
        goto CPyL195;
    }
    cpy_r_r206 = CPyStatics[56]; /* 0 */
    cpy_r_r207 = PyObject_SetItem(cpy_r_r205, cpy_r_r206, cpy_r_r201);
    CPy_DECREF(cpy_r_r205);
    CPy_DECREF(cpy_r_r201);
    cpy_r_r208 = cpy_r_r207 >= 0;
    if (unlikely(!cpy_r_r208)) {
        CPy_AddTraceback("object.py", "draw_object", 103, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r209 = CPyModule_vertex;
    cpy_r_r210 = CPyStatics[23]; /* 'vec2' */
    cpy_r_r211 = CPyObject_GetAttr(cpy_r_r209, cpy_r_r210);
    if (unlikely(cpy_r_r211 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 104, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r212 = CPyStatics[56]; /* 0 */
    cpy_r_r213 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r214[2] = {cpy_r_r212, cpy_r_r213};
    cpy_r_r215 = (PyObject **)&cpy_r_r214;
    cpy_r_r216 = _PyObject_Vectorcall(cpy_r_r211, cpy_r_r215, 2, 0);
    CPy_DECREF(cpy_r_r211);
    if (unlikely(cpy_r_r216 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 104, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r217 = CPyStatics[57]; /* 1 */
    cpy_r_r218 = PyObject_GetItem(cpy_r_verts, cpy_r_r217);
    if (unlikely(cpy_r_r218 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 104, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r219 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r220 = CPyObject_GetAttr(cpy_r_r218, cpy_r_r219);
    CPy_DECREF(cpy_r_r218);
    if (unlikely(cpy_r_r220 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 104, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r221 = CPyStatics[56]; /* 0 */
    cpy_r_r222 = PyObject_SetItem(cpy_r_r220, cpy_r_r221, cpy_r_r216);
    CPy_DECREF(cpy_r_r220);
    CPy_DECREF(cpy_r_r216);
    cpy_r_r223 = cpy_r_r222 >= 0;
    if (unlikely(!cpy_r_r223)) {
        CPy_AddTraceback("object.py", "draw_object", 104, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r224 = CPyModule_vertex;
    cpy_r_r225 = CPyStatics[23]; /* 'vec2' */
    cpy_r_r226 = CPyObject_GetAttr(cpy_r_r224, cpy_r_r225);
    if (unlikely(cpy_r_r226 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 105, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r227 = CPyStatics[56]; /* 0 */
    cpy_r_r228 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r229[2] = {cpy_r_r227, cpy_r_r228};
    cpy_r_r230 = (PyObject **)&cpy_r_r229;
    cpy_r_r231 = _PyObject_Vectorcall(cpy_r_r226, cpy_r_r230, 2, 0);
    CPy_DECREF(cpy_r_r226);
    if (unlikely(cpy_r_r231 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 105, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r232 = CPyStatics[59]; /* 2 */
    cpy_r_r233 = PyObject_GetItem(cpy_r_verts, cpy_r_r232);
    if (unlikely(cpy_r_r233 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 105, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r234 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r235 = CPyObject_GetAttr(cpy_r_r233, cpy_r_r234);
    CPy_DECREF(cpy_r_r233);
    if (unlikely(cpy_r_r235 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 105, CPyStatic_globals);
        goto CPyL197;
    }
    cpy_r_r236 = CPyStatics[56]; /* 0 */
    cpy_r_r237 = PyObject_SetItem(cpy_r_r235, cpy_r_r236, cpy_r_r231);
    CPy_DECREF(cpy_r_r235);
    CPy_DECREF(cpy_r_r231);
    cpy_r_r238 = cpy_r_r237 >= 0;
    if (unlikely(!cpy_r_r238)) {
        CPy_AddTraceback("object.py", "draw_object", 105, CPyStatic_globals);
        goto CPyL187;
    } else
        goto CPyL118;
CPyL94: ;
    cpy_r_r239 = CPyStatics[22]; /* 'uvs' */
    cpy_r_r240 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r239);
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 107, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r241 = CPyStatics[30]; /* 'faces' */
    cpy_r_r242 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r241);
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 107, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r243 = PyObject_GetItem(cpy_r_r242, cpy_r_i);
    CPy_DECREF(cpy_r_r242);
    if (unlikely(cpy_r_r243 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 107, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r244 = CPyStatics[34]; /* 'a_vt' */
    cpy_r_r245 = CPyObject_GetAttr(cpy_r_r243, cpy_r_r244);
    CPy_DECREF(cpy_r_r243);
    if (unlikely(cpy_r_r245 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 107, CPyStatic_globals);
        goto CPyL198;
    }
    cpy_r_r246 = PyObject_GetItem(cpy_r_r240, cpy_r_r245);
    CPy_DECREF(cpy_r_r240);
    CPy_DECREF(cpy_r_r245);
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 107, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r247 = CPyStatics[56]; /* 0 */
    cpy_r_r248 = PyObject_GetItem(cpy_r_verts, cpy_r_r247);
    if (unlikely(cpy_r_r248 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 107, CPyStatic_globals);
        goto CPyL199;
    }
    cpy_r_r249 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r250 = CPyObject_GetAttr(cpy_r_r248, cpy_r_r249);
    CPy_DECREF(cpy_r_r248);
    if (unlikely(cpy_r_r250 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 107, CPyStatic_globals);
        goto CPyL199;
    }
    cpy_r_r251 = CPyStatics[56]; /* 0 */
    cpy_r_r252 = PyObject_SetItem(cpy_r_r250, cpy_r_r251, cpy_r_r246);
    CPy_DECREF(cpy_r_r250);
    CPy_DECREF(cpy_r_r246);
    cpy_r_r253 = cpy_r_r252 >= 0;
    if (unlikely(!cpy_r_r253)) {
        CPy_AddTraceback("object.py", "draw_object", 107, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r254 = CPyStatics[22]; /* 'uvs' */
    cpy_r_r255 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r254);
    if (unlikely(cpy_r_r255 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 108, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r256 = CPyStatics[30]; /* 'faces' */
    cpy_r_r257 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r256);
    if (unlikely(cpy_r_r257 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 108, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r258 = PyObject_GetItem(cpy_r_r257, cpy_r_i);
    CPy_DECREF(cpy_r_r257);
    if (unlikely(cpy_r_r258 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 108, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r259 = CPyStatics[35]; /* 'b_vt' */
    cpy_r_r260 = CPyObject_GetAttr(cpy_r_r258, cpy_r_r259);
    CPy_DECREF(cpy_r_r258);
    if (unlikely(cpy_r_r260 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 108, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r261 = PyObject_GetItem(cpy_r_r255, cpy_r_r260);
    CPy_DECREF(cpy_r_r255);
    CPy_DECREF(cpy_r_r260);
    if (unlikely(cpy_r_r261 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 108, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r262 = CPyStatics[57]; /* 1 */
    cpy_r_r263 = PyObject_GetItem(cpy_r_verts, cpy_r_r262);
    if (unlikely(cpy_r_r263 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 108, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r264 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r265 = CPyObject_GetAttr(cpy_r_r263, cpy_r_r264);
    CPy_DECREF(cpy_r_r263);
    if (unlikely(cpy_r_r265 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 108, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r266 = CPyStatics[56]; /* 0 */
    cpy_r_r267 = PyObject_SetItem(cpy_r_r265, cpy_r_r266, cpy_r_r261);
    CPy_DECREF(cpy_r_r265);
    CPy_DECREF(cpy_r_r261);
    cpy_r_r268 = cpy_r_r267 >= 0;
    if (unlikely(!cpy_r_r268)) {
        CPy_AddTraceback("object.py", "draw_object", 108, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r269 = CPyStatics[22]; /* 'uvs' */
    cpy_r_r270 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r269);
    if (unlikely(cpy_r_r270 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 109, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r271 = CPyStatics[30]; /* 'faces' */
    cpy_r_r272 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r271);
    if (unlikely(cpy_r_r272 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 109, CPyStatic_globals);
        goto CPyL202;
    }
    cpy_r_r273 = PyObject_GetItem(cpy_r_r272, cpy_r_i);
    CPy_DECREF(cpy_r_r272);
    if (unlikely(cpy_r_r273 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 109, CPyStatic_globals);
        goto CPyL202;
    }
    cpy_r_r274 = CPyStatics[36]; /* 'c_vt' */
    cpy_r_r275 = CPyObject_GetAttr(cpy_r_r273, cpy_r_r274);
    CPy_DECREF(cpy_r_r273);
    if (unlikely(cpy_r_r275 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 109, CPyStatic_globals);
        goto CPyL202;
    }
    cpy_r_r276 = PyObject_GetItem(cpy_r_r270, cpy_r_r275);
    CPy_DECREF(cpy_r_r270);
    CPy_DECREF(cpy_r_r275);
    if (unlikely(cpy_r_r276 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 109, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r277 = CPyStatics[59]; /* 2 */
    cpy_r_r278 = PyObject_GetItem(cpy_r_verts, cpy_r_r277);
    if (unlikely(cpy_r_r278 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 109, CPyStatic_globals);
        goto CPyL203;
    }
    cpy_r_r279 = CPyStatics[43]; /* 'vec2s' */
    cpy_r_r280 = CPyObject_GetAttr(cpy_r_r278, cpy_r_r279);
    CPy_DECREF(cpy_r_r278);
    if (unlikely(cpy_r_r280 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 109, CPyStatic_globals);
        goto CPyL203;
    }
    cpy_r_r281 = CPyStatics[56]; /* 0 */
    cpy_r_r282 = PyObject_SetItem(cpy_r_r280, cpy_r_r281, cpy_r_r276);
    CPy_DECREF(cpy_r_r280);
    CPy_DECREF(cpy_r_r276);
    cpy_r_r283 = cpy_r_r282 >= 0;
    if (unlikely(!cpy_r_r283)) {
        CPy_AddTraceback("object.py", "draw_object", 109, CPyStatic_globals);
        goto CPyL187;
    }
CPyL118: ;
    cpy_r_r284 = CPyStatics[30]; /* 'faces' */
    cpy_r_r285 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r284);
    if (unlikely(cpy_r_r285 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 111, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r286 = PyObject_GetItem(cpy_r_r285, cpy_r_i);
    CPy_DECREF(cpy_r_r285);
    if (unlikely(cpy_r_r286 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 111, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r287 = CPyStatics[37]; /* 'a_vn' */
    cpy_r_r288 = CPyObject_GetAttr(cpy_r_r286, cpy_r_r287);
    CPy_DECREF(cpy_r_r286);
    if (unlikely(cpy_r_r288 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 111, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r289 = CPyStatics[55]; /* -1 */
    cpy_r_r290 = PyObject_RichCompare(cpy_r_r288, cpy_r_r289, 2);
    CPy_DECREF(cpy_r_r288);
    if (unlikely(cpy_r_r290 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 111, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r291 = PyObject_IsTrue(cpy_r_r290);
    CPy_DECREF(cpy_r_r290);
    cpy_r_r292 = cpy_r_r291 >= 0;
    if (unlikely(!cpy_r_r292)) {
        CPy_AddTraceback("object.py", "draw_object", 111, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r293 = cpy_r_r291;
    if (cpy_r_r293) {
        goto CPyL204;
    } else
        goto CPyL139;
CPyL124: ;
    cpy_r_r294 = CPyModule_vertex;
    cpy_r_r295 = CPyStatics[27]; /* 'vec3' */
    cpy_r_r296 = CPyObject_GetAttr(cpy_r_r294, cpy_r_r295);
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 112, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r297 = CPyStatics[56]; /* 0 */
    cpy_r_r298 = CPyStatics[56]; /* 0 */
    cpy_r_r299 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r300[3] = {cpy_r_r297, cpy_r_r298, cpy_r_r299};
    cpy_r_r301 = (PyObject **)&cpy_r_r300;
    cpy_r_r302 = _PyObject_Vectorcall(cpy_r_r296, cpy_r_r301, 3, 0);
    CPy_DECREF(cpy_r_r296);
    if (unlikely(cpy_r_r302 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 112, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r303 = CPyStatics[56]; /* 0 */
    cpy_r_r304 = PyObject_GetItem(cpy_r_verts, cpy_r_r303);
    if (unlikely(cpy_r_r304 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 112, CPyStatic_globals);
        goto CPyL206;
    }
    cpy_r_r305 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r306 = CPyObject_GetAttr(cpy_r_r304, cpy_r_r305);
    CPy_DECREF(cpy_r_r304);
    if (unlikely(cpy_r_r306 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 112, CPyStatic_globals);
        goto CPyL206;
    }
    cpy_r_r307 = CPyStatics[56]; /* 0 */
    cpy_r_r308 = PyObject_SetItem(cpy_r_r306, cpy_r_r307, cpy_r_r302);
    CPy_DECREF(cpy_r_r306);
    CPy_DECREF(cpy_r_r302);
    cpy_r_r309 = cpy_r_r308 >= 0;
    if (unlikely(!cpy_r_r309)) {
        CPy_AddTraceback("object.py", "draw_object", 112, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r310 = CPyModule_vertex;
    cpy_r_r311 = CPyStatics[27]; /* 'vec3' */
    cpy_r_r312 = CPyObject_GetAttr(cpy_r_r310, cpy_r_r311);
    if (unlikely(cpy_r_r312 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 113, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r313 = CPyStatics[56]; /* 0 */
    cpy_r_r314 = CPyStatics[56]; /* 0 */
    cpy_r_r315 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r316[3] = {cpy_r_r313, cpy_r_r314, cpy_r_r315};
    cpy_r_r317 = (PyObject **)&cpy_r_r316;
    cpy_r_r318 = _PyObject_Vectorcall(cpy_r_r312, cpy_r_r317, 3, 0);
    CPy_DECREF(cpy_r_r312);
    if (unlikely(cpy_r_r318 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 113, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r319 = CPyStatics[57]; /* 1 */
    cpy_r_r320 = PyObject_GetItem(cpy_r_verts, cpy_r_r319);
    if (unlikely(cpy_r_r320 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 113, CPyStatic_globals);
        goto CPyL207;
    }
    cpy_r_r321 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r322 = CPyObject_GetAttr(cpy_r_r320, cpy_r_r321);
    CPy_DECREF(cpy_r_r320);
    if (unlikely(cpy_r_r322 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 113, CPyStatic_globals);
        goto CPyL207;
    }
    cpy_r_r323 = CPyStatics[56]; /* 0 */
    cpy_r_r324 = PyObject_SetItem(cpy_r_r322, cpy_r_r323, cpy_r_r318);
    CPy_DECREF(cpy_r_r322);
    CPy_DECREF(cpy_r_r318);
    cpy_r_r325 = cpy_r_r324 >= 0;
    if (unlikely(!cpy_r_r325)) {
        CPy_AddTraceback("object.py", "draw_object", 113, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r326 = CPyModule_vertex;
    cpy_r_r327 = CPyStatics[27]; /* 'vec3' */
    cpy_r_r328 = CPyObject_GetAttr(cpy_r_r326, cpy_r_r327);
    if (unlikely(cpy_r_r328 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 114, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r329 = CPyStatics[56]; /* 0 */
    cpy_r_r330 = CPyStatics[56]; /* 0 */
    cpy_r_r331 = CPyStatics[56]; /* 0 */
    PyObject *cpy_r_r332[3] = {cpy_r_r329, cpy_r_r330, cpy_r_r331};
    cpy_r_r333 = (PyObject **)&cpy_r_r332;
    cpy_r_r334 = _PyObject_Vectorcall(cpy_r_r328, cpy_r_r333, 3, 0);
    CPy_DECREF(cpy_r_r328);
    if (unlikely(cpy_r_r334 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 114, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r335 = CPyStatics[59]; /* 2 */
    cpy_r_r336 = PyObject_GetItem(cpy_r_verts, cpy_r_r335);
    if (unlikely(cpy_r_r336 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 114, CPyStatic_globals);
        goto CPyL208;
    }
    cpy_r_r337 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r338 = CPyObject_GetAttr(cpy_r_r336, cpy_r_r337);
    CPy_DECREF(cpy_r_r336);
    if (unlikely(cpy_r_r338 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 114, CPyStatic_globals);
        goto CPyL208;
    }
    cpy_r_r339 = CPyStatics[56]; /* 0 */
    cpy_r_r340 = PyObject_SetItem(cpy_r_r338, cpy_r_r339, cpy_r_r334);
    CPy_DECREF(cpy_r_r338);
    CPy_DECREF(cpy_r_r334);
    cpy_r_r341 = cpy_r_r340 >= 0;
    if (unlikely(!cpy_r_r341)) {
        CPy_AddTraceback("object.py", "draw_object", 114, CPyStatic_globals);
        goto CPyL205;
    } else
        goto CPyL163;
CPyL139: ;
    cpy_r_r342 = CPyStatics[26]; /* 'normals' */
    cpy_r_r343 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r342);
    if (unlikely(cpy_r_r343 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 116, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r344 = CPyStatics[30]; /* 'faces' */
    cpy_r_r345 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r344);
    if (unlikely(cpy_r_r345 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 116, CPyStatic_globals);
        goto CPyL209;
    }
    cpy_r_r346 = PyObject_GetItem(cpy_r_r345, cpy_r_i);
    CPy_DECREF(cpy_r_r345);
    if (unlikely(cpy_r_r346 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 116, CPyStatic_globals);
        goto CPyL209;
    }
    cpy_r_r347 = CPyStatics[37]; /* 'a_vn' */
    cpy_r_r348 = CPyObject_GetAttr(cpy_r_r346, cpy_r_r347);
    CPy_DECREF(cpy_r_r346);
    if (unlikely(cpy_r_r348 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 116, CPyStatic_globals);
        goto CPyL209;
    }
    cpy_r_r349 = PyObject_GetItem(cpy_r_r343, cpy_r_r348);
    CPy_DECREF(cpy_r_r343);
    CPy_DECREF(cpy_r_r348);
    if (unlikely(cpy_r_r349 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 116, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r350 = CPyStatics[56]; /* 0 */
    cpy_r_r351 = PyObject_GetItem(cpy_r_verts, cpy_r_r350);
    if (unlikely(cpy_r_r351 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 116, CPyStatic_globals);
        goto CPyL210;
    }
    cpy_r_r352 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r353 = CPyObject_GetAttr(cpy_r_r351, cpy_r_r352);
    CPy_DECREF(cpy_r_r351);
    if (unlikely(cpy_r_r353 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 116, CPyStatic_globals);
        goto CPyL210;
    }
    cpy_r_r354 = CPyStatics[56]; /* 0 */
    cpy_r_r355 = PyObject_SetItem(cpy_r_r353, cpy_r_r354, cpy_r_r349);
    CPy_DECREF(cpy_r_r353);
    CPy_DECREF(cpy_r_r349);
    cpy_r_r356 = cpy_r_r355 >= 0;
    if (unlikely(!cpy_r_r356)) {
        CPy_AddTraceback("object.py", "draw_object", 116, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r357 = CPyStatics[26]; /* 'normals' */
    cpy_r_r358 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r357);
    if (unlikely(cpy_r_r358 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 117, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r359 = CPyStatics[30]; /* 'faces' */
    cpy_r_r360 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r359);
    if (unlikely(cpy_r_r360 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 117, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r361 = PyObject_GetItem(cpy_r_r360, cpy_r_i);
    CPy_DECREF(cpy_r_r360);
    if (unlikely(cpy_r_r361 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 117, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r362 = CPyStatics[38]; /* 'b_vn' */
    cpy_r_r363 = CPyObject_GetAttr(cpy_r_r361, cpy_r_r362);
    CPy_DECREF(cpy_r_r361);
    if (unlikely(cpy_r_r363 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 117, CPyStatic_globals);
        goto CPyL211;
    }
    cpy_r_r364 = PyObject_GetItem(cpy_r_r358, cpy_r_r363);
    CPy_DECREF(cpy_r_r358);
    CPy_DECREF(cpy_r_r363);
    if (unlikely(cpy_r_r364 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 117, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r365 = CPyStatics[57]; /* 1 */
    cpy_r_r366 = PyObject_GetItem(cpy_r_verts, cpy_r_r365);
    if (unlikely(cpy_r_r366 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 117, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r367 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r368 = CPyObject_GetAttr(cpy_r_r366, cpy_r_r367);
    CPy_DECREF(cpy_r_r366);
    if (unlikely(cpy_r_r368 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 117, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_r369 = CPyStatics[56]; /* 0 */
    cpy_r_r370 = PyObject_SetItem(cpy_r_r368, cpy_r_r369, cpy_r_r364);
    CPy_DECREF(cpy_r_r368);
    CPy_DECREF(cpy_r_r364);
    cpy_r_r371 = cpy_r_r370 >= 0;
    if (unlikely(!cpy_r_r371)) {
        CPy_AddTraceback("object.py", "draw_object", 117, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r372 = CPyStatics[26]; /* 'normals' */
    cpy_r_r373 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r372);
    if (unlikely(cpy_r_r373 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 118, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r374 = CPyStatics[30]; /* 'faces' */
    cpy_r_r375 = CPyObject_GetAttr(cpy_r_obj, cpy_r_r374);
    if (unlikely(cpy_r_r375 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 118, CPyStatic_globals);
        goto CPyL213;
    }
    cpy_r_r376 = PyObject_GetItem(cpy_r_r375, cpy_r_i);
    CPy_DECREF(cpy_r_r375);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r376 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 118, CPyStatic_globals);
        goto CPyL214;
    }
    cpy_r_r377 = CPyStatics[39]; /* 'c_vn' */
    cpy_r_r378 = CPyObject_GetAttr(cpy_r_r376, cpy_r_r377);
    CPy_DECREF(cpy_r_r376);
    if (unlikely(cpy_r_r378 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 118, CPyStatic_globals);
        goto CPyL214;
    }
    cpy_r_r379 = PyObject_GetItem(cpy_r_r373, cpy_r_r378);
    CPy_DECREF(cpy_r_r373);
    CPy_DECREF(cpy_r_r378);
    if (unlikely(cpy_r_r379 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 118, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r380 = CPyStatics[59]; /* 2 */
    cpy_r_r381 = PyObject_GetItem(cpy_r_verts, cpy_r_r380);
    if (unlikely(cpy_r_r381 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 118, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r382 = CPyStatics[42]; /* 'vec3s' */
    cpy_r_r383 = CPyObject_GetAttr(cpy_r_r381, cpy_r_r382);
    CPy_DECREF(cpy_r_r381);
    if (unlikely(cpy_r_r383 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 118, CPyStatic_globals);
        goto CPyL215;
    }
    cpy_r_r384 = CPyStatics[56]; /* 0 */
    cpy_r_r385 = PyObject_SetItem(cpy_r_r383, cpy_r_r384, cpy_r_r379);
    CPy_DECREF(cpy_r_r383);
    CPy_DECREF(cpy_r_r379);
    cpy_r_r386 = cpy_r_r385 >= 0;
    if (unlikely(!cpy_r_r386)) {
        CPy_AddTraceback("object.py", "draw_object", 118, CPyStatic_globals);
        goto CPyL205;
    }
CPyL163: ;
    cpy_r_r387 = CPyModule_clipping;
    cpy_r_r388 = CPyStatics[45]; /* 'draw' */
    cpy_r_r389 = CPyObject_GetAttr(cpy_r_r387, cpy_r_r388);
    if (unlikely(cpy_r_r389 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 120, CPyStatic_globals);
        goto CPyL205;
    }
    PyObject *cpy_r_r390[6] = {
        cpy_r_verts, cpy_r_vs, cpy_r_v_uni, cpy_r_fs, cpy_r_f_uni,
        cpy_r_tri_draw_func
    };
    cpy_r_r391 = (PyObject **)&cpy_r_r390;
    cpy_r_r392 = _PyObject_Vectorcall(cpy_r_r389, cpy_r_r391, 6, 0);
    CPy_DECREF(cpy_r_r389);
    if (unlikely(cpy_r_r392 == NULL)) {
        CPy_AddTraceback("object.py", "draw_object", 120, CPyStatic_globals);
        goto CPyL205;
    } else
        goto CPyL216;
CPyL165: ;
    cpy_r_r393 = CPyTagged_Add(cpy_r_r138, 2);
    CPyTagged_DECREF(cpy_r_r138);
    CPyTagged_INCREF(cpy_r_r393);
    cpy_r_r138 = cpy_r_r393;
    cpy_r_r394 = CPyTagged_StealAsObject(cpy_r_r393);
    cpy_r_i = cpy_r_r394;
    goto CPyL49;
CPyL166: ;
    cpy_r_r395 = Py_None;
    CPy_INCREF(cpy_r_r395);
    return cpy_r_r395;
CPyL167: ;
    cpy_r_r396 = NULL;
    return cpy_r_r396;
CPyL168: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL167;
CPyL169: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r7);
    goto CPyL167;
CPyL170: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r11);
    goto CPyL167;
CPyL171: ;
    CPy_DecRef(cpy_r_verts);
    goto CPyL167;
CPyL172: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r17);
    goto CPyL167;
CPyL173: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r31);
    goto CPyL167;
CPyL174: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r32);
    goto CPyL167;
CPyL175: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r47);
    goto CPyL167;
CPyL176: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r48);
    goto CPyL167;
CPyL177: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r56);
    goto CPyL167;
CPyL178: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r70);
    goto CPyL167;
CPyL179: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r71);
    goto CPyL167;
CPyL180: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r86);
    goto CPyL167;
CPyL181: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r87);
    goto CPyL167;
CPyL182: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r95);
    goto CPyL167;
CPyL183: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r109);
    goto CPyL167;
CPyL184: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r110);
    goto CPyL167;
CPyL185: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r125);
    goto CPyL167;
CPyL186: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r126);
    goto CPyL167;
CPyL187: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    goto CPyL167;
CPyL188: ;
    CPy_DECREF(cpy_r_verts);
    CPy_DECREF(cpy_r_r137);
    CPyTagged_DECREF(cpy_r_r138);
    CPy_DECREF(cpy_r_i);
    goto CPyL166;
CPyL189: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r146);
    goto CPyL167;
CPyL190: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r152);
    goto CPyL167;
CPyL191: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r159);
    goto CPyL167;
CPyL192: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r165);
    goto CPyL167;
CPyL193: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r172);
    goto CPyL167;
CPyL194: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r178);
    goto CPyL167;
CPyL195: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r201);
    goto CPyL167;
CPyL196: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r216);
    goto CPyL167;
CPyL197: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r231);
    goto CPyL167;
CPyL198: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r240);
    goto CPyL167;
CPyL199: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r246);
    goto CPyL167;
CPyL200: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r255);
    goto CPyL167;
CPyL201: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r261);
    goto CPyL167;
CPyL202: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r270);
    goto CPyL167;
CPyL203: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r276);
    goto CPyL167;
CPyL204: ;
    CPy_DECREF(cpy_r_i);
    goto CPyL124;
CPyL205: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    goto CPyL167;
CPyL206: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_r302);
    goto CPyL167;
CPyL207: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_r318);
    goto CPyL167;
CPyL208: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_r334);
    goto CPyL167;
CPyL209: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r343);
    goto CPyL167;
CPyL210: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r349);
    goto CPyL167;
CPyL211: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r358);
    goto CPyL167;
CPyL212: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r364);
    goto CPyL167;
CPyL213: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r373);
    goto CPyL167;
CPyL214: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_r373);
    goto CPyL167;
CPyL215: ;
    CPy_DecRef(cpy_r_verts);
    CPy_DecRef(cpy_r_r137);
    CPyTagged_DecRef(cpy_r_r138);
    CPy_DecRef(cpy_r_r379);
    goto CPyL167;
CPyL216: ;
    CPy_DECREF(cpy_r_r392);
    goto CPyL165;
}

PyObject *CPyPy_draw_object(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"obj", "vs", "v_uni", "fs", "f_uni", "tri_draw_func", 0};
    static CPyArg_Parser parser = {"OOOOOO:draw_object", kwlist, 0};
    PyObject *obj_obj;
    PyObject *obj_vs;
    PyObject *obj_v_uni;
    PyObject *obj_fs;
    PyObject *obj_f_uni;
    PyObject *obj_tri_draw_func;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_obj, &obj_vs, &obj_v_uni, &obj_fs, &obj_f_uni, &obj_tri_draw_func)) {
        return NULL;
    }
    PyObject *arg_obj = obj_obj;
    PyObject *arg_vs = obj_vs;
    PyObject *arg_v_uni = obj_v_uni;
    PyObject *arg_fs = obj_fs;
    PyObject *arg_f_uni = obj_f_uni;
    PyObject *arg_tri_draw_func = obj_tri_draw_func;
    PyObject *retval = CPyDef_draw_object(arg_obj, arg_vs, arg_v_uni, arg_fs, arg_f_uni, arg_tri_draw_func);
    return retval;
fail: ;
    CPy_AddTraceback("object.py", "draw_object", 82, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    PyObject **cpy_r_r6;
    PyObject **cpy_r_r7;
    void *cpy_r_r9;
    void *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    int32_t cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    int32_t cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    int32_t cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[46]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("object.py", "<module>", -1, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_re;
    cpy_r_r6 = (PyObject **)&CPyModule_clipping;
    cpy_r_r7 = (PyObject **)&CPyModule_vertex;
    PyObject **cpy_r_r8[3] = {cpy_r_r5, cpy_r_r6, cpy_r_r7};
    cpy_r_r9 = (void *)&cpy_r_r8;
    int64_t cpy_r_r10[3] = {1, 2, 3};
    cpy_r_r11 = (void *)&cpy_r_r10;
    cpy_r_r12 = CPyStatics[68]; /* (('re', 're', 're'), ('clipping', 'clipping', 'clipping'),
                                   ('vertex', 'vertex', 'vt')) */
    cpy_r_r13 = CPyStatic_globals;
    cpy_r_r14 = CPyStatics[50]; /* 'object.py' */
    cpy_r_r15 = CPyStatics[51]; /* '<module>' */
    cpy_r_r16 = CPyImport_ImportMany(cpy_r_r12, cpy_r_r9, cpy_r_r13, cpy_r_r14, cpy_r_r15, cpy_r_r11);
    if (!cpy_r_r16) goto CPyL15;
    cpy_r_r17 = NULL;
    cpy_r_r18 = CPyStatics[52]; /* 'object' */
    cpy_r_r19 = (PyObject *)CPyType_face_template;
    cpy_r_r20 = CPyType_FromTemplate(cpy_r_r19, cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("object.py", "<module>", 5, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r21 = CPyDef_face_trait_vtable_setup();
    if (unlikely(cpy_r_r21 == 2)) {
        CPy_AddTraceback("object.py", "<module>", -1, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r22 = CPyStatics[53]; /* '__mypyc_attrs__' */
    cpy_r_r23 = CPyStatics[31]; /* 'a_v' */
    cpy_r_r24 = CPyStatics[34]; /* 'a_vt' */
    cpy_r_r25 = CPyStatics[37]; /* 'a_vn' */
    cpy_r_r26 = CPyStatics[32]; /* 'b_v' */
    cpy_r_r27 = CPyStatics[35]; /* 'b_vt' */
    cpy_r_r28 = CPyStatics[38]; /* 'b_vn' */
    cpy_r_r29 = CPyStatics[33]; /* 'c_v' */
    cpy_r_r30 = CPyStatics[36]; /* 'c_vt' */
    cpy_r_r31 = CPyStatics[39]; /* 'c_vn' */
    cpy_r_r32 = PyTuple_Pack(9, cpy_r_r23, cpy_r_r24, cpy_r_r25, cpy_r_r26, cpy_r_r27, cpy_r_r28, cpy_r_r29, cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("object.py", "<module>", 5, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r33 = PyObject_SetAttr(cpy_r_r20, cpy_r_r22, cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r34 = cpy_r_r33 >= 0;
    if (unlikely(!cpy_r_r34)) {
        CPy_AddTraceback("object.py", "<module>", 5, CPyStatic_globals);
        goto CPyL16;
    }
    CPyType_face = (PyTypeObject *)cpy_r_r20;
    CPy_INCREF(CPyType_face);
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyStatics[54]; /* 'face' */
    cpy_r_r37 = CPyDict_SetItem(cpy_r_r35, cpy_r_r36, cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r38 = cpy_r_r37 >= 0;
    if (unlikely(!cpy_r_r38)) {
        CPy_AddTraceback("object.py", "<module>", 5, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r39 = NULL;
    cpy_r_r40 = CPyStatics[52]; /* 'object' */
    cpy_r_r41 = (PyObject *)CPyType_object_template;
    cpy_r_r42 = CPyType_FromTemplate(cpy_r_r41, cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("object.py", "<module>", 19, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r43 = CPyDef_object_trait_vtable_setup();
    if (unlikely(cpy_r_r43 == 2)) {
        CPy_AddTraceback("object.py", "<module>", -1, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r44 = CPyStatics[53]; /* '__mypyc_attrs__' */
    cpy_r_r45 = CPyStatics[16]; /* 'vertices' */
    cpy_r_r46 = CPyStatics[22]; /* 'uvs' */
    cpy_r_r47 = CPyStatics[26]; /* 'normals' */
    cpy_r_r48 = CPyStatics[30]; /* 'faces' */
    cpy_r_r49 = PyTuple_Pack(4, cpy_r_r45, cpy_r_r46, cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("object.py", "<module>", 19, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r50 = PyObject_SetAttr(cpy_r_r42, cpy_r_r44, cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    cpy_r_r51 = cpy_r_r50 >= 0;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("object.py", "<module>", 19, CPyStatic_globals);
        goto CPyL17;
    }
    CPyType_object = (PyTypeObject *)cpy_r_r42;
    CPy_INCREF(CPyType_object);
    cpy_r_r52 = CPyStatic_globals;
    cpy_r_r53 = CPyStatics[52]; /* 'object' */
    cpy_r_r54 = CPyDict_SetItem(cpy_r_r52, cpy_r_r53, cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("object.py", "<module>", 19, CPyStatic_globals);
        goto CPyL15;
    }
    return 1;
CPyL15: ;
    cpy_r_r56 = 2;
    return cpy_r_r56;
CPyL16: ;
    CPy_DecRef(cpy_r_r20);
    goto CPyL15;
CPyL17: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL15;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_object = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_re = Py_None;
    CPyModule_clipping = Py_None;
    CPyModule_vertex = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[69];
const char * const CPyLit_Str[] = {
    "\t\001r\004open\b__exit__\t__enter__\breadline\002v \nstartswith\n-\?\\d+\\.\\d*\afindall",
    "\004\003map\027Error: vertex at line ## doesn\'t have 3 or more coordinates\005print",
    "\005\bvertices\004vec4\006append\003vt \037Error: vertex texture at line #",
    "\004# doesn\'t have 2 or more coordinates\003uvs\004vec2\003vn ",
    "\t\036Error: vertex normal at line #\anormals\004vec3\002f \003\\d+\005faces\003a_v\003b_v\003c_v",
    "\f\004a_vt\004b_vt\004c_vt\004a_vn\004b_vn\004c_vn\006vertex\005vec4s\005vec3s\005vec2s\003pos\004draw",
    "\b\bbuiltins\002re\bclipping\002vt\tobject.py\b<module>\006object\017__mypyc_attrs__",
    "\001\004face",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\n-1\0000\0001\0003\0002\0004\0005\0006\0007\0008",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {4, 3, 47, 47, 47, 3, 48, 48, 48, 3, 40, 40, 49, 3, 65, 66, 67};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_object_internal = NULL;
CPyModule *CPyModule_object;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_re;
CPyModule *CPyModule_clipping;
CPyModule *CPyModule_vertex;
PyTypeObject *CPyType_face;
PyObject *CPyDef_face(void);
PyTypeObject *CPyType_object;
PyObject *CPyDef_object(void);
char CPyDef_face_____init__(PyObject *cpy_r_self);
PyObject *CPyPy_face_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef_object_____init__(PyObject *cpy_r_self);
PyObject *CPyPy_object_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_load_obj(PyObject *cpy_r_filepath);
PyObject *CPyPy_load_obj(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_draw_object(PyObject *cpy_r_obj, PyObject *cpy_r_vs, PyObject *cpy_r_v_uni, PyObject *cpy_r_fs, PyObject *cpy_r_f_uni, PyObject *cpy_r_tri_draw_func);
PyObject *CPyPy_draw_object(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
