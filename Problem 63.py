__author__ = 'popina'

import math
MAX_NUM = 144

cnt = 0
for power in range(1, MAX_NUM) :
    for base in range(1, MAX_NUM) :
        val = base ** power
        if len(str(val) ) == power :
            print base,power, val
            cnt += 1
print cnt