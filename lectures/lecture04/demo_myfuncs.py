# author: Henry Eichten

import myfuncs as mf, numpy as np
from importlib import reload
reload(mf)

x = 2

print("np.sqrt(2): \t\t\t\t\t", np.sqrt(x))
print("mySqrt(2): \t\t\t\t\t\t", mf.my_sqrt(x), "\n")

print("2.7182818284590451 ** 5: \t\t", 2.7182818284590451 ** 5)
print("myExp(5): \t\t\t\t\t\t", mf.my_exp(5), "\n")
# print("myExp(5): \t\t\t\t\t\t", mf.newtons_exp(5), "\n")

print("np.log(8): \t\t\t\t\t\t", np.log(8))
print("myLn(8): \t\t\t\t\t\t", mf.my_ln(8))
