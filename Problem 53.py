__author__ = 'popina'

import itertools
import math

BORDER = 1000000
list = []

for n in range(1, 101) :
    for r in range(1, n + 1) :
        val = math.factorial(n) / (math.factorial(r) * math.factorial(n - r))
        if (val > BORDER) :
            list.append(val)
#print list
print len(list)

