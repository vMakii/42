import numpy as np
from dataclasses import dataclass

@dataclass
class NumPyCreator:
    def from_list(self, lst, dtype=object):
        """
        Takes a list or nested lists and returns its corresponding Numpy array.
        """
        if not isinstance(lst, list):
            return None
        try:
            return np.array(lst, dtype=dtype)
        except Exception as e:
            print(f"Error: {e}")
            return None
        
    def from_tuple(self, tpl, dtype=None):
        """
        Takes a tuple or nested tuples and returns its corresponding Numpy array.
        """
        if not isinstance(tpl, tuple):
            return None
        try:
            return np.array(tpl, dtype=dtype)
        except Exception as e:
            print(f"Error: {e}")
            return None
        
    def from_iterable(self, itr, dtype=None):
        """
        Takes an iterable and returns an array which contains all of its elements.
        """
        if isinstance(itr, (list, tuple, str)):
            return None
        try:
            iter(itr)
            return np.array(list(itr), dtype=dtype)
        except TypeError:
            return None
        except Exception as e:
            print(f"Error: {e}")
            return None

    def from_shape(self, shape, value=0, dtype=None):
        """
        Returns an array filled with the same value.
        The first argument is a tuple which specifies the shape of the array,
        and the second argument specifies the value of elements.
        This value must be 0 by default.
        """
        try:
            return np.full(shape, value, dtype=dtype)
        except Exception as e:
            print(f"Error: {e}")
            return None
        
    def random(self, shape, dtype=None):
        """
        Returns an array filled with random values.
        It takes as an argument a tuple which specifies the shape of the array.
        """
        try:
            if dtype:
                return np.random.rand(*shape).astype(dtype)
            return np.random.rand(*shape)
        except Exception as e:
            print(f"Error: {e}")
            return None
        
    def identity(self, n, dtype=None):
        """
        Returns an array reprensenting the identity matrix of size n.
        """
        try:
            return np.identity(n, dtype=dtype)
        except Exception as e:
            print(f"Error: {e}")
            return None