<<<<<<< HEAD
=======
from collections.abc import Callable
from functools import lru_cache
from typing import TypeVar


_RT = TypeVar("_RT")


>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)
class Freezable:
  _frozen: bool = False

  def freeze(self):
    if not self._frozen:
      self._frozen = True

  def __setattr__(self, *args, **kwargs):
    if self._frozen:
      raise Exception("cannot modify frozen object")
    super().__setattr__(*args, **kwargs)
<<<<<<< HEAD
=======


def cache(user_function: Callable[..., _RT], /) -> Callable[..., _RT]:
  return lru_cache(maxsize=None)(user_function)
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)
