import mylinalg as mf
import numpy as np
from numpy.linalg import solve

A = np.array([[-4.3, 7.1],[-0.2, 5.6]])

b = np.dot(A, np.array([2.0, -5.0]))

print("A:")
print(A)

print("b:")
print(b)

np_solve = solve(A, b)
print("\n\nsolve(A,b):")
print(np_solve)

my_gaus = mf.my_gaussian(A, b)
print("my_gaussian(A,b):")
print(my_gaus)


A = np.array([[-4.3, 7.1, 1.1],[-0.2, 5.6, -2.3],[1.9, -6.3, 2.7]])

b = np.dot(A, np.array([2.0, -5.0, 3.3]))

print("\n\n\nA:")
print(A)

print("b:")
print(b)

np_solve = solve(A, b)
print("\n\nsolve(A,b):")
print(np_solve)

my_gaus = mf.my_gaussian(A, b)
print("my_gaussian(A,b):")
print(my_gaus)
