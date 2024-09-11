import numpy as np

def my_gaussian(a, b):
    n = len(b)
    x = np.zeros(n, float)

    # Forward Elimination
    for k in range(n-1):
        for i in range(k + 1, n):
            factor = a[i, k] / a[k, k]
            for j in range(k, n):
                a[i, j] = a[i, j] - factor * a[k, j]
            b[i] = b[i] - factor * b[k]

    # Back-Substitution
    x[n-1] = b[n-1] / a[n-1, n-1]
    for i in range(n-2, -1, -1):
        sum = b[i]
        for j in range(i+1, n):
            sum = sum - a[i, j] * x[j]
        x[i] = sum / a[i,i]

    return x