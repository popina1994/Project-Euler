__author__ = 'popina'

import itertools

def IsPrime(x) :
    if (x == 2) :
        return True
    if x == 1 :
        return False
    if (x % 2 == 0) :
        return False
    import math
    for idx in range(3, int(math.sqrt(x) + 1), 2) :
        if (x % idx == 0) :
            return False
    return True

biggestNum = -1

for digit in itertools.permutations('1234567', 7) :
    num = (int)(''.join(digit))
    if (num > biggestNum) and IsPrime(num) :
        biggestNum = num
print "Najveci je", biggestNum
