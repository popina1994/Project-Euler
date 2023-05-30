__author__ = 'popina'

import itertools

sum = 0

for perm in itertools.permutations('0123456789', 10) :
    strNum = ''.join(perm)
    if (int(strNum[1:4]) % 2 == 0)\
and (int(strNum[2:5]) % 3 == 0)\
and (int(strNum[3:6]) % 5 == 0)and\
(int(strNum[4:7]) % 7 == 0) and (int(strNum[5:8]) % 11 == 0) and\
(int(strNum[6:9]) % 13 == 0) and (int(strNum[7:10]) % 17 == 0) :
        print strNum
        sum += int(strNum)
print sum
