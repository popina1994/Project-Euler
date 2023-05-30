__author__ = 'popina'

STOP = 100000

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

curNum = 1
curCnt = 0
numPass = 1
for idx in range(2, STOP, 2) :
    for dirCnt in range(4) :
        curNum += idx
        numPass += 1
        if dirCnt != 3 : # nije "poslednja" dijagonala
            if IsPrime(curNum) :
                curCnt += 1
    print curNum, curCnt, numPass, float(curCnt) / numPass
    if (float(curCnt) / numPass) < 0.1 :
        import math
        print int(math.sqrt(curNum))
        break