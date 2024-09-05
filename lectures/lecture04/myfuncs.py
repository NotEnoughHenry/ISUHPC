# author: Henry Eichten

import numpy as np

def myFactorial(x):
    s = 1.0
    for k in range(x):
        s = (k+1)*s
    return s


def myExp(x):
    x0 = int(round(x))
    z = 1.0 * x - x0
    econst = 2.7182818284590451
    expx0 = econst ** x0
    s = 1
    for k in range(x0):
        s += (z**(k+1)) / myFactorial(k + 1)
    return expx0**s


def myLn(x):
    s = x
    tol = 1e-10
    for i in range(100):
        s_next = s - 1 + x * myExp(-s)
        if abs(s_next - s) < tol:
            return s_next
        s = s_next
    return s

def newtons_ln(x):
    s = x
    tol = 1e-10
    for i in range(100):
        s_next = s - 1 + x * myExp(-s)
        if abs(s_next - s) < tol:
            return s_next
        s = s_next
    return s

def mySqrt(x):
    if x > 0:
        kmax = 100
        s = 1.0
        for k in range(kmax):
            s = 0.5 * (s + x/s)
        return s
    elif x == 0:
        return 0.0
    else:
        return np.nan