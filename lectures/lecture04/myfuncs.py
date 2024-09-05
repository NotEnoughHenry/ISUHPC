# author: Henry Eichten

import numpy as np

def my_factorial(x):
    s = 1.0
    for k in range(x):
        s = (k+1)*s
    return s

def my_exp(x):
    x0 = int(round(x))
    z = 1.0 * x - x0
    econst = 2.7182818284590451
    expx0 = econst ** x0
    s = 1
    k = 0
    for k in range(x0):
        s += (z**(k+1)) / my_factorial(k + 1)
    print("iteration count:", k)
    return expx0**s

def my_new_exp(x):
    max_iterations = 100
    tolerance = 1e-10
    s = 1.0
    k = 0
    for k in range(max_iterations):
        ln_s = my_ln(s)
        s_next = s * (1 + x - ln_s)
        if abs(s_next - s) < tolerance:
            print("iteration count:", k)
            return s_next
        s = s_next
    print("iteration count:", k)
    return s

def my_sqrt(x):
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

def my_ln(x):
    ln2 = 0.6931471805599453
    tolerance = 1e-10
    n = 0
    z = (x - 1) / (x + 1)
    z_squared = z * z
    ln_approx = 0
    term = 2 * z
    i = 1
    while abs(term) > tolerance:
        ln_approx += term
        term *= z_squared * (2 * i - 1) / (2 * i + 1)
        i += 1
    return ln_approx + n * ln2