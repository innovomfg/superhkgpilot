# distutils: language = c++

<<<<<<< HEAD
from msgq.visionipc.visionipc cimport cl_mem
from msgq.visionipc.visionipc_pyx cimport CLContext as BaseCLContext
=======
from cereal.visionipc.visionipc cimport cl_mem
from cereal.visionipc.visionipc_pyx cimport CLContext as BaseCLContext
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)

cdef class CLContext(BaseCLContext):
  pass

cdef class CLMem:
  cdef cl_mem * mem

  @staticmethod
  cdef create(void*)
