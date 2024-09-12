# Author: Henry Eichten

import numpy as np
from numpy import cos
from matplotlib import pyplot as plt


def my_gaussian(a, b):
    n = len(b)
    x = np.zeros(n, float)

    # Forward Elimination
    for k in range(n - 1):
        for i in range(k + 1, n):
            factor = a[i, k] / a[k, k]
            for j in range(k, n):
                a[i, j] = a[i, j] - factor * a[k, j]
            b[i] = b[i] - factor * b[k]

    # Back-Substitution
    x[n - 1] = b[n - 1] / a[n - 1, n - 1]
    for i in range(n - 2, -1, -1):
        sum = b[i]
        for j in range(i + 1, n):
            sum = sum - a[i, j] * x[j]
        x[i] = sum / a[i, i]
    return x


def p(coefficients, x):
    return coefficients[0] * x ** 3 + coefficients[1] * x ** 2 + coefficients[2] * x + coefficients[3]


if __name__ == "__main__":
    points = [(-0.1, cos(-0.1)), (-0.02, cos(-0.02)), (0.02, cos(0.02)), (0.1, cos(0.1))]
    # This is just easier than entering numbers and making sure it's right
    A = np.array([[x ** 3, x ** 2, x, 1] for x, _ in points], float)
    b = np.array([y for _, y in points], float)

    print("A:")
    print(A)
    print("b:")
    print(b)

    x = my_gaussian(A, b)
    print("\nx:")
    print(x)

    x_vals = np.linspace(-0.1, 0.1, 100)
    plt.plot(x_vals, np.cos(x_vals), label='f(x) = cos(x)', color='red')
    plt.plot(x_vals, p(x, x_vals), label='p(x) (Cubic Polynomial)', linestyle='--', color='black')
    # *zip(*points) simply packs it into ((x_0,y_0), (x_1,y_1), ... (x_n, y_n)) format
    plt.scatter(*zip(*points), color='black')
    plt.legend()
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Cubic Polynomial Interpolation of cos(x)')
    plt.grid(True)
    plt.show()
