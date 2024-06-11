# distutils: language = c++

from libcpp.string cimport string

<<<<<<< HEAD
from msgq.visionipc.visionipc cimport cl_context
=======
from cereal.visionipc.visionipc cimport cl_context
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)

cdef extern from "selfdrive/modeld/runners/thneedmodel.h":
  cdef cppclass ThneedModel:
    ThneedModel(string, float*, size_t, int, bool, cl_context)
