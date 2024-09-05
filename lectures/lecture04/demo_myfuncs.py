# author: Henry Eichten

import myfuncs as mf, numpy as np
from importlib import reload

reload(mf)

x = 2

print("np.sqrt(2): \t\t\t\t\t\t", np.sqrt(x))
print("my_sqrt(2): \t\t\t\t\t\t", mf.my_sqrt(x), "\n")

x = 5
print("2.7182818284590451 ** ", x, ": \t\t\t", 2.7182818284590451 ** x)
print("my_exp(", x, "): \t\t\t\t\t\t", mf.my_exp(x))
print("my_new_exp(", x, ") (Newtons Method): \t", mf.my_new_exp(x), "\n")

print("np.log(8): \t\t\t\t\t\t\t", np.log(8))
print("my_ln(8): \t\t\t\t\t\t\t", mf.my_ln(8))
