import ctypes
import sys
from ctypes import *

def sort(lst):
    n = len(lst)
    DATA_TYPE = ctypes.c_int * n
    data = DATA_TYPE(*lst)
    so_file = './lib.so'
    funcs = CDLL(so_file)
    funcs.quickSort(data, 0, n - 1)