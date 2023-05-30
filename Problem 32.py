__author__ = 'popina'

def CheckPan(map, num) :
    list = [int(char) for char in str(num)]
    for digit in list :
        if (map[digit] > 0) :
            return False
        else :
            map[digit] = 1
    return True

def IsPan(map) :
    if (map[0] != 0) :
        return False
    for digit in range(1, 10) :
        if (map[digit] == 0):
            return False
    return True

sum = 0
for it in range(1, 10000) :

    num = it
    div = 2
    import math

    while (div < math.sqrt(num) + 1) :
        if (num % div == 0) :
            map = {}
            for idx in range (0, 10) :
                map[idx] = 0
            q = num / div
            if CheckPan(map, q) and CheckPan(map, div) and CheckPan(map, num) and IsPan(map) :

                print num, q, div
                print sum
                sum += num
                break
        div += 1
print sum